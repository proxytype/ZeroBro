[img](https://raw.githubusercontent.com/proxytype/ZeroBro/main/Experimental/Oled-Multiscreen/ESP32/Arduino/PCA9548A.PNG)
# OLED Display Multiplexing with ESP32

This Arduino sketch demonstrates how to use the TCA9548A I2C multiplexer to control multiple OLED displays with an ESP32 board.

### Libraries Used
- `Wire.h`: ESP32's/Arduino's I2C communication library.
- `Adafruit_GFX.h`: Graphics library for drawing shapes, text, etc.
- `Adafruit_SSD1306.h`: Library for controlling SSD1306-based OLED displays.

### Constants
- `SCREEN_WIDTH`: Width of the OLED display in pixels.
- `SCREEN_HEIGHT`: Height of the OLED display in pixels.

### Variables
- `display`: Object of type `Adafruit_SSD1306` for controlling the OLED display.

### Functions
- `TCA9548A(uint8_t bus)`: Function to select the I2C bus using the TCA9548A multiplexer.

### Setup Function (`void setup()`)
- Initializes serial communication at a baud rate of 115200.
- Begins I2C communication.
- Initializes the OLED display connected to bus number 2.
- Clears the display buffer.
- Initializes the OLED display connected to bus number 3.
- Clears the display buffer.
- Writes text "1" to the OLED display on bus number 2.
- Writes text "2" to the OLED display on bus number 3.

### Loop Function (`void loop()`)
- The `loop()` function is empty as there are no continuous tasks to perform.

### Additional Notes
- The TCA9548A multiplexer is used to switch between different I2C buses connected to the OLED displays. This allows controlling multiple displays with a single ESP32 board.
- Each OLED display is initialized separately, and text is written to each display individually.

```[tasklist]
### TASK LIST
- [ ] Translate To clean ESP-IDF
```
### References
https://randomnerdtutorials.com/tca9548a-i2c-multiplexer-esp32-esp8266-arduino/
