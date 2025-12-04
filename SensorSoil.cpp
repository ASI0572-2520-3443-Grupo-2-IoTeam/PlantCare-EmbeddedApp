#include "SensorSoil.h"
#include <Arduino.h>

SoilSensor::SoilSensor(int pin) : pin(pin) {}

void SoilSensor::begin() {
  pinMode(pin, INPUT);
}

bool SoilSensor::read(TelemetryData& out) {
  int raw = analogRead(pin);
  
  float pct = map(raw, 0, 4095, 0, 100);
  out.soilMoisturePct = 100.0f - pct;
  return true;
}
