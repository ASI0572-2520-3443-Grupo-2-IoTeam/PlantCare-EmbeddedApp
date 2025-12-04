#pragma once
#include "Command.h"

class CommandHandler {
public:
  virtual ~CommandHandler() = default;
  virtual void handleCommand(const Command& cmd) = 0;
};

class CommandBus {
public:
  CommandBus();
  void registerHandler(CommandHandler* h);
  void dispatch(const Command& cmd);

private:
  static const int MAX_HANDLERS = 8;
  CommandHandler* handlers[MAX_HANDLERS];
  int handlersCount;
};
