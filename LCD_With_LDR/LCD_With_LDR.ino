#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "dht.h"
#define dht_apin A3

dht DHT;
LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.setCursor (0,0);
  lcd.print("Temperature is:");
}

void loop(){
  DHT.read11(dht_apin);
  lcd.setCursor (0,1);
  lcd.print(DHT.temperature);
  lcd.setCursor (14,1);
  lcd.print("C");
  delay(5000);
  
}
