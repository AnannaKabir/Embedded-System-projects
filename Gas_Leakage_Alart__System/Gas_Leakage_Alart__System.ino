int MQ2 = A0;
int Red_Led = 16;
int Green_Led = 5;
int Buzzer = 4;
int Sensor_Threshold = 300;
 
void setup() {
  pinMode(Red_Led, OUTPUT);
  pinMode(Green_Led, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(MQ2, INPUT); 
  Serial.begin(9600);
  Serial.println("Gas sensor warming up!");
  delay(20000); 
}

void loop() {
  int analogSensor = analogRead(MQ2);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > Sensor_Threshold)
  {
    digitalWrite(Red_Led, HIGH);
    digitalWrite(Green_Led, LOW);
    tone(Buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(Red_Led, LOW);
    digitalWrite(Green_Led, HIGH);
    noTone(Buzzer);
  }
  delay(100);
}
