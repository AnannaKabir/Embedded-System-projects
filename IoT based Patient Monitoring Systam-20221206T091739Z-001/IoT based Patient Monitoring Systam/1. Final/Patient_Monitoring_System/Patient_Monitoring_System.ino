#define BLYNK_TEMPLATE_ID "TMPLeaQLeEjr"
#define BLYNK_DEVICE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "-g3JBVdRBPpzl3dsgOTQKT_L10ZHD0O-"

#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 13
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);


int x = 0;
#define REPORTING_PERIOD_MS 1000

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "nfc";  
char pass[] = "789654321";
BlynkTimer timer;
void sendSensor()
{
  sensors.requestTemperatures();

  Serial.print("Celsius temperature: ");
  //We can connect more than one IC on the same data wire. 0 refers to the first IC on the wire
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


void setup()
{
  Serial.begin(9600);
  
  pinMode(14, INPUT); // LO +
  pinMode(12, INPUT); // LO -
  
  sensors.begin();
  Blynk.begin(auth, ssid, pass);
  
  timer.setInterval(100L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
