#include "Keyboard.h"

const String SERIAL_KEY_SHIFT = "[SHIFT]";
const String SERIAL_KEY_CTRL = "[CTRL]";
const String SERIAL_KEY_ENTER = "[ENTER]";
const String SERIAL_KEY_DEL = "[DEL]";
const String SERIAL_KEY_TAB = "[TAB]";
const String SERIAL_KEY_ALT = "[ALT]";

bool isShift = false;
bool isCtrl = false;
bool isAlt = false;



void setup() {
    Serial1.begin(9600);
    Serial.begin(9600);
    Keyboard.begin();
}

void loop() {


  while(Serial1.available()) {
    
    
    String a = Serial1.readString();// read the incoming data as string
    Serial.print("Serial Detected!:");
    Serial.print(a);
    Serial.print('\n');
    
    if(a.equals(SERIAL_KEY_SHIFT)) {
     
      isShift = !isShift;
      Keyboard.press(KEY_RIGHT_SHIFT);

    } else if(a == SERIAL_KEY_CTRL) {

      isCtrl = !isCtrl;  
      Keyboard.press(KEY_LEFT_CTRL);

    } else if(a == SERIAL_KEY_ENTER) {

      isAlt = !isAlt;
      Keyboard.press(KEY_KP_ENTER);

    } else if(a == SERIAL_KEY_ALT) {

      Keyboard.press(KEY_LEFT_ALT);

    } else if(a == SERIAL_KEY_DEL) {

      Keyboard.press(KEY_DELETE);

    } else if(a == SERIAL_KEY_TAB) {

      Keyboard.press(KEY_TAB);

    } else {

      if(isShift) {
        a.toUpperCase();
      } 
      Keyboard.print(a);
    }
  }
}
