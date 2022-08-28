    int LDR = A0;  
       
    void setup() {  
      Serial.begin(9600);  
      pinMode(LDR, INPUT);  
    }  
    
    void loop() {  
      int sensorValue = analogRead(LDR);  
      Serial.print("Sensor Value =");
      Serial.println(sensorValue);
    }   
