#define D0 0
#define D1 1
#define D2 2
#define D3 3

int currentColor = D0;

void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, INPUT_PULLUP);

  // устанавливаем прерывание на пине BUTTON_PIN
  attachInterrupt(D3, changeColor, FALLING);
}

void loop() {
  
}

void changeColor() {
  digitalWrite(currentColor, LOW);  // 
    
  if (currentColor == D0) {
    currentColor = D1;
  } else if (currentColor == D1) {
    currentColor = D2;
  } else {
    currentColor = D0;
  }
    
  digitalWrite(currentColor, HIGH); // включаем новый цвет
  delay(500); //ключаем прерывания снова
}
