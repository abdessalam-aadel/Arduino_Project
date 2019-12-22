#include <SPI.h>
#include <MFRC522.h>
#include "pitches.h"

const int SS_PIN = 10;
const int RST_PIN = 9;

MFRC522 mfrc522(SS_PIN, RST_PIN);

byte card_ID[4];
byte First_card_ID[4]={0x76,0x93,0xEE,0x1A};

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
//note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};
s
void setup() {
  Serial.begin(9600); 
  SPI.begin();  
  mfrc522.PCD_Init(); 
  Serial.println("Ready to Read a Card ");
}

void loop() {

  if ( ! mfrc522.PICC_IsNewCardPresent())
    return;
  
  if ( ! mfrc522.PICC_ReadCardSerial())
    return;
  
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    card_ID[i]=mfrc522.uid.uidByte[i];
  }
  if(card_ID[0]==First_card_ID[0] && card_ID[1]==First_card_ID[1] && card_ID[2]==First_card_ID[2] && card_ID[3]==First_card_ID[3])
  {
    Serial.println();
    Serial.println("Done Success :)");
    for (int thisNote = 0; thisNote < 8; thisNote++)
    {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(7, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(7);
    }
    Serial.println("Your Cart Id is : ");
    Serial.print("--");
    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
      Serial.print(mfrc522.uid.uidByte[i]);
      Serial.print("-");
    }
    Serial.print("-");
    delay(5000);
  }
  else 
  {
    Serial.println("Not Access");
    tone(7, NOTE_CS8, 500);
    delay(1000);
  }
}
