#pragma once
#include "Command.h"

struct ReadLightCommand : public Command {
  ReadLightCommand() = default;
  CommandType type() const override { return CommandType::READ_LIGHT; }
};
