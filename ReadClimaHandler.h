#pragma once
#include "CommandBus.h"
#include "EventBus.h"
#include "SensorClima.h"

class ReadClimaHandler : public CommandHandler {
public:
  ReadClimaHandler(EventBus* eventBus, ClimateSensor* sensor);
  void handleCommand(const Command& cmd) override;

private:
  EventBus* eventBus;
  ClimateSensor* sensor;
};
