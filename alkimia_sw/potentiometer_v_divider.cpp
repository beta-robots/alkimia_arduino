#include "potentiometer_v_divider.h"       

PotentiometerVdivider::PotentiometerVdivider(int _pin_d, float _r_d, float _vcc, int _ref_adc)
{
    //set class member variables
    pin_d_ = _pin_d;
    r_d_ = _r_d;
    vcc_ = _vcc;
    
    //set pin as analog input
    pinMode(pin_d_, INPUT);
    
    //set ADC analog ref value in volts. Assumed analogReference call done outside
    //analogReference(_ref_adc);
    switch (_ref_adc)
    {
        case DEFAULT: v_ref_adc_ = 5.0; break;
        case EXTERNAL: v_ref_adc_ = 5.0; break; //TODO
        //case INTERNAL: v_ref_adc_ = 3.3; break; //TOREVIEW
        case INTERNAL1V1: v_ref_adc_ = 1.1; break;
        case INTERNAL2V56: v_ref_adc_ = 2.56; break;
        default: v_ref_adc_ = 5.0; break;   
    }
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
    
    //get voltage from ADC (ADC ref 5V, ADC bits 10->1024 levels )
    adc_level = analogRead(pin_d_);
    vd = v_ref_adc_*adc_level/1023.0;
    
    //Compute resistance from voltage divider expression, and return
    return (2*r_d_*vd)/(vcc_-vd);
}

