#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#define SS_PIN 10//ESP-D8-15
#define RST_PIN 9 //D0-16

MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
MFRC522::MIFARE_Key key;
String tag;


int servoPin = 4;
Servo servo; // create servo object to control a servo
int angle = 0;  // servo position in degrees

void setup() {
  Serial.begin(115200);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522
  servo.attach(servoPin);

}
void loop() {
  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if (rfid.PICC_ReadCardSerial()) {
    for (byte i = 0; i < 4; i++) {
      tag += rfid.uid.uidByte[i];
    }
    Serial.println(tag);
    if (tag == "153217234110") {
      Serial.println("Access Granted!");
        angle=180;
        servo.write(angle);
        Serial.println("Welcome Ananna! The Door is open. Plese enter within 5s");
        delay(5000);
        angle=0;
        servo.write(angle);
        Serial.println("Door Closed");
    }else {
      Serial.println("Access Denied!");
    }
    tag = "";
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }
}
