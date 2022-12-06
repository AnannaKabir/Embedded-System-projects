//Viral Science www.youtube.com/c/viralscience  www.viralsciencecreativity.com
//Pulse Heart Rate BPM and Oxygen SpO2 Monitor
#define BLYNK_TEMPLATE_ID "TMPLeaQLeEjr"
#define BLYNK_DEVICE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "-g3JBVdRBPpzl3dsgOTQKT_L10ZHD0O-"

#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 
#define REPORTING_PERIOD_MS 1000
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "nfc";  // type your wifi name
char pass[] = "789654321";  // type your wifi password
 
// Connections : SCL PIN - D1 , SDA PIN - D2 , INT PIN - D0
PulseOximeter pox;
 
float BPM, SpO2;
uint32_t tsLastReport = 0;

void onBeatDetected()
{
    Serial.println("Beat Detected!");
}
 
void setup()
{
    Serial.begin(115200);
    
    pinMode(16, OUTPUT);
    Blynk.begin(auth, ssid, pass);
 
    Serial.print("Initializing Pulse Oximeter..");
 
    if (!pox.begin())
    {
         Serial.println("FAILED");
         for(;;);
    }
    else
    {
         pox.setOnBeatDetectedCallback(onBeatDetected);
    }
 
    // The default current for the IR LED is 50mA and it could be changed by uncommenting the following line.
     //pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
 
}
 
void loop()
{
    pox.update();
    Blynk.run();
 
    BPM = pox.getHeartRate();
    SpO2 = pox.getSpO2();
    if (millis() - tsLastReport > REPORTING_PERIOD_MS)
    {
        Serial.print("Heart rate:");
        Serial.print(BPM);
        Serial.print(" SpO2:");
        Serial.print(SpO2);
        Serial.println(" %");
 
        Blynk.virtualWrite(V2, BPM);
        Blynk.virtualWrite(V3, SpO2);
 
        tsLastReport = millis();
    }
}
