int red = 0;
int green = 0;
int blue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 8; i++){
    red = 1 - i % 2;
    green = 1 - i / 2 % 2;
    blue = 1 - i / 4 % 2;
    digitalWrite(2, red);
    digitalWrite(3, green);
    digitalWrite(4, blue);
    delay(1000);
  }
}
