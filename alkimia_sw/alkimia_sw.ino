//Arduino standards
#include "Arduino.h"

//Alkimia project
#include "constants.h"
#include "accelerometer_adxl335.h"
#include "motor_controller.h"
#include "potentiometer_v_divider.h"

//Main Objects
AccelerometerADXL335 accelerometer(PIN_ADC_ACCEL_X,PIN_ADC_ACCEL_Y,PIN_ADC_ACCEL_Z); 
MotorController motor(PIN_MOTOR_PWM, PIN_MOTOR_DIRECTION); 
PotentiometerVdivider potent(PIN_POTENTIOMETER_DIVIDER, POTENTIOMETER_DIVIDER_RD, POTENTIOMETER_DIVIDER_VCC);

//global variables
bool new_input = false;
//boolean user_command_ok = false; 

//setup
void setup() 
{
  //sets heart beat led pin as a digital output
  pinMode(PIN_LED_HEART_BEAT, OUTPUT);
  
  //attach interruption from user button
  attachInterrupt(0, userButtonCallback, RISING);//TODO: decide whether rising or falling
 
  //opens serial port, sets data rate to 9600 bps, Useful for debugging
  Serial.begin(SERIAL_BAUD_RATE);  
}

//main loop
void loop() 
{   
    //local variables
    float angle_sensor, angle_user, angle_diff;
    int main_loop_delay = MAIN_LOOP_PERIOD_STOP; 
    boolean limit_switches = false; 
    boolean motion_allowed = false; 
    boolean led_value = false;
    boolean human_loop_button = false; 
    int debug_ii = 0; //useful for debugging
    
    // turn the heart beat LED on 
    led_value = !led_value; 
    digitalWrite(PIN_LED_HEART_BEAT, led_value);   

/*
    //check if new user input. If everyhting ok, this "if" will set motion_allowed flag
    if (new_input)
    {
        //flag down 
        new_input = false; 
                
        //get target angle from user input
        angle_user = (90.0/POTENTIOMETER_DIVIDER_RP)*potent.getResistance(); //angle in degs

        //get sensor angle about X axis
        angle_sensor = accelerometer.getAngleX(); 
        
        //angle diff
        angle_diff = angle_sensor - angle_user; 
    
        //check micro switches TODO
        limit_switches = false; //DEBUG
            
        //Decide wheter to start up the motor or not
        if ( ( abs(angle_diff) > ANGLE_DELTA ) && ( !limit_switches ) )
        {
            //compute & set turn direction
            if ( angle_diff > 0 ) motor.setTurnDirection(MOTOR_DIRECTION_DOWN);
            else motor.setTurnDirection(MOTOR_DIRECTION_UP);
            
            //sets the motor to start state
            motor.start();
                        
            //allows motion 
            motion_allowed = true;
        }
        else 
        {
            //do not allow motion
            motion_allowed = false; 
        }            
    } // end if(new_input)
    
    //get human-loop button
    human_loop_button = digitalRead(PIN_HUMAN_LOOP_BUTTON);
    
    //check human_in_loop button
    if ( (human_loop_button) && (motion_allowed) )
    {
        //get target angle from user input
        //TODO:  Decide if just read the first user input or get it at each iteration
        angle_user = (90.0/POTENTIOMETER_DIVIDER_RP)*potent.getResistance(); //angle in degs
    
        //get sensor angle about X
        angle_sensor = accelerometer.getAngleX(); 
        
        //angle diff
        angle_diff = angle_sensor - angle_user; 
        
        //check micro switches TODO
        limit_switches = false; //DEBUG
        
        //check end motion condition or limit switches ON
        if ( ( abs(angle_diff) < ANGLE_DELTA ) || ( limit_switches ) )
        {
            //stops the motor
            motor.stop();
                    
            //sets loop period to wait for user input
            main_loop_delay = MAIN_LOOP_PERIOD_STOP;    
            
            //disallows motion 
            motion_allowed = false;        
        }
        else
        {
            //carry on with command to motor controller
            motor.run(); 
            
            //set main loop rate for motor controlling
            main_loop_delay = MAIN_LOOP_PERIOD_RUN;
            
            //disallows motion 
            motion_allowed = false;                    
        }
    }
    else
    {
        //stops the motor
        motor.stop();
                
        //sets loop period to wait for user input
        main_loop_delay = MAIN_LOOP_PERIOD_STOP;    
        
        //disallows motion 
        motion_allowed = false;        
    }
 */

/******************* HEALTH CHECKING AREA ************************/

    //check potentiometer voltage divider
    //checkPotentiometerVoltageDivider();
    
    //check motor 
    checkMotor(debug_ii);
    
/******************* HEALTH CHECKING AREA ************************/

    //relax 
    delay(main_loop_delay); 
    
    //increment debugging index
    debug_ii ++;

}

void userButtonCallback()
{
    new_input = true; //flag indicating new user entry
}

void checkPotentiometerVoltageDivider()
{
    //local vars
    float r_p, angle; 
    
    //get potentiometer input
    r_p = potent.getResistance(); 
    angle = r_p*90/10000.; 

    //DEBUGGING
    Serial.print("r_p: ");    
    Serial.println(r_p,DEC);
    Serial.print("angle: ");    
    Serial.println(angle,DEC);
}

void checkMotor(int _ii)
{
    //implement several movements to check motor motion correctness
    if ( motor.getState() == STATE_STOP )
    {
        //sets turn direction
        motor.setTurnDirection(boolean(_ii%2));
        
        //sets the motor to start state
        motor.start();
    }
    
    motor.run(); 
    
    if (_ii%21 == 0) motor.stop(); 
    
}

