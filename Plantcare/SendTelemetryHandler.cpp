#include "SendTelemetryHandler.h"
#include "SendTelemetryCommand.h"
#include "JsonSerializer.h"

SendTelemetryHandler::SendTelemetryHandler(HttpClientService* http, TimeService* timeSvc, DeviceIdProvider* idProv)
  : httpService(http), timeService(timeSvc), idProvider(idProv) {}

void SendTelemetryHandler::handleCommand(const Command& cmd) {
  if (cmd.type() != CommandType::SEND_TELEMETRY) return;
  const SendTelemetryCommand& st = static_cast<const SendTelemetryCommand&>(cmd);

  
  String ts = timeService->getIsoTimestamp();
  String dev = idProvider->getDeviceId();


  TelemetryData payload = st.data;
  payload.timestamp = ts;
  payload.deviceId = dev;

  String json;
  JsonSerializer::serialize(payload, json);

  Serial.println("Sending payload:");
  Serial.println(json);

  // Perform POST (blocking)
  if (httpService) {
    int code = httpService->post(json);
    Serial.printf("HTTP result: %d\n", code);
  }
}
