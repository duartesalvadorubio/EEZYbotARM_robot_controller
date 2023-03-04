# EEZYbotARM_robot_controller

 
Simple software controller to manage [EEZYbotARM](http://www.eezyrobots.it/eba_mk1.html) based on ad-hoc control hardware. 

# Overview

An experimental development of a hardware control board using an Atmega 328p microcontroller is carried out. An RC transmitter and a Flysky ia6-b receiver are used as controllers for the robot. The hardware board developed has the specific connections for the servos and the receiver, and is programmed using the Arduino environment.

# Program description

The program consists of a manual and an automatic operating mode:

- **Manual mode:** For which the radio control and the receiver are used. The user can drive the robot by using the sticks.
- **Automatic mode:** In this mode certain position values are memorized for which the robot must carry out a programmed movement.

The program is structured in the following files:

- **EEZYbotARM_robot_controller:** Main program, makes calls to the control functions.
- **functionsLibrary:** Consists of a header file and a source code file. The functions necessary to manage the use of the radio receiver and the handling of the robot's servos are collected.

# Project images

[EEZYbot](http://www.eezyrobots.it/eba_mk1.html) robot overview:
![IMG20230304112418](https://user-images.githubusercontent.com/101353583/222894825-264cf9d8-dfaf-4af0-85ff-ef5ef23a4ca7.jpg)


Ad-hoc microcontroller hardware:
![IMG20230304112343](https://user-images.githubusercontent.com/101353583/222894836-53b918ae-918d-495d-a2f2-5c804579b1cc.jpg)

Ad-hoc potentiometer controls:
![IMG20230304112242](https://user-images.githubusercontent.com/101353583/222894841-26846e92-9ce2-479d-b606-66e5f75254b2.jpg)
