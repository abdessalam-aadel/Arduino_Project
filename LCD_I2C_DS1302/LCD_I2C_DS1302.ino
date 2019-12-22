#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DS1302.h>
//#include <SPI.h>
//#include <MFRC522.h>
//#include "pitches.h"
#include <IRremote.h>
#include "dht.h"
#define dht_apin A3
#define light_apin A2
#define inclinison_apin A1
#define code_on 3772809343
#define code_off 3772793023

//const int SS_PIN = 10;
//const int RST_PIN = 9;
//MFRC522 mfrc522(SS_PIN, RST_PIN);
//byte card_ID[4];
//byte First_card_ID[4]={0x81,0xA1,0x4E,0xD3};
// notes in the melody:
//int melody[] = {
//  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
//};
//note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

int value_light;
int value_roller_ball;
const int led_yellow = 6;
const int led_blue = 7;
int IRpin = 5;
bool condition_yellow = false;
bool condition_blue = false;

// Define IR Receiver and Results Objects
IRrecv irrecv(IRpin);
decode_results results;

dht DHT;
LiquidCrystal_I2C lcd(0x27,16,2); 
 //      RST,DAT,CLK
DS1302 rtc(4, 3, 2 );
// Degree caractere
byte degreeChar[] = { B01110,B10001,B10001,B10001,B01110,B00000,B00000,B00000 };
void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.createChar(0,degreeChar);
  rtc.halt(false);
  rtc.writeProtect(false);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_blue, OUTPUT);
  irrecv.enableIRIn(); // start the receiver

  // initialize RFID
  //SPI.begin();  
  //mfrc522.PCD_Init(); 

  pinMode (A0,INPUT);
  // Reset Clock
  //rtc.setDOW(SATURDAY);
  //rtc.setTime(13, 22, 25);
  //rtc.setDate(04, 05, 2019);
}

void loop()
{
  // Resistance Variable
  int val=analogRead(A0);
  int vsl=map(val,0,1023,0,255);
  analogWrite(led_blue,vsl);
  
  DHT.read11(dht_apin);
  value_light = analogRead(light_apin);
  lcd.print(value_light);
  if(value_light < 300) {
    digitalWrite(led_yellow, HIGH);
  }
  else {
    digitalWrite(led_yellow, LOW);
  }
  value_roller_ball = analogRead(inclinison_apin);
  if (value_roller_ball == 1023) {
    digitalWrite(led_blue, HIGH);
  }
  else {
    digitalWrite(led_blue, LOW);
  }
  if(irrecv.decode(&results))
  {
    On_Off();
    irrecv.resume();
  }
  
  lcd.setCursor(0,0);
  lcd.print(" ");
  lcd.print(rtc.getDOWStr()); // Set Day
  lcd.print(" ");
  
  lcd.print(rtc.getDateStr()); // Set Date
  lcd.print(" Current humidity = ");
  lcd.print(DHT.humidity);
  lcd.print("%  ");
  
  lcd.setCursor(0,1);
  lcd.print(rtc.getTimeStr()); // Set Time
  
  lcd.print(" temperature = ");
  lcd.print(DHT.temperature); 
  lcd.print(" C");
  lcd.write(0);

  
  delay(1000);

  lcd.scrollDisplayLeft();
}

void On_Off()
{
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_blue, LOW);
  switch(results.value){
    case code_on:
      if(!condition_yellow){
        digitalWrite(led_yellow, HIGH);
        condition_yellow = true;
      }
      else {
        digitalWrite(led_yellow, LOW);
        condition_yellow = false;
      }
      break;
    case code_off: 
      if(!condition_blue){
        digitalWrite(led_blue, LOW);
        condition_blue = true;
      }
      else {
        digitalWrite(led_blue, HIGH);
        condition_blue = false;
      }
      break;
  default: 
    lcd.print("Unknown button value in decimal");
  }
}
