#define IR 2
int reading;
int count = 0;
boolean state = true;

void setup() {
  Serial.begin(9600);
}

void loop() 
{
    reading = digitalRead(IR);
    
    if (!(reading && state)){  

    count++;  
    state = false;  
    Serial.print("Count: ");  
    Serial.println(count);
    Serial.print("After Condition Reading =");
    Serial.println(reading);
    }  
      if (digitalRead(IR))  
  { 
    state = true;  
    delay(100);  
  }  
}
