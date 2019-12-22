int led_rouge = 10;
void setup() {
  // put your setup code here, to run once:
  pinMode(led_rouge,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led_rouge, HIGH);
  delay(1000);
  digitalWrite(led_rouge, LOW);
  delay(3000);
}
