/*
  Motion_Sensor.ino
  -----------------
  Detects motion using a PIR sensor and signals a connected system to start recording.
  Includes a cooldown timer to prevent repeated triggers and an LED for visual feedback.
  Author: Bharath Gowda
*/
// Duration for sensor calibration (in seconds)
int calibrationTime = 15;

// Time when PIR sensor last detected low signal
unsigned long lowIn;

// Delay before considering the motion has stopped (in ms)
unsigned long pause = 5000;

// Control variables for PIR sensor behavior
boolean lockLow = true;
boolean takeLowTime;

// Pin configuration
int pirPin = 13;         // PIR motion sensor output connected to digital pin 13
int ledPin = 31;         // Optional LED indicator connected to digital pin 31

// Cooldown period after motion is detected to avoid repeated triggers (in ms)
unsigned long cooldownPeriod = 10 * 60 * 1000;  // 10 minutes
unsigned long lastMotionTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW); // Ensure PIR pin starts LOW

  // Wait for the PIR sensor to calibrate
  delay(calibrationTime * 1000);
  Serial.println("SENSOR_ACTIVE"); // Log that sensor is now active
  delay(50);
}

void loop() {
  // Motion detected
  if (digitalRead(pirPin) == HIGH) {
    unsigned long currentTime = millis();

    // Only trigger motion response if cooldown has passed
    if (currentTime - lastMotionTime >= cooldownPeriod) {
      if (lockLow) {
        lockLow = false;
        lastMotionTime = currentTime;

        // Notify to start recording (handled by a separate system)
        Serial.println("START_VIDEO");

        // Visual feedback (e.g., turn on LED)
        digitalWrite(ledPin, HIGH);
        delay(50);
      }
      takeLowTime = true;
    }
  }

  // No motion detected
  if (digitalRead(pirPin) == LOW) {
    if (takeLowTime) {
      // Note the time when PIR went LOW
      lowIn = millis();
      takeLowTime = false;
    }

    // If motion has stopped for long enough, reset lock
    if (!lockLow && millis() - lowIn > pause) {
      lockLow = true;

      // Turn off LED (indicating no motion)
      digitalWrite(ledPin, LOW);
      delay(50);
    }
  }
}
