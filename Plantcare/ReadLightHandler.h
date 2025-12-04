#pragma once
#include "CommandBus.h"
#include "EventBus.h"
#include "SensorLight.h"

class ReadLightHandler : public CommandHandler {
public:
  ReadLightHandler(EventBus* eventBus, LightSensor* sensor);
  void handleCommand(const Command& cmd) override;

private:
  EventBus* eventBus;
  LightSensor* sensor;
};
