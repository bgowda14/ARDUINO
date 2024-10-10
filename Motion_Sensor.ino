int calibrationTime = 15;        
unsigned long lowIn;         
unsigned long pause = 5000;  
boolean lockLow = true;
boolean takeLowTime;  
int pirPin = 13;    
int ledPin = 31;
unsigned long cooldownPeriod = 10 * 60 * 1000;  
unsigned long lastMotionTime = 0;

void setup(){
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);

  // Give the sensor some time to calibrate
  delay(calibrationTime * 1000); // Calibrate sensor for the specified time
  Serial.println("SENSOR_ACTIVE");
  delay(50);
}

void loop(){
  if(digitalRead(pirPin) == HIGH){
    unsigned long currentTime = millis();
    if (currentTime - lastMotionTime >= cooldownPeriod) {
      if(lockLow){  
        lockLow = false;            
        lastMotionTime = currentTime; 
        Serial.println("START_VIDEO"); // Signal to start video capture
        digitalWrite(ledPin, HIGH);    // Turn on the LED
        delay(50);
      }         
      takeLowTime = true;
    }
  }

  if(digitalRead(pirPin) == LOW){       
    if(takeLowTime){
      lowIn = millis();          
      takeLowTime = false;       
    }
    
    if(!lockLow && millis() - lowIn > pause){  
      lockLow = true;                        
      digitalWrite(ledPin, LOW);    // Turn off the LED
      delay(50);
    }
  }
}
