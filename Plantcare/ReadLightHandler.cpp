#include "ReadLightHandler.h"
#include "ReadLightCommand.h"
#include "LightEvent.h"

ReadLightHandler::ReadLightHandler(EventBus* eventBus, LightSensor* sensor)
  : eventBus(eventBus), sensor(sensor) {}

void ReadLightHandler::handleCommand(const Command& cmd) {
  if (cmd.type() != CommandType::READ_LIGHT) return;
  
  if (sensor) {
    TelemetryData temp;
    sensor->read(temp);
    
    LightEvent event(temp.lightIntensityRaw);
    if (eventBus) eventBus->emit(event);
    
    Serial.println("LightEvent emitted");
  }
}
