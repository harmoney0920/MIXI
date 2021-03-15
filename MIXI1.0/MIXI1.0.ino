#include <Bounce2.h>
int buttonPins[] = {5, 6, 7, 8, 9, 10, 11, 12};
int buttonStates[] = {0, 0, 0, 0, 0, 0, 0, 0};
Bounce * buttons = new Bounce[8];

int potPins[] = {A0, A1, A2, A3};
int potStates[] = {0, 0, 0, 0};


int drumLights=false;
int synthLights=false;
int noteLights=false;

int switchVal = 0;
int color =100;

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(8, 4, NEO_RGB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.clear();
  initializeButtons();
  Serial.println("Ready!");
}

void loop() {
  updateButtons();
  printButtons();
  updatePots();
  printPots();
  delay(100);

 switch(switchVal){
  case 0: lights();
  break;
  case 1: drumBoard();
  break;
  case 2: synthBoard();
  break;
  case 3: noteBoard();
  break;
 }
}

void initLEDs(){
  for (int i = 0; i < 8; i++){
    strip.setPixelColor(i, 255, 0, 255);
    strip.show();
    delay(50);
  }
}

void initializeButtons(){
  for (int i = 0; i < 8; i++){
    buttons[i].attach(buttonPins[i] , INPUT_PULLUP  );
    buttons[i].interval(25);  
  }
}

void updateButtons(){
  for (int i = 0; i < 8; i++){
    buttons[i].update();
    if(buttons[i].rose()){buttonStates[i] = 1;}
    else{buttonStates[i] = 0;}
  }
}

void printButtons(){
  for (int i = 0; i < 8; i++){
    int thisButton = buttonStates[i];
    Serial.print(thisButton);
    Serial.print("\t");
  }  
  //Serial.println();
}

void updatePots(){
  for (int i = 0; i < 4; i++){
    int thisPot = analogRead(potPins[i]);
    int mapPot = map(thisPot, 0, 1023, 0, 127);
    potStates[i] = mapPot;
  }
}

void printPots(){
  for (int i = 0; i < 4; i++){
    int thisPot = potStates[i];
    Serial.print(thisPot);
    Serial.print("\t");
  }  
  Serial.println();
}
