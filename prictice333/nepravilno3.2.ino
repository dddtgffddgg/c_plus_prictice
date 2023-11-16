#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_SHT31.h>
#include <Adafruit_LPS2X.h>

char ssid[] = "ASOIU";  
char pass[] = "kf.asoiu.48";
int status = WL_IDLE_STATUS; // для статуса подключения

//WiFiServer server(80);

Adafruit_SHT31 sht31 = Adafruit_SHT31();
Adafruit_LPS25HB lps25hb = Adafruit_LPS25HB();

void setup() {
  Serial.begin(115200);	//"92.246.214.18"

  status = WiFi.begin(ssid, pass);
  if (status != WL_CONNECTED) {
    Serial.println("Подключение к: ");
  }
  
  if (!sht31.begin(0x44)) {
    Serial.println("Не удалось инициализировать SHT31");
  }
  
  if (!lps25hb.begin_I2C(0x44)) {
    Serial.println("Не удалось инициализировать LPS25HB");
  }

  Serial.print("Подключение к: ");
  server.begin();
  
}

void loop() {
 WiFiClient client = server.available();
 
 if (client) {
   Serial.println("Новый клиент подключен");
   
   float temperature = sht31.readTemperature();
   float humidity = sht31.readHumidity();
   float pressure = lps25hb.readPressure()/100.0F;
   
   float humidity_mmHg = humidity * 0.750062; 
   
   client.println("HTTP/1.1 200 OK");
   client.println("Content-Type: text/html");
   client.println();
   client.println("<html><body>");
   client.println("<h1>Показания с датчиков</h1>");
   client.print("Температура: ");
   client.print(temperature);
   client.println(" &deg;C<br>");
   client.print("Влажность: ");
   client.print(humidity_mmHg, 2);//округление до 2 знаков
   client.println(" mmHg<br>");
   client.print("Давление: ");
   client.print(pressure);
   client.println(" hPa<br>");
   client.println("</body></html>");

   client.stop();
   Serial.println("Клиент отключен");
 }
}
