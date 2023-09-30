# RFID Reader

![ESP and Arduino Pro Micro](https://raw.githubusercontent.com/proxytype/ZeroBro/main/Sections/SPI%20-%20RFID%20reader/rudenetwork-card-mask-zerobro1.png)

This code is a C program designed for use with ESP32 microcontrollers and the ESP-IDF (Espressif IoT Development Framework) SDK. It interacts with an RC522 RFID (Radio-Frequency Identification) module to scan RFID tags. Below is an explanation of the code:

1. **Header File Inclusions**:
   - `#include <esp_log.h>`: This header file is used for logging and debugging in ESP32 applications.
   - `#include <inttypes.h>`: This header file provides portable integer types like `PRIu64` for formatting and manipulating integers.
   - `"rc522.h"`: This is a custom header file that contains declarations and functions related to the RC522 RFID module.

2. **Static Constants**:
   - `static const char* TAG = "rc522-demo";`: This defines a static character array (string) named `TAG`, which is used as a tag or identifier for logging purposes. It helps identify log messages related to this code.
   - `static rc522_handle_t scanner;`: This defines a static handle or instance of the RC522 module named `scanner`. It will be used to interact with the RC522 module.

3. **Event Handler Function**:
   - `static void rc522_handler(void* arg, esp_event_base_t base, int32_t event_id, void* event_data)`: This function serves as an event handler for RC522 events. It is called when specific events related to the RC522 module occur.
   - Inside the function, it extracts the event data and processes it based on the event ID.
   - In this code, it specifically handles the `RC522_EVENT_TAG_SCANNED` event. When a tag is scanned, it logs the tag's serial number using `ESP_LOGI`.

4. **`app_main` Function**:
   - `void app_main(void)`: This is the main function of the application and serves as the entry point for execution when the ESP32 starts.
   - Inside this function, an RC522 configuration structure (`rc522_config_t`) named `config` is defined and initialized with various parameters:
     - `spi.host = VSPI_HOST`: Specifies the SPI host (Virtual SPI Host) to be used for communication.
     - `spi.miso_gpio = 19`: Defines the GPIO pin for SPI MISO (Master In Slave Out).
     - `spi.mosi_gpio = 23`: Defines the GPIO pin for SPI MOSI (Master Out Slave In).
     - `spi.sck_gpio = 18`: Defines the GPIO pin for SPI SCK (Serial Clock).
     - `spi.sda_gpio = 5`: Defines the GPIO pin for the RC522's SDA (Serial Data) connection.

   - The RC522 scanner instance is created using `rc522_create(&config, &scanner)`. It is initialized with the specified configuration.

   - An event handler function (`rc522_handler`) is registered using `rc522_register_events`. It tells the RC522 module to call `rc522_handler` when any RC522 event occurs (`RC522_EVENT_ANY`).

   - Finally, the RC522 module is started by calling `rc522_start(scanner)`. This initiates the RFID scanning process, and when a tag is scanned, the registered event handler (`rc522_handler`) will process and log the tag's serial number.

In summary, this code sets up an ESP32 application to interface with an RC522 RFID module, configure its parameters, register an event handler, and start scanning for RFID tags. When a tag is scanned, it logs the tag's serial number to the ESP32's console using the ESP_LOGI function.
