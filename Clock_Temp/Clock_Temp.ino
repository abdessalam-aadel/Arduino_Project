#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <virtuabotixRTC.h> //Library used
#include "dht.h"
#define dht_apin A0 // Analog Pin sensor is connected to
 
dht DHT;

//Wiring SCLK -> 6, I/O -> 7, CE -> 8
//Or CLK -> 6 , DAT -> 7, Reset -> 8
virtuabotixRTC myRTC(6, 7, 8); //If you change the wiring change the pins here also
LiquidCrystal_I2C lcd(0x27,16,2);
byte degreeChar[] = { B01110,B10001,B10001,B10001,B01110,B00000,B00000,B00000 };

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0,degreeChar);
}

void loop() {
   lcd.clear();
   myRTC.updateTime();
   lcd.setCursor(0,0); 
   lcd.print("Current Time : ");
   lcd.setCursor(0,1); 
   lcd.print(myRTC.hours);
   lcd.print(":");
   lcd.print(myRTC.minutes);
   lcd.print(":");
   lcd.print(myRTC.seconds);
   delay(1000);
}
