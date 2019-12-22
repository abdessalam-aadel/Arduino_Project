void setup() {
  for(int i=2; i < 14;i++){pinMode(i, OUTPUT);}
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
}

void loop() {
  for(int i=2; i < 14;i++){digitalWrite(i, HIGH);}

}
