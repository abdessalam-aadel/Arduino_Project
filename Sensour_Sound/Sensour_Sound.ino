const int led = 3;
const int soundpin = A0;
const int threshold = 50;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(soundpin, INPUT);
}

void loop() {
  int soundsens = analogRead(soundpin);
  Serial.println(soundsens);
  if(soundsens >= threshold){
    digitalWrite(led, HIGH);
    delay(1000);
  }
  else
    digitalWrite(led, LOW);
}
