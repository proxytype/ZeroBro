#ifndef WIFI_SCANNER_H
#define WIFI_SCANNER_H
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "esp_event.h"
#include "regex.h"

//#define DEFAULT_SCAN_LIST_SIZE CONFIG_EXAMPLE_SCAN_LIST_SIZE
#define MAX_AP_LIST 10

char* cipherGroup(int groupCipher);
char* cipherType(int cipherType);
char* printAuthMode(int authmode);

wifi_ap_record_t* wifiScan(int* count);

void wifiScannerEvent(void *ctx, system_event_t *event);

#endif /* WIFI_SCANNER_H */