#include <WiFi.h>

#define CONNECTION_TIMEOUT 120 //seconds
#define DEEP_SLEEP_DURATION 10 //seconds

const char* ssid = "A73_GABRIEL";
const char* password = "ghtf36@f348";

//const char* ssid = "Wokwi-GUEST";
//const char* password = "";

IPAddress ip(192, 168, 43, 42); //The IP address you wish to assign. Ping this ip when connected to test it
IPAddress dns(192, 168, 43, 1); //Service that links a URL to an IP. By default, we use the DNS server of the router: so we indicate the same address as the router (in general, 192.168.0.1).
IPAddress gateway(192, 168, 43, 1); //This is the IP address of the router (usually 192.168.0.1)
IPAddress subnet(255, 255, 255, 0); // Subnet mask (usually 255.255.255.0)

//uint8_t new_mac[] = {0x60, 0x8B, 0x0E, 0x01, 0x5A, 0x32};

void get_network_info(){
    if(WiFi.status() == WL_CONNECTED) {
        Serial.print("[*] Network information for ");
        Serial.println(ssid);

        Serial.println("[+] BSSID : " + WiFi.BSSIDstr());
        Serial.print("[+] Gateway IP : ");
        Serial.println(WiFi.gatewayIP());
        Serial.print("[+] Subnet Mask : ");
        Serial.println(WiFi.subnetMask());
        Serial.println((String)"[+] RSSI : " + WiFi.RSSI() + " dB");
        Serial.print("[+] ESP32 IP : ");
        Serial.println(WiFi.localIP());
    }
}

String get_wifi_status(int status){
    switch(status){
        case WL_IDLE_STATUS:
        return "WL_IDLE_STATUS";
        case WL_SCAN_COMPLETED:
        return "WL_SCAN_COMPLETED";
        case WL_NO_SSID_AVAIL:
        return "WL_NO_SSID_AVAIL";
        case WL_CONNECT_FAILED:
        return "WL_CONNECT_FAILED";
        case WL_CONNECTION_LOST:
        return "WL_CONNECTION_LOST";
        case WL_CONNECTED:
        return "WL_CONNECTED";
        case WL_DISCONNECTED:
        return "WL_DISCONNECTED";
    }
}

void setup(){
    Serial.begin(115200);

    WiFi.mode(WIFI_STA); //Optional

    int status = WL_IDLE_STATUS;
    Serial.println(get_wifi_status(status));
    
    WiFi.config(ip, gateway, subnet, dns);
    WiFi.begin(ssid, password);

    int cntr = 0;
    Serial.println("\nConnecting");
    while(WiFi.status() != WL_CONNECTED){
        delay(500); //500ms
        if(WiFi.status() != status){
          status = WiFi.status();
          Serial.println(get_wifi_status(status));
        }
        
        if((cntr++)%2 == 0){
          Serial.print(".");
        }

        if(cntr*2 >= CONNECTION_TIMEOUT){
          Serial.println("\nCouldn't establish WiFi connection");
          //Setup timer
          esp_sleep_enable_timer_wakeup(DEEP_SLEEP_DURATION * 1000000);
          //Start deep sleep - 10 seconds
          esp_deep_sleep_start();
          
          //ESP.restart();
        }
    }

    Serial.println("\nConnected to the WiFi network");
    get_network_info();

    //esp_wifi_set_mac(ESP_IF_WIFI_STA, new_mac);
    Serial.print("[+] Current MAC Address:  ");
    //Serial.println(WiFi.macAddress());

}



void loop(){}