#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  lcd.clear(); 
}

void loop() {
  lcd.setCursor(1, 0);
  lcd.print("HELLO THERE!");
  lcd.setCursor(0, 1);
  lcd.print("GOD BLESS YOU!");
  delay(100);
}