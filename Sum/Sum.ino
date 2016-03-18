#define SEG_A 2
#define SEG_B 3
#define SEG_C 4
#define SEG_D 5
#define SEG_E 6
#define SEG_F 7
#define SEG_G 8
#define SEG_H 9

#define COM1 10
#define COM2 11
#define COM3 12
#define COM4 13

#define KEY 0

int sum = 0;
int flag_up = 1;

unsigned char table[10][8] = {
  {0, 0, 1, 1, 1, 1, 1, 1},
  {0, 0, 0, 0, 0, 1, 1, 0},
  {0, 1, 0, 1, 1, 0, 1, 1},
  {0, 1, 0, 0, 1, 1, 1, 1},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {0, 1, 1, 0, 1, 1, 0, 1},
  {0, 1, 1, 1, 1, 1, 0, 1},
  {0, 0, 0, 0, 0, 1, 1, 1},
  {0, 1, 1, 1, 1, 1, 1, 1},
  {0, 1, 1, 0, 1, 1, 1, 1}
};

void setup() {
  // put your setup code here, to run once:
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
  pinMode(SEG_H, OUTPUT);

  pinMode(COM1, OUTPUT);
  pinMode(COM2, OUTPUT);
  pinMode(COM3, OUTPUT);
  pinMode(COM4, OUTPUT);

  pinMode(KEY, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (ScanKey() == 1){
    sum++;
    if (sum > 9999){
      sum = 9999;
    }
  }
  Display(1, sum / 1000);
  delay(3);
  Display(2, sum % 1000 / 100);
  delay(3);
  Display(3, sum % 100 / 10);
  delay(3);
  Display(4, sum % 10);
  delay(3);
}

void Display(unsigned char com, unsigned char num) {
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_E, LOW);
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
  digitalWrite(SEG_H, LOW);

  switch (com) {
    case 1:
      digitalWrite(COM1, LOW);
      digitalWrite(COM2, HIGH);
      digitalWrite(COM3, HIGH);
      digitalWrite(COM4, HIGH);
      break;
    case 2:
      digitalWrite(COM1, HIGH);
      digitalWrite(COM2, LOW);
      digitalWrite(COM3, HIGH);
      digitalWrite(COM4, HIGH);
      break;
    case 3:
      digitalWrite(COM1, HIGH);
      digitalWrite(COM2, HIGH);
      digitalWrite(COM3, LOW);
      digitalWrite(COM4, HIGH);
      break;
    case 4:
      digitalWrite(COM1, HIGH);
      digitalWrite(COM2, HIGH);
      digitalWrite(COM3, HIGH);
      digitalWrite(COM4, LOW);
      break;
    default:
      break;
  }

  digitalWrite(SEG_A, table[num][7]);
  digitalWrite(SEG_B, table[num][6]);
  digitalWrite(SEG_C, table[num][5]);
  digitalWrite(SEG_D, table[num][4]);
  digitalWrite(SEG_E, table[num][3]);
  digitalWrite(SEG_F, table[num][2]);
  digitalWrite(SEG_G, table[num][1]);
  digitalWrite(SEG_H, table[num][0]);
}

unsigned char ScanKey(){
  if (flag_up && digitalRead(KEY) == LOW){
    flag_up = 0;
    delay(20);
    if (digitalRead(KEY) == LOW){
      return 1;
    }
  }
  if (digitalRead(KEY) == HIGH){
    flag_up = 1;
    return 0;
  }
}

