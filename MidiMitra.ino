/*
* Edit the Ultrasonic.cpp file, changing Time_out
* to value 30000
*/
#include <Ultrasonic.h>

/*
* Constants
*/
const int MINDELAY = 30;
const int MAXDELAY = 500;

/*
* Pins
*/
const int ledPin = 24;
const int potPin = 0;
const int buttonPin = 40;

// Led variables
int ledStatus = LOW;
// Pot variables
int potValue = 0;
// Ultrasonic sensor
Ultrasonic ultrasonic(32,33);
int distance;
// MIDI
int note;

void setup() {
  // Initialize serial communications at 9600 bps:
  //Serial.begin(9600);
  Serial.begin(31250);
  // Set led pin as output
  pinMode(ledPin, OUTPUT);
  // Set button pin as output
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
}

/*
* Each time this function is called the led
* changes state
*/
void changeLedState(){
  if(ledStatus == HIGH){
     digitalWrite(ledPin, LOW);
     ledStatus = LOW;
  } else {
     digitalWrite(ledPin, HIGH);
     ledStatus = HIGH;
  } 
}

/*
* Reads the potentiometer value and maps it
* to a delay (ms)
*/
int readDelay(){
   potValue = analogRead(potPin);
   return map(potValue, 0, 1023, MINDELAY, MAXDELAY);
}

/*
* Reads if the button is pressed
*/
boolean isButtonPressed(){
    if(digitalRead(buttonPin) == HIGH){
      return true;
    } else {
      return false; 
    }
}

/*
*   Midi notes ranging from 0×18 to 0×46
*   Distance ranging from 0 to 517 (After editing Ultrasonic.cpp)
*/
int getNote(int distance){
   return map(distance, 0, 517, 0x18, 0x46);
}

/*
* Write note
*/
void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}


void loop() {
  /*
  * Application Logic:
  *   If the button is pressed check the distance from the ultrasonic sensor
  *   and the value of the potentiometer. The distance as to be assigned to a
  *   Midi value while the value of the potentiometer sets the frequency.
  *   The led is just for fun :)
  */
  
  if(isButtonPressed()){
      changeLedState();
      
      note = getNote(ultrasonic.Ranging(CM));
      noteOn(0x90, note, 0x45);
      
      delay(readDelay());
  } else {
    digitalWrite(ledPin, LOW);
  }
}
