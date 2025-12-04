#include "SensorClima.h"
#include <Arduino.h>

ClimateSensor::ClimateSensor(int pin) : pin(pin) {}

void ClimateSensor::begin() {
  dht.setup(pin, DHTesp::DHT22);
}

bool ClimateSensor::read(TelemetryData& out) {
  last = dht.getTempAndHumidity();
  if (dht.getStatus() != DHTesp::ERROR_NONE) {
    Serial.println("DHT read error");
    return false;
  }
  out.airTemperatureC = last.temperature;
  out.airHumidityPct = last.humidity;
  return true;
}
