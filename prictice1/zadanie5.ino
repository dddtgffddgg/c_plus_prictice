volatile int flag = 0;
volatile int check = 1;
struct repeating_timer timer;

void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  add_repeating_timer_ms(5000, changeColor, nullptr, &timer );
}

void loop() {

}

bool changeColor(struct repeating_timer *t)
{
    if (flag == 0)
  {
    if (check == 1)
    {
      digitalWrite(D0,HIGH);
      flag = 1;
    }else {
      digitalWrite(D0, LOW);
    }
    if (check == 2)
    {
      flag = 1;
      digitalWrite(D1,HIGH);
    }else {
      digitalWrite(D1,LOW);
    }
    if (check == 3)
    {
      digitalWrite(D2,HIGH);
      flag = 1;
      check = 0;
    }else {
      digitalWrite(D2,LOW);
    }
  }
  if (flag == 1)
  {
    check++;
    flag = 0;
  }
  return true;
}
