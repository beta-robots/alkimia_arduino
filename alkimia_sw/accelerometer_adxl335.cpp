#include "accelerometer_adxl335.h"

AccelerometerADXL335::AccelerometerADXL335(int _pin_x, int _pin_y, int _pin_z)
{    
    //set input pins
    pin_x_ = _pin_x;
    pin_y_ = _pin_y;
    pin_z_ = _pin_z;
    
    //Set AD converter reference to 2.56V
    analogReference(INTERNAL2V56);    
}


AccelerometerADXL335::~AccelerometerADXL335()
{
    
}

float AccelerometerADXL335::getVoltageX(int _n_readings)
{
    return getVoltage(pin_x_, _n_readings);
}

float AccelerometerADXL335::getVoltageY(int _n_readings)
{
    return getVoltage(pin_y_, _n_readings);
}

float AccelerometerADXL335::getVoltageZ(int _n_readings)
{
    return getVoltage(pin_z_, _n_readings);
}

void AccelerometerADXL335::getVoltageXYZ(float & _vx, float & _vy, float & _vz, int _n_readings)
{
    //local variables
    int adc_x = 0; //level from analog to digital converter, x axis
    int adc_y = 0; //level from analog to digital converter, x axis
    int adc_z = 0; //level from analog to digital converter, x axis

    //get the mean over _n_readings
    for (int ii=0; ii<_n_readings; ii++)
    {
        adc_x += analogRead(pin_x_);
        adc_y += analogRead(pin_y_);
        adc_z += analogRead(pin_z_);
        delay(5);
    }
    
    //convert to voltage
    _vx = ( ADC_VOLTAGE_REFERENCE * ((float)adc_x/(float)ADC_LEVELS) ) / (float)_n_readings;
    _vy = ( ADC_VOLTAGE_REFERENCE * ((float)adc_y/(float)ADC_LEVELS) ) / (float)_n_readings;  
    _vz = ( ADC_VOLTAGE_REFERENCE * ((float)adc_z/(float)ADC_LEVELS) ) / (float)_n_readings;  
}

float AccelerometerADXL335::voltage2acceleration(float _volts, float _bias)
{
    //convert to acceleration and return
    return ((_volts-_bias)/SENSITIVITY_VOLTS_G)*GRAVITY;
}

float AccelerometerADXL335::getAngleX(int _n_readings)
{
    //local vars
    float vx, vy, vz, ay, az;
    
    //get voltage
    getVoltageXYZ(vx, vy, vz, _n_readings); 
    
    //convert to acceleration
    ay = voltage2acceleration(vy, ZEROG_VOLTS_Y);
    az = voltage2acceleration(vz, ZEROG_VOLTS_Z);
    
    //compute roll, about X, return in degrees
    return atan2(ay,az)*180./PI;  
}

float AccelerometerADXL335::getAngleY(int _n_readings)
{
    
}

float AccelerometerADXL335::getAngleZ(int _n_readings)
{
    
}


//*********************** PROTECTED ***************************+
float AccelerometerADXL335::getVoltage(int _pin, int _n_readings)
{
    //local variables
    int adc_level = 0; //level from analog to digital converter

    //get the mean over _n_readings
    for (int ii=0; ii<_n_readings; ii++)
    {
        adc_level += analogRead(_pin);
        delay(5);
    }
    
    //convert to voltage
    return  ( ADC_VOLTAGE_REFERENCE * ((float)adc_level/(float)ADC_LEVELS) ) / (float)_n_readings;  
}

