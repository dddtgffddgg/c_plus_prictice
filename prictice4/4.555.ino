#include <Wire.h>

const int I2C_ADDR = 32;
const int pwm_pin = 8;

struct EncoderData {
  int EncoderValue;
};

void receiveEvent(int sizeBytes) {
  if (sizeBytes == sizeof(EncoderData)) {
    EncoderData dataRec;
    Wire.readBytes(reinterpret_cast<uint8_t*>(&dataRec), sizeof(EncoderData));

    Serial.println(dataRec.EncoderValue);
    analogWrite(pwm_pin, dataRec.EncoderValue);
  }
}

void setup() {
  Wire.begin(I2C_ADDR);
  Wire.onReceive(receiveEvent);
  analogWriteFrequency(25000);
}

void loop() {
  // Ваш основной код в loop, если необходимо что-то добавить
}
