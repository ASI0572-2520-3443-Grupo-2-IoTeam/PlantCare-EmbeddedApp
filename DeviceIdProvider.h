#pragma once
#include <Arduino.h>

class DeviceIdProvider {
public:
  DeviceIdProvider();
  void begin();
  String getDeviceId();
private:
  String deviceId;
};
