#include <DHT.h>

#define sensor    A0 
#define DHTPIN A2          
#define DHTTYPE DHT11     // DHT 11

int gasLevel = 0;         //int variable for gas level
String quality =""; 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  dht.begin();
}

void sendSensor()
{
  float h = dht.getHumidity();
  float t = dht.getTemperature();

  Serial.print("Temperature:");
  Serial.print(t);
  Serial.println("C");
  Serial.print("Humidity :");
  Serial.print(h);
  Serial.println("%");
  Serial.println(" ");
}

void air_sensor()
{
  gasLevel = analogRead(sensor);
  if(gasLevel<33)
  {
    quality = " Very  GOOD!";
  }
  else if(gasLevel> 100 && gasLevel<250){
    quality = "Fresh Air";
  }
  else if(gasLevel> 251 && gasLevel<320){
    quality = "Fair!";
  }
  else if (gasLevel >321 && gasLevel<500){
    quality ="Poor Air";
  }
    else if (gasLevel >200){
    quality = "Highly polluted air";
  } 

  Serial.print("Air Quality:");
  Serial.println(quality); 
}


void loop() 
{
air_sensor();
sendSensor();
delay(2000);  
}
