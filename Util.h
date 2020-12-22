bool displayState = true;

float getBatteryPercentage() {
  return (M5.Axp.GetBatVoltage() - 3.27) * 100;
}

void displayOff() {
  if (displayState == true) {
    for (int i = SCREEN_BRIGHTNESS; i >= 0; i--) {
      M5.Axp.ScreenBreath(i);
      delay(50);
    }
    displayState = false;
  }
}

void displayOn() {
  if (displayState == false) {
    for (int i = 0; i < SCREEN_BRIGHTNESS; i++) {
      M5.Axp.ScreenBreath(i);
      delay(50);
    }
    displayState = true;
  }
}

void toggleDisplay() {
  if (displayState)  displayOff();
  else  displayOn();
}
