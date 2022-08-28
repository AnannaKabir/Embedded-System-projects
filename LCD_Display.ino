#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>
#define T 2
dht DHT; 
LiquidCrystal_I2C lcd(0x26, 20, 4);

void setup()
{
  pinMode(T, INPUT);
  lcd.begin();
  //lcd.backlight();
  lcd.print("Hello, world!");
  lcd.setCursor (0, 1); //character zero, line 1
  lcd.print("Getting Started");
  lcd.setCursor (4, 2);
  lcd.print("with Arduino");
  delay(1000);
}

void loop()
{
  int readData = DHT.read11(T);
  float t = DHT.temperature;
  lcd.clear();

  lcd.setCursor (0, 0); //character zero, line 1
  lcd.print("Temp =");
  lcd.print(t);
  lcd.print("°C");
  delay(5000);
  lcd.clear();
}
