#pragma once
#include "EventBus.h"
#include "CommandBus.h"
#include "TelemetryData.h"

class TelemetryAggregator : public EventHandler {
public:
  TelemetryAggregator(CommandBus* commandBus);
  void handleEvent(const Event& e) override;
  void reset();

private:
  CommandBus* commandBus;
  TelemetryData aggregatedData;
  bool climaReceived;
  bool lightReceived;
  bool soilReceived;
  
  void checkAndSend();
};
