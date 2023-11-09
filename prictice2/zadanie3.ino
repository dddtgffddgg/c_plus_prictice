#include <AmperkaFET.h>
#include <SPI.h>
#include <string.h>
#include <sstream>

FET mosfet(D17, 2);

void setup()
{
  Serial.begin();
  mosfet.begin();
}

void loop()
{
  if (Serial.available() > 0)
  {
    uint32_t device;
    uint32_t pin;
    bool mode;

    std::stringstream input;

    input << Serial.readString().c_str();

    input >> device;
    input >> pin;
    input >> mode;

    Serial.println(device);
    Serial.println(pin);
    Serial.println(mode);

    mosfet.digitalWrite(device, pin, mode);
  }
}
