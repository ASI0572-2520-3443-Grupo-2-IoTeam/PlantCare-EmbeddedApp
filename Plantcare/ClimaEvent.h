#pragma once
#include "Event.h"

struct ClimaEventData {
  float temperatureC = 0.0f;
  float humidityPct = 0.0f;
};

struct ClimaEvent : public Event {
  ClimaEventData data;
  ClimaEvent() = default;
  ClimaEvent(float temp, float hum) {
    data.temperatureC = temp;
    data.humidityPct = hum;
  }
  EventType type() const override { return EventType::CLIMA_COLLECTED; }
};
