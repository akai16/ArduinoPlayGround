//Acende e apaga um LED conforme o
// pressionamento de um botão

const int buttonPin = 7;
const int ledPin = 2;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int buttonStatus = digitalRead(buttonPin);
  
  if (buttonStatus == HIGH) {
    int ledStatus = digitalRead(ledPin);
    digitalWrite(ledPin,!ledStatus);
    delay(500);
  }



}
