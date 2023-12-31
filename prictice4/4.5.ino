#include <Wire.h>

const int I2C_ADDR = 32;
const int pwm_pin = 8;
struct EncoderData {
  int EncoderValue;
};


void receiveEvent(int sizeBytes) {
  if(sizeBytes == sizeof(EncoderData))
  {
    uint8_t* array = new uint8_t[sizeof(EncoderData)];

    Wire.readBytes(array, sizeof(EncoderData));

    EncoderData* dataRec = reinterpret_cast<EncoderData>(array);
    Serial.println(dataRec->EncoderValue);
    analogWrite(pwm_pin, dataRec->EncoderValue);

    delete[] array; 
  }
}

void setup() {
  Wire.begin(I2C_ADDR);
  Wire.onReceive(receiveEvent);
  analogWriteFrequency(25000);
}

void loop() {
}
