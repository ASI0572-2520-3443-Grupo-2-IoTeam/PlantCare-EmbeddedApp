#pragma once
#include "Event.h"


class EventHandler {
public:
  virtual ~EventHandler() = default;
  virtual void handleEvent(const Event& e) = 0;
};

class EventBus {
public:
  EventBus();
  void registerHandler(EventHandler* h);
  void emit(const Event& e);

private:
  static const int MAX_HANDLERS = 8;
  EventHandler* handlers[MAX_HANDLERS];
  int handlersCount;
};
