#define LM35 A0

int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(LM35);
  Serial.print("LM35 = ");
  Serial.println(val * 0.48876);
  delay(500);
}
