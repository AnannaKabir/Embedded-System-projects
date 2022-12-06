#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include <TFT.h>
#include <SPI.h>
#include <Wire.h>

#define REPORTING_PERIOD_MS     1000
#define cs   10
#define dc   9
#define rst  8
//char HR[30];
//char OR[30];
// Create a PulseOximeter object
PulseOximeter pox;

// Time at which the last beat occurred
uint32_t tsLastReport = 0;

//Display
TFT TFTscreen = TFT(cs, dc, rst);


// Callback routine is executed when a pulse is detected
void onBeatDetected() {
  Serial.println("Beat!");
}

void setup() {
  Serial.begin(115200);

  TFTscreen.begin();
  TFTscreen.background(0, 0, 0);
  TFTscreen.stroke(255, 255, 255);
  TFTscreen.setTextSize(1);
  TFTscreen.text("Heart Rate :", 0, 0);
  TFTscreen.setTextSize(2);
  //TFTscreen.text("Spo2 :", 0, 10);

  Serial.print("Initializing pulse oximeter..");
  // Initialize sensor
  if (!pox.begin()) {
    Serial.println("FAILED");
    for (;;);
  } else {
    Serial.println("SUCCESS");
  }

  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
  pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop() {

    pox.update();
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        Serial.print("Heart rate:");
        Serial.print(pox.getHeartRate());
        Serial.print("bpm / SpO2:");
        Serial.print(pox.getSpO2());
        Serial.println("%");
        tsLastReport = millis();
    }
}
