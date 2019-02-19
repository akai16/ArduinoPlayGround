int buzzer_pin = 2;
int ldr_pin = A0;
int ldr_value = 0;

void alarme(int buzzer){
  float seno;
  int frequencia;
  
  for(int x=0;x<180;x++){
    seno=(sin(x*3.1416/180));
    frequencia = 2000+(int(seno*1000));
    tone(buzzer, frequencia);
    delay(2);
 }
}

 
void setup() {
 Serial.begin(9600);
 pinMode(buzzer_pin ,OUTPUT);
 pinMode(ldr_pin, INPUT);
}
 
void loop() {
  ldr_value = analogRead(ldr_pin);

  if (ldr_value <800) {
     alarme(buzzer_pin);
    }

   else {
      noTone(buzzer_pin);
    }

  Serial.println(ldr_value);

}
