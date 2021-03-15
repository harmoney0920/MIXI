///////DRUMS///////

boolean drumButtons[] = {false, false, false, false, false, false};

int drumPots[] = {0, 0, 0, 0};
int drumPotTol = 10;

void drumBoard() {

  drumLights=true;

  if (drumLights) {
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(0,250,0,100);
      strip.setPixelColor(5,0,255,0);
      strip.setPixelColor(6,255,0,100);
       strip.setPixelColor(3,255,255,255);
      strip.setPixelColor(i, 68, 50, 170);
      if (i == 4) {
        strip.setPixelColor(i, 255, 247, 0);
      }
    }
    strip.show();
    drumLights = false;
  }


  for (int i = 0; i < 8; i++) {
    int curDrum = buttonStates[i];

    if (curDrum == 1 && i != 0 && 1 != 4) {
      drumButtons[i] = !drumButtons[i];
      if (drumButtons[i]) {
        usbMIDI.sendControlChange(i, 127, 1);
      }
      else {
        usbMIDI.sendControlChange(i, 0, 1);
      }
    }

    if (curDrum == 1 && i == 0) {
      switchVal = 2; drumLights = false; synthLights = true;

  }
 

  //storing the pots//
  for (int i = 0; i < 4; i++) {
    int thisPot = potStates[i];
    if (abs(thisPot - drumPots[i]) > drumPotTol) {
      usbMIDI.sendControlChange(i + 8, thisPot, 1);
      drumPots[i] = thisPot;
    }

  }
}
}
