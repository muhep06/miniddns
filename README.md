# MiniDDNS

An Easy to Use ESP8266 NameCheap DDNS Update Client Library.

## Getting Started

*This Dynamic DDNS Update Client only for NameCheap Domains*

This library is created to update your NameCheap DDNS Domains with your ESP8266.

**Only for ESP8266**

### What we need?

```
- Platformio core
- Editor (Visul Studio Code, SublimeText, Clion etc.)
- CH340 driver (If your Esp8266 use CH340)
- ESP8266
```

### Installing

###### Step First

- Install Platformio Core
```
// Windows
pip install -U platformio

// Linux
sudo pip install -U platformio
```
- Install driver (If your Esp8266 using CH340)
```
https://maker.robotistan.com/download/ch341ser.zip // Windows

http://blog.sengotta.net/wp-content/uploads/2015/11/CH341SER_MAC-1.4.zip // Mac
```
- Clone repository
```
git clone https://github.com/muhep06/miniddns.git
```

###### Step Two
- Go to src/
- Open main.cpp in your favorite editor.

###### Step Three
- Edit WiFi credentials to yours

```
const char* ssid = "MyAwesomeSSID";
const char* password = "MyTopSecretPassword";
```

- Edit NameCheap DDNS creadentials and settings to yours

```
MiniDDNS.client("host", "domain", "secret");

// Example
MiniDDNS.client("myhost", "mydomain.com", "123456789");  // Access url: http://myhost.mydomain.com
```

- Set interval to Check for New Public IP.

```
 MiniDDNS.update(10000); // Check for New Ip Every 10 Seconds.
```

## Run

- Connect ESP8266 to your computer
- Open cmd or console in project root

```
pio run --target upload
```

That's it. Check your domain.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
