#define BLYNK_TEMPLATE_ID "TMPLeaQLeEjr"
#define BLYNK_DEVICE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "-g3JBVdRBPpzl3dsgOTQKT_L10ZHD0O-"

#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "MAX30100_PulseOximeter.h"

//temp
#define ONE_WIRE_BUS 13
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int x = 0;
#define REPORTING_PERIOD_MS 1000

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "nfc";  // type your wifi name
char pass[] = "789654321";

PulseOximeter pox;
float BPM, SpO2;
uint32_t tsLastReport = 0;

BlynkTimer timer;

void onBeatDetected()
{
  Serial.println("Beat Detected!");
}

void sendSensor()
{
  sensors.requestTemperatures();

  Serial.print("Celsius temperature: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print(" - Fahrenheit temperature: ");
  Serial.println(sensors.getTempFByIndex(0));
  int tempC = sensors.getTempCByIndex(0);
  int tempF = sensors.getTempFByIndex(0);
  delay(1000);
  if ((digitalRead(10) == 1) || (digitalRead(11) == 1)) {
    Serial.println('!');
  }
  else {
    x = analogRead(A0);
    Blynk.virtualWrite(V4, x);
    Serial.println(x);
  }
  delay(1);
  Blynk.virtualWrite(V0, tempC);
  Blynk.virtualWrite(V1, tempF);
  delay(1);
}

void oxymeter() {



  if (millis() - tsLastReport > REPORTING_PERIOD_MS)
  {
    BPM = pox.getHeartRate();
    SpO2 = pox.getSpO2();
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

void setup()
{
  Serial.begin(115200);
  pinMode(16, OUTPUT); // max30100
  pinMode(14, INPUT); // LO +
  pinMode(12, INPUT); //LO -
  sensors.begin();
  Blynk.begin(auth, ssid, pass);

  Serial.print("Initializing Pulse Oximeter..");

  if (!pox.begin())
  {
    Serial.println("FAILED");
    for (;;);
  }

  else
  {
    pox.setOnBeatDetectedCallback(onBeatDetected);
  }

  timer.setInterval(100L, sendSensor);
}

void loop() {
  pox.update();
  Blynk.run();
  oxymeter();
  timer.run();
}
