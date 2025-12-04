#include "ReadSoilHandler.h"
#include "ReadSoilCommand.h"
#include "SoilEvent.h"

ReadSoilHandler::ReadSoilHandler(EventBus* eventBus, SoilSensor* sensor)
  : eventBus(eventBus), sensor(sensor) {}

void ReadSoilHandler::handleCommand(const Command& cmd) {
  if (cmd.type() != CommandType::READ_SOIL) return;
  
  if (sensor) {
    TelemetryData temp;
    sensor->read(temp);
    
    SoilEvent event(temp.soilMoisturePct);
    if (eventBus) eventBus->emit(event);
    
    Serial.println("SoilEvent emitted");
  }
}
