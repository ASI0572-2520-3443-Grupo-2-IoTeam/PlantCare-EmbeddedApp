#pragma once
#include "Command.h"

struct ReadSoilCommand : public Command {
  ReadSoilCommand() = default;
  CommandType type() const override { return CommandType::READ_SOIL; }
};
