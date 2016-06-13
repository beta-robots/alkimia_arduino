#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "Arduino.h"

//general purpose and config constants
int SERIAL_BAUD_RATE = 9600;
int PIN_LED_HEART_BEAT = 13; 

//Main Loop delay periods
int MAIN_LOOP_PERIOD_STOP = 1000; //1Hz
int MAIN_LOOP_PERIOD_RUN = 50; //25Hz

//Motor driver wiring
int PIN_MOTOR_PWM = 9; 
int PIN_MOTOR_DIRECTION = 8; 

//User buttons wiring & constants
int PIN_HUMAN_LOOP_BUTTON_UP = 2;
int PIN_HUMAN_LOOP_BUTTON_DOWN = 3; 

//Control constants
boolean MOTOR_DIRECTION_UP = HIGH; 
boolean MOTOR_DIRECTION_DOWN = LOW; 

#endif
