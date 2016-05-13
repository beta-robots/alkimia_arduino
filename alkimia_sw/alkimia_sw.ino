//Arduino standards
#include "Arduino.h"

//Alkimia project
#include "constants.h"
#include "accelerometer_adxl335.h"

//Main Objects
AccelerometerADXL335 accelerometer(PIN_ADC_ACCEL_X,PIN_ADC_ACCEL_Y,PIN_ADC_ACCEL_Z); 

//setup
void setup() 
{
  //sets heart beat led pin as a digital output
  pinMode(PIN_LED_HEART_BEAT, OUTPUT);
  
  //opens serial port, sets data rate to 9600 bps, Useful for debugging
  Serial.begin(SERIAL_BAUD_RATE);
  
}

//main loop
void loop() 
{    

}

