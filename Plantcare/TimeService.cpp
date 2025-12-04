#include "TimeService.h"
#include <time.h>

TimeService::TimeService() : synced(false) {}

void TimeService::begin() {
  configTime(0, 0, "pool.ntp.org", "time.nist.gov");
  syncTime();
}

void TimeService::syncTime() {
  
  time_t now = time(nullptr);
  int tries = 0;
  while (now < 24*3600 && tries < 5) {
    delay(500);
    now = time(nullptr);
    tries++;
  }
  synced = (now >= 24*3600);
  if (synced) {
    Serial.println("Time synced");
  } else {
    Serial.println("Time not yet synced");
  }
}

String TimeService::getIsoTimestamp() {
  time_t now = time(nullptr);
  struct tm* tminfo = gmtime(&now);
  char buf[25] = {0};
  if (tminfo) {
    strftime(buf, sizeof(buf), "%Y-%m-%dT%H:%M:%SZ", tminfo);
    return String(buf);
  }
  return String("");
}
