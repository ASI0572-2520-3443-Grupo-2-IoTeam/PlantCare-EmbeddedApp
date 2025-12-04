#pragma once
#include "TelemetryData.h"

class ISensor {
public:
  virtual ~ISensor() = default;
  
  virtual bool read(TelemetryData& out) = 0;
  virtual void begin() = 0;
};
