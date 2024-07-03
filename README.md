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
![img](https://github.com/proxytype/ZeroBro/blob/1050294310dfeb6d6b9d6ca315c60866f8d7245e/esp32-oled2.jpg)

![img](https://raw.githubusercontent.com/proxytype/ZeroBro/main/large-oled.png)

* Multi Oled Screens using TCA9548A with I2C (Arduino Sketch). [>>>](https://github.com/proxytype/ZeroBro/tree/main/Experimental/Oled-Multiscreen/ESP32/Arduino)
  


## Hardware

* CPU
  * NodeMCU ESP32. [>>>](https://www.aliexpress.com/item/32834130422.html)
  * Arduino Pro Micro. [>>>](https://www.aliexpress.com/item/1005001622051348.html)

* Peripherals
   * RFID Reader - RC522. [>>>](https://www.aliexpress.com/item/1005004659043670.html)
   * IR Transmitter / Receiver - 38Khz. [>>>](https://www.aliexpress.com/item/4001237995692.html)
   * TFT - ILI9341. [>>>](https://www.aliexpress.com/item/1005004928951786.html)
   * Oled - SSD1306. [>>>](https://www.aliexpress.com/item/33036863902.html)
   * GPS - GY-NEO6MV2. [>>>](https://www.aliexpress.com/item/1005001635722164.html)
   * GSM - SIM800L. [>>>](https://www.aliexpress.com/item/1005005547754754.html)
 
* Power Supply
    * 18650 Battery bay (3v/5v + protection). [>>>](https://www.aliexpress.com/item/1005004006109248.html)
    * 18650 Batteries with protection. [>>>](https://www.aliexpress.com/item/1005003411216513.html)
 
  ![Power](https://raw.githubusercontent.com/proxytype/ZeroBro/main/power2.jpg)

Starting to design a modular system where each layer consists of a set of components:

* ESP32 Layer

![img](https://raw.githubusercontent.com/proxytype/ZeroBro/main/esp-base.png)

* Arduino Micro Layer

![img](https://raw.githubusercontent.com/proxytype/ZeroBro/main/arduino-base1.png)

* GPS Layer - SIM800L

![img](https://raw.githubusercontent.com/proxytype/ZeroBro/main/gps-1.jpg)

## Environments
### ESP
   * ESP IDF FRAMEWORK: 4.1.4
   * Visual Code

### Arduino Pro Micro
* Arduino IDE

```[tasklist]
### TASK LIST
- [x] Connect to TFT/OLED
- [ ] Navigation Control
- [ ] USB HID INTERFACE
- [ ] CC1101 RF INTERFACE
- [x] 18650 Battery Bay
- [ ] SD Card INTERFACE
```
