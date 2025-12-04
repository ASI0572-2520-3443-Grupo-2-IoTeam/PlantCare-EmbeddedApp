#pragma once
#include "Command.h"
#include "TelemetryData.h"

struct SendTelemetryCommand : public Command {
  TelemetryData data;
  SendTelemetryCommand() = default;
  SendTelemetryCommand(const TelemetryData& d) : data(d) {}
  CommandType type() const override { return CommandType::SEND_TELEMETRY; }
};
