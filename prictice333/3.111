#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <Wire.h>
#include <TroykaMeteoSensor.h>
#include <Barometer.h>
#include <LEAmDNS.h>

#ifndef STASSID
#define STASSID "your-ssid"
#define STAPSK "your-password"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

WebServer server(80);

const int led = LED_BUILTIN;

TroykaMeteoSensor meteoSensor;
Barometer barometer;

void handleRoot() {
  digitalWrite(led, 1);

  // Read data from sensors
  int stateSensor = meteoSensor.read();
  float temperatureSHT = meteoSensor.getTemperatureC();
  float humiditySHT = meteoSensor.getHumidity();
  float pressureLPS = barometer.readPressureMillimetersHg();
  float altitudeLPS = barometer.readAltitude();
  float temperatureLPS = barometer.readTemperatureC();

  // Prepare the response HTML
  String html = "<html><body>";
  html += "<h1>Sensor Readings</h1>";
  html += "<p>Temperature (SHT31): " + String(temperatureSHT) + "°C</p>";
  html += "<p>Humidity (SHT31): " + String(humiditySHT) + "%</p>";
  html += "<p>Pressure (LPS25HB): " + String(pressureLPS) + " mmHg</p>";
  html += "<p>Altitude (LPS25HB): " + String(altitudeLPS) + " meters</p>";
  html += "<p>Temperature (LPS25HB): " + String(temperatureLPS) + "°C</p>";
  html += "</body></html>";

  // Send the HTML response
  server.send(200, "text/html", html);

  digitalWrite(led, 0);
}

void setup(void) {
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("picow")) {
    Serial.println("MDNS responder started");
  }

  // Setup the root handler
  server.on("/", handleRoot);

  // Setup additional handlers if needed

  server.begin();
}

void loop(void) {
  server.handleClient();
  delay(5000);
}
