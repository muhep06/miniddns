#ifndef MiniDDNS_H
#define MiniDDNS_H

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

class MiniDDNSClass {
    public:
        void client(String host, String domain, String password);
        void update(unsigned long update_interval);
    
    private:
        unsigned long interval;
        unsigned long previousInterval;

        String host;
        String domain;
        String password;

        String newIPAddress;
        String oldIPAddress;

        String getIPAddress();
};

extern MiniDDNSClass MiniDDNS;

#endif