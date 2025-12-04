#include "DeviceIdProvider.h"
#include <esp_system.h>

DeviceIdProvider::DeviceIdProvider() : deviceId("") {}

void DeviceIdProvider::begin() {
  uint64_t mac = ESP.getEfuseMac();
  char buf[13];
  sprintf(buf, "%012llX", mac);
  deviceId = String("esp32-") + String(buf);
  Serial.print("Device ID: "); Serial.println(deviceId);
}

String DeviceIdProvider::getDeviceId() {
  return deviceId;
}
