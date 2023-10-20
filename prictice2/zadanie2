void setup() {
  // put your setup code here, to run once:
  pinMode(D0, OUTPUT);  // dlya upravleniya SHIM
  pinMode(D1, OUTPUT); // diya upravleniya ventilatorom
  analogWrite(25000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue = analogRead(A0);
  int angle = map(potValue, 0, 4095, 0, 255); //skvazhnost SHIM
  analogWrite(D0, angle);  // upravlenie silovim kluchom
  analogWrite(D1, angle);
}
https://alexgyver.ru/lessons/esp8266/
