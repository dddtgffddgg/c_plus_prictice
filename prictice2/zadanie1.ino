#include <Servo.h>

Servo servo;
int potPin = A0;
int servoPin = D0;

void setup() {
  // put your setup code here, to run once:
  servo.attach(servoPin, 600, 2600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue = analogRead(potPin);
  int angle = map(potValue, 0, 4095, 0, 255);
  servo.write(angle);

  delay(15);
}
