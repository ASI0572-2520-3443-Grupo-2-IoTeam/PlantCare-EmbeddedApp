#pragma once
#include "EventBus.h"
#include "CommandBus.h"

class Device {
public:
  Device(CommandBus* commandBus, unsigned long intervalMs);
  void begin();
  void loop();

private:
  CommandBus* commandBus;
  unsigned long intervalMs;
  unsigned long lastMillis;
  void requestSensorReadings();
};
