//Pin
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = LED_BUILTIN;

// variables
long duration;
int distance;
int safetyDistance;


void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}


void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;

  safetyDistance = distance;
  if (safetyDistance <= 60) {
    tone(buzzer, 500);
    digitalWrite(ledPin, HIGH);
  }
  else {
    noTone(buzzer);
    digitalWrite(ledPin, LOW);
  }

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}
