#pragma once
#include <Arduino.h>

struct TelemetryData {
  String deviceId;
  String timestamp; // ISO8601
  float airTemperatureC = 0.0f;
  float airHumidityPct = 0.0f;
  int lightIntensityRaw = 0;
  float soilMoisturePct = 0.0f;
};
