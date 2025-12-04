#pragma once
#include "Event.h"

struct LightEventData {
  int intensityRaw = 0;
};

struct LightEvent : public Event {
  LightEventData data;
  LightEvent() = default;
  LightEvent(int intensity) {
    data.intensityRaw = intensity;
  }
  EventType type() const override { return EventType::LIGHT_COLLECTED; }
};
