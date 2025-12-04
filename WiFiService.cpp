#include "WiFiService.h"
#include <Arduino.h>

WiFiService::WiFiService(const char* ssid, const char* password) : ssid(ssid), password(password) {}

void WiFiService::begin() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (millis() - start > 10000) break; 
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi connected");
    Serial.print("IP: "); Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nWiFi not connected (timeout)");
  }
}

bool WiFiService::isConnected() {
  return WiFi.status() == WL_CONNECTED;
}
