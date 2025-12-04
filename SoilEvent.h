#pragma once
#include "Event.h"

struct SoilEventData {
  float moisturePct = 0.0f;
};

struct SoilEvent : public Event {
  SoilEventData data;
  SoilEvent() = default;
  SoilEvent(float moisture) {
    data.moisturePct = moisture;
  }
  EventType type() const override { return EventType::SOIL_COLLECTED; }
};
