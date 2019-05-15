#include "RCSwitch.h"

const char wave[] = "1001111001000000101000110101";

const int button_pin = 2;
RCSwitch mySwitch = RCSwitch();

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(button_pin, INPUT_PULLUP);
    mySwitch.enableTransmit(10);
}

void loop() {
  if (digitalRead(button_pin) == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
    mySwitch.send("1001111001000000101000110101");
    delay(2000);  
  }

  else {
    digitalWrite(LED_BUILTIN, LOW);
  }

}
