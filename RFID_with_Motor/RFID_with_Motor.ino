#include <SPI.h>
#include <MFRC522.h>
#include <Stepper.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
// Number of steps per internal motor revolution 
const float STEPS_PER_REV = 32; 
//  Amount of Gear Reduction
const float GEAR_RED = 64;
// Number of steps per geared output rotation
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;
// Number of Steps Required
int StepsRequired;
// Create Instance of Stepper Class
// Specify Pins used for motor coils
// The pins used are 2,3,4,5 
// Connected to ULN2003 Motor Driver In1, In2, In3, In4 
// Pins entered in sequence 1-3-2-4 for proper step sequencing
Stepper steppermotor(STEPS_PER_REV, 2, 4, 3, 5);

const int SS_PIN = 10;
const int RST_PIN = 9;

MFRC522 mfrc522(SS_PIN, RST_PIN);

byte card_ID[4];
byte First_card_ID[4]={0x76,0x93,0xEE,0x1A}; // 0x81,0xA1,0x4E,0xD3

byte b11[] = {
  B11100,
  B10100,
  B00010,
  B00011,
  B00011,
  B00110,
  B01110,
  B00000
};

byte b12[] = {
  B00111,
  B00101,
  B01000,
  B11000,
  B11000,
  B01100,
  B01110,
  B00000
};

byte b21[] = {
  B10000,
  B01000,
  B00100,
  B11100,
  B11010,
  B01000,
  B11000,
  B00000
};

byte b22[] = {
  B00001,
  B00010,
  B00100,
  B00111,
  B01011,
  B00010,
  B00011,
  B00000
};

byte h11[] = {
  B00111,
  B01000,
  B01010,
  B11000,
  B10101,
  B10100,
  B01000,
  B11011
};

byte h12[] = {
  B11100,
  B00010,
  B01010,
  B00011,
  B10101,
  B00101,
  B00010,
  B11011
};

byte h21[] = {
  B11000,
  B00100,
  B00010,
  B01010,
  B00101,
  B00101,
  B01001,
  B11000
};

byte h22[] = {
  B00011,
  B00100,
  B01000,
  B01010,
  B10100,
  B10100,
  B10010,
  B00011
};
void setup() {
  lcd.init();
  lcd.backlight();
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.createChar(0, h11);
  lcd.createChar(1, h12);
  lcd.createChar(2, h21);
  lcd.createChar(3, h22);
  lcd.createChar(4, b11);
  lcd.createChar(5, b12);
  lcd.createChar(6, b21);
  lcd.createChar(7, b22);
}

void loop() {
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print(" Ready to Read");
  lcd.setCursor(2,1);
  lcd.print(" a Card ...");
  // left dog character moving
  lcd.setCursor(0,0);
  lcd.write(0);
  lcd.write(2);
  lcd.setCursor(0,1);
  lcd.write(4);
  lcd.write(6);
  delay(1000);

  // right dog caractere moving
  lcd.setCursor(0,0);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(0,1);
  lcd.write(7);
  lcd.write(5);
  delay(1000);
  
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
    lcd.clear();
    lcd.print("Done Success :)");
    // Slow - 4-step CW sequence to observe lights on driver board
    steppermotor.setSpeed(800);    
    StepsRequired  =  64*32;
    steppermotor.step(StepsRequired);
    delay(2000);
    steppermotor.step(-StepsRequired);
    delay(2000);
  }
  else 
  {
    lcd.clear();
    lcd.print("Not Access");
    delay(1000);
  }
}
