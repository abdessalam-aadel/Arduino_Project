//const int buzzer = 10;
int sensor;
void setup() {
  // put your setup code here, to run once:

  //pinMode(buzzer, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600); // Serial Monitor @ 9600 baud
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor = analogRead(A0);
  Serial.println(sensor);
  //While sensor is not moving, analog pin receive 1023~1024 value
  if (sensor == 1023){
    //tone(buzzer, 500);
    digitalWrite(12, HIGH);
    Serial.print("Sensor Value: ");
    Serial.println(sensor);
  }
  else{ 
    //noTone(buzzer);
    digitalWrite(12, LOW);
    Serial.print("Sensor Value: ");
    Serial.println(sensor);
  }
  delay(100);
}
