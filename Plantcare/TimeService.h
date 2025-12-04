#pragma once
#include <Arduino.h>

class TimeService {
public:
  TimeService();
  void begin();
  String getIsoTimestamp();
private:
  bool synced;
  void syncTime();
};
