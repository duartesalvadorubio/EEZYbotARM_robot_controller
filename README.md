# EEZYbotARM_robot_controller

 
Simple software controller to manage [EEZYbotARM](http://www.eezyrobots.it/eba_mk1.html) based on ad-hoc control hardware. 

# Overview

The code presented here is part of a mechatronics project, in which a [EEZYbotARM](http://www.eezyrobots.it/eba_mk1.html) robot has been 3D printed and mounted. All the electronics have been assembled and a hardware controller has been developed ad-hoc to manage the robot.
This control board has an Atmega 328p microcontroller integrated in a socket and soldered on a prototyping board. On this board, the rest of the necessary electronic components and the necessary connections to control all the servos of the robot have been included. To program the microcontroller, the [Arduino](https://www.arduino.cc/) environment has been used.

The embedded program used in this control board has two versions:
- **EEZYbotARM_robot_controller:** This uses a control panel developed using potentiometers, by means of which the user can control the different articulations of the robot. This is the simplest type of operation.
- **EEZYbotARM_robot_controller_RC:** The potentiometer panel is replaced by a Flysky ia6b radio control receiver, which allows the robot to be operated from a greater distance and also includes an automatic operating mode in this programme.


An experimental development of a hardware control board using an Atmega 328p microcontroller is carried out. An RC transmitter and a Flysky ia6-b receiver are used as controllers for the robot. The hardware board developed has the specific connections for the servos and the receiver, and is programmed using the Arduino environment.

# EEZYbotARM_robot_controller
## Program description

This is actually a very simple program that reads the voltage values dropped on each potentiometer by means of the analog-to-digital converter of the microcontroller. It then maps these measurements to a certain setpoint value for the servomotors of each joint.
The program is structured in the following files:

- **EEZYbotARM_robot_controller:** Main program, makes calls to the control functions.
- **functionsLibrary:** Consists of a header file and a source code file. The functions necessary to manage the use of the potentiometers and the handling of the robot's servos.


# EEZYbotARM_robot_controller_RC

## Program description

This program is intended for use with the RC receiver. In this case it has a larger number of inputs and one of the switches on the remote control can be assigned to change the operating mode.

The program consists of a manual and an automatic operating mode:

- **Manual mode:** For which the radio control and the receiver are used. The user can drive the robot by using the sticks.
- **Automatic mode:** In this mode certain position values are memorized for which the robot must carry out a programmed movement.

The program is structured in the following files:

- **EEZYbotARM_robot_controller_RC:** Main program, makes calls to the control functions.
- **functionsLibrary:** Consists of a header file and a source code file. The functions necessary to manage the use of the radio receiver and the handling of the robot's servos are collected.

# Project images

[EEZYbot](http://www.eezyrobots.it/eba_mk1.html) robot overview:
![IMG20230304112418](https://user-images.githubusercontent.com/101353583/222894825-264cf9d8-dfaf-4af0-85ff-ef5ef23a4ca7.jpg)


Ad-hoc microcontroller hardware:
![IMG20230304112343](https://user-images.githubusercontent.com/101353583/222894836-53b918ae-918d-495d-a2f2-5c804579b1cc.jpg)

Ad-hoc potentiometer controls:
![IMG20230304112242](https://user-images.githubusercontent.com/101353583/222894841-26846e92-9ce2-479d-b606-66e5f75254b2.jpg)
