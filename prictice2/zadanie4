#include <TroykaMeteoSensor.h>
#include <Barometer.h>

TroykaMeteoSensor meteoSensor;
Barometer barometer;

void setup() {
  Serial.begin(9600);
  meteoSensor.begin();
  barometer.begin();
}

void loop() {
  if (Serial.available()) {
    Serial.println("Serial init OK");
    Serial.println("Meteo Sensor and barometer init OK");
  }

  int stateSensor = meteoSensor.read();

  Serial.print("Barometer's pressure: ");
  Serial.print(barometer.readPressureMillimetersHg());
  Serial.println(" mmHg");

  Serial.print("Barometer's altitude: ");
  Serial.print(barometer.readAltitude());
  Serial.println(" meters");

  Serial.print("Barometer's temperature: ");
  Serial.print(barometer.readTemperatureC());
  Serial.println("°C");

  switch (stateSensor) {
    case SHT_OK:
      Serial.println("Data sensor is OK");
      Serial.print("Temperature = ");
      Serial.print(meteoSensor.getTemperatureC());
      Serial.println("°C");

      Serial.print("Humidity = ");
      Serial.print(meteoSensor.getHumidity());
      Serial.println("%");
      break;

    case SHT_ERROR_DATA:
      Serial.println("Data error or sensor not connected");
      break;

    case SHT_ERROR_CHECKSUM:
      Serial.println("Checksum error");
      break;
  }
  delay(5000);
}
