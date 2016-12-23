#include "timer0.h"

timer0_Struct volatile *timer0::_t0;
combined_Struct volatile *timer0::_cbS;

void timer0::timer0() {
    _t0 = _timer0;
    _cbS = _combined;
}

void timer0::setClockSelect(clock clk) {
    unsigned char tmp =0x00;

    switch (clk) {
        case no_clk_source:
            tmp = 0x00;
            break;
        case clk_1_no_prescaling:
            tmp = 0x01;
            break;
        case clk_8_from_prescaler:
            tmp = 0x02;
            break;
        case clk_64_from_prescaler:
            tmp = 0x03;
            break;
        case clk_256_from_prescaler:
            tmp = 0x04;
            break;
        case clk_1024_from_prescaler:
            tmp = 0x05;
            break;
        case external_falling_edge:
            tmp = 0x06;
            break;
        case external_rising_edge:
            tmp = 0x07;
            break;
    }

    _t0->_TCCR0 = tmp;
}

timer0::clock timer0::getClockSelect() {
    unsigned char tmp = _t0->_TCCR0;

    switch (tmp) {
        case 0x00:
            return no_clk_source;
        case 0x01:
            return clk_1_no_prescaling;
        case 0x02:
            return clk_8_from_prescaler;
        case 0x03:
            return clk_64_from_prescaler;
        case 0x04:
            return clk_256_from_prescaler;
        case 0x05:
            return clk_1024_from_prescaler;
        case 0x06:
            return external_falling_edge;
        case 0x07:
            return external_rising_edge;
    }
}

void timer0::setCounterValue(unsigned char value) {
    _t0->_TCNT0 = value;
}

unsigned char timer0::getCounterValue() {
    return (_t0->_TCNT0);
}

void timer0::setOverflowInterrput() {
    unsigned char tmp;

    tmp = _cbS->_TIMSK;
    tmp |= 0x01;
    _cbS->_TIMSK = tmp;
}

void timer0::clearOverflowInterrput() {
    unsigned char tmp;

    tmp = _cbS->_TIMSK;
    tmp &= ~0x01;
    _cbS->_TIMSK = tmp;
}

bool timer0::getOverflowInterrputInfo() {
    return ( (_cbS->_TIMSK & 1) == 0)? false : true;
}

void timer0::clearOverflowFlag() {
    unsigned char tmp;

    tmp = _cbS->_TIFR;
    tmp |= 0x01;
    _cbS->_TIFR = tmp;
}
bool timer0::readOverflowFlag() {
    return ( (_cbS->_TIFR & 1) == 0)? false: true;
}

void timer0::timerResetPrescale() {
    unsigned char tmp;

    tmp = _cbS->_SFIOR;
    tmp |= 0x01;
    _cbS->_SFIOR = tmp;
}

bool timer0::timerCheckIfReset() {
    unsigned char tmp;

    tmp = _cbS->_SFIOR;
    tmp = (tmp & 0x01);

    return (tmp == 1)? false: true;
}