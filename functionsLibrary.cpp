//Libraries
//#include <Servo.h>
#include "Arduino.h"
#include "functionsLibrary.h"


// FS IA6B Pin in
const int pinch1 = A1;//Rota la torre. Servo 1
const int pinch2 = A2;//Eslabon 1. Servo 2
const int pinch3 = A3;//Mueve la pinza. Servo 3
const int pinch4 = A4;//Eslabon 2. Servo 4
const int pinch5 = A5;//Selecciona velocidad. Pensado en usar VrA
const int pinch6 = A0; //Selecciona el modo. Pensado en usar SwC

//Variables
int ch1, ch2, ch3, ch4, ch5, ch6; // Pulse wide for each channel
int i1 = 90, i2 = 90, i3 = 0, i4 = 90;// Servo angle counter
int speed; // Turning angle variation difference 

int modo = 0; // Working mode variable: 0: Stop / 1: Manual / 2: Automatic

//Variables auto mode
int state;
int vel1 = 15;
int vel2 = 15;
int vel3 = 50;
int vel4 = 15;


//Standard servo library
/*Servo servo1;//Nombre de mi servo. Pin 6
  Servo servo2;//Pin 9
  Servo servo3;//Pin 10
  Servo servo4;//pin 11*/

//Speed-controlling servo library
VarSpeedServo servo1;//Nombre de mi servo. Pin 6
VarSpeedServo servo2;//Nombre de mi servo. Pin 9
VarSpeedServo servo3;//Nombre de mi servo. Pin 10
VarSpeedServo servo4;//Nombre de mi servo. Pin 11


// *** >>> FUNCTIONS <<< ***

void getPulseWide(){
    //Obtención del ancho de pulso de cada canal
    ch1 = pulseIn(pinch1, HIGH);//Rotates the tower. Servo 1
    ch2 = pulseIn(pinch2, HIGH);//Eslabon 1. Servo 2
    ch3 = pulseIn(pinch3, HIGH);//Gripper actuation. Servo 3
    ch4 = pulseIn(pinch4, HIGH);//Eslabon 2. Servo 4
    ch5 = pulseIn(pinch5, HIGH); //Speed selection. Intended for VrA switch
    ch6 = pulseIn(pinch6, HIGH); //Mode selection. Intended for SwC switch
}



void modeEvolution() {
  switch (modo) { //0: Stop / 1: Manual / 2: Auto

    case 0: //Modo Stop
      if (ch6 > 1400 and ch6 < 1600) {
        modo = 1;
      }
      if (ch6 > 1700) {
        modo = 2;
      }
      break;

    case 1: //Modo Manual
      if (ch6 < 1200) {
        modo = 0;
      }
      if (ch6 > 1700) {
        modo = 2;
      }
      break;

    case 2: //Modo Auto
      if (ch6 > 1400 and ch6 < 1600) {
        modo = 1;
      }
      if (ch6 < 1200) {
        modo = 0;
      }
      break;

  }
}



void manualMovement() {
  if (modo == 1) {

    speed = map(ch5, 994, 1990, 0, 15); //Channel 5 linked to VRA in the rc-transmitter. Pulse is mapped for adequate speed value.

    if (i1 < 180) {
      if (ch1 < 1400) {
        i1 = i1 + speed ;
        servo1.write(i1);
      }
    }

    if (i1 > 0) {
      if (ch1 > 1600) {
        i1 = i1 - speed;
        servo1.write(i1);
      }
    }

    if (i2 < 180) {
      if (ch2 > 1600) {
        i2 = i2 + speed ;
        servo2.write(i2);
      }
    }

    if (i2 > 0) {
      if (ch2 < 1400) {
        i2 = i2 - speed;
        servo2.write(i2);
      }
    }

    if (i4 < 180) {
      if (ch4 < 1400 ) {
        i4 = i4 + speed ;
        servo4.write(i4);
      }
    }

    if (i4 > 0) {
      if (ch4 > 1600) {
        i4 = i4 - speed;
        servo4.write(i4);
      }
    }

    i3 = map(ch3, 994, 1993, 0, 180); //Directly using the stick value (not auto-centered in rc-transmitter)

    servo3.write(i3); 

  }

  //Servo position print to prepare Auto mode
  Serial.print(i1);
  Serial.print(" ; ");
  Serial.print(i2);
  Serial.print(" ; ");
  Serial.print(i3);
  Serial.print(" ; ");
  Serial.println(i4);
}


void autoMovement() {
  if (modo == 2) {

    //Auto mode instructions
    //The idea is to look for positions in manual mode by looking at them through the serial. Then here I will make a series of positions with some delays to go little by little.
    //For timings, instead of delay I can use a time difference with an if and a previous millis and millis, so that it will be en tiempo real y poder cambiar de modo al darle al switch

    switch (state) {

      case  0 :
        //Posición 1 (25, 90, 0, 90)
        servo3.write(0, vel3, true);
        servo2.write(90, vel2, true);
        servo4.write(90, vel4, true);
        servo1.write(25, vel1, true);
        state = 1;
        break;

      case 1 :
        //Posición 2 (25, 150, 0, 40)
        servo2.write(150, vel2);
        servo4.write(40, vel4);
        servo2.wait(); servo4.wait();
        break;

      case 2 :
        //Posición 3 (25, 150, 175, 40)
        servo3.write(75, vel3, true);
        break;

      case 3 :
        //Posición 4 (25, 165, 175, 55)
        servo2.write(165, vel2);
        servo4.write(55, vel4);
        servo2.wait(); servo4.wait();
        break;

      case 4 :
        //Posición 5 (25, 165, 0, 55)
        servo3.write(0, vel3, true);
        break;

      case 5 :
        //Posición 6 (25, 165, 0, 90)
        servo4.write(90, vel4, true);
        break;

      case 6 :
        //Posición 7 (25, 125, 0. 90)
        servo2.write(125, vel2, true);
        break;

      case 7 :
        //Posición 8 (100, 125, 0, 90)
        servo1.write(100, vel1, true);
        break;

      case 8 :
        //Posición 9 (100, 120, 0, 75)
        servo2.write(120, vel2);
        servo4.write(75, vel4);
        servo2.wait(); servo4.wait();
        break;

      case 9:
        //Posición 10 (100, 120, 175, 75
        servo3.write(75, vel3, true);
        break;

      case 10:
        //Posición 11 (100, 120, 0, 75)
        servo3.write(0, vel3, true);
        break;

      case 11 :
        //Posición 12 (50, 90, 0, 90)
        servo2.write(90, vel2);
        servo4.write(90, vel4);
        servo2.wait(); servo4.wait();
        servo1.write(50, vel1, true);
        break;

    }
  }
}


void visualization () {
  if (modo == 0) {
    Serial.println("STOP");
  }

  if (modo == 1) {
    Serial.println("MANUAL");
  }

  if (modo == 2) {
    Serial.println("AUTO");
    // Idea: LED 13 on?
  }

}
