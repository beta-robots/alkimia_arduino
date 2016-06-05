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
        int pin_d_;
        float r_d_;
        float vcc_;
        
    public: 
        //constructor with pin and min , max values
        PotentiometerVdivider(int _pin_d, float _r_d, float _vcc); 
        
        //destructor
        ~PotentiometerVdivider(); 
        
        //gets state
        float getResistance(); 
        
};

#endif

