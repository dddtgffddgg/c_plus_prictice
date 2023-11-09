volatile int ledVal = 0;
void setup() {
  pinMode(D0, OUTPUT);
  analogWriteFreq(120);

}

void loop() {

  int potVal = analogRead(A0);
  ledVal = map(potVal, 0, 4095, 0, 255);
  
  analogWrite(D0, ledVal);
}
