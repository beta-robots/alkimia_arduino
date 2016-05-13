#ifndef ACCELEROMETER_ADXL335_H
#define ACCELEROMETER_ADXL335_H

//Arduino
#include "Arduino.h"

//constants
#define GRAVITY 9.81
#define N_READINGS_DEFAULT 5 
#define ADC_LEVELS 1023 
#define ADC_VOLTAGE_REFERENCE 2.56 
#define V_SUPPLY 3.3 //supplied at 3.3V
#define ZEROG_VOLTS_XYZ 1.5*(V_SUPPLY/3.0) //Bias level 1.5V at Vs=3V, ratiometric to Vs
#define ZEROG_VOLTS_X 1.5*(V_SUPPLY/3.0) //Bias level 1.5V at Vs=3V, ratiometric to Vs
#define ZEROG_VOLTS_Y 1.5*(V_SUPPLY/3.0) //Bias level 1.5V at Vs=3V, ratiometric to Vs
#define ZEROG_VOLTS_Z 1.5*(V_SUPPLY/3.0) //Bias level 1.5V at Vs=3V, ratiometric to Vs
#define SENSITIVITY_VOLTS_G 0.3*(V_SUPPLY/3.0)//sensitivity 300mV/g at Vs=3V, ratiometric to Vs

//class for accelerometer ADXL335 
class AccelerometerADXL335
{
    protected: 
        //variables
        int pin_x_; //where accel_x is attached
        int pin_y_; //where accel_y is attached
        int pin_z_; //where accel_y is attached
        
    public: 
        //constructor. Allows only with xy mode (no z)
        AccelerometerADXL335(int _pin_x, int _pin_y, int _pin_z); 
        
        //destructor
        ~AccelerometerADXL335(); 
        
        //gets raw voltage per axis. Returns mean of _n_readings [V]
        float getVoltageX(int _n_readings = N_READINGS_DEFAULT); 
        float getVoltageY(int _n_readings = N_READINGS_DEFAULT); 
        float getVoltageZ(int _n_readings = N_READINGS_DEFAULT); 
        void getVoltageXYZ(float & _vx, float & _vy, float & _vz, int _n_readings = N_READINGS_DEFAULT); 
        
        //gets raw acceleration per axis. Returns mean of _n_readings [m/s^2]
        float voltage2acceleration(float _volts, float _bias = ZEROG_VOLTS_XYZ );
        
        //gets angle about each axis. Returns mean of _n_readings [deg]
        float getAngleX(int _n_readings = N_READINGS_DEFAULT);
        float getAngleY(int _n_readings = N_READINGS_DEFAULT);
        float getAngleZ(int _n_readings = N_READINGS_DEFAULT);  
        
    protected: 
        //gets raw voltage for a given pin. Returns mean of _n_readings [V]
        float getVoltage(int _pin, int _n_readings);
};

#endif

