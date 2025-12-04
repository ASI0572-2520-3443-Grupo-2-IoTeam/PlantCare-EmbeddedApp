#include "JsonSerializer.h"

void JsonSerializer::serialize(const TelemetryData& t, String& out) {
  StaticJsonDocument<400> doc;
  doc["deviceId"] = t.deviceId;
  doc["timestamp"] = t.timestamp;
  doc["airTemperatureC"] = t.airTemperatureC;
  doc["airHumidityPct"] = t.airHumidityPct;
  doc["lightIntensityLux"] = t.lightIntensityRaw;
  doc["soilMoisturePct"] = t.soilMoisturePct;
  serializeJson(doc, out);
}
