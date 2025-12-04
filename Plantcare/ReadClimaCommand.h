#pragma once
#include "Command.h"

struct ReadClimaCommand : public Command {
  ReadClimaCommand() = default;
  CommandType type() const override { return CommandType::READ_CLIMA; }
};
