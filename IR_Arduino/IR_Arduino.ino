#include <IRremote.h>

#define code_on 3772809343
#define code_off 3772793023

const int led_red = 9;
const int led_yellow = 8;
// Define sensor pin
const int IRpin = 10;
// Condition
bool condition_red = false;
bool condition_yellow = false;
// Define IR Receiver and Results Objects
IRrecv irrecv(IRpin);
decode_results results;

void setup() {
  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  irrecv.enableIRIn(); // start the receiver
  Serial.begin(9600); // Serial Monitor @ 9600 baud
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_red, HIGH);
}

void loop() {
  if(irrecv.decode(&results))
  {
    On_Off();
    irrecv.resume();
  }
}

// On and Off Led
void On_Off()
{
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
      if(!condition_red){
        digitalWrite(led_red, LOW);
        condition_red = true;
      }
      else {
        digitalWrite(led_red, HIGH);
        condition_red = false;
      }
      break;
  default: 
    Serial.print("Unknown button value in decimal : ");
    Serial.println(results.value, DEC);
    // Determining Manufacturer Codes
    Serial.print("Manufacturer Codes is : ");
    Manufacturer_Codes();
  }
}

// Determining Manufacturer Codes
void Manufacturer_Codes()
{
  switch (results.decode_type){
    case NEC: 
      Serial.println("NEC"); 
      break;
    case SONY: 
      Serial.println("SONY"); 
      break;
    case RC5: 
      Serial.println("RC5"); 
      break;
    case RC6: 
      Serial.println("RC6"); 
      break;
    case DISH: 
      Serial.println("DISH"); 
      break;
    case SHARP: 
      Serial.println("SHARP"); 
      break;
    case JVC: 
      Serial.println("JVC"); 
      break;
    case SANYO: 
      Serial.println("SANYO"); 
      break;
    case MITSUBISHI: 
      Serial.println("MITSUBISHI"); 
      break;
    case SAMSUNG: 
      Serial.println("SAMSUNG"); 
      break;
    case LG: 
      Serial.println("LG"); 
      break;
    case WHYNTER: 
      Serial.println("WHYNTER"); 
      break;
    case AIWA_RC_T501: 
      Serial.println("AIWA_RC_T501"); 
      break;
    case PANASONIC: 
      Serial.println("PANASONIC"); 
      break;
    case DENON: 
      Serial.println("DENON"); 
      break;
  default:
    case UNKNOWN: 
      Serial.println("UNKNOWN"); 
      break;
  }
}
