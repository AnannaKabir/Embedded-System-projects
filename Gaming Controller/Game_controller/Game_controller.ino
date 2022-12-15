#include <Wire.h>
#include <MPU6050.h>
#include "Keyboard.h"
MPU6050 mpu;

int accelerate = 7;
int stop_break = 5;
int horn = 6;

void setup() 
{
  Serial.begin(115200);
  Keyboard.begin();
  Serial.println("Initialize Gamepad");
  
  pinMode(accelerate, INPUT_PULLUP);
  pinMode(stop_break, INPUT_PULLUP);
  pinMode(horn, INPUT_PULLUP);

  
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }
}

void loop()
{
  //Vector rawAccel = mpu.readRawAccel();
  Vector normAccel = mpu.readNormalizeAccel();
  
  int x = normAccel.XAxis;
  int y = normAccel.YAxis;
  int z = normAccel.ZAxis;

  int acc = digitalRead(accelerate);
  int stop_b = digitalRead(stop_break);
  int horn_v = digitalRead(horn);
  
  Serial.print(x);
  Serial.print(" Ynorm = ");
  Serial.print(y);
  Serial.print(" Znorm = ");
  Serial.println(z);

  if(y>=5)
  {
   Keyboard.press('D');
   delay(250);
   Keyboard.releaseAll(); 
  }

  if(y<=-5)
  {
   Keyboard.press('A');
   delay(250);
   Keyboard.releaseAll(); 
  }

  if(x>=5)
  {
   Keyboard.press('J');
   delay(250);
   Keyboard.releaseAll(); 
  }


  if(x<=-10)
  {
   Keyboard.press('K');
   delay(250);
   Keyboard.releaseAll(); 
  }


  if (acc ==LOW)
  {
   Keyboard.press('W');
   delay(250);
   Keyboard.releaseAll();
  }

  if (stop_b ==LOW)
  {
   Keyboard.press('S');
   delay(250);
   Keyboard.releaseAll();
  }

  if (horn_v ==LOW)
  {
   Keyboard.press('Z');
   delay(250);
   Keyboard.releaseAll();
  }
 delay(10);
}
