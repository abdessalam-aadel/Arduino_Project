int light;
const int led_yellow = 5;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_yellow, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  light = analogRead(0);
  Serial.println(light);
  if(light < 300)
    digitalWrite(led_yellow, HIGH);
  else
    digitalWrite(led_yellow, LOW);
}
