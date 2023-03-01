#include "functionsLibrary.h"

// Main program variables
unsigned long tiempo;
unsigned long tiempoant;



// *** >>> MAIN PROGRAM <<< ***

void setup() {
  servoInitialize();
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
