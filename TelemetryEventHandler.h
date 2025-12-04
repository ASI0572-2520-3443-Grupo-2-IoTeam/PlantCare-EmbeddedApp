#pragma once
#include "EventBus.h"
#include "TelemetryEvent.h"
#include "CommandBus.h"
#include "SendTelemetryCommand.h"

class TelemetryEventHandler : public EventHandler {
public:
  TelemetryEventHandler(CommandBus* bus);
  void handleEvent(const Event& e) override;

private:
  CommandBus* commandBus;
};
