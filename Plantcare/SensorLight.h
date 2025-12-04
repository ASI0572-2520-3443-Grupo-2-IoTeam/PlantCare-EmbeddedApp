#pragma once
#include "ISensor.h"

class LightSensor : public ISensor {
public:
  LightSensor(int pin);
  void begin() override;
  bool read(TelemetryData& out) override;
private:
  int pin;
};
