// Libraries
#include <Servo.h>
#include "Arduino.h"

// Potentiometer pinin
int potPin1 = A0;
int potPin2 = A1;
int potPin3 = A2;
int potPin4 = A3;

// Potentiometer values variables
int potValue1;
int potValue2;
int potValue3;
int potValue4;

// Servo instanciate
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;


// Functions
void manualMovement() {

  potValue1 = analogRead(potPin1);            // Analog value between 0 - 1023
  potValue1 = map(potPin1, 0, 1023, 0, 180);  // Map to servo-motor available angle range
  servo1.write(potValue1);

  potValue2 = analogRead(potPin2);
  potValue2 = map(potValue2, 0, 1023, 0, 180);
  servo2.write(potValue2);

  potValue3 = analogRead(potPin3);
  potValue3 = map(potValue3, 0, 1023, 0, 180);
  servo3.write(potValue3);

  potValue4 = analogRead(potPin4);
  potValue4 = map(potValue4, 0, 1023, 0, 180);
  servo4.write(potValue4);

  // Potentiometer values serial printing  
  Serial.println(potValue1);
  Serial.println(potValue2);
  Serial.println(potValue3);
  Serial.println(potValue4);
  Serial.println(" ");

}

void initializeServos() {
  // Servo pinout
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(11);
}