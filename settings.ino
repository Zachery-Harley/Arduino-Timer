/**
 * Set the timer up
 */
void setUp(){
  if(setting){
    if(setMin){
      setMins++;
      if(setMins > 99){
        setMins = 0;
      }
    } else {
      setSecs++;
      if(setSecs > 59) {
        setSecs = 0;
      }
    }

    //Update the current
    secs = setSecs;
    mins = setMins;
  }
}

/**
 * Set the timer down
 */
void setDown(){
  if(setting){
    if(setMin){
      setMins--;
      if(setMins < 0){
        setMins = 99;
      }
    } else {
      setSecs--;
      if(setSecs < 0){
        setSecs = 59;
      }
    }
    //Update the current
    secs = setSecs;
    mins = setMins;
  }
}

/**
 * Set the time
 */
void setTime(){
  if(setting == false){
    setting = true;
    setMin = false;
    timerRestart();
  } else if(setting && !setMin){
    setMin = true;
  } else {
    setting = false;
  }
}

