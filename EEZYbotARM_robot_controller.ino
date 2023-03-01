#include "functionsLibrary.h"

// Main program variables
unsigned long tiempo;
unsigned long tiempoant;



// *** >>> MAIN PROGRAM <<< ***

void setup() {
  //Pines de los servos
  servo1.attach(6);
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);

  Serial.begin(9600);
}

void loop() {
  // Time differenciation
  tiempo = millis() - tiempoant;
  tiempoant = millis();

  //Function calling
  getPulseWide();
  modeEvolution();
  manualMovement();
  autoMovement();
  visualization();

}
