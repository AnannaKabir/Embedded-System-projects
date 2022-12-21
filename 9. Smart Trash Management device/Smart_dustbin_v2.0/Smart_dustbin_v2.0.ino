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
int plasticsensor = 8;
//int anothersensor = A4;
int metalsensor = A0;
int metalsensor_M = A1;
//int irSensor = 8;

Servo myservo; 
Servo myservo_M; 


int pos = 180; 
int pos_M = 180; 

void setup() {
  myservo.attach(11); // attaches the servo on pin 9 to the servo object
  myservo_M.attach(12); // attaches the servo on pin 9 to the servo object
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  //metal sensor
  pinMode(redpin_M, OUTPUT);
  pinMode(bluepin_M, OUTPUT);
  pinMode(greenpin_M, OUTPUT);

  pinMode(plasticsensor, INPUT);
  pinMode(metalsensor, INPUT_PULLUP);
  pinMode(metalsensor_M, INPUT_PULLUP);
  Serial.begin(9600);
  analogWrite(redpin, 255);
  analogWrite(bluepin, 0255);
  analogWrite(greenpin, 255);
  analogWrite(redpin_M, 255);
  analogWrite(bluepin_M, 0255);
  analogWrite(greenpin_M, 255);

}

void loop() {

  int sensor_read = digitalRead(plasticsensor);
  int sensor_read_m = digitalRead(metalsensor);
  int sensor_read_mm = digitalRead(metalsensor_M);
  Serial.println("plastic sensor");
  Serial.println(sensor_read);
  Serial.println("metal sensor");
  Serial.println(sensor_read_m);
  Serial.println(sensor_read_mm);


  //Plastic bin
  if (sensor_read_m == 1) {
    analogWrite(redpin, 0);
    analogWrite(bluepin, 255);
    analogWrite(greenpin, 255);
    delay(2500);
    analogWrite(redpin, 255);
    analogWrite(bluepin, 255);
    analogWrite(greenpin, 255);
  }

  else if ((sensor_read == 0) && (sensor_read_m != 1)) {
    for (pos = 180; pos >= 90; pos -= 1) {
      myservo.write(pos);
      delay(1);
    }
    analogWrite(redpin, 255);
    analogWrite(bluepin, 255);
    analogWrite(greenpin, 0);
    delay(2500);
    for (pos = 90; pos <= 180; pos += 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos); // tell servo to go to position in variable 'pos'
      delay(1); // waits 15ms for the servo to reach the position

    }
    analogWrite(redpin, 0);
    analogWrite(bluepin, 0);
    analogWrite(greenpin, 0);

  }
  else {
    // goes from 180 degrees to 0 degrees
    myservo.write(pos); // tell servo to go to position in variable 'pos'
    // waits 15ms for the servo to reach the position
    analogWrite(redpin, 255);
    analogWrite(bluepin, 255);
    analogWrite(greenpin, 255);

  }

  //metal sensor

  if (sensor_read_mm == 1) {
    for (pos_M = 180; pos_M >= 90; pos_M -= 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo_M.write(pos_M); // tell servo to go to position in variable 'pos'
      delay(1); // waits 15ms for the servo to reach the position
    }
    analogWrite(redpin_M, 255);
    analogWrite(bluepin_M, 0);
    analogWrite(greenpin_M, 255);
    delay(2500);
    for (pos_M = 90; pos_M <= 180; pos_M += 1) { // goes from 180 degrees to 0 degrees
      myservo_M.write(pos_M); // tell servo to go to position in variable 'pos'
      delay(1);
    }
    analogWrite(redpin_M, 0);
    analogWrite(bluepin_M, 0);
    analogWrite(greenpin_M, 0);

  }
  else {            
    // goes from 180 degrees to 0 degrees
    myservo_M.write(pos_M); // tell servo to go to position in variable 'pos'
    // waits 15ms for the servo to reach the position
    analogWrite(redpin_M, 255);
    analogWrite(bluepin_M, 255);
    analogWrite(greenpin_M, 255);

  }

}
