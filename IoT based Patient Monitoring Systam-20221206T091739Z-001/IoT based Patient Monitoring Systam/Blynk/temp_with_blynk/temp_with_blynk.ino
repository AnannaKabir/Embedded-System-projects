#define BLYNK_TEMPLATE_ID "TMPLeaQLeEjr"
#define BLYNK_DEVICE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "-g3JBVdRBPpzl3dsgOTQKT_L10ZHD0O-"

#define BLYNK_PRINT Serial
//#include <WiFi.h>
//#include <WiFiClient.h>
//#include <BlynkSimpleEsp32.h>
 #include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 13
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "nfc";  // type your wifi name
char pass[] = "789654321";  // type your wifi password

BlynkTimer timer;

void sendSensor()
{
  // Request temperature to all devices on the data line
  sensors.requestTemperatures(); 
  
  Serial.print("Celsius temperature: ");
  //We can connect more than one IC on the same data wire. 0 refers to the first IC on the wire
  Serial.print(sensors.getTempCByIndex(0)); 
  Serial.print(" - Fahrenheit temperature: ");
  Serial.println(sensors.getTempFByIndex(0));
  int tempC=sensors.getTempCByIndex(0);
  int tempF=sensors.getTempFByIndex(0);
  delay(1000);
  
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
    Blynk.virtualWrite(V0, tempC);
    Blynk.virtualWrite(V1, tempF);
    delay(500);
}
void setup()
{   
  
   Serial.begin(9600);
  sensors.begin();

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(100L, sendSensor);
 
  }

void loop()
{
  Blynk.run();
  timer.run();
 }