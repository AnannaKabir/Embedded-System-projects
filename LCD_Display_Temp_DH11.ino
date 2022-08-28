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
  lcd.print("Weather Station");
  delay(1000);
}

void loop()
{
  int readData = DHT.read11(T);
  float t = DHT.temperature;
  float h = DHT.humidity;
  lcd.clear();

  lcd.setCursor (0, 0); //character zero, line 1
  lcd.print("Temp =");
  lcd.print(t);
  lcd.print("'C");
  lcd.setCursor (0, 1); //character zero, line 2
  lcd.print("Humidity =");
  lcd.print(h);
  lcd.print("%");
  delay(5000);
  lcd.clear();
}
