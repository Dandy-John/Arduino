#define ADpin A5

int led = 13;
int ADBuffer = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  ADBuffer = analogRead(ADpin);
  Serial.print("AD = ");
  Serial.print(ADBuffer);
  if (ADBuffer > 800){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }
  delay(500);
}
