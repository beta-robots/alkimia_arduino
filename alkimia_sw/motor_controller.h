#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

//Arduino
#include "Arduino.h"

//constants motor state
#define STATE_STOP 0
#define STATE_STARTING 1
#define STATE_RUNNING 2
#define STATE_STOPPING 3

//constants motor start-up and stop ramp
#define CURVE_DURATION 1 //duration of start/stop curves [s]
#define CURVE_STEP_DURATION 0.02 //[s]
#define PWM_NUM_STEPS (int)(CURVE_DURATION/CURVE_STEP_DURATION)
// #define V_MIN 6 // minimum V to move the motor[V]
// #define K_SPEED_VOLTS 317 //speed motor constant [rpm/V]
// #define GEARBOX_REDUCTION 936 //reduction ratio
// #define PWM_MIN 100 
// #define PWM_MAX 200
// #define PWM_STEP_SIZE 2

//preset pwm level values found using scilab/motor_maxon_trajectory.sce
const int pwm_preset[PWM_NUM_STEPS] = {10,10,11,12,14,16,18,21,24,28,32,36,40,45,
                                        50,55,61,66,72,78,84,90,96,102,108,115,121,
                                        127,133,140,146,152,157,163,169,174,179,184,
                                        189,193,198,201,205,208,211,213,215,217,218,220};

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
        
        //get state
        int getState(); 
        
        //set motor turn direction. _dir should be either HIGH or LOW
        void setTurnDirection(boolean _dir); 
        
        //start. No internal loop. Just set the state. 
        void start(); 
        
        //stop. Internal loop up to stop
        void stop(); 
        
        //run. Carry on and state transition
        int run(); 
        
};

#endif

