#pragma once
#include <WiFi.h>

class WiFiService {
public:
  WiFiService(const char* ssid, const char* password);
  void begin();
  bool isConnected();
private:
  const char* ssid;
  const char* password;
};
