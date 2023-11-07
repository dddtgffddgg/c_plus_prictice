#include <SPI.h>
#include <WiFi.h>
#include <ESP32Ping.h>

char ssid[] = "Имя вашей сети";  
char pass[] = "Пароль вашей сети";
int status = WL_IDLE_STATUS; // для статуса подключения

WiFiServer server(80);

void setup() {
  Serial.begin(9600);	//"92.246.214.18"

  while(!Serial) {
    ;
  }

  status = WiFi.begin(ssid, pass);
  if (status != WL_CONNECTED) {
    Serial.println("Не удалось подключиться к WiFi");

    while (true);
  }

  Serial.print("Подключение к:");
  printWiFiData();
  
  bool succes = Ping.ping("www.google.com", 3);
  
  if (!succes) {
    Serial.print("Не удалось выполнить пинг");
    return; 
  }
  
  Serial.println("Пинг выполнен")
}

void loop() {
  delay(10000);
  
  printCurrentNet();
}

void printWiFiData() {
  IPAddres ip = WiFi.localIP(); //узнаем и отправляем свой айпи
  
  Serial.print("Локальный IP адрес: ");
  Serial.println(ip);
} 
