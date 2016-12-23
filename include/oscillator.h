#ifndef LIBATM8A_OSCILLATOR_H
#define LIBATM8A_OSCILLATOR_H

#include "common.h"

namespace oscillator {
    extern oscillator_Struct volatile *_os;

    void oscillator();

    void setOscillatorCalibration(unsigned char val);
    unsigned char getOscillatorCalibration();

};


#endif //LIBATM8A_OSCILLATOR_H
