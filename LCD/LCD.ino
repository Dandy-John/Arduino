#include <LiquidCrystal.h>

#define LM35 A0

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int val = 0;
float temp = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("Welcome to use!");
  delay(1000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(LM35);
  temp = val * 4.8876;
  lcd.setCursor(0, 0);
  lcd.print("LM35 temp =");
  lcd.setCursor(0, 1);
  lcd.print((int)temp / 10);
  lcd.print(".");
  lcd.print((int)temp % 10);

  lcd.print((char)223);
  lcd.print("C");
  delay(1000);
}
