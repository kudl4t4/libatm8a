/** @file adc.cpp
 *  @brief Namespace for the AVR Analog to Digital Converter
 *
 * Features
 * \n• 10-bit Resolution
 * \n• 0.5LSB Integral Non-Linearity
 * \n• ±2LSB Absolute Accuracy
 * \n• 13 - 260μs Conversion Time
 * \n• Up to 15kSPS at Maximum Resolution
 * \n• Six Multiplexed Single Ended Input Channels
 * \n• Two Additional Multiplexed Single Ended Input Channels (TQFP and QFN/MLF Package only)
 * \n• Optional Left Adjustment for ADC Result Readout
 * \n• 0 - VCC ADC Input Voltage Range
 * \n• Selectable 2.56V ADC Reference Voltage
 * \n• Free Running or Single Conversion Mode
 * \n• Interrupt on ADC Conversion Complete
 * \n• Sleep Mode Noise Canceler
 */

#include "adc.h"

adc_Struct volatile *adc::_adS;

void adc::adc() {
    _adS = _adc;
}

void adc::setReference(adc::reference ref) {
    unsigned char tmp;
    unsigned char val =0x00;

    switch (ref) {
        case adc::reference::aref_internal_turned_off:
            break;
        case adc::reference::avcc_external_capacitor_at_aref_pin:
            val = 0x01;
            break;
        case adc::reference::internal_2_56V_vol_reference_with_external_capacitor_at_aref_pin:
            val = 0x03;
            break;
    }

    tmp = _adS->_ADMUX;
    tmp &= ~(0x03 << 6);
    tmp |= (val << 6);
    _adS->_ADMUX = tmp;
}

adc::reference adc::getReference() {
    unsigned char tmp;

    tmp = _adS->_ADMUX;
    tmp = (tmp >> 6) & 0x03;

    switch (tmp) {
        case 0x00:
            return adc::reference::aref_internal_turned_off;
        case 0x01:
            return adc::reference::avcc_external_capacitor_at_aref_pin;
        case 0x03:
            return adc::reference::internal_2_56V_vol_reference_with_external_capacitor_at_aref_pin;
    }
}

void adc::setLeftAdjustResult() {
    unsigned char tmp;

    tmp = _adS->_ADMUX;
    tmp |= (1 << 5);
    _adS->_ADMUX = tmp;
}

void adc::clearLeftAdjustResult() {
    unsigned char tmp;

    tmp = _adS->_ADMUX;
    tmp &= ~(1 << 5);
    _adS->_ADMUX = tmp;
}

bool adc::getLeftAdjustResult() {
    unsigned char tmp;

    tmp = _adS->_ADMUX;
    return ((tmp & 0x20) == 0x20)? true: false;
}

void adc::setChannel(adc::channel ch) {
    unsigned char tmp;
    unsigned char val = 0x00;

    switch (ch) {
        case adc::channel::adc0:
            break;
        case adc::channel::adc1:
            val = 0x01;
            break;
        case adc::channel::adc2:
            val = 0x02;
            break;
        case adc::channel::adc3:
            val = 0x03;
            break;
        case adc::channel::adc4:
            val = 0x04;
            break;
        case adc::channel::adc5:
            val = 0x05;
            break;
        case adc::channel::adc6:
            val = 0x06;
            break;
        case adc::channel::adc7:
            val = 0x07;
            break;
        case adc::channel::_1_30V_Vbg:
            val = 0x0E;
            break;
        case adc::channel::_0_00V_Gnd:
            val = 0x0F;
            break;
    }

    tmp = _adS->_ADMUX;
    tmp &= ~(0x0F);
    tmp |= (val);
    _adS->_ADMUX = tmp;
}

adc::channel adc::getChannel() {
    unsigned char tmp;

    tmp = _adS->_ADMUX;
    tmp &= 0x0F;

    switch (tmp) {
        case 0x00:
            return adc::channel::adc0;
        case 0x01:
            return adc::channel::adc1;
        case 0x02:
            return adc::channel::adc2;
        case 0x03:
            return adc::channel::adc3;
        case 0x04:
            return adc::channel::adc4;
        case 0x05:
            return adc::channel::adc5;
        case 0x06:
            return adc::channel::adc6;
        case 0x07:
            return adc::channel::adc7;
        case 0x0E:
            return adc::channel::_1_30V_Vbg;
        case 0x0F:
            return adc::channel::_0_00V_Gnd;
    }
}

void adc::setEnable() {
    unsigned char tmp;

    tmp = _adS->_ADCSRA;
    tmp |= (1 << 7);
    _adS->_ADCSRA = tmp;
}

void adc::clearEnable() {
    unsigned char tmp;

    tmp = _adS->_ADCSRA;
    tmp &= ~(1 << 7);
    _adS->_ADCSRA = tmp;
}

bool adc::getEnable() {
    unsigned char tmp;

    tmp = _adS->_ADCSRA;
    return ((tmp & 0x80) == 0x80)? true: false;
}

void adc::setStartConversion() {
    unsigned char tmp;

    tmp = _adS->_ADCSRA;
    tmp |= (1 << 6);
    _adS->_ADCSRA = tmp;
}

void adc::clearStartConversion() {
    unsigned char tmp;

    tmp = _adS->_ADCSRA;
    tmp &= ~(1 << 6);
    _adS->_ADCSRA = tmp;
}

bool adc::getStartConversion() {
    unsigned char tmp;

    tmp = _adS->_ADCSRA;
    return ((tmp & 0x40) == 0x40)? true: false;
}

void adc::setFreeRunning() {
    unsigned char tmp;

    tmp = _adS->_ADCSRA;
    tmp |= (1 << 5);
    _adS->_ADCSRA = tmp;
}

void adc::clearFreeRunning() {
    unsigned char tmp;

    tmp = _adS->_ADCSRA;
    tmp &= ~(1 << 5);
    _adS->_ADCSRA = tmp;
}

bool adc::getFreeRunning() {
    unsigned char tmp;

    tmp = _adS->_ADCSRA;
    return ((tmp & 0x20) == 0x20)? true: false;
}

bool adc::readInterruptFlag() {
    unsigned char tmp;

    tmp = _adS->_ADCSRA;
    return ((tmp & 0x10) == 0x10)? true: false;
}

void adc::clearInterruptFlag() {
    unsigned char tmp;

    tmp = _adS->_ADCSRA;
    tmp |= (1 << 4);
    _adS->_ADCSRA = tmp;
}

void adc::setInterruptEnable() {
    unsigned char tmp;

    tmp = _adS->_ADCSRA;
    tmp |= (1 << 3);
    _adS->_ADCSRA = tmp;
}

void adc::clearInterruptEnable() {
    unsigned char tmp;

    tmp = _adS->_ADCSRA;
    tmp &= ~(1 << 3);
    _adS->_ADCSRA = tmp;
}

bool adc::getInterruptEnable() {
    unsigned char tmp;

    tmp = _adS->_ADCSRA;
    return ((tmp & 0x08) == 0x08)? true: false;
}

void adc::setPrescaler(adc::prescaler pr) {
    unsigned char tmp;
    unsigned char val = 0x00;

    switch (pr) {
        case adc::prescaler::_2_1:
            break;
        case adc::prescaler::_2_2:
            val = 0x01;
            break;
        case adc::prescaler::_4:
            val = 0x02;
            break;
        case adc::prescaler::_8:
            val = 0x03;
            break;
        case adc::prescaler::_16:
            val = 0x04;
            break;
        case adc::prescaler::_32:
            val = 0x05;
            break;
        case adc::prescaler::_64:
            val = 0x06;
            break;
        case adc::prescaler::_128:
            val = 0x07;
            break;
    }

    tmp = _adS->_ADCSRA;
    tmp &= ~(0x07);
    tmp |= (val);
    _adS->_ADCSRA = tmp;
}

adc::prescaler adc::getPrescaler() {
    unsigned char tmp;

    tmp = _adS->_ADCSRA;
    tmp &= 0x07;

    switch (tmp) {
        case 0x00:
            return adc::prescaler::_2_1;
        case 0x01:
            return adc::prescaler::_2_2;
        case 0x02:
            return adc::prescaler::_4;
        case 0x03:
            return adc::prescaler::_8;
        case 0x04:
            return adc::prescaler::_16;
        case 0x05:
            return adc::prescaler::_32;
        case 0x06:
            return adc::prescaler::_64;
        case 0x07:
            return adc::prescaler::_128;
    }
}

unsigned int adc::getData() {
    unsigned int val;
    unsigned char tmp;

    if ( false == getLeftAdjustResult()) {
        tmp = _adS->_ADCL;
        val = _adS->_ADCH;
        val = (val << 8);
        val |= tmp;
    } else {
        val = _adS->_ADCL;
        tmp = _adS->_ADCH;
        val = ( val << 2);
        val |= tmp;
    }
    return val;
}