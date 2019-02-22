/* Toca o começo da Marcha Imperial ao pressionar
 *  um botão. 
 *  Usa um Piezzo Buzzer
*/

//Pins
const int buttonPin = 12;
const int piezzoPin = 9;

int buttonStatus = 0;
bool isPlaying = false;

// A5 as LA5 due to Arduino's Analog Pins
enum Note {F5, G5, bA5, LA5, bB5, B5, C6, D6, E6, F6, G6};

int noteFrequency(Note note) {
  int frequency = 0;
  
  switch(note) {
    case F5:
      frequency = 698;
      break;
    case G5:
      frequency = 783;
      break;
    case bA5:
      frequency = 830;
      break;
    case LA5:
      frequency = 880;
      break;
    case bB5:
      frequency = 932;
      break;
    case B5:
      frequency = 987;
      break;
    case C6:
      frequency = 1046;
      break;
    case D6:
      frequency = 1174;
      break;
    case E6:
      frequency = 1318;
      break;
    case F6:
      frequency = 1396;
      break;
    case G6:
      frequency = 1567;
      break;
   }

   return frequency;
}

void sing(Note note, float time) {

   int frequency = noteFrequency(note);
   int duration = time * 800;
   int silence = time * 200;
   
   tone(piezzoPin,frequency,duration);
   delay(duration + 10);
   
   tone(piezzoPin,0,silence);
   delay(silence + 10);
}


void imperial_march() {
      
    sing(LA5,1);
    sing(LA5,1);
    sing(LA5,1);
    sing(F5,0.5);
    sing(C6,0.5);
    sing(LA5,1);
    sing(F5,0.5);
    sing(C6,0.5);
    sing(LA5,2);

    sing(E6,1);
    sing(E6,1);
    sing(E6,1);
    sing(F6,0.5);
    sing(C6,0.5);
    sing(bA5,1);
    sing(F5,0.5);
    sing(C6,0.5);
    sing(LA5,2);
  
}

 
void setup() {
  Serial.begin(9600);
  
  pinMode(buttonPin, INPUT);
  pinMode(piezzoPin, OUTPUT);

}

void loop() {
  buttonStatus = digitalRead(buttonPin);
  Serial.println(buttonStatus);

  if (buttonStatus == HIGH && isPlaying == false) {
    isPlaying = true;

    imperial_march();
    
    isPlaying = false;
  }

}
