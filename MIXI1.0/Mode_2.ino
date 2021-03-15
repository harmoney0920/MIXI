///////SYNTH///////

boolean synthButtons[] = {false, false, false, false, false, false};

int synthPots[] = {0, 0, 0, 0};
int synthPotTol = 10;

void synthBoard() {

  synthLights=true;

  if (synthLights) {
    for (int i = 0; i < strip.numPixels(); i++) {
       strip.setPixelColor(0,250,0,100);
         strip.setPixelColor(4,0,255,0);
      strip.setPixelColor(i, 68, 50, 170);
    
    strip.show();
    synthLights = false;
  }
  }


  for (int i = 0; i < 8; i++) {
    int curSynth = buttonStates[i];

    if (curSynth == 1 && i != 0 && 1 != 4) {
      synthButtons[i] = !synthButtons[i];
      if (synthButtons[i]) {
        usbMIDI.sendControlChange(i, 127, 2);
      }
      else {
        usbMIDI.sendControlChange(i, 0, 2);
      }
    }
  

    if (curSynth == 1 && i == 0) {
      switchVal = 3; drumLights = false; synthLights = false;

  }
 

  //storing the pots//
  for (int i = 0; i < 4; i++) {
    int thisPot = potStates[i];
    if (abs(thisPot - synthPots[i]) > synthPotTol) {
      usbMIDI.sendControlChange(i + 8, thisPot, 2);
      synthPots[i] = thisPot;
    }

  }
}
}
