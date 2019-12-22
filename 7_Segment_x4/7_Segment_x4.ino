#include<SevSeg.h>
SevSeg sevseg;
int A = 2;
int B = 3;
int C = 4;
int D = 5;
int E = 6;
int F = 7;
int G = 8;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;


void setup() {
//  byte numDigits = 4;
//  byte digitPins[] = {2, 3, 4, 5};
//  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
//  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
//  sevseg.setBrightness(10);
  for(int i =2; i<=12; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop() {
//  sevseg.setNumber(12);
//  sevseg.refreshDisplay();
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  delay(1000);

  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  delay(1000);
}
