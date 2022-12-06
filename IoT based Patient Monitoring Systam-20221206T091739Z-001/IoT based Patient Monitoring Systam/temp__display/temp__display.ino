#include <OneWire.h>
#include <DallasTemperature.h>
#include <TFT.h>  
#include <SPI.h>
// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 3

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  
#define cs   10
#define dc   9
#define rst  8
TFT TFTscreen = TFT(cs, dc, rst);
// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);
char sensorPrintout[4];

void setup(void)
{

  sensors.begin();  // Start up the library
  Serial.begin(9600);
  
    TFTscreen.begin();
    TFTscreen.background(0, 0, 0);
    TFTscreen.stroke(255, 255, 255);
    TFTscreen.setTextSize(2);
    TFTscreen.text("Heart Rate :\n ", 0, 35);

    
}

void loop(void)
{ 
  // Send the command to get temperatures
  sensors.requestTemperatures(); 
  String sensorVal = String((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
  sensorVal.toCharArray(sensorPrintout, 4);
  TFTscreen.stroke(255, 255, 255);
  TFTscreen.setTextSize(2);
  TFTscreen.text("Temperature : ", 0, 0);
  TFTscreen.text(sensorPrintout, 0, 20);
  TFTscreen.text("F", 40, 20);
  // wait for a moment
  delay(250);
  // erase the text you just wrote
  TFTscreen.stroke(0, 0, 0);
  TFTscreen.text(sensorPrintout, 0, 20);

  delay(500);
}
