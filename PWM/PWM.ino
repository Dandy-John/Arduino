#define POT A0

int led = 3;
int PotBuffer = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  PotBuffer = analogRead(POT);
  PotBuffer = map(PotBuffer, 0, 1023, 0, 255);
  analogWrite(led, PotBuffer);
}
