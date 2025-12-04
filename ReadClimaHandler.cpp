#include "ReadClimaHandler.h"
#include "ReadClimaCommand.h"
#include "ClimaEvent.h"

ReadClimaHandler::ReadClimaHandler(EventBus* eventBus, ClimateSensor* sensor)
  : eventBus(eventBus), sensor(sensor) {}

void ReadClimaHandler::handleCommand(const Command& cmd) {
  if (cmd.type() != CommandType::READ_CLIMA) return;
  
  if (sensor) {
    TelemetryData temp;
    sensor->read(temp);
    
    ClimaEvent event(temp.airTemperatureC, temp.airHumidityPct);
    if (eventBus) eventBus->emit(event);
    
    Serial.println("ClimaEvent emitted");
  }
}
