#pragma once
#include <Arduino.h>

enum class CommandType {
  SEND_TELEMETRY,
  READ_CLIMA,
  READ_LIGHT,
  READ_SOIL,
};

struct Command {
  virtual ~Command() = default;
  virtual CommandType type() const = 0;
};
