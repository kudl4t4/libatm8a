#include "oscillator.h"

oscillator_Struct volatile *oscillator::_os;

void oscillator::oscillator() {
    _os = _oscillator;
}

void oscillator::setOscillatorCalibration(unsigned char val) {
    _os->_OSCCAL = val;
}

unsigned char oscillator::getOscillatorCalibration() {
    return _os->_OSCCAL;
}