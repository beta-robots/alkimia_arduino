#ifndef POTENTIOMETER_V_DIVIDER_H
#define POTENTIOMETER_V_DIVIDER_H

//Arduino
#include "Arduino.h"

//class for potentiometer mounted in a voltage divider
//   Vcc ---- Rd ---- Rpoten/2 ---- GROUND
class PotentiometerVdivider
{
    protected: 
        //variables
        int pin_d_; //#
        float r_d_; //Ohms
        float vcc_; //Volts
        float v_ref_adc_; //Volts
        
    public: 
        //constructor with pin , Rd, Vcc and analog ref values. 
        //_v_ref_adc should be one of the defined at Arduino.h (DEFAULT, EXTERNAL, INTERNALXVX)
        PotentiometerVdivider(int _pin_d, float _r_d, float _vcc, int _ref_adc); 
        
        //destructor
        ~PotentiometerVdivider(); 
        
        //gets state
        float getResistance(); 
        
};

#endif

