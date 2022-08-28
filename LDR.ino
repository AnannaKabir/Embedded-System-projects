    int LED = 2;  
    int LDR = A0;  
        
    void setup() {  
        
      Serial.begin(9600);  
      pinMode(LED, OUTPUT);  
    }  
    void loop() {  
      int sensorStatus = analogRead(LDR);  
      if (sensorStatus <200)  
      {  
        digitalWrite(LED, HIGH);  
        Serial.println(" LED is ON, Night_Mode");  
      }  
      else  
      {  
        digitalWrite(LED, LOW);  
        Serial.println("LED is OFF, DayLight");  
      }  
    }   
