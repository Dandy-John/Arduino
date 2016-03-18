#define ADpin A0
#define Buzzer 2

int ADBuffer = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  ADBuffer = analogRead(ADpin);
  Serial.print("AD = ");
  Serial.println(ADBuffer);
  delay(500);
  if (ADBuffer > 20){
    digitalWrite(Buzzer, HIGH);
  }
  else{
    digitalWrite(Buzzer, LOW);
  }
}
