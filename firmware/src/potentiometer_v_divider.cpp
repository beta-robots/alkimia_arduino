#include "potentiometer_v_divider.h"       

PotentiometerVdivider::PotentiometerVdivider(int _pin_d, float _r_d, float _vcc)
{
    //set class member variables
    pin_d_ = _pin_d;
    r_d_ = _r_d;
    vcc_ = _vcc;
    
    //set pin as analog input
    pinMode(pin_d_, INPUT);
    
    //set (explicitly) ADC analog ref at 5V
    analogReference(DEFAULT); 
}

PotentiometerVdivider::~PotentiometerVdivider()
{
    //
}

float PotentiometerVdivider::getResistance()
{
    //get Vd, analog reading between potentiometer and Rd
    int adc_level; 
    float vd; 
    
    //get voltage from adc
    adc_level = analogRead(pin_d_);
    vd = 5.0*adc_level/1023.0;
    
    //Compute resistance from voltage divider expression, and return
    return (2*r_d_*vd)/(vcc_-vd);
}

