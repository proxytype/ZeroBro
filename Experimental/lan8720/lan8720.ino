/*
 This sketch shows how to use lan8720 with esp32 with minimal/standard configuration
 
 You can set the parameter in begin function or at start with define before the import
 of ETH.h file, this way is preferible.
 
 by Renzo Mischianti <mischianti.org>
 */
 
// I²C-address of Ethernet PHY (0 or 1 for LAN8720, 31 for TLK110)
#define ETH_PHY_ADDR 1                      // DEFAULT VALUE IS 0 YOU CAN OMIT IT
// Type of the Ethernet PHY (LAN8720 or TLK110)
#define ETH_PHY_TYPE ETH_PHY_LAN8720        // DEFAULT VALUE YOU CAN OMIT IT
// Pin# of the enable signal for the external crystal oscillator (-1 to disable for internal APLL source)
#define ETH_PHY_POWER -1                    // DEFAULT VALUE YOU CAN OMIT IT
// Pin# of the I²C clock signal for the Ethernet PHY
#define ETH_PHY_MDC 23                      // DEFAULT VALUE YOU CAN OMIT IT
// Pin# of the I²C IO signal for the Ethernet PHY
#define ETH_PHY_MDIO 18                     // DEFAULT VALUE YOU CAN OMIT IT
// External clock from crystal oscillator
#define ETH_CLK_MODE ETH_CLOCK_GPIO0_IN     // DEFAULT VALUE YOU CAN OMIT IT
 
#include <ETH.h>
 
static bool eth_connected = false;
 
void WiFiEvent(WiFiEvent_t event) {
    switch (event) {
    case ARDUINO_EVENT_ETH_START:
        Serial.println("ETH Started");
        ETH.setHostname("esp32-mischianti-eth");
        break;
    case ARDUINO_EVENT_ETH_CONNECTED:
        Serial.println("ETH Connected");
        break;
    case ARDUINO_EVENT_ETH_GOT_IP:
        Serial.print("ETH MAC: ");
        Serial.print(ETH.macAddress());
        Serial.print(", IPv4: ");
        Serial.print(ETH.localIP());
        if (ETH.fullDuplex()) {
            Serial.print(", FULL_DUPLEX");
        }
        Serial.print(", ");
        Serial.print(ETH.linkSpeed());
        Serial.println("Mbps");
        eth_connected = true;
        break;
    case ARDUINO_EVENT_ETH_DISCONNECTED:
        Serial.println("ETH Disconnected");
        eth_connected = false;
        break;
    case ARDUINO_EVENT_ETH_STOP:
        Serial.println("ETH Stopped");
        eth_connected = false;
        break;
    default:
        break;
    }
}
 
void testClient(const char *host, uint16_t port) {
    Serial.print("\nconnecting to ");
    Serial.println(host);
 
    WiFiClient client;
    if (!client.connect(host, port)) {
        Serial.println("connection failed");
        return;
    }
    client.printf("GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host);
    while (client.connected() && !client.available())
        ;
    while (client.available()) {
        Serial.write(client.read());
    }
 
    Serial.println("closing connection\n");
    client.stop();
}
 
void setup() {
    Serial.begin(115200);
    WiFi.onEvent(WiFiEvent);
    ETH.begin();
}
 
void loop() {
    if (eth_connected) {
        testClient("google.com", 80);
    }
    delay(10000);
 
}