#define A1 2
#define B1 3
#define C1 4
#define D1 5

void setup() {
  // put your setup code here, to run once:
  pinMode(A1, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(D1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Phase_A();
  delay(10);
  Phase_B();
  delay(10);
  Phase_C();
  delay(10);
  Phase_D();
  delay(10);
}

void Phase_A(){
  digitalWrite(A1, HIGH);
  digitalWrite(B1, LOW);
  digitalWrite(C1, LOW);
  digitalWrite(D1, LOW);
}

void Phase_B(){
  digitalWrite(A1, LOW);
  digitalWrite(B1, HIGH);
  digitalWrite(C1, LOW);
  digitalWrite(D1, LOW);
}

void Phase_C(){
  digitalWrite(A1, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(C1, HIGH);
  digitalWrite(D1, LOW);
}

void Phase_D(){
  digitalWrite(A1, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(C1, LOW);
  digitalWrite(D1, HIGH);
}

