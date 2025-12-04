#pragma once
#include "CommandBus.h"
#include "EventBus.h"
#include "SensorSoil.h"

class ReadSoilHandler : public CommandHandler {
public:
  ReadSoilHandler(EventBus* eventBus, SoilSensor* sensor);
  void handleCommand(const Command& cmd) override;

private:
  EventBus* eventBus;
  SoilSensor* sensor;
};
