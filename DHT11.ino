#include "DHTesp.h" // Click here to get the library: https://github.com/beegee-tokyo/DHTesp
DHTesp dht;

void setup()
{
  Serial.begin(115200);
  Serial.println();

Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)\t");
  dht.setup(A2, DHTesp::DHT11); // Connect DHT sensor to GPIO 17
}

void loop() {
  delay(2000);
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity);
  Serial.print("\t\t");
  Serial.print(temperature);
  Serial.print("\t\t");
  Serial.print(dht.toFahrenheit(temperature));
  Serial.println("\t\t");
}
