void setup() {
  pinMode (10,OUTPUT);
  pinMode (A0,INPUT);

  Serial.begin(9600);

}

void loop() {
  int val=analogRead(A0);
  int vsl=map(val,0,1023,0,255);
  analogWrite(10,vsl);

  Serial.println(vsl);
  delay (100);



}
