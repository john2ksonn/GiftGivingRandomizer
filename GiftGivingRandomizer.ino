#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <M5StickC.h>
#include <LinkedList.h> // https://github.com/ivanseidel/LinkedList

#include "index.h"
#include "Settings.h"
#include "Util.h"

WebServer server(80);
String nextName = "Santa Claus";
LinkedList<String> nameList;

float accX = 0;
float accY = 0;
float accZ = 0;

void initNameList() {
  for (String n : names) {
    nameList.add(n);
    Serial.print("add ");
    Serial.println(n);
  }
}

void displayNextName() {
  M5.Lcd.begin();
  displayOn();
  nextName = getNextName();
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(10, 10);
  M5.Lcd.setTextSize(2);
  M5.Lcd.print("\n");
  M5.Lcd.print(nextName);
  for (int i = 0; i < 10 * NAME_DISPLAY_TIME / 2; i++) {
    digitalWrite(LED_PIN, 0);
    delay(100);
    digitalWrite(LED_PIN, 1);
    delay(100);
  }
  displayOff();
}

String getNextName() {
  if (nameList.size() == 0) {
    initNameList();
  }
  int randIdx;
  String n = "";
  randIdx = random(0, nameList.size());
  n = nameList.get(randIdx);
  nameList.remove(randIdx);
  Serial.println(n);
  return n;
}

void handleRoot() {
  String s = MAIN_page;
  server.send(200, "text/html", s);
}

void handleNextName() {
  server.send(200, "text/plain", nextName);
}

void handleBatteryLevel() {
  String content = String(getBatteryPercentage());
  server.send(200, "text/plain", content);
}

void setup(void) {
  Serial.begin(115200);
  M5.begin();
  M5.MPU6886.Init();

  //ESP32 connects to wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  displayOn();
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(WHITE);
  delay(100);
  M5.Lcd.fillScreen(BLACK);

  // setup LED
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, 0);
  delay(100);
  digitalWrite(LED_PIN, 1);

  Serial.println("Connecting to ");
  Serial.print(ssid);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.setTextSize(1);
  M5.Lcd.printf("Connecting to\n\n");
  M5.Lcd.setTextSize(2);
  M5.Lcd.print(ssid);

  //Wait for WiFi to connect
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.print(".");
  }

  // print IP
  Serial.print("\nConnected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.setTextSize(1);
  M5.Lcd.printf("Browse to\n\n");
  M5.Lcd.setTextSize(2);
  M5.Lcd.print(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/nextName", handleNextName);
  server.on("/battery", handleBatteryLevel);
  server.begin();
  Serial.println("HTTP server started");
  delay(5000);
  displayOff();
}

void loop(void) {
  server.handleClient();
  delay(1);
  M5.update();
  M5.MPU6886.getAccelData(&accX, &accY, &accZ);
  if (abs(accX) >= WAKE_ON_MOTION_THRESHOLD || abs(accY) >= WAKE_ON_MOTION_THRESHOLD || abs(accZ) >= WAKE_ON_MOTION_THRESHOLD) {
    displayNextName();
    delay(2000);
  }
  if (M5.BtnA.isPressed()) {
    toggleDisplay();
  }
}
