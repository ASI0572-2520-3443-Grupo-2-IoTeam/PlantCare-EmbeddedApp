#pragma once
#include <ArduinoJson.h>
#include "TelemetryData.h"

class JsonSerializer {
public:
  
  static void serialize(const TelemetryData& t, String& out);
};
