const int timeout = 10000; //define timeout of 10 sec
char menuOption = 0;
long time0;

#include <Servo.h>

//Plastic bin pinouts
#define redpin 2
#define greenpin 3
#define bluepin 4
int plasticsensor = 8;
int metalsensor = A2;
int IR_Plastic = 10;
int IR_Metal = 9;
Servo myservo;
int pos = 180;


//Metal bin pinouts
#define greenpin_M 5
#define bluepin_M 6
#define redpin_M 7
int metalsensor_M = A1;
Servo myservo_M;
int pos_M = 180;



void setup() {

  //Plastic bin
  myservo.attach(11); 
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);

  pinMode(IR_Plastic, INPUT);//For Trash amount
  pinMode(plasticsensor, INPUT);//IR for object detection
  pinMode(metalsensor, INPUT_PULLUP);//Inductive Proximity Sensors "NPN"

  //etal bin
  myservo_M.attach(12); 
  pinMode(redpin_M, OUTPUT);
  pinMode(bluepin_M, OUTPUT);
  pinMode(greenpin_M, OUTPUT);

  pinMode(IR_Metal , INPUT);//For Trash amount
  pinMode(metalsensor_M, INPUT_PULLUP);//Inductive Proximity Sensors "PNP"

  Serial.begin(9600);

  //LED LOW
  analogWrite(redpin, 255);
  analogWrite(bluepin, 0255);
  analogWrite(greenpin, 255);
  analogWrite(redpin_M, 255);
  analogWrite(bluepin_M, 0255);
  analogWrite(greenpin_M, 255);
}

void loop() {

  //Plastic Bin
  int sensor_read = digitalRead(plasticsensor);
  int sensor_read_m = digitalRead(metalsensor);
  int ir_p = digitalRead(IR_Plastic);
  
  //Metal Bin
  int sensor_read_mm = digitalRead(metalsensor_M);
  int ir_m = digitalRead(IR_Metal);

  Serial.println("plastic sensor");
  Serial.println(sensor_read);

  Serial.println("Plastic bin metal sensor value: ");
  Serial.println(sensor_read_m);

  Serial.println("Metal bin metal sensor value:");
  Serial.println(sensor_read_mm);

  //Plastic bin
  if (sensor_read_m == 0) {
    analogWrite(redpin, 0);
    analogWrite(bluepin, 255);
    analogWrite(greenpin, 255);
    delay(2500);
    analogWrite(redpin, 255);
    analogWrite(bluepin, 255);
    analogWrite(greenpin, 255);
  }

  else if ((sensor_read == 0) && (sensor_read_m != 0)) {
    for (pos = 180; pos >= 90; pos -= 1) {
      myservo.write(pos);
      delay(1);
    }
    analogWrite(redpin, 255);
    analogWrite(bluepin, 255);
    analogWrite(greenpin, 0);
    delay(2500);
    for (pos = 90; pos <= 180; pos += 1) {
      myservo.write(pos); // tell servo to go to position in variable 'pos'
      delay(1);

    }
    analogWrite(redpin, 0);
    analogWrite(bluepin, 0);
    analogWrite(greenpin, 0);

  }
  else if (ir_p == 0)
  {
    myservo.write(pos);
    analogWrite(redpin, 255);
    analogWrite(bluepin, 0);
    analogWrite(greenpin, 255);
  }

  else {

    myservo.write(pos); // tell servo to go to position in variable 'pos'
    analogWrite(redpin, 255);
    analogWrite(bluepin, 255);
    analogWrite(greenpin, 255);

  }


  //metal sensor

  if (sensor_read_mm == 1) {
    for (pos_M = 180; pos_M >= 90; pos_M -= 1) { 
      // in steps of 1 degree
      myservo_M.write(pos_M); // tell servo to go to position in variable 'pos'
      delay(1); 
    }
    analogWrite(redpin_M, 255);
    analogWrite(bluepin_M, 255);
    analogWrite(greenpin_M, 0);// Green Led On
    delay(2500);
    for (pos_M = 90; pos_M <= 180; pos_M += 1) { 
      myservo_M.write(pos_M); // tell servo to go to position in variable 'pos'
      delay(1);
    }
    analogWrite(redpin_M, 0);
    analogWrite(bluepin_M, 0);
    analogWrite(greenpin_M, 0);

  }
  else if (ir_m == 0)
  {
    analogWrite(redpin_M, 255);
    analogWrite(bluepin_M, 0); // Blue Led On
    analogWrite(greenpin_M, 255);
  }
  else {
    myservo_M.write(pos_M);
    analogWrite(redpin_M, 255);
    analogWrite(bluepin_M, 255);
    analogWrite(greenpin_M, 255);
  }
}
