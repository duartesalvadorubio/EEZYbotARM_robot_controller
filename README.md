# EEZYbotARM_robot_controller
 Arduino-based controller for EEZYbotARM robotic arm
 
Simple software controller to manage EEZYbotARM based on ad-hoc control hardware. An Atmega 328p microcontroller programmed using the Arduino environment is used.
The robot is controlled by a Flysky ia6-b radio receiver and a radio control transmitter. It consists of a manual and an automatic operating mode:

- **Manual mode:** For which the radio control and the receiver are used. The user can drive the robot by using the sticks.
- **Automatic mode:** In this mode certain position values are memorized for which the robot must carry out a programmed movement.

The program is structured in the following files:

- **EEZYbotARM_robot_controller:** Main program, makes calls to the following functions
- **functionsLibrary:** Consists of a header file and a source code file. The functions necessary to manage the use of the radio receiver and the handling of the robot's servos are collected.

Images: // TO ADD
