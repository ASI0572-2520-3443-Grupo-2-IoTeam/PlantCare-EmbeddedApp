#include "TelemetryAggregator.h"
#include "ClimaEvent.h"
#include "LightEvent.h"
#include "SoilEvent.h"
#include "SendTelemetryCommand.h"

TelemetryAggregator::TelemetryAggregator(CommandBus* commandBus)
  : commandBus(commandBus), climaReceived(false), lightReceived(false), soilReceived(false) {}

void TelemetryAggregator::reset() {
  aggregatedData = TelemetryData();
  climaReceived = false;
  lightReceived = false;
  soilReceived = false;
}

void TelemetryAggregator::handleEvent(const Event& e) {
  switch (e.type()) {
    case EventType::CLIMA_COLLECTED: {
      const ClimaEvent& ce = static_cast<const ClimaEvent&>(e);
      aggregatedData.airTemperatureC = ce.data.temperatureC;
      aggregatedData.airHumidityPct = ce.data.humidityPct;
      climaReceived = true;
      Serial.println("Aggregator: Clima data received");
      break;
    }
    case EventType::LIGHT_COLLECTED: {
      const LightEvent& le = static_cast<const LightEvent&>(e);
      aggregatedData.lightIntensityRaw = le.data.intensityRaw;
      lightReceived = true;
      Serial.println("Aggregator: Light data received");
      break;
    }
    case EventType::SOIL_COLLECTED: {
      const SoilEvent& se = static_cast<const SoilEvent&>(e);
      aggregatedData.soilMoisturePct = se.data.moisturePct;
      soilReceived = true;
      Serial.println("Aggregator: Soil data received");
      break;
    }
    default:
      return;
  }
  
  checkAndSend();
}

void TelemetryAggregator::checkAndSend() {
  if (climaReceived && lightReceived && soilReceived) {
    Serial.println("Aggregator: All sensor data collected, sending telemetry...");
    
    SendTelemetryCommand cmd(aggregatedData);
    if (commandBus) commandBus->dispatch(cmd);
    
    // Reset for next cycle
    reset();
  }
}
