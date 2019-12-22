void setup() {
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

}

void loop() {
  for(int i = 5; i<=7; i++)
  {
    digitalWrite(i, HIGH);
    delay(500);
  }

  for(int i = 8; i<=10; i++)
  {
    digitalWrite(i, HIGH);
    delay(500);
  }

  for(int i = 11; i<=13; i++)
  {
    digitalWrite(i, HIGH);
    delay(500);
  }

  for(int i = 5; i<=13; i++)
  {
    digitalWrite(i, LOW);
    delay(100);
  }
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(9, HIGH);
  delay(100);
  digitalWrite(6, HIGH);
  delay(5000);
  

}
