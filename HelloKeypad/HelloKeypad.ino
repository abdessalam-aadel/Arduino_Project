#include <Key.h>
#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','4'},
  {'5','6','7','8'},
  {'9','A','B','C'},
  {'D','*','0','#'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key == '*'){
    digitalWrite(13, HIGH);
  }
  if (key == '#'){
    digitalWrite(13, LOW);
  }
}
