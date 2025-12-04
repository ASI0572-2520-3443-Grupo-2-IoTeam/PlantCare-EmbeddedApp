#pragma once
#include <Arduino.h>

enum class EventType {
  CLIMA_COLLECTED,
  LIGHT_COLLECTED,
  SOIL_COLLECTED,
};

struct Event {
  virtual ~Event() = default;
  virtual EventType type() const = 0;
};
