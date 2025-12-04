#pragma once
#include "ISensor.h"

class SoilSensor : public ISensor {
public:
  SoilSensor(int pin);
  void begin() override;
  bool read(TelemetryData& out) override;
private:
  int pin;
};
