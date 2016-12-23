#include "timer2.h"
#include <assert.h>

timer2_Struct volatile *timer2::_t2;
combined_Struct volatile *timer2::_cbS;

void timer2::timer2() {
    _t2 = _timer2;
    _cbS = _combined;
}

void timer2::setForceOutputCompare() {
    unsigned char tmp;

    tmp = _t2->_TCCR2;
    tmp |= (1 << 7);
    _t2->_TCCR2 = tmp;
}

void timer2::clearForceOutputCompare() {
    unsigned char tmp;

    tmp = _t2->_TCCR2;
    tmp &= ~(1 << 7);
    _t2->_TCCR2 = tmp;
}

void timer2::setWaveformGenerationMode(timer2::waveformMode md) {
    unsigned char tmp;
    unsigned char value;

    switch(md) {
        case timer2::waveformMode::normal:
            value = 0x00;
            break;
        case timer2::waveformMode::PWM_phaseCorrect:
            value = 0x01;
            break;
        case timer2::waveformMode::clearTimerOnCompareMatch_Output:
            value = 0x02;
            break;
        case timer2::waveformMode::FastPWM:
            value = 0x03;
            break;
        default:
            /*The execution should never reach this point.*/
            assert(0);
    }

    tmp = _t2->_TCCR2;
    tmp &= ~(0x48);
    tmp |= ((value & 0x01) << 6);
    tmp |= ((value & 0x02) << 2);
    _t2->_TCCR2 = tmp;
}

timer2::waveformMode timer2::getWaveformGenerationMode() {
    unsigned char tmp;

    tmp = _t2->_TCCR2;
    tmp = ((tmp >> 2) & 0x02) | ((tmp >> 6) & 0x01);

    switch(tmp) {
        case 0x00:
            return timer2::waveformMode::normal;
        case 0x01:
            return timer2::waveformMode::PWM_phaseCorrect;
        case 0x02:
            return timer2::waveformMode::clearTimerOnCompareMatch_Output;
        case 0x03:
            return timer2::waveformMode::FastPWM;
    }
}

void timer2::setCompareOutputMode(timer2::compareMode md){
    unsigned char tmp;
    unsigned char value;

    switch(md) {
        case timer2::compareMode::normal_port_operation:
            value = 0x00;
            break;
        case timer2::compareMode::toggle_on_Compare_Match:
            value = 0x01;
            break;
        case timer2::compareMode::clear_on_Compare_Match:
            value = 0x02;
            break;
        case timer2::compareMode::set_on_Compare_Match:
            value = 0x03;
            break;
        default:
            /*The execution should never reach this point.*/
            assert(0);
    }
    tmp = _t2->_TCCR2;
    tmp &= ~(0x03 << 4);
    tmp |= (value << 4);
    _t2->_TCCR2 = tmp;

}

timer2::compareMode timer2::getCompareOutputMode(){
    unsigned char tmp;

    tmp = _t2->_TCCR2;
    tmp = (tmp >> 4);
    tmp &= (0x03);

    switch (tmp) {
        case 0x00:
            return timer2::compareMode::normal_port_operation;
        case 0x01:
            return timer2::compareMode::toggle_on_Compare_Match;
        case 0x02:
            return  timer2::compareMode::clear_on_Compare_Match;
        case 0x03:
            return timer2::compareMode::set_on_Compare_Match;
    }
}

void timer2::setClockSelect(timer2::clock clk) {
    unsigned char tmp;
    unsigned char value;

    switch (clk) {
        case timer2::clock::no_clk_source:
            value = 0x00;
            break;
        case timer2::clock::clk_1_no_prescaling:
            value = 0x01;
            break;
        case timer2::clock::clk_8_from_prescaler:
            value = 0x02;
            break;
        case timer2::clock::clk_32_from_prescaler:
            value = 0x03;
            break;
        case timer2::clock::clk_64_from_prescaler:
            value = 0x04;
            break;
        case timer2::clock::clk_128_from_prescaler:
            value = 0x05;
            break;
        case timer2::clock::clk_256_from_prescaler:
            value = 0x06;
            break;
        case timer2::clock::clk_1024_from_prescaler:
            value = 0x07;
            break;
        default:
            /*The execution should never reach this point.*/
            assert(0);
    }

    tmp = _t2->_TCCR2;
    tmp &= ~(0x07);
    tmp |= value;
    _t2->_TCCR2 = tmp;
}

timer2::clock timer2::getClockSelect() {
    unsigned char tmp;

    tmp = _t2->_TCCR2;
    tmp = (tmp & 0x07);

    switch (tmp) {
        case 0x00:
            return timer2::clock::no_clk_source;
        case 0x01:
            return timer2::clock::clk_1_no_prescaling;
        case 0x02:
            return timer2::clock::clk_8_from_prescaler;
        case 0x03:
            return timer2::clock::clk_32_from_prescaler;
        case 0x04:
            return timer2::clock::clk_64_from_prescaler;
        case 0x05:
            return timer2::clock::clk_128_from_prescaler;
        case 0x06:
            return timer2::clock::clk_256_from_prescaler;
        case 0x07:
            return timer2::clock::clk_1024_from_prescaler;
    }
}

void timer2::setCounterValue(unsigned char value) {
    _t2->_TCNT2 = value;
}

unsigned char timer2::getCounterValue() {
    return _t2->_TCNT2;
}

void timer2::setOutputCompareValue(unsigned char value) {
    _t2->_OCR2 = value;
}

unsigned char timer2::getOutputCompareValue() {
    return _t2->_OCR2;
}

void timer2::setAsynchronous() {
    _t2->_ASSR = (1 << 3);
}

bool timer2::getAsynchronous() {
    unsigned char tmp;
    tmp = _t2->_ASSR;

    return (((tmp >> 3) & 0x01) == 0x00)? false: true;
}

bool timer2::getTimerCounterUpdateBusy() {
    unsigned char tmp;
    tmp = _t2->_ASSR;

    return (((tmp >> 2) & 0x01) == 0x00)? false: true;
}

bool timer2::getOutputCompareUpdateBusy() {
    unsigned char tmp;
    tmp = _t2->_ASSR;

    return (((tmp >> 1) & 0x01) == 0x00)? false: true;
}

bool timer2::getTimerCounterControlUpdateBusy() {
    unsigned char tmp;
    tmp = _t2->_ASSR;

    return ((tmp & 0x01) == 0x00)? false: true;
}

void timer2::setOutputCompareMatchInterrupt() {
    unsigned char tmp;

    tmp = _cbS->_TIMSK;
    tmp |= (1 << 7);
    _cbS->_TIMSK = tmp;
}

void timer2::clearOutputCompareMatchInterrupt() {
    unsigned char tmp;

    tmp = _cbS->_TIMSK;
    tmp &= ~(1 << 7);
    _cbS->_TIMSK = tmp;
}

bool timer2::getOutputCompareMatchInterrupt() {
    unsigned char tmp;
    tmp = _cbS->_TIMSK;

    return (((tmp >> 7) & 0x01) == 0x00)? false: true;
}

void timer2::setOverflowInterrput() {
    unsigned char tmp;

    tmp = _cbS->_TIMSK;
    tmp |= (1 << 6);
    _cbS->_TIMSK = tmp;
}

void timer2::clearOverflowInterrput() {
    unsigned char tmp;

    tmp = _cbS->_TIMSK;
    tmp &= ~(1 << 6);
    _cbS->_TIMSK = tmp;
}

bool timer2::getOverflowInterrputInfo() {
    unsigned char tmp;
    tmp = _cbS->_TIMSK;

    return (((tmp >> 6) & 0x01) == 0x00)? false: true;
}

void timer2::clearOutputCompareMatchFlag() {
    unsigned char tmp;

    tmp = _cbS->_TIFR;
    tmp |= (1 << 7);
    _cbS->_TIFR = tmp;
}

bool timer2::readOutputCompareMatchFlag() {
    unsigned char tmp;
    tmp = _cbS->_TIFR;

    return (((tmp >> 7) & 0x01) == 0x00)? false: true;
}

void timer2::clearOverflowFlag() {
    unsigned char tmp;

    tmp = _cbS->_TIFR;
    tmp |= (1 << 6);
    _cbS->_TIFR = tmp;
}

bool timer2::readOverflowFlag() {
    unsigned char tmp;
    tmp = _cbS->_TIFR;

    return (((tmp >> 6) & 0x01) == 0x00)? false: true;
}

void timer2::timerResetPrescale() {
    unsigned char tmp;

    tmp = _cbS->_SFIOR;
    tmp |= 0x02;
    _cbS->_SFIOR = tmp;
}

bool timer2::timerCheckIfReset() {
    unsigned char tmp;

    tmp = _cbS->_SFIOR;
    tmp = ((tmp >> 1) & 0x01);

    return (tmp == 1)? false: true;
}