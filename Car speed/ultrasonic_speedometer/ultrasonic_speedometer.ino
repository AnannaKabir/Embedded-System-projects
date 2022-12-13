const int trigPin = 9;
const int echoPin = 10;


long duration;
int distance1 = 0;
int distance2 = 0;
double Speed = 0;
int distance = 0;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode( 7 , OUTPUT);
  Serial.begin(9600);
}

float ultrasonicRead ()
{

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance in cm : ");
  Serial.println(distance);
  return distance;
}

void loop()
{

  distance1 = ultrasonicRead();
  delay(1000);
  distance2 = ultrasonicRead();
  Speed = (distance2 - distance1) / 1.0;


  Serial.print("Speed in km/h :");
  Speed = Speed * 3600; //multiply by seconds per hr
  Speed = Speed / 1000; //division by meters per Km
  //if (Speed > 1) {
    Serial.println(Speed);
  //}



  //  if (distance > 0 && distance < 5)
  //  {
  //    digitalWrite( 7 , HIGH);
  //    delay(50);
  //  }
  //
  //  if (distance > 5 && distance < 10 )
  //  {
  //    digitalWrite( 7 , HIGH);
  //    delay(50);
  //    digitalWrite( 7 , LOW);
  //    delay(50);
  //  }
  //
  //  if (distance > 10 && distance < 20)
  //  {
  //    digitalWrite( 7 , HIGH);
  //    delay(210);
  //    digitalWrite( 7 , LOW);
  //    delay(210);
  //  }
  //
  //  if (distance > 20 && distance < 35)
  //  {
  //    digitalWrite( 7 , HIGH);
  //    delay(610);
  //    digitalWrite( 7 , LOW);
  //    delay(610);
  //  }
}
