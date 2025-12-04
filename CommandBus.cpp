#include "CommandBus.h"

CommandBus::CommandBus() : handlersCount(0) {
  for (int i = 0; i < MAX_HANDLERS; ++i) handlers[i] = nullptr;
}

void CommandBus::registerHandler(CommandHandler* h) {
  if (handlersCount < MAX_HANDLERS && h != nullptr) {
    handlers[handlersCount++] = h;
  }
}

void CommandBus::dispatch(const Command& cmd) {
  for (int i = 0; i < handlersCount; ++i) {
    if (handlers[i]) handlers[i]->handleCommand(cmd);
  }
}
