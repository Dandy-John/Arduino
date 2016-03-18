#define POT A0

int buzzer = 2;

int PotBuffer = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  PotBuffer = analogRead(POT);

  for (int i = 0; i < 100; ++i){
    digitalWrite(buzzer, HIGH);
  delayMicroseconds(PotBuffer / 3);
  digitalWrite(buzzer, LOW);
  }

  delay(1000);
}
