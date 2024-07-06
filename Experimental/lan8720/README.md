# ESP32 LAN8720 Ethernet
This sketch demonstrates how to use the LAN8720 Ethernet PHY with an ESP32 using minimal and standard configuration.

![img](https://raw.githubusercontent.com/proxytype/ZeroBro/main/Experimental/lan8720/wiring.PNG)
<br />
<br />
![img](https://raw.githubusercontent.com/proxytype/ZeroBro/main/Experimental/lan8720/lan8720.jpg)

## Overview

The example allows setting parameters for the Ethernet PHY either within the `begin` function or using `#define` statements before including the `ETH.h` file. The preferred method is using `#define` statements. This sketch was created by Renzo Mischianti.

## Configuration

Several `#define` statements are used to configure the Ethernet PHY parameters such as the I²C address of the Ethernet PHY, the type of Ethernet PHY, the pin for the external crystal oscillator's enable signal, the I²C clock signal pin, the I²C IO signal pin, and the external clock mode from the crystal oscillator. These parameters can be omitted if the default values are suitable.

## Including the Ethernet Library

The Ethernet library `ETH.h` is included to manage the Ethernet functionalities of the ESP32.

## Global Variables

A boolean variable is declared to keep track of the Ethernet connection status, indicating whether the ESP32 is connected to the Ethernet network.

## Event Handler

An event handler function `WiFiEvent` manages various Ethernet events. It handles events such as when the Ethernet starts, connects, gets an IP address, disconnects, or stops. Depending on the event, it performs actions like printing messages to the Serial Monitor, setting the hostname, and updating the connection status.

## Test Client Function

The `testClient` function tests the Ethernet connection by attempting to connect to a specified host and port, sending an HTTP GET request, and printing the response to the Serial Monitor. This function is useful for verifying that the Ethernet connection is functioning correctly.

## Setup Function

The `setup` function initializes serial communication at a specified baud rate, attaches the event handler function to handle Ethernet events, and starts the Ethernet connection.

## Loop Function

The `loop` function continuously checks if the Ethernet is connected. If connected, it calls the `testClient` function to connect to a specified host and port at regular intervals (every 10 seconds). This ensures that the Ethernet connection is tested periodically.

## Monitor Output
![img](https://raw.githubusercontent.com/proxytype/ZeroBro/main/Experimental/lan8720/outout.PNG)

Arduino code based on this reference:<br />
https://mischianti.org/integrating-lan8720-with-esp32-for-ethernet-connectivity-with-plain-http-and-ssl-https/
