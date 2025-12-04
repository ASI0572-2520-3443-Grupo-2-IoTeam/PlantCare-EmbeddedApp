#include "SensorLight.h"
#include <Arduino.h>

LightSensor::LightSensor(int pin) : pin(pin) {}

void LightSensor::begin() {
  pinMode(pin, INPUT);
}

bool LightSensor::read(TelemetryData& out) {
  int raw = analogRead(pin);
  out.lightIntensityRaw = raw;
  return true;
}
