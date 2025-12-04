#include "Device.h"
#include "EventBus.h"
#include "CommandBus.h"
#include "TelemetryAggregator.h"
#include "SendTelemetryHandler.h"
#include "ReadClimaHandler.h"
#include "ReadLightHandler.h"
#include "ReadSoilHandler.h"
#include "WiFiService.h"
#include "HttpClientService.h"
#include "TimeService.h"
#include "DeviceIdProvider.h"
#include "SensorClima.h"
#include "SensorLight.h"
#include "SensorSoil.h"


const char* SERVER_URL = "https://plantcare-edge-service.onrender.com/plants";
const char* WIFI_SSID = "Wokwi-GUEST";
const char* WIFI_PASSWORD = "";

unsigned long READ_INTERVAL_MS = 10000; // 10s


static EventBus gEventBus;
static CommandBus gCommandBus;
static WiFiService gWiFiService(WIFI_SSID, WIFI_PASSWORD);
static HttpClientService gHttpService(SERVER_URL);
static TimeService gTimeService;
static DeviceIdProvider gDeviceIdProvider;

// Sensors
static ClimateSensor gClimateSensor(15);
static LightSensor gLightSensor(34);
static SoilSensor gSoilSensor(32);

// Handlers for reading each sensor (Command -> Event)
static ReadClimaHandler gReadClimaHandler(&gEventBus, &gClimateSensor);
static ReadLightHandler gReadLightHandler(&gEventBus, &gLightSensor);
static ReadSoilHandler gReadSoilHandler(&gEventBus, &gSoilSensor);

// Aggregator: collects sensor events and dispatches SendTelemetryCommand
static TelemetryAggregator gTelemetryAggregator(&gCommandBus);

// Handler for sending telemetry
static SendTelemetryHandler gSendTelemetryHandler(&gHttpService, &gTimeService, &gDeviceIdProvider);

// Device dispatches read commands periodically
static Device gDevice(&gCommandBus, READ_INTERVAL_MS);

void setup() {
  Serial.begin(115200);
  delay(100);

  // Initialize services
  gWiFiService.begin();
  gTimeService.begin();
  gDeviceIdProvider.begin();

  // Register command handlers
  gCommandBus.registerHandler(&gReadClimaHandler);
  gCommandBus.registerHandler(&gReadLightHandler);
  gCommandBus.registerHandler(&gReadSoilHandler);
  gCommandBus.registerHandler(&gSendTelemetryHandler);

  // Register event handlers
  gEventBus.registerHandler(&gTelemetryAggregator);

  // Initialize sensors 
  gClimateSensor.begin();
  gLightSensor.begin();
  gSoilSensor.begin();

  gDevice.begin();

  Serial.println("Setup complete.");
}

void loop() {

  gDevice.loop();

  delay(10);
}
