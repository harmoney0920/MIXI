///////NOTES///////

boolean noteButtons[] = {false, false, false, false, false, false};

int notePots[] = {0, 0, 0, 0};
int notePotTol = 10;

void noteBoard() {

  noteLights=true;

  if (noteLights) {
    for (int i = 0; i < strip.numPixels(); i++) {
       strip.setPixelColor(0,250,0,100);
       strip.setPixelColor(i, 0, 255, 0);
         strip.setPixelColor(3,68,50,170);
      strip.setPixelColor(7, 68, 50, 170);
      strip.setPixelColor(5, 68, 50, 170);
      strip.setPixelColor(6, 68, 50, 170);
      if (i == 4) {
        strip.setPixelColor(i, 68, 50, 170);
        
      }
    }
    strip.show();
    noteLights = false;
  }


  for (int i = 0; i < 8; i++) {
    int curNote = buttonStates[i];

    if (curNote == 1 && i != 0 && 1 != 4) {
      noteButtons[i] = !noteButtons[i];
      if (noteButtons[i]) {
        usbMIDI.sendControlChange(i, 127, 3);
      }
      else {
        usbMIDI.sendControlChange(i, 0, 3);
      }
    }

    if (curNote == 1 && i == 0) {
      switchVal = 1; noteLights=false; 

  }
  
 

  //storing the pots//
  for (int i = 0; i < 4; i++) {
    int thisPot = potStates[i];
    if (abs(thisPot - notePots[i]) > notePotTol) {
      usbMIDI.sendControlChange(i + 8, thisPot, 3);
     notePots[i] = thisPot;
    }

  }
  }
}
