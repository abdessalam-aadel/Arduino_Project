int E = 13;
int D = 12;
int C = 11;
int DP = 10;
int B = 9;
int A = 8;
int F = 7;
int G = 6;
const int ldr = A0;
void setup() {
  for(int i = 6; i <=13; i++)
  {
    pinMode(i, OUTPUT);
  }
  atteindre();
  pinMode(0, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrstatus = analogRead(0);
  Serial.println(ldrstatus);
  delay(500);
  if(ldrstatus < 1000)
  {
    affiche();
    Serial.println("LDR is Dark");
  }
  else
  {
    atteindre();
    Serial.println("------------------");
  }
  
}

// Affiche number of 0 to 9
void affiche()
{
  // Affiche 0
  allumer();
  digitalWrite(G, LOW);
  delay(1000);
  
  atteindre();

  // Afiche 1
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  delay(1000);

  atteindre();

  // Afiche 2
  allumer();
  digitalWrite(C, LOW);
  digitalWrite(F, LOW);
  delay(1000);

  atteindre();

  // Afiche 3
  allumer();
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  delay(1000);

  // Afiche 4
  digitalWrite(A, LOW);
  digitalWrite(D, LOW);
  digitalWrite(F, HIGH);
  delay(1000);

  atteindre();
  
  // Afiche 5
  allumer();
  digitalWrite(B, LOW);
  digitalWrite(E, LOW);
  delay(1000);
  
  // Afiche 6
  digitalWrite(B, LOW);
  digitalWrite(E, HIGH);
  delay(1000);

  atteindre();
  
  // Afiche 7
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  delay(1000);

  atteindre();
  
  // Afiche 8
  allumer();
  delay(1000);

  // Afiche 9
  digitalWrite(E, LOW);
  delay(1000);

  atteindre();
  delay(2000);
}

// Atteindre tout les led
void atteindre()
{
  for(int i = 6; i <=13; i++)
  {
    digitalWrite(i, LOW);
  }
}

// Allumer tout les led
void allumer()
{
  for(int i = 6; i <=13; i++)
  {
    digitalWrite(i, HIGH);
  }
  digitalWrite(DP, LOW);
}
