int buttonState = 0;

void setup() {
	pinMode(D0, OUTPUT); //вывод для светодиода
	pinMode(D1, INPUT); //ввод для кнопки //кнопка
}

void loop() {
	buttonState = digitalRead(D1);

  if (buttonState == HIGH) {
    digitalWrite(D0, HIGH);
  }else {
    digitalWrite(D0, LOW);
  }
}
