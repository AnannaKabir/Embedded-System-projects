#include "DHTesp.h" // Click here to get the library: http://librarymanager/All#DHTesp
DHTesp dht;
#define MQ_135_Pin  A0
int MQ_135_Value;
void setup()
{
  Serial.begin(115200);
  Serial.println();
Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)\t Air Pollution (PPM)\t" );

  dht.setup(16, DHTesp::DHT11); // Connect DHT sensor to GPIO 17
}

void loop()
{
  delay(2000);
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
  MQ_135_Value= analogRead(MQ_135_Pin);
  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity);
  Serial.print("\t\t");
  Serial.print(temperature);
  Serial.print("\t\t");
  Serial.print(dht.toFahrenheit(temperature));
  Serial.print("\t\t");
  Serial.print(MQ_135_Value);
  Serial.println("\t\t");
  delay(2000);
}
