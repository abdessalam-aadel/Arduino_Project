//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

// make some custom characters:
byte heart[] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smiley[] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

byte armsDown[] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

byte customT[] = {
  B11111,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};

byte customMonster[] = {
  B10101,
  B01110,
  B10101,
  B11111,
  B00100,
  B01110,
  B10101,
  B10101
};

byte right[] = {
  B00000,
  B10000,
  B01000,
  B00100,
  B00011,
  B00100,
  B01000,
  B10000
};

byte left[] = {
  B00000,
  B00001,
  B00010,
  B00100,
  B11000,
  B00100,
  B00010,
  B00001
};

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor (1,0);
  lcd.print("First LCD-I2C");
  delay(1000);
  lcd.setCursor (0,1);
  lcd.print("..Hello World..");
  delay(5000);
  lcd.clear();

  // create a new character
  lcd.createChar(0, heart);
  lcd.createChar(1, smiley);
  lcd.createChar(2, frownie);
  lcd.createChar(3, armsDown);
  lcd.createChar(4, armsUp);
  lcd.createChar(5, customT);
  lcd.createChar(6, customMonster);
  lcd.createChar(7, right);
  lcd.createChar(8, left);
  // set the cursor to the top left
  lcd.setCursor(0, 0);

  // Print a message to the lcd.
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  lcd.write(6);
  lcd.write(7);
  lcd.write(8);
}

void loop()
{
  lcd.clear();
  lcd.print("Habiba Aadel");
  delay(5000);
//  char myName[] = "Write Less Do More";
//  char myCountrie[] = "Discover Who you are";
//  for (int i = 0; i < sizeof(myName)-1; i++) {
//    lcd.print(myName[i]);
//    delay(500);
//  }
//
//  lcd.setCursor(16, 1);
//  // set the display to automatically scroll:
//  lcd.autoscroll();
//  for (int i=0; i < sizeof(myCountrie)-1; i++) {
//    lcd.print(myCountrie[i]);
//    delay(500);
//  }
//  // turn off automatic scrolling
//  lcd.noAutoscroll();
//
//  // clear screen for the next loop:
//  lcd.clear();
}
