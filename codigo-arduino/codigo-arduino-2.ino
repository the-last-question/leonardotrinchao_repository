//Arduino Secundário

#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <string.h>

#define tmp 3000

String text;

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop()
{
  if(Serial.available() > 0){
    text = Serial.readString();
    Serial.flush();
    lcd.clear();
    lcd.print(text);
    delay(tmp);
  }
}