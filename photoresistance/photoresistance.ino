const int ldrPin = A0;
const int ledPin = 13;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(ldrPin,OUTPUT);
}

void loop(){
  int ldrstatus = analogRead(ldrPin);
  
  if(ldrstatus <= 300)
  {
    digitalWrite(ledPin,HIGH);
    Serial.println("LDR is Dark, LED is ON");
  }
  else
  {
    digitalWrite(ledPin,LOW);
    Serial.println("------------------");
  }
}
