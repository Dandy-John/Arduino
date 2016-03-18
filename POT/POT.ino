#define POT A0

int PotBuffer = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  PotBuffer = analogRead(POT);
  Serial.print("Pot = ");
  Serial.println(PotBuffer);
  delay(500);
}
