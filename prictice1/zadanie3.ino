#define RED 0
#define YELLOW 1
#define GREEN 2
#define BUTTON_PIN 3

int currentColor = RED;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  
  if (buttonState == LOW) {
    // Кнопка нажата
    
    digitalWrite(currentColor, LOW);  // Выключаем текущий цвет
    
    if (currentColor == RED) {
      currentColor = YELLOW;
    } else if (currentColor == YELLOW) {
      currentColor = GREEN;
    } else {
      currentColor = RED;
    }
    
    digitalWrite(currentColor, HIGH); // Включаем новый цвет
    delay(500); // Задержка для избежания множественных смен цвета при удержании кнопки
    while (digitalRead(BUTTON_PIN) == LOW) {
      // Ждем, пока кнопка будет отпущена
    }
  }
}
