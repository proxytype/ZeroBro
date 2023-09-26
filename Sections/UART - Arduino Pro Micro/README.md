# BadUSB

This code demonstrates the seamless communication between an ESP32 device and an Arduino Pro Micro using UART. The Arduino Pro Micro is particularly advantageous in this setup as it can emulate HID devices such as keyboards and mice, enabling keystroke injection similar to the functionality offered by the Rubberduck

![ESP and Arduino Pro Micro](https://raw.githubusercontent.com/proxytype/ZeroBro/main/Sections/UART%20-%20Arduino%20Pro%20Micro/badusb.jpg)

## ESP
This code demonstrate how to set up UART communication between the ESP32 and an Arduino Pro Micro. The purpose of this code is to send data from the ESP32 to the Arduino Pro Micro over a UART (serial) connection.

Here's a breakdown of what the code does:

1. Include necessary libraries and header files:
   - `<stdio.h>`: Standard C library for input and output operations.
   - `"sdkconfig.h"`: Configuration header file for ESP32 SDK.
   - `"freertos/FreeRTOS.h"`: Header file for the FreeRTOS real-time operating system.
   - `"freertos/task.h"`: Header file for FreeRTOS task management.
   - `"esp_system.h"`: ESP32 system-specific functions.
   - `"esp_spi_flash.h"`: ESP32 SPI flash functions.
   - `"driver/uart.h"`: ESP32 UART (serial communication) driver.
   - `"driver/gpio.h"`: ESP32 GPIO (general-purpose input/output) driver.
   - `<string.h>`: Standard C library for string manipulation.

2. Define some constants and macros:
   - `RX_BUF_SIZE`: Size of the receive buffer for UART communication (1024 bytes).
   - `TXD_PIN` and `RXD_PIN`: Define the GPIO pins used for UART communication (TXD_PIN = GPIO 1, RXD_PIN = GPIO 0).
   - `UART`: Specifies which UART interface to use (UART_NUM_0).

3. Declare a global integer variable `num` and initialize it to 0.

4. Implement the `app_main` function, which is the entry point of the program:
   - Print a message indicating that UART communication between ESP32 and Arduino Pro Micro is starting.

5. Configure the UART communication settings:
   - Define a `uart_config_t` structure with the desired UART configuration, including baud rate, data bits, parity, stop bits, and flow control. In this case, it's configured for 9600 baud, 8 data bits, no parity, 1 stop bit, and no flow control.
   - Install and configure the UART driver with the specified settings.
   - Set the UART pins (TXD and RXD) using `uart_set_pin`.

6. Allocate memory for a character array `Txdata` using `malloc`. This array will be used to store the data to be transmitted over UART.

7. Enter an infinite loop (`while (1)`) where data is continuously sent over UART:
   - Use `sprintf` to format the data to be sent. The data includes a string that indicates the number of packets being sent, which increments with each transmission.
   - Transmit the data using `uart_write_bytes`.
   - Delay the task for 500 milliseconds using `vTaskDelay`.

This code effectively configures UART communication between the ESP32 and Arduino Pro Micro and continuously sends data packets over the UART connection. The data sent includes an incrementing packet number for demonstration purposes.

## Arduino
This code is an Arduino sketch that allows you to emulate a keyboard using an Arduino Pro Micro board. It listens for specific commands received over a serial connection (Serial1) and translates them into keyboard keypresses and releases. Here's an explanation of the code:

1. **Library Inclusion**: The code includes the "Keyboard.h" library, which is essential for emulating keyboard behavior.

2. **Command Definitions**: A set of strings is defined, each representing a special key or command that can be recognized when received over the serial connection. These commands include `[SHIFT]`, `[CTRL]`, `[ENTER]`, `[DEL]`, `[TAB]`, and `[ALT]`.

3. **Modifier Key State Variables**: Three boolean variables (`isShift`, `isCtrl`, `isAlt`) are declared to keep track of the state of modifier keys (Shift, Ctrl, Alt).

4. **Setup Function**: In the `setup` function:
   - Serial communication is initiated with two interfaces: `Serial1` for receiving commands from an external device and `Serial` for debugging and communication with the computer.
   - The emulated keyboard is initialized using `Keyboard.begin()`.

5. **Loop Function**: In the `loop` function:
   - A `while` loop continuously checks for incoming data on the `Serial1` interface.
   - When data is available, it is read as a string (`a`).
   - The received command is printed to the serial monitor for debugging purposes.

6. **Command Processing**: The code processes the received command as follows:
   - If the command is `[SHIFT]`, it toggles the state of the Shift key using `isShift` and simulates a press of the right Shift key using `Keyboard.press(KEY_RIGHT_SHIFT)`.
   - If the command is `[CTRL]`, it toggles the state of the Ctrl key using `isCtrl` and simulates a press of the left Ctrl key using `Keyboard.press(KEY_LEFT_CTRL)`.
   - If the command is `[ENTER]`, it toggles the state of the Alt key using `isAlt` and simulates a press of the Enter key on the keypad using `Keyboard.press(KEY_KP_ENTER)`.
   - If the command is `[ALT]`, it simulates a press of the left Alt key using `Keyboard.press(KEY_LEFT_ALT)`.
   - If the command is `[DEL]`, it simulates a press of the Delete key using `Keyboard.press(KEY_DELETE)`.
   - If the command is `[TAB]`, it simulates a press of the Tab key using `Keyboard.press(KEY_TAB)`.

7. **Character Typing**: If the received command is none of the recognized special commands, the code checks whether the Shift key is active (`isShift`). If it is, the character is converted to uppercase using `a.toUpperCase()`. Then, the code emulates typing the character using `Keyboard.print(a)`.

This code essentially allows you to control a virtual keyboard through a serial interface by sending specific commands representing keyboard keys, making it useful for tasks such as automating keystrokes or remotely controlling a computer using an Arduino board.
