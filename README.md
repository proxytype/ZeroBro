# ZeroBro
ZeroBro is a cost-effective DIY alternative to the Flipper Zero, providing a similar functionality and design while catering to budget-conscious enthusiasts.

![ZeroBro](https://raw.githubusercontent.com/proxytype/ZeroBro/main/zerobro-1.PNG)

* UART - ESP comunication With Arduino Pro Micro (BadUSB). [>>>](https://github.com/proxytype/ZeroBro/tree/main/Sections/UART%20-%20Arduino%20Pro%20Micro)
* SPI - ESP communication With RFID Reader. [>>>](https://github.com/proxytype/ZeroBro/tree/main/Sections/SPI%20-%20RFID%20reader)
* GPIO - IR Receiver And Transmitter With Arduino Pro Micro. [>>>](https://github.com/proxytype/ZeroBro/tree/main/Sections/GPIO%20-%20IR)
* SPI - ESP communication With TFT ILI9341. [>>>](https://github.com/proxytype/ZeroBro/tree/main/Sections/SPI%20-%20TFT%20ILI9341)
* I2C - ESP communication With OLed 1306. [>>>](https://github.com/proxytype/ZeroBro/tree/main/Sections/I2C-%20OLED)


## TFT Screen:
[![ESP32-TFT-ILI9341](https://img.youtube.com/vi/Ap0bh388Uds/0.jpg)](https://www.youtube.com/embed/Ap0bh388Uds)

## Oled Screen:
![img](https://github.com/proxytype/ZeroBro/blob/f361cc0d8af86de086bf9072c415d846689d1ee1/esp32-oled.jpg)

* Multi Oled Screen using TCA9548A with I2C (Arduino Sketch). [>>>](https://github.com/proxytype/ZeroBro/tree/main/Experimental/Oled-Multiscreen/ESP32/Arduino)
  


## Hardware

* CPU
  * NodeMCU ESP32. [>>>](https://www.aliexpress.com/item/32834130422.html)
  * Arduino Pro Micro. [>>>](https://www.aliexpress.com/item/1005001622051348.html)

* Peripherals
   * RFID Reader - RC522. [>>>](https://www.aliexpress.com/item/1005004659043670.html)
   * IR Transmitter / Receiver - 38Khz. [>>>](https://www.aliexpress.com/item/4001237995692.html)
   * TFT - ILI9341. [>>>](https://www.aliexpress.com/item/1005004928951786.html)
   * Oled - SSD1306. [>>>](https://www.aliexpress.com/item/33036863902.html)

## Environments
### ESP
   * ESP IDF FRAMEWORK: 4.1.4
   * Visual Code

### Arduino Pro Micro
* Arduino IDE

```[tasklist]
### TASK LIST
- [x] Connect to TFT/OLED
- [ ] Create Navigation Control
- [ ] USB HID INTERFACE
- [ ] CC1101 RF INTERFACE
- [ ] 18650 Battery Bay
- [ ] SD Card INTERFACE
```
