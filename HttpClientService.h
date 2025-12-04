#pragma once
#include <Arduino.h>

class HttpClientService {
public:
  HttpClientService(const char* serverUrl);
  int post(const String& jsonPayload);
private:
  const char* serverUrl;
};
