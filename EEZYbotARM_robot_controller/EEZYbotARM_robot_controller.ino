#include "functionsLibrary.h"


// *** >>> MAIN PROGRAM <<< ***

void setup() {
  initializeServos();
  Serial.begin(115200);
}

void loop() {
  manualMovement();
}
