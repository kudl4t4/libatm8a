#include "powerManagement.h"

powerManagement_Struct volatile *powerManagement::_pm;

void powerManagement::powerManagement() {
    _pm = _powerManagement;
}

void powerManagement::setSleepEnable() {
    unsigned char tmp;

    tmp = _pm->_MCUCR;
    tmp |= (1 << 5);
    _pm->_MCUCR = tmp;
}

void powerManagement::clearSleepEnable() {
    unsigned char tmp;

    tmp = _pm->_MCUCR;
    tmp &= ~(1 << 5);
    _pm->_MCUCR = tmp;
}

bool powerManagement::getSleepEnable() {
    unsigned char tmp;

    tmp = _pm->_MCUCR;

    return (((tmp >> 5) & 0x01) == 0x00)? false: true;
}

void powerManagement::setSleepMode(powerManagement::sleepMode sm) {
    unsigned char tmp;
    unsigned char value =0;

    switch (sm) {
        case powerManagement::sleepMode::idle:
            value = 0x00;
            break;
        case powerManagement::sleepMode::adc_noise_reduction:
            value = 0x01;
            break;
        case powerManagement::sleepMode::power_down:
            value = 0x02;
            break;
        case powerManagement::sleepMode::power_save:
            value = 0x03;
            break;
        case powerManagement::sleepMode::standby:
            value = 0x06;
            break;
    }

    tmp = _pm->_MCUCR;
    tmp &= ~(0x70);
    tmp |= (value << 4);
    _pm->_MCUCR = tmp;
}

powerManagement::sleepMode powerManagement::getSleepMode() {
    unsigned char tmp;

    tmp = _pm->_MCUCR;
    tmp = (tmp >> 4) & 0x07;

    switch (tmp) {
        case 0x00:
            return powerManagement::sleepMode::idle;
        case 0x01:
            return powerManagement::sleepMode::adc_noise_reduction;
        case 0x02:
            return powerManagement::sleepMode::power_down;
        case 0x03:
            return powerManagement::sleepMode::power_save;
        case 0x06:
            return powerManagement::sleepMode::standby;
    }
}