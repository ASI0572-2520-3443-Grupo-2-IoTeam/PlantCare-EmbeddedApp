#pragma once
#include "CommandBus.h"
#include "SendTelemetryCommand.h"
#include "HttpClientService.h"
#include "TimeService.h"
#include "DeviceIdProvider.h"

class SendTelemetryHandler : public CommandHandler {
public:
  SendTelemetryHandler(HttpClientService* http, TimeService* timeSvc, DeviceIdProvider* idProv);
  void handleCommand(const Command& cmd) override;

private:
  HttpClientService* httpService;
  TimeService* timeService;
  DeviceIdProvider* idProvider;
};
