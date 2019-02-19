//Pins
int led_pin = 10;

//Fading variables
int brightness = 0;
int fade_value = 5;

void setup(){
    pinMode(led_pin, OUTPUT);
}

void loop(){
    analogWrite(led_pin, brightness);

    brightness =  brightness + fade_value;

    if (brightness<=0 || brightness>=255) {
        fade_value = -fade_value;
    }

    delay(30);
}