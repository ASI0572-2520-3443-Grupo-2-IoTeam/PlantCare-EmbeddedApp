#include "Device.h"
#include "ReadClimaCommand.h"
#include "ReadLightCommand.h"
#include "ReadSoilCommand.h"
#include <Arduino.h>

Device::Device(CommandBus* commandBus, unsigned long intervalMs)
  : commandBus(commandBus), intervalMs(intervalMs), lastMillis(0) {}

void Device::begin() {
  lastMillis = millis();
}

void Device::requestSensorReadings() {
  Serial.println("Device: Requesting sensor readings...");
  
  // Dispatch read commands for each sensor
  ReadClimaCommand climaCmd;
  if (commandBus) commandBus->dispatch(climaCmd);
  
  ReadLightCommand lightCmd;
  if (commandBus) commandBus->dispatch(lightCmd);
  
  ReadSoilCommand soilCmd;
  if (commandBus) commandBus->dispatch(soilCmd);
}

void Device::loop() {
  unsigned long now = millis();
  if (now - lastMillis >= intervalMs) {
    lastMillis = now;
    requestSensorReadings();
  }
}
