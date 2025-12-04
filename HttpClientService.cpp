#include "HttpClientService.h"
#include <HTTPClient.h>
#include <WiFi.h>

HttpClientService::HttpClientService(const char* serverUrl) : serverUrl(serverUrl) {}

int HttpClientService::post(const String& jsonPayload) {
  if (WiFi.status() != WL_CONNECTED) return -1;
  HTTPClient http;
  http.begin(serverUrl);
  http.addHeader("Content-Type", "application/json");
  int code = http.POST(jsonPayload);
  String resp = http.getString();
  Serial.print("HTTP POST code: "); Serial.println(code);
  Serial.print("Server response: "); Serial.println(resp);
  http.end();
  return code;
}
