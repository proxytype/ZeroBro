#include "wifi_scanner.h";

static const char *TAG = "scan";

char *printAuthMode(int authmode)
{
    switch (authmode)
    {
    case WIFI_AUTH_OPEN:
        return "WIFI_AUTH_OPEN";
        break;
    // case WIFI_AUTH_OWE:
    //     ESP_LOGI(TAG, "Authmode \tWIFI_AUTH_OWE");
    //     break;
    case WIFI_AUTH_WEP:
        return "WIFI_AUTH_WEP";
    case WIFI_AUTH_WPA_PSK:
        return "WIFI_AUTH_WPA_PSK";
    case WIFI_AUTH_WPA2_PSK:
        return "WIFI_AUTH_WPA2_PSK";
    case WIFI_AUTH_WPA_WPA2_PSK:
        return "WIFI_AUTH_WPA_WPA2_PSK";
    case WIFI_AUTH_ENTERPRISE:
        return "WIFI_AUTH_ENTERPRISE";
    case WIFI_AUTH_WPA3_PSK:
        return "WIFI_AUTH_WPA3_PSK";
    case WIFI_AUTH_WPA2_WPA3_PSK:
        return "WIFI_AUTH_WPA2_WPA3_PSK";
    case WIFI_AUTH_WPA3_ENT_192:
        return "WIFI_AUTH_WPA3_ENT_192";
    default:
        return "WIFI_AUTH_UNKNOWN";
    }
}

char *cipherGroup(int groupCipher)
{
    switch (groupCipher)
    {
    case WIFI_CIPHER_TYPE_NONE:
        return "WIFI_CIPHER_TYPE_NONE";
    case WIFI_CIPHER_TYPE_WEP40:
        return "WIFI_CIPHER_TYPE_WEP40";
    case WIFI_CIPHER_TYPE_WEP104:
        return "WIFI_CIPHER_TYPE_WEP104";
    case WIFI_CIPHER_TYPE_TKIP:
        return "WIFI_CIPHER_TYPE_TKIP";
    case WIFI_CIPHER_TYPE_CCMP:
        return "WIFI_CIPHER_TYPE_CCMP";
    case WIFI_CIPHER_TYPE_TKIP_CCMP:
        return "WIFI_CIPHER_TYPE_TKIP_CCMP";
    case WIFI_CIPHER_TYPE_SMS4:
        return "WIFI_CIPHER_TYPE_SMS4";
    case WIFI_CIPHER_TYPE_GCMP:
        return "WIFI_CIPHER_TYPE_GCMP";
    case WIFI_CIPHER_TYPE_GCMP256:
        return "WIFI_CIPHER_TYPE_GCMP256";
    default:
        return "WIFI_CIPHER_TYPE_UNKNOWN";
    }
}

char *cipherType(int cipherType)
{
    switch (cipherType)
    {
    case WIFI_CIPHER_TYPE_NONE:
        return "WIFI_CIPHER_TYPE_NONE";
    case WIFI_CIPHER_TYPE_WEP40:
        return "WIFI_CIPHER_TYPE_WEP40";
    case WIFI_CIPHER_TYPE_WEP104:
        return "WIFI_CIPHER_TYPE_WEP104";
    case WIFI_CIPHER_TYPE_TKIP:
        return "WIFI_CIPHER_TYPE_TKIP";
    case WIFI_CIPHER_TYPE_CCMP:
        return "WIFI_CIPHER_TYPE_CCMP";
    case WIFI_CIPHER_TYPE_TKIP_CCMP:
        return "WIFI_CIPHER_TYPE_TKIP_CCMP";
    case WIFI_CIPHER_TYPE_AES_CMAC128:
        return "WIFI_CIPHER_TYPE_AES_CMAC128";
    case WIFI_CIPHER_TYPE_SMS4:
        return "WIFI_CIPHER_TYPE_SMS4";
    case WIFI_CIPHER_TYPE_GCMP:
        return "WIFI_CIPHER_TYPE_GCMP";
    case WIFI_CIPHER_TYPE_GCMP256:
        return "WIFI_CIPHER_TYPE_GCMP256";
    default:
        return "WIFI_CIPHER_TYPE_UNKNOWN";
    }
}

/* Initialize Wi-Fi as sta and set scan method */
wifi_ap_record_t *wifiScan(int *count)
{
    // Initialize ESP-IDF components
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_t *sta_netif = esp_netif_create_default_wifi_sta();
    assert(sta_netif);

    // Initialize WiFi
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_start());

    // Start WiFi scan
    ESP_ERROR_CHECK(esp_wifi_scan_start(NULL, true));

    // Allocate memory for ap_info array dynamically
    wifi_ap_record_t *ap_info = (wifi_ap_record_t *)malloc(MAX_AP_LIST * sizeof(wifi_ap_record_t));
    if (ap_info == NULL)
    {
        ESP_LOGE(TAG, "Failed to allocate memory for ap_info");
        *count = 0;
        return NULL;
    }

    // Get scan results
    uint16_t number = MAX_AP_LIST;
    esp_err_t scan_result = esp_wifi_scan_get_ap_records(&number, ap_info);
    if (scan_result != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to get scan records: %s", esp_err_to_name(scan_result));
        free(ap_info);
        *count = 0;
        return NULL;
    }

    // Get scan count
    scan_result = esp_wifi_scan_get_ap_num(count);
    if (scan_result != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to get scan count: %s", esp_err_to_name(scan_result));
        free(ap_info);
        *count = 0;
        return NULL;
    }

    return ap_info;
}