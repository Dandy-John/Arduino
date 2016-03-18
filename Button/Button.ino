int led = 13;
int key = 2;
int buzzer = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(key, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(key) == LOW){
    delay(20);
    if (digitalRead(key) == LOW){
      digitalWrite(buzzer, HIGH);
      digitalWrite(led, !digitalRead(led));
      delay(20);
      digitalWrite(buzzer,LOW);
      while(digitalRead(key) == LOW);
    }
  }
}
