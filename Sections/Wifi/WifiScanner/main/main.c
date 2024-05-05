#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_event.h" // Include the esp_event header
#include "nvs_flash.h"
#include "wifi_scanner.h"

static const char* TAG = "MAIN";

void app_main() {

    // Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }

    ESP_ERROR_CHECK( ret );
    int count = 0;
    
    wifi_ap_record_t* ap_info = wifiScan(&count);
    ESP_LOGI(TAG, "AP Detect: \t\t%d", count);
    
    if (ap_info != NULL) {
        // Iterate through ap_info array and print SSID of each access point
        for (int i = 0; i < count; i++) {
            ESP_LOGI(TAG, "SSID:\t\t%s", (char*)ap_info[i].ssid);
            ESP_LOGI(TAG, "RSSI:\t\t%d", ap_info[i].rssi);
            if (ap_info[i].authmode != WIFI_AUTH_WEP) {
                char *ctype = cipherType(ap_info[i].pairwise_cipher);
                ESP_LOGI(TAG, "Type: \t\t%s", ctype);
                char *cgroup = cipherGroup(ap_info[i].group_cipher);
                ESP_LOGI(TAG, "Group: \t\t%s", cgroup);
            }
            ESP_LOGI(TAG, "Channel \t\t%d", ap_info[i].primary);
        }
        // Free dynamically allocated memory for ap_info array
        free(ap_info);
    } else {
        ESP_LOGI(TAG, "Failed to scan WiFi networks");
        // Handle error
    }
}