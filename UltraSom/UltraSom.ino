#include <HCSR04.h>

int triggerPin = 9;
int echoPin = 8;

UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

void setup () {
    Serial.begin(9600);    
}

void loop () {
    Serial.println(distanceSensor.measureDistanceCm());
    delay(500);
}