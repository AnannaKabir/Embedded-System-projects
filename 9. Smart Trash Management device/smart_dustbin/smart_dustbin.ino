//#define REFLECTIVEIR_PIN_COLL A2
//#define REFLECTIVEIR_PIN_COLL_M A3

// define vars for testing menu
const int timeout = 10000; //define timeout of 10 sec
char menuOption = 0;
long time0;

#include <Servo.h>
#define redpin 2
#define bluepin 4
#define greenpin 3
#define redpin_M 7
#define bluepin_M 5
#define greenpin_M 6
//int plasticsensor = A5;
//int anothersensor = A4;
int metalsensor = A0;
int metalsensor_M = A1;
int irSensor = 8;

Servo myservo;
Servo myservo_M;


int pos = 165;
int pos_M = 158;

void setup() {
  myservo.attach(11);
  myservo_M.attach(12);
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(irSensor, INPUT);
  //metal sensor
  pinMode(redpin_M, OUTPUT);
  pinMode(bluepin_M, OUTPUT);
  pinMode(greenpin_M, OUTPUT);

  pinMode(metalsensor, INPUT_PULLUP);
  pinMode(metalsensor_M, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {

  int sensor_read = digitalRead(irSensor);
  int sensor_read_m = digitalRead(metalsensor);
  int sensor_read_mm = digitalRead(metalsensor_M);
  Serial.println("IR Sensor");
  Serial.println(sensor_read);
  Serial.println("metal sensor1");
  Serial.println(sensor_read_m);
  Serial.println("metal sensor2");
  Serial.println(sensor_read_mm);


  //Plastic bin
  if (sensor_read_m == 1) {
    myservo.write(pos);
    digitalWrite(redpin, HIGH);
    digitalWrite(bluepin, LOW);
    digitalWrite(greenpin, LOW);

  }

  else if ((sensor_read_m == 0) && (sensor_read == 0)) {
    for (pos = 160; pos >= 90; pos -= 1) {
      myservo.write(pos);
      delay(1);
    }
    digitalWrite(redpin, LOW);
    digitalWrite(bluepin, LOW);
    digitalWrite(greenpin, HIGH);
    delay(2500);
    for (pos = 90; pos <= 160; pos += 1) {
      myservo.write(pos);
      delay(1);
    }
    digitalWrite(redpin, LOW);
    digitalWrite(bluepin, LOW);
    digitalWrite(greenpin, LOW);

  }
  else {
    myservo.write(pos);
    digitalWrite(redpin, LOW);
    digitalWrite(bluepin, LOW);
    digitalWrite(greenpin, LOW);
  }

  //metal sensor

  if (sensor_read_mm == 1) {
    for (pos_M = 160; pos_M >= 90; pos_M -= 1) {
      myservo_M.write(pos_M);
      delay(1);
    }
    digitalWrite(redpin_M, HIGH);
    digitalWrite(bluepin_M, LOW);
    digitalWrite(greenpin_M, HIGH);
    delay(2500);
    for (pos_M = 90; pos_M <= 160; pos_M += 1) {
      myservo_M.write(pos_M);
      delay(1);

    }
    digitalWrite(redpin_M, LOW);
    digitalWrite(bluepin_M, LOW);
    digitalWrite(greenpin_M, LOW);

  }

  else {

    myservo_M.write(pos_M);
    digitalWrite(redpin_M, HIGH);
    digitalWrite(bluepin_M, HIGH);
    digitalWrite(greenpin_M, HIGH);

  }

}
