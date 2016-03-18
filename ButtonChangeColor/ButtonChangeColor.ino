int red = 0;
int green = 0;
int blue = 0;
int i = 0;
int flag_up = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (ScanKey() == 1){
    i++;
    if (i > 7){
      i = 0;
    }
  }
  Serial.println(i);

  red = 1 - i % 2;
  green = 1 - i / 2 % 2;
  blue = 1 - i / 4 % 2;
  digitalWrite(2, red);
  digitalWrite(3, green);
  digitalWrite(4, blue);
}

unsigned char ScanKey(){
  if (flag_up && digitalRead(5) == LOW){
    flag_up = 0;
    delay(20);
    if (digitalRead(5) == LOW){
      return 1;
    }
  }
  if (digitalRead(5) == HIGH){
    flag_up = 1;
    return 0;
  }
}
