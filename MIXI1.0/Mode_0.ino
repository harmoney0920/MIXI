void lights(){

  
boolean lightButtons[] = {false, false, false, false, false, false};

 for(int i=0; i<8;i++){
  strip.setPixelColor(i,Wheel(color));
   color= color+25;
   strip.show();
  delay(200);
 // color= color+100;
  }
  delay(1000);
switchVal=1;


}
    uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);}
  if(WheelPos < 170) {WheelPos -= 85; return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);}
  WheelPos -= 170;  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
 }
