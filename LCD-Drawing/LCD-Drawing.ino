#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte c0[] = {B01110, B11111, B11111, B11111, B11111, B11111, B11111, B11111};
byte c1[] = {B01110, B10001, B11111, B11111, B11111, B11111, B11111, B11111};
byte c2[] = {B01110, B10001, B10001, B11111, B11111, B11111, B11111, B11111};
byte c3[] = {B01110, B10001, B10001, B10001, B11111, B11111, B11111, B11111};
byte c4[] = {B01110, B10001, B10001, B10001, B10001, B11111, B11111, B11111};
byte c5[] = {B01110, B10001, B10001, B10001, B10001, B10001, B11111, B11111};
byte c6[] = {B01110, B10001, B10001, B10001, B10001, B10001, B10001, B11111};
int h = 1000;
void setup() {
  lcd.init();
  lcd.backlight();
  // creat charactere
  lcd.createChar(0, c0);
  lcd.createChar(1, c1);
  lcd.createChar(2, c2);
  lcd.createChar(3, c3);
  lcd.createChar(4, c4);
  lcd.createChar(5, c5);
  lcd.createChar(6, c6);
}

void loop() {
  lcd.setCursor(1, 0);
  lcd.print("Please wait ...");
  for (int i = 6; i >= 0; i--)
  {
    lcd.setCursor(0, 0);
    lcd.write(i);
    delay(500);
  }
}
