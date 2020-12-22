# Gift Giving Randomizer - M5Stack Christmas

> **TL;DR**
>
> I built a device to display the name of the next person to receive a present on the TV to make the bestowment more fun and organized.

![Website screenshot](README.assets/192.168.2.107_.png)

It uses the M5StickC from M5Stack as motion sensor and a TV or any PC with a browser as display. The M5StickC connects with your local WiFi, displays it's IP address and hosts a website. After browse with your TV or any browser to the displayed IP address you should see something like pictured in the above screenshot. When you shake the M5StickC it randomly determines the name of the next one to open a present and displays it on it's display and after a short moment on the website. You can enter your own names in the source code before flashing the M5StickC.

## Dependencies

| Dependency          | Link                                     | Description                                                  |
| ------------------- | ---------------------------------------- | ------------------------------------------------------------ |
| M5StickC library    | https://github.com/m5stack/M5StickC      | M5Stack's library to interface with the hardware of the M5StickC |
| Linked List library | https://github.com/ivanseidel/LinkedList | An implementation of a Linked List for Arduino based Systems |

## Installation

1. Open the Arduino IDE
2. Configure it to be able to flash the M5StackC [https://oneguyoneblog.com/2020/03/05/programming-the-m5stickc-with-the-arduino-ide/](https://oneguyoneblog.com/2020/03/05/programming-the-m5stickc-with-the-arduino-ide/)
3. Open `GiftGivingRandomizer.ino` in the Arduino IDE
4. Edit `Settings.h`
    1. Enter your WiFi's SSID and passphrase.
    2. Populate the `names[]`-Array with your names.
    3. Change any other settings you want to
5. Flash the M5StickC

## Usage

1. Let the M5StickC connect to your WiFi and start it's server
2. Browse to the displayed IP address (for example `192.168.2.107`)
3. Shake the M5StickC to display the next name

## Thanks

Thanks to [Ivan Seidel](https://github.com/ivanseidel) for his LinkedList implementation 👍