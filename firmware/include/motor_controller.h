#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

//Arduino
#include "Arduino.h"

//constants
#define PWM_MIN 100
#define PWM_MAX 200
#define PWM_STEP_SIZE 2
#define PWM_NUM_STEPS 40
#define STATE_STOP 0
#define STATE_STARTING 1
#define STATE_RUNNING 2
#define STATE_STOPPING 3

//class for motor controller
class MotorController
{
    protected: 
        //variables
        int state_; 
        int pin_pwm_; //where accel_y is attached
        int pin_turn_direction_; //where accel_y is attached
        int pwm_idx_; //in STARTING/STOPPING states, indicates at which index of the pwm_ramp_vector the motor is.
        int pwm_ramp_[PWM_NUM_STEPS]; //pwm levels to start up and stop the motor smoothly
        
    public: 
        //constructor with pins
        MotorController(int _pin_pwm, int _pin_turn_direction); 
        
        //destructor
        ~MotorController(); 
        
        //gets state
        int getState(); 
        
        //set motor turn direction. _dir should be either HIGH or LOW
        void setTurnDirection(boolean _dir); 
        
        //starts
        void start(); 
        
        //stops 
        void stop(); 
        
        //run. Carry on state
        void run(); 
        
};

#endif

