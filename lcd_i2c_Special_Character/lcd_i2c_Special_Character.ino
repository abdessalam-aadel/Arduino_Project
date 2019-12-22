#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
byte first[] = {
  B00000,
  B00100,
  B01010,
  B10100,
  B01110,
  B00101,
  B00100,
  B01110
};

byte se_cond[] = {
  B00000,
  B00100,
  B01010,
  B00101,
  B01110,
  B10100,
  B00100,
  B01110
};

byte firstSmile[] = {
  B00000,
  B00000,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};

byte secondSmile[] = {
  B00000,
  B00000,
  B00000,
  B01010,
  B00000,
  B01110,
  B10001,
  B00000
};

void setup()
{
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, first);
  lcd.createChar(1, se_cond);
  lcd.createChar(2, firstSmile);
  lcd.createChar(3, secondSmile);
}

void loop()
{
  for(int i=0; i<16; i++)
  {
    lcd.setCursor(i, 0);
    lcd.write(0);
    delay(500);
    lcd.clear();
    lcd.setCursor(i, 0);
    lcd.write(1);
    delay(500);
    lcd.clear();
    i++;
  }
  for(int j=0; j<16; j++)
  {
    lcd.setCursor(j, 1);
    lcd.write(2);
    delay(500);
    lcd.clear();
    lcd.setCursor(j, 1);
    lcd.write(3);
    delay(500);
    lcd.clear();
    j++;
  }

  lcd.setCursor(5, 0);
  lcd.print("meriam");
  lcd.setCursor(5, 1);
  lcd.print("aadel");
  delay(5000);
  lcd.clear();
  
}
