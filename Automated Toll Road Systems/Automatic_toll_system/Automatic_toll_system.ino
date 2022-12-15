#include <Servo.h>
#define echo A1
#define trigger A2                                                                                                                                                     //Trigger pin
#define Recheck A5

#define G_led 8 // choose the pin for the Green Led
#define R_led 9 // choose the pin for the Red Led
#define buz 6 // choose the pin for the Buzzer

Servo myservo;
int pos = 0; 
// defines variables
float Speed = 0, distance = 0, Time = 0;
int flag1 = 0, flag2 = 0;
int time1, time2;

// Other configuration
const unsigned int BEEP_FREQUENCY = 3000;

void setup() {
  Serial.begin(9600);
  myservo.attach(11);
  pinMode(Recheck, INPUT_PULLUP);
  pinMode(echo, INPUT );// declare ultrasonic sensor Echo pin as input
  pinMode(trigger, OUTPUT); // declare ultrasonic sensor Trigger pin as Output
  pinMode(R_led, OUTPUT); // declare Red LED as output
  pinMode(G_led, OUTPUT); // declare Green LED as output
  pinMode(buz, OUTPUT);  // declare Buzzer as output

  Serial.print(" Vehicle  Speed ");
  Serial.println("   Measurement  ");
  delay(2000);
}

void ultrasonicRead() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  long time = pulseIn(echo, HIGH);
  distance = time / 28.5 / 2;
}

void loop() {
  ultrasonicRead(); 

  if (distance <= 30 && flag1 == 0) {
    time1 = millis();
    flag1 = 1;
  }
  if (distance <= 20 && flag2 == 0) {
    time2 = millis();
    flag2 = 1;
  }

  if (flag1 == 1 && flag2 == 1) {
    flag1 = 2, flag2 = 2;
    if (time1 > time2) {
      Time = time1 - time2;
    }
    else if (time2 > time1) {
      Time = time2 - time1;
    }
    Time = Time / 1000; //convert millisecond to second
    Speed = (10 / Time); //v=d/t cm/s
    Speed = Speed * 3600; //multiply by seconds per hr
    Speed = Speed / 1000; //division by meters per Km
    
    Serial.println(Speed);
    Serial.print("Speed Km/Hr ");
    
    digitalWrite(R_led, 0);
    digitalWrite(G_led, 1);
    for (pos = 25; pos <= 160; pos += 1) { // goes from 0 degrees to 180 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(20);                       // waits 15ms for the servo to reach the position
    }
    tone(buz, BEEP_FREQUENCY, 200);  // Beep when done
  }

  if (digitalRead(Recheck) == 0) {
    Speed = 0;
    flag1 = 0, flag2 = 0;
    delay(50);
    digitalWrite(R_led, 1);
    digitalWrite(G_led, 0);
    
    for (pos = 160; pos >= 25; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(20); 
    }
    
    tone(buz, BEEP_FREQUENCY, 400);  // Beep when done
    delay(2000);
  }

}
