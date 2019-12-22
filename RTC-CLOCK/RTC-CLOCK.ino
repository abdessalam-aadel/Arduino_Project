#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <virtuabotixRTC.h> //Library used
//Wiring SCLK -> 6, I/O -> 7, CE -> 8
//Or CLK -> 6 , DAT -> 7, Reset -> 8

virtuabotixRTC myRTC(6, 7, 8); //If you change the wiring change the pins here also
LiquidCrystal_I2C lcd(0x27,16,2); 

void setup() {
  lcd.init();
  lcd.backlight();
  myRTC.setDS1302Time(12, 45, 35, 7, 4, 5, 2019);
}

void loop() {
 myRTC.updateTime();
 lcd.setCursor(0,0); 
 lcd.print("Current Date / Time: ");
 lcd.setCursor(0,1); 
 lcd.print(myRTC.dayofmonth); //You can switch between day and month if you're using American system
 lcd.print("/");
 lcd.print(myRTC.month);
 lcd.print("/");
 lcd.print(myRTC.year);
 lcd.print(" ");
 lcd.print(myRTC.hours);
 lcd.print(":");
 lcd.print(myRTC.minutes);
 lcd.print(":");
 lcd.println(myRTC.seconds);

 delay(1000);
}
