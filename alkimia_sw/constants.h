#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "Arduino.h"

//general purpose constants
bool VERBOSE = true; 
int SERIAL_BAUD_RATE = 9600;
int PIN_LED_HEART_BEAT = 13; 

//Main Loop delay periods
int MAIN_LOOP_PERIOD_STOP = 1000; //1Hz
int MAIN_LOOP_PERIOD_RUN = 20; //50Hz

//accelerometer wiring
int PIN_ADC_ACCEL_X = 0; 
int PIN_ADC_ACCEL_Y = 1; 
int PIN_ADC_ACCEL_Z = 2; 

//Motor driver wiring
int PIN_MOTOR_PWM = 3; 
int PIN_MOTOR_DIRECTION = 4; 

//User buttons wiring & constants
int PIN_HUMAN_LOOP_BUTTON = 10; //TODO
int PIN_POTENTIOMETER_DIVIDER = 15; 
float POTENTIOMETER_DIVIDER_RP = 10000.0; //max resistance of the potentiometer [ohms]
float POTENTIOMETER_DIVIDER_RD = 10000.0; //top resistance at the voltage divider [ohms]
float POTENTIOMETER_DIVIDER_VCC = 5.0; //Volts
//float POTENTIOMETER_DIVIDER_VREF_ADC = 5; //Volts. Not yet used ...

//micro switch wiring
//TODO

//Control constants
float ANGLE_DELTA = 10.;
boolean MOTOR_DIRECTION_UP = HIGH; 
boolean MOTOR_DIRECTION_DOWN = LOW; 

#endif
