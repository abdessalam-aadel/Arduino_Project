#include "pitches.h"

const int push_button_on = 13;
const int push_button_off = 7;
bool state = false;
int delay_time = 500;
// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

int led = 9;

void setup() {
  //Pin of Led
  for(int i=2; i<=4; i++) { pinMode(i,OUTPUT); }
  //pinMode(led,OUTPUT);
  // Pin of button push
  pinMode(push_button_on,INPUT);
  pinMode(push_button_off,INPUT);
}

void loop() {
  // -----ON-----
  if(digitalRead(push_button_on) == HIGH && !state)
  {
    for(int j=4; j>1; j--)
    {
      tone(8, NOTE_CS8, 500);  
      digitalWrite(j+1,LOW);
      delay(delay_time);
      digitalWrite(j,HIGH);
      delay(delay_time);
    }
    
    for(int i=3; i<5; i++)
    {
      delay(delay_time);
      digitalWrite(i,HIGH);
    }

    delay(1000);
    for(int i=0; i<=2; i++) 
    {
      for(int j=4; j>1; j--)
      {
        digitalWrite(j,LOW);
      }
      delay(delay_time);
      for(int j=4; j>1; j--)
      {
        tone(8, NOTE_CS8, 500);
        digitalWrite(j,HIGH);
      }
      delay(delay_time);
    }
    state = true;
  }

  // -----OFF-----
  if (digitalRead(push_button_off) == HIGH && state)
  {
    for(int i=2; i<5; i++)
    {
      delay(delay_time);
      digitalWrite(i,LOW);
    }
    state = false;
    
    for (int thisNote = 0; thisNote < 8; thisNote++)
    {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(8, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(8);
    }

    delay(1000);
    tone(8, NOTE_DS8, 1000);
    //--ON LED 2 volt
    for(int i=0; i<= 255;i++)
    {
      analogWrite(led,i);
      delay(10);
    }
    for(int i=255; i>= 0;i--)
    {
      analogWrite(led,i);
      delay(10);
    }
    delay(1000);
  }
}
