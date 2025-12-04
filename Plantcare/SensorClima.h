#pragma once
#include "ISensor.h"
#include <DHTesp.h>

class ClimateSensor : public ISensor {
public:
  ClimateSensor(int pin);
  void begin() override;
  bool read(TelemetryData& out) override;

private:
  int pin;
  DHTesp dht;
  TempAndHumidity last;
};
