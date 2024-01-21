#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 or 0x3f for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);

int analog_IN = A0;  // This is our input pin


void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(analog_IN, INPUT);
  Serial.begin(9600);  
}

void loop() {

  int Value = analogRead(analog_IN);  
  Serial.print("Analog read: ");Serial.println(Value);
    
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pollution Read:");
  lcd.setCursor(2,1);
  lcd.print(Value);

  if(Value < 200)
  {
    lcd.print(":NO SMOKE");
  }
  else
  {
    lcd.print(":SMOKE");
  }  
  
  delay(200);
}
