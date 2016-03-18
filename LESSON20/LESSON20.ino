int latchPin = 10;
int clockPin = 12;
int dataPin = 11;

unsigned char table1[8][8] =       //大“心型”的数据
{
  0,0,0,0,0,0,0,0,
  0,1,1,0,0,1,1,0,
  1,1,1,1,1,1,1,1,
  1,1,1,1,1,1,1,1,
  1,1,1,1,1,1,1,1,
  0,1,1,1,1,1,1,0,
  0,0,1,1,1,1,0,0,
  0,0,0,1,1,0,0,0,
};

int table[] = { 0x55, 0x55, 0x11, 0x44, 0x5, 0x50, 0x1, 0x40, 0x51, 0x45, 0x11, 0x44, 0x11, 0x44, 0x55, 0x55 };

void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  int a = 0x01;
/*
  digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, ~0x01); //先选择列
    shiftOut(dataPin, clockPin, MSBFIRST, 0xf1); //再送行数据
    digitalWrite(latchPin, HIGH);*/

    /*for (int i = 0; i < 8; i++){
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, ~(a<<i)); //先选择列
      shiftOut(dataPin, clockPin, MSBFIRST, a<<i); //再送行数据
      digitalWrite(latchPin, HIGH);
    }*/
    for (int k = 0; k < 125; k++){
      for (int i = 0; i < 8; i++){
      int temp = 0;
      for (int j = 0; j < 8; j++){
        temp = temp * 2 + table1[i][j];
      }
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, ~(0x01<<i)); //先选择列
      shiftOut(dataPin, clockPin, MSBFIRST, temp); //再送行数据
      digitalWrite(latchPin, HIGH);
      delay(1);
    }
    }
    for (int i = 0; i < 8; i++){
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, ~(0x01<<i)); //先选择列
      shiftOut(dataPin, clockPin, MSBFIRST, 0x00); //再送行数据
      digitalWrite(latchPin, HIGH);
    }
    delay(500);
}
