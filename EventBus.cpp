#include "EventBus.h"

EventBus::EventBus() : handlersCount(0) {
  for (int i = 0; i < MAX_HANDLERS; ++i) handlers[i] = nullptr;
}

void EventBus::registerHandler(EventHandler* h) {
  if (handlersCount < MAX_HANDLERS && h != nullptr) {
    handlers[handlersCount++] = h;
  }
}

void EventBus::emit(const Event& e) {
  for (int i = 0; i < handlersCount; ++i) {
    if (handlers[i]) handlers[i]->handleEvent(e);
  }
}
