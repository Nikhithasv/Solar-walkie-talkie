
 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

#define Sensor A1

void setup() {
  Serial.begin(9600);8;
  lcd.init();
  lcd.backlight();
}

void loop() {
  int value = analogRead(Sensor);
  
  if (value > 400) {
    lcd.print(value);
    lcd.setCursor(0, 1);
    lcd.print("pollution");
  } else {
    lcd.print(value);
    lcd.setCursor(0, 1);
    lcd.print("no pollution");
  }
}
