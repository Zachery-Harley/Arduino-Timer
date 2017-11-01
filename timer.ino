#include "SevSeg.h"

SevSeg sevseg; //Initiate a seven segment controller object

//Pins for buttons
char start = A5;
char reset = A3;
char set = A4;

char lastStart = LOW;
char lastReset = LOW;
char lastSet = LOW;
char beeps = 10;

//Settings
boolean setting = false;
boolean setMin = false;
boolean blinkInt = false;
char newValue = 0;

int mins = 0;
int secs = 0;
int setMins = 3;
int setSecs = 0;

unsigned long lastMillis;
boolean counting = false; //True when the count dowm active
boolean finished = false;

void setup() {
  //Set up the display
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 12, 11, 13};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);

  //Start the timer
  timerRestart();
}





void loop() {

  readButtonStates();
  String concas = (String)mins + (String)secs;
  int show = concas.toInt();

  if(secs < 10){
    sevseg.setNumber(show, 1);
  } else {
    sevseg.setNumber(show, 2);
  }
  sevseg.refreshDisplay(); // Must run repeatedly
  
  //Blink the mins if needed
  if(setting && setMin){
    if((millis() % 1000) > 500){
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      if(secs < 10){
        digitalWrite(4, HIGH);
      }
    }
  }

  //Blink the mins if needed
  if(setting && !setMin){
    if((millis() % 1000) > 500){
      if(secs > 9){
        digitalWrite(4, HIGH);
      }
      digitalWrite(5, HIGH);
    }
  }

  //If timer is counting then count down
  if(counting && !finished){
    countDown();
  }

}
