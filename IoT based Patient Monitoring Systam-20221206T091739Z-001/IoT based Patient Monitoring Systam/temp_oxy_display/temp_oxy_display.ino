#include <OneWire.h>
#include <DallasTemperature.h>
#include <TFT.h>
#include <SPI.h>
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

// temp Data wire is plugged into digital pin 3 on the Arduino
#define ONE_WIRE_BUS 3

//oxy
#define REPORTING_PERIOD_MS     1000
PulseOximeter pox;
uint32_t tsLastReport = 0;


// Display Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);
#define cs   10
#define dc   9
#define rst  8
TFT TFTscreen = TFT(cs, dc, rst);
// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);
char sensorPrintout[4];


void onBeatDetected() {
  Serial.println("Beat!");
}

void setup(void)
{

  sensors.begin();  // Start up the library
  Serial.begin(9600);
  // oxy
  if (!pox.begin()) {
    Serial.println("FAILED");
    for (;;);
  } else {
    Serial.println("SUCCESS");
  }
  // Configure sensor to use 7.6mA for LED drive
  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
  pox.setOnBeatDetectedCallback(onBeatDetected);

  TFTscreen.begin();
  TFTscreen.background(0, 0, 0);
  TFTscreen.stroke(255, 255, 255);
  TFTscreen.setTextSize(2);
  TFTscreen.text("Heart Rate :\n ", 0, 35);
}

void loop(void)
{

    pox.update();
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        Serial.print("Heart rate:");
        Serial.print(pox.getHeartRate());
        Serial.print("bpm / SpO2:");
        Serial.print(pox.getSpO2());
        Serial.println("%");
        tsLastReport = millis();
    }
    
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
  
// oxy

}
