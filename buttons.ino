void readButtonStates(){

  /**
  * Reset the timer
  */
  if(digitalRead(set)){
    //Check if the last state wasnt high
    if(digitalRead(set) != lastSet){
      if(setting){
        setTime();
        lastSet = HIGH;
      } else {
        lastSet = HIGH;
        setTime();
      }
    }
    
  } else {
    lastSet = LOW;
  }

  /**
  * Reset the timer
  */
  if(digitalRead(reset)){
    //Check if the last state wasnt high
    if(digitalRead(reset) != lastReset){
      if(setting){
        setUp();
        lastReset = HIGH;
      } else {
        lastReset = HIGH;
        timerRestart();
      }
    }
    
  } else {
    lastReset = LOW;
  }

  /**
   * Start the timer or stop the timer
   */
  if(digitalRead(start)){
    //Check if the last state wasnt high
    if(digitalRead(start) != lastStart){
      if(setting){
        setDown();
        lastStart = HIGH;
      } else {
        lastStart = HIGH;
        timerStopStart();
      }
    }
    
  } else {
    lastStart = LOW;
  }
  
}

