#include <MiniDDNS.h>
#include <ESP8266WiFi.h>

const char* ssid = "MyAwesomeSSID";
const char* password = "MyTopSecretPassword";

MiniDDNSClass MiniDDNS;

void setup() {
    Serial.begin(115200);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    
    Serial.println();
    Serial.println(WiFi.localIP()); // Print the IP address

    MiniDDNS.client("host", "domain", "secret"); // Enter namecheap ddns host, domain and password | Example - "myhost", "mydomain.com", "123456789"
}

void loop() {
    MiniDDNS.update(10000); // Check for New Ip Every 10 Seconds.
}