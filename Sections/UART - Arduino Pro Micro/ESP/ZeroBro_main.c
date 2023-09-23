#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include <string.h>

static const int RX_BUF_SIZE = 1024;

#define TXD_PIN (1)
#define RXD_PIN (0)

#define UART UART_NUM_0

int num = 0;

void app_main(void)
{
    printf("UART Esp32 communicate with Arduino Pro Micro!\n");

      const uart_config_t uart_config = {
        .baud_rate = 9600,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_APB,
    };

    uart_driver_install(UART, RX_BUF_SIZE * 2, 0, 0, NULL, 0);
    uart_param_config(UART, &uart_config);
    uart_set_pin(UART, TXD_PIN, RXD_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    
    
   char* Txdata = (char*) malloc(100);
    while (1) {
    	sprintf (Txdata, "Sending Packet = %d\r\n", num++);
        uart_write_bytes(UART, Txdata, strlen(Txdata));
        vTaskDelay(500);
    }
    
}
