#include <MiniDDNS.h>

void MiniDDNSClass::client(String host, String domain, String password) {
    MiniDDNS.host = host;
    MiniDDNS.domain = domain;
    MiniDDNS.password = password;
}

String MiniDDNSClass::getIPAddress() {
    HTTPClient http;
    http.begin("http://api.ipify.org");
    int httpCode = http.GET();
    if(httpCode > 0) {
        if(httpCode == HTTP_CODE_OK) {
            return http.getString();
        } else {
            return "";
        }
    }else{
        http.end();
        return "";
    }
    http.end();
}

void MiniDDNSClass::update(unsigned long update_interval) {
    interval = update_interval;

    unsigned long currentMillis = millis();

    if (currentMillis - previousInterval >= update_interval) {
        previousInterval = currentMillis;

        newIPAddress = getIPAddress();
        
        String requestUrl = "http://dynamicdns.park-your-domain.com/update?host=" + MiniDDNS.host + "&domain=" + MiniDDNS.domain + "&password=" + MiniDDNS.password + "&ip=" + newIPAddress;

        if (oldIPAddress != newIPAddress) {
            HTTPClient http;
            http.begin(requestUrl);
            int httpCode = http.GET();
            if(httpCode > 0) {
                oldIPAddress = newIPAddress;
            }
            http.end();
        }
    }
}