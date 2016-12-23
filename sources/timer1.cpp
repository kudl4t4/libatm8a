#include "timer1.h"
#include <assert.h>

timer1_Struct volatile *timer1::_t1;
combined_Struct volatile *timer1::_cbS;

void timer1::timer1() {
    _t1 = _timer1;
    _cbS = _combined;
}

void timer1::setCompareOutputMode(channel ch, compareMode md) {
    unsigned char bitShift;
    unsigned char value;
    unsigned char tmp;

    if ( timer1::channel::channel_A == ch )
        bitShift = 6;
    else
        bitShift = 4;

    switch(md) {
        case normal_port_operation:
            value = 0x00;
            break;
        case toggle_on_Compare_Match:
            value = 0x01;
            break;
        case clear_on_Compare_Match:
            value = 0x02;
            break;
        case set_on_Compare_Match:
            value = 0x03;
            break;
        default:
            /*The execution should never reach this point.*/
            assert(0);
    }

    tmp = _t1->_TCCR1A;
    tmp &= ~(0x03 << bitShift);
    tmp |= (value << bitShift);
    _t1->_TCCR1A = tmp;
}

timer1::compareMode timer1::getCompareOutputMode(channel ch) {
    unsigned char bitShift;
    unsigned char tmp;

    if ( timer1::channel::channel_A == ch )
        bitShift = 6;
    else
        bitShift = 4;

    tmp = _t1->_TCCR1A;
    tmp = (tmp >> bitShift);
    tmp = (tmp & 0x03);

    switch (tmp) {
        case 0x00:
            return normal_port_operation;
        case 0x01:
            return toggle_on_Compare_Match;
        case 0x02:
            return clear_on_Compare_Match;
        case 0x03:
            return set_on_Compare_Match;
    }
}

void timer1::setForceOutputCompare(channel ch) {
    unsigned char tmp;
    unsigned char bitShift;

    if ( timer1::channel::channel_A == ch )
        bitShift = 3;
    else
        bitShift = 2;

    tmp = _t1->_TCCR1A;
    tmp |= (1 << bitShift);
    _t1->_TCCR1A = tmp;
}

void timer1::clearForceOutputCompare(channel ch) {
    unsigned char tmp;
    unsigned char bitShift;

    if ( timer1::channel::channel_A == ch )
        bitShift = 3;
    else
        bitShift = 2;

    tmp = _t1->_TCCR1A;
    tmp &= ~(1 << bitShift);
    _t1->_TCCR1A = tmp;
}

void timer1::setWaveformGenerationMode(waveformMode md) {
    unsigned char valueA;
    unsigned char valueB;
    unsigned char tmpA;
    unsigned char tmpB;

    switch (md) {
        case waveformMode::normal:
            valueA = 0x00;
            valueB = 0x00;
            break;
        case waveformMode::PWM_phaseCorrect_08bit:
            valueA = 0x01;
            valueB = 0x00;
            break;
        case waveformMode::PWM_phaseCorrect_09bit:
            valueA = 0x02;
            valueB = 0x00;
            break;
        case waveformMode::PWM_phaseCorrect_10bit:
            valueA = 0x03;
            valueB = 0x00;
            break;
        case waveformMode::clearTimerOnCompareMatch_Output:
            valueA = 0x00;
            valueB = 0x01;
            break;
        case waveformMode::FastPWM_08bit:
            valueA = 0x01;
            valueB = 0x01;
            break;
        case waveformMode::FastPWM_09bit:
            valueA = 0x02;
            valueB = 0x01;
            break;
        case waveformMode::FastPWM_10bit:
            valueA = 0x03;
            valueB = 0x01;
            break;
        case waveformMode::PWM_phaseFreqCorrect_Input:
            valueA = 0x00;
            valueB = 0x02;
            break;
        case waveformMode::PWM_phaseFreqCorrect_Output:
            valueA = 0x01;
            valueB = 0x02;
            break;
        case waveformMode::PWM_phaseCorrect_Input:
            valueA = 0x02;
            valueB = 0x02;
            break;
        case waveformMode::PWM_phaseCorrect_Output:
            valueA = 0x03;
            valueB = 0x02;
            break;
        case waveformMode::clearTimerOnCompareMatch_Input:
            valueA = 0x00;
            valueB = 0x03;
            break;
        case waveformMode::FastPWM_Input:
            valueA = 0x02;
            valueB = 0x03;
            break;
        case waveformMode::FastPWM_Output:
            valueA = 0x03;
            valueB = 0x03;
            break;
        default:
            /*The execution should never reach this point.*/
            assert(0);
    }

    tmpA = _t1->_TCCR1A;
    tmpB = _t1->_TCCR1B;
    tmpA &= ~0x03;
    tmpB &= ~0x18;
    tmpA |= (valueA << 0);
    tmpB |= (valueB << 3);
    _t1->_TCCR1A = tmpA;
    _t1->_TCCR1B = tmpB;
}

timer1::waveformMode timer1::getWaveformGenerationMode() {
    unsigned char tmpA;
    unsigned char tmpB;

    tmpA = _t1->_TCCR1A;
    tmpB = _t1->_TCCR1B;

    tmpB = ( tmpB << 1 );
    tmpB = ( tmpB & 0x30 ) | (tmpA & 0x03);

    switch (tmpB) {
        case 0x00:
            return waveformMode::normal;
        case 0x01:
            return waveformMode::PWM_phaseCorrect_08bit;
        case 0x02:
            return waveformMode::PWM_phaseCorrect_09bit;
        case 0x03:
            return waveformMode::PWM_phaseCorrect_10bit;
        case 0x10:
            return waveformMode::clearTimerOnCompareMatch_Output;
        case 0x11:
            return waveformMode::FastPWM_08bit;
        case 0x12:
            return waveformMode::FastPWM_09bit;
        case 0x13:
            return waveformMode::FastPWM_10bit;
        case 0x20:
            return waveformMode::PWM_phaseFreqCorrect_Input;
        case 0x21:
            return waveformMode::PWM_phaseFreqCorrect_Output;
        case 0x22:
            return waveformMode::PWM_phaseCorrect_Input;
        case 0x23:
            return waveformMode::PWM_phaseCorrect_Output;
        case 0x30:
            return waveformMode::clearTimerOnCompareMatch_Input;
        case 0x32:
            return waveformMode::FastPWM_Input;
        case 0x33:
            return waveformMode::FastPWM_Output;
    }
}

void timer1::setInputCaptureNoiseCanceler() {
    unsigned char tmp;

    tmp = _t1->_TCCR1B;
    tmp |= (1 << 7);
    _t1->_TCCR1B = tmp;
}

void timer1::clearInputCaptureNoiseCanceler() {
    unsigned char tmp;

    tmp = _t1->_TCCR1B;
    tmp &= ~(1 << 7);
    _t1->_TCCR1B = tmp;
}

bool timer1::getInputCaptureNoiseCanceler() {
    unsigned char tmp;

    tmp = _t1->_TCCR1B;

    return (((tmp >> 7) & 1) == 0)? false: true;
}

void timer1::setInputCaptureEdgeSelect(edge e) {
    unsigned char tmp;

    tmp = _t1->_TCCR1B;
    if (timer1::edge::falling == e)
        tmp &= ~(1 << 6);
    else
        tmp |= (1 << 6);

    _t1->_TCCR1B = tmp;
}

timer1::edge timer1::getInputCaptureEdgeSelect() {
    unsigned char tmp;

    tmp = _t1->_TCCR1B;

    if (((tmp >> 6) & 1) == 1)
        return (timer1::edge::rising);
    else
        return (timer1::edge::falling);
}

void timer1::setClockSelect(clock clk) {
    unsigned char tmp =0x00;

    tmp = _t1->_TCCR1B;
    tmp &= ~0x07;

    switch (clk) {
        case no_clk_source:
            tmp |= 0x00;
            break;
        case clk_1_no_prescaling:
            tmp |= 0x01;
            break;
        case clk_8_from_prescaler:
            tmp |= 0x02;
            break;
        case clk_64_from_prescaler:
            tmp |= 0x03;
            break;
        case clk_256_from_prescaler:
            tmp |= 0x04;
            break;
        case clk_1024_from_prescaler:
            tmp |= 0x05;
            break;
        case external_falling_edge:
            tmp |= 0x06;
            break;
        case external_rising_edge:
            tmp |= 0x07;
            break;
    }

    _t1->_TCCR1B = tmp;
}

timer1::clock timer1::getClockSelect() {
    unsigned char tmp = _t1->_TCCR1B;

    tmp = (tmp & 0x07);

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

void timer1::setCounterValue(unsigned int value) {
    _t1->_TCNT1H = ((value >> 8) & 0x00FF);
    _t1->_TCNT1L = (value & 0x00FF);
}

unsigned int timer1::getCounterValue() {
    unsigned int tmp;

    tmp = _t1 ->_TCNT1L;
    tmp |= (_t1->_TCNT1H << 8);

    return tmp;
}

void timer1::setOutputCompareValue(channel ch, unsigned int value) {
    if ( timer1::channel::channel_A == ch) {
        _t1->_OCR1AH = ((value >> 8) & 0x00FF);
        _t1->_OCR1AL = (value & 0x00FF);
    } else {
        _t1->_OCR1BH = ((value >> 8) & 0x00FF);
        _t1->_OCR1BL = (value & 0x00FF);
    }
}

unsigned int timer1::getOutputCompareValue(channel ch) {
    unsigned int tmp;

    if ( timer1::channel::channel_A == ch) {
        tmp = _t1 ->_OCR1AL;
        tmp |= (_t1->_OCR1AH << 8);
    } else {
        tmp = _t1 ->_OCR1BL;
        tmp |= (_t1->_OCR1BH << 8);
    }

    return tmp;
}

void timer1::setInputCompareValue(unsigned int value) {
    _t1->_ICR1H = ((value >> 8) & 0x00FF);
    _t1->_ICR1L = (value & 0x00FF);
}

unsigned int timer1::getInputCompareValue() {
    unsigned int tmp;

    tmp = _t1 ->_ICR1L;
    tmp |= (_t1->_ICR1H << 8);

    return tmp;
}

void timer1::setInputCaptureInterrupt() {
    unsigned char tmp;

    tmp = _cbS->_TIMSK;
    tmp |= (1 << 5);
    _cbS->_TIMSK = tmp;
}

void timer1::clearInputCaptureInterrupt() {
    unsigned char tmp;

    tmp = _cbS->_TIMSK;
    tmp &= ~(1 << 5);
    _cbS->_TIMSK = tmp;
}

bool timer1::getInputCaptureInterrupt() {
    unsigned char tmp;

    tmp = _cbS->_TIMSK;
    return (((tmp >> 5) & 1) == 0)? false: true;
}

void timer1::setOutputCompareMatchInterrupt(channel ch) {
    unsigned char tmp;
    tmp = _cbS->_TIMSK;

    if ( timer1::channel::channel_A == ch)
        tmp |= (1 << 4);
    else
        tmp |= (1 << 3);

    _cbS->_TIMSK = tmp;
}

void timer1::clearOutputCompareMatchInterrupt(channel ch) {
    unsigned char tmp;
    tmp = _cbS->_TIMSK;

    if ( timer1::channel::channel_A == ch)
        tmp &= ~(1 << 4);
    else
        tmp &= ~(1 << 3);

    _cbS->_TIMSK = tmp;
}

bool timer1::getOutputCompareMatchInterrupt(channel ch) {
    unsigned char tmp;
    unsigned char bitShift;

    if (timer1::channel::channel_A == ch)
        bitShift =4;
    else
        bitShift = 3;

    tmp = _cbS->_TIMSK;

    return (((tmp >> bitShift) & 1) == 0)? false: true;
}

void timer1::setOverflowInterrput() {
    unsigned char tmp;

    tmp = _cbS->_TIMSK;
    tmp |= (1 << 2);
    _cbS->_TIMSK = tmp;
}

void timer1::clearOverflowInterrput() {
    unsigned char tmp;

    tmp = _cbS->_TIMSK;
    tmp &= ~(1 << 2);
    _cbS->_TIMSK = tmp;
}

bool timer1::getOverflowInterrputInfo() {
    unsigned char tmp;

    tmp = _cbS->_TIMSK;
    return (((tmp >> 2) & 1) == 0)? false: true;
}

void timer1::clearInputCaptureFlag() {
    unsigned char tmp;

    tmp = _cbS->_TIFR;
    tmp |= (1 << 5);
    _cbS->_TIFR = tmp;
}

bool timer1::readInputCaptureFlag() {
    unsigned char tmp;

    tmp = _cbS->_TIFR;
    return (((tmp >> 5) & 1) == 0)? false: true;
}

void timer1::clearOutputCompareMatchFlag(channel ch) {
    unsigned char tmp;
    unsigned char bitShift;

    if(timer1::channel::channel_A == ch)
        bitShift = 4;
    else
        bitShift = 3;

    tmp = _cbS->_TIFR;
    tmp |= (1 << bitShift);
    _cbS->_TIFR = tmp;
}

bool timer1::readOutputCompareMatchFlag(channel ch) {
    unsigned char tmp;
    unsigned char bitShift;

    if (timer1::channel::channel_A == ch)
        bitShift = 4;
    else
        bitShift = 3;

    tmp = _cbS->_TIFR;

    return (((tmp >> bitShift) & 1) == 0)? false: true;
}

void timer1::clearOverflowFlag() {
    unsigned char tmp;

    tmp = _cbS->_TIFR;
    tmp |= (1 << 2);
    _cbS->_TIFR = tmp;
}

bool timer1::readOverflowFlag() {
    unsigned char tmp;

    tmp = _cbS->_TIFR;
    return (((tmp >> 2) & 1) == 0)? false: true;
}

void timer1::timerResetPrescale() {
    unsigned char tmp;

    tmp = _cbS->_SFIOR;
    tmp |= 0x01;
    _cbS->_SFIOR = tmp;
}

bool timer1::timerCheckIfReset() {
    unsigned char tmp;

    tmp = _cbS->_SFIOR;
    tmp = (tmp & 0x01);

    return (tmp == 1)? false: true;
}