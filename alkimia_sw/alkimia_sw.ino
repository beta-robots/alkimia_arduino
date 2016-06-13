//Arduino standards
#include "Arduino.h"

//Alkimia project
#include "constants.h"
#include "motor_controller.h"

//Main Objects
MotorController motor(PIN_MOTOR_PWM, PIN_MOTOR_DIRECTION); 

//global variables
boolean new_input = false;
int main_loop_delay = MAIN_LOOP_PERIOD_RUN; 
boolean motion_allowed = false; 
boolean led_value = false;
boolean button_up = false; 
boolean button_down = false; 
int run_return; 

//setup
void setup() 
{
    //sets heart beat led pin as a digital output
    pinMode(PIN_LED_HEART_BEAT, OUTPUT);
    
    //sets human loop push buttons pins as a digital inputs
    pinMode(PIN_HUMAN_LOOP_BUTTON_UP, INPUT);
    pinMode(PIN_HUMAN_LOOP_BUTTON_DOWN, INPUT);    

    //attach interruption from user buttons
    //attachInterrupt(0, userButtonCallback, RISING);
    //attachInterrupt(1, userButtonCallback, RISING);
    
    //opens serial port, sets data rate to 9600 bps, Useful for debugging
    Serial.begin(SERIAL_BAUD_RATE);

    int myEraser = 7;             // this is 111 in binary and is used as an eraser
    TCCR2B &= ~myEraser;   // this operation (AND plus NOT),  set the three bits in TCCR2B to 0
    int myPrescaler = 1;         // this could be a number in [1 , 6]. In this case, 3 corresponds in binary to 011.
    TCCR2B |= myPrescaler;  //this operation (OR), replaces the last three bits in TCCR2B with our new value 011
}

//main loop
void loop() 
{   
  
    // turn the heart beat LED on 
    led_value = !led_value; 
    digitalWrite(PIN_LED_HEART_BEAT, led_value);   

    //check new input flag
/*    if (new_input)
    {
        //flag down
        new_input = false; 
        
        //sets loop rate at run mode
        //main_loop_delay = MAIN_LOOP_PERIOD_RUN;
        
        //flag motion_allowed
        motion_allowed = true; 
        
        //start motor
        motor.start(); 
    }*/
        
    //check motion
//    if ( motion_allowed )
//    {
        //check the buttons
        button_up = digitalRead(PIN_HUMAN_LOOP_BUTTON_UP);
        button_down = digitalRead(PIN_HUMAN_LOOP_BUTTON_DOWN);
        if ( (button_up) && (!button_down) )
        {
            if ( motor.getState() == STATE_STOP ) motor.start();          
            motor.setTurnDirection(MOTOR_DIRECTION_UP); 
            //motor.run(); 
        }
        if ( (!button_up) && (button_down) )
        {
            if ( motor.getState() == STATE_STOP ) motor.start();          
            motor.setTurnDirection(MOTOR_DIRECTION_DOWN); 
            //motor.run();             
        }
        if ( (!button_up) && (!button_down) ) 
        {
            //stops motor
            motor.stop(); 
            
            //sets loop rate at stop mode
            //main_loop_delay = MAIN_LOOP_PERIOD_STOP; 
            
            //flag down motion_allowed
            motion_allowed = false; 
        }
        
        
        run_return = motor.run(); 
    //}
    
    Serial.print("Motor at:");
    Serial.println(motor.getState(),DEC);
    Serial.print("Run Return:");
    Serial.println(run_return,DEC);

    //relax 
    delay(main_loop_delay); 
    
    //debug    
    //Serial.println("Looping");
    
}

void userButtonCallback()
{
    new_input = true; //flag indicating new user entry
    //Serial.println("Interrupt!");
}
