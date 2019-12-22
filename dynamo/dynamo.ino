int motor = 3;
void setup() {
  // put your setup code here, to run once:
  //pinMode(motor, OUTPUT);
}

void loop() {
  for(int i=0; i<= 255;i++)
    {
      analogWrite(motor,i);
      delay(10);
    }
}
