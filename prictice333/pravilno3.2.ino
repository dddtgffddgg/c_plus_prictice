#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <Wire.h>
#include <TroykaMeteoSensor.h>
#include <Barometer.h>
#include <LEAmDNS.h>

const char* ssid = "ASOIU";
const char* password = "kaf.asoiu.48";

WebServer server(80);

const int led = LED_BUILTIN;

TroykaMeteoSensor meteoSensor;
Barometer barometer;

void handleRoot() {
  digitalWrite(led, 1);

  int stateSensor = meteoSensor.read();
  float temperatureSHT = meteoSensor.getTemperatureC();
  float humiditySHT = meteoSensor.getHumidity();
  float pressureLPS = barometer.readPressureMillimetersHg();
  float altitudeLPS = barometer.readAltitude();
  float temperatureLPS = barometer.readTemperatureC();

  String html = "<html><body>";
  html += "<h1>Sensor Readings</h1>";
  html += "<p>Temperature (SHT31): " + String(temperatureSHT) + "°C</p>";
  html += "<p>Humidity (SHT31): " + String(humiditySHT) + "%</p>";
  html += "<p>Pressure (LPS25HB): " + String(pressureLPS) + " mmHg</p>";
  html += "<p>Altitude (LPS25HB): " + String(altitudeLPS) + " meters</p>";
  html += "<p>Temperature (LPS25HB): " + String(temperatureLPS) + "°C</p>";
  html += "</body></html>";

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

  server.on("/", handleRoot);

  server.begin();
}

void loop(void) {
  server.handleClient();
  delay(5000);
}
