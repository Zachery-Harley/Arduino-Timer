/**
 * Start and stop the timer of the clock
 */
void timerStopStart(){
  if(counting){
    counting = false;//Timer has stopped
  } else {
    //resume the millies
    counting = true;
    lastMillis = millis();
  }
}

/**
 * Restart the timer
 */
void timerRestart(){
  //Restart the timer
  counting = false;
  finished = false;
  mins = setMins;
  secs = setSecs;
}



void checkEnd(){
  tone(A1, 800, 1000);
}

/**
 * Count down the timer if needed
 */
void countDown(){
  //If timer counting then count down
  if((millis() - lastMillis) > 1000){
    //reduce the seconds by 1
    secs--;
    //If seconds if less than 0 go to 59
    if(secs < 0){
      secs = 59;
      mins--;
    }

    //if mins less than 0 then done
    if(mins < 0){
      mins = 0;
      secs = 0;
      counting = false;
      finished = true;
      checkEnd();
    }

    //Set the last millis
    lastMillis = millis();
  }
}

