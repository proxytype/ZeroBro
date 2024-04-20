# ESP32 OLED Display with LVGL

![img](https://raw.githubusercontent.com/proxytype/ZeroBro/main/Sections/I2C-%20OLED/ESP-OLED.PNG)

This code demonstrates how to interface an ESP32 with an OLED display using the LVGL (Light and Versatile Graphics Library) library. LVGL is a powerful graphics library for creating embedded GUIs.

### Libraries Used
- `stdio.h`: Standard Input/Output library for handling input/output operations.
- `freertos/FreeRTOS.h`: FreeRTOS library for real-time operating systems.
- `esp_timer.h`: ESP-IDF timer functions.
- `esp_lcd_panel_io.h`: ESP-IDF library for interfacing with LCD panels.
- `esp_lcd_panel_vendor.h`: ESP-IDF library for defining LCD panel vendors.
- `esp_lcd_panel_ops.h`: ESP-IDF library for LCD panel operations.
- `driver/i2c.h`: ESP-IDF I2C driver.
- `esp_err.h`: ESP-IDF error handling.
- `esp_log.h`: ESP-IDF logging.
- `lvgl.h`: LVGL library header.

### Constants
- `TAG`: Tag used for ESP-IDF logging.
- `I2C_HOST`: I2C bus number.
- Configuration parameters for the connected OLED display:
  - `EXAMPLE_LCD_PIXEL_CLOCK_HZ`: Pixel clock frequency.
  - `EXAMPLE_PIN_NUM_SDA`: Pin number for I2C SDA.
  - `EXAMPLE_PIN_NUM_SCL`: Pin number for I2C SCL.
  - `EXAMPLE_PIN_NUM_RST`: Pin number for the display reset (if applicable).
  - `EXAMPLE_I2C_HW_ADDR`: I2C hardware address of the display.
  - `EXAMPLE_LCD_H_RES`: Horizontal resolution of the display.
  - `EXAMPLE_LCD_V_RES`: Vertical resolution of the display.
  - `EXAMPLE_LCD_CMD_BITS`: Number of bits for LCD commands.
  - `EXAMPLE_LCD_PARAM_BITS`: Number of bits for LCD parameters.
  - `EXAMPLE_LVGL_TICK_PERIOD_MS`: Period (in milliseconds) for LVGL tick.

### Functions
- `example_notify_lvgl_flush_ready()`: Callback function to notify LVGL when a flush is ready.
- `example_lvgl_flush_cb()`: Callback function to flush LVGL's display buffer to the physical display.
- `example_lvgl_set_px_cb()`: Callback function to set a pixel in LVGL's buffer.
- `example_lvgl_rounder()`: Callback function to round the drawing area coordinates.
- `example_increase_lvgl_tick()`: Callback function to increase LVGL's tick.

### Main Function (`app_main()`)
- Initializes I2C bus communication.
- Installs panel IO for the connected OLED display.
- Installs the SSD1306 panel driver.
- Initializes LVGL library.
- Allocates and initializes LVGL draw buffers.
- Registers display driver to LVGL.
- Installs LVGL tick timer.
- Displays LVGL scroll text.
- Enters an infinite loop to handle LVGL tasks.

### Additional Notes
- The code assumes an ESP32 microcontroller with a connected OLED display using the SSD1306 driver.
- LVGL is configured to use a 2ms tick period for refreshing the display.
- LVGL UI functionality can be extended or modified within the provided `example_lvgl_demo_ui()` function.

## ESP IDF
Version: 5.0.1
