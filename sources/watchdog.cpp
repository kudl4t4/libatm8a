#include "watchdog.h"

watchdog_Struct volatile *watchdog::_wtch;

void watchdog::watchdog() {
    _wtch = _watchdog;
}

watchdog::resetSource watchdog::getResetSourceFlag() {
    unsigned char tmp;

    tmp = _wtch->_MCUCSR;
    tmp &= (0x0F);

    switch (tmp) {
        case 0x01:
            return watchdog::resetSource::power_on;
        case 0x02:
            return watchdog::resetSource::external;
        case 0x04:
            return watchdog::resetSource::brown_out;
        case 0x08:
            return watchdog::resetSource::watchDog;
    }
}

void watchdog::clearResetSourceFlag(watchdog::resetSource fl) {
    unsigned char tmp;
    unsigned char val =0;

    switch (fl) {
        case watchdog::resetSource::watchDog:
            val = 0x08;
            break;
        case watchdog::resetSource::brown_out:
            val = 0x04;
            break;
        case watchdog::resetSource::external:
            val = 0x02;
            break;
        case watchdog::resetSource::power_on:
            val = 0x01;
            break;
    }
    tmp = _wtch->_MCUCSR;
    tmp &= ~(val);
    _wtch->_MCUCSR = tmp;
}

void watchdog::setWatchdogChangeEnable() {
    unsigned char tmp;

    tmp = _wtch->_WDTCR;
    tmp |= (1 << 4);
    _wtch->_WDTCR = tmp;
}

void watchdog::clearWatchdogChangeEnable() {
    unsigned char tmp;

    tmp = _wtch->_WDTCR;
    tmp &= ~(1 << 4);
    _wtch->_WDTCR = tmp;
}

bool watchdog::getWatchdogChangeEnable() {
    unsigned char tmp;

    tmp = _wtch->_WDTCR;
    return (((tmp >> 4) & 0x01) == 0x00)? false: true;
}

void watchdog::setWatchdogEnable() {
    unsigned char tmp;

    tmp = _wtch->_WDTCR;
    tmp |= (1 << 3);
    _wtch->_WDTCR = tmp;
}

void watchdog::clearWatchdogEnable() {
    unsigned char tmp;

    tmp = _wtch->_WDTCR;
    tmp &= ~(1 << 3);
    _wtch->_WDTCR = tmp;
}

bool watchdog::getWatchdogEnable() {
    unsigned char tmp;

    tmp = _wtch->_WDTCR;
    return (((tmp >> 3) & 0x01) == 0x00)? false: true;
}

void watchdog::setWatchdogTimerPrescaler(watchdog::timerPrescale tp) {
    unsigned char tmp;
    unsigned char val =0;

    switch (tp) {
        case watchdog::timerPrescale::oscillatorCycles_16K:
            val = 0x00;
            break;
        case watchdog::timerPrescale::oscillatorCycles_32K:
            val = 0x01;
            break;
        case watchdog::timerPrescale::oscillatorCycles_64K:
            val = 0x02;
            break;
        case watchdog::timerPrescale::oscillatorCycles_128K:
            val = 0x03;
            break;
        case watchdog::timerPrescale::oscillatorCycles_256K:
            val = 0x04;
            break;
        case watchdog::timerPrescale::oscillatorCycles_512K:
            val = 0x05;
            break;
        case watchdog::timerPrescale::oscillatorCycles_1024K:
            val = 0x06;
            break;
        case watchdog::timerPrescale::oscillatorCycles_2048K:
            val = 0x07;
            break;
    }

    tmp = _wtch->_WDTCR;
    tmp &= ~(0x07);
    tmp |= val;
    _wtch->_WDTCR = tmp;
}

watchdog::timerPrescale watchdog::getWatchdogTimerPrescaler() {
    unsigned char tmp;

    tmp = _wtch->_WDTCR;
    tmp &= (0x07);

    switch (tmp) {
        case 0x00:
            return watchdog::timerPrescale::oscillatorCycles_16K;
        case 0x01:
            return watchdog::timerPrescale::oscillatorCycles_32K;
        case 0x02:
            return watchdog::timerPrescale::oscillatorCycles_64K;
        case 0x03:
            return watchdog::timerPrescale::oscillatorCycles_128K;
        case 0x04:
            return watchdog::timerPrescale::oscillatorCycles_256K;
        case 0x05:
            return watchdog::timerPrescale::oscillatorCycles_512K;
        case 0x06:
            return watchdog::timerPrescale::oscillatorCycles_1024K;
        case 0x07:
            return watchdog::timerPrescale::oscillatorCycles_2048K;
    }
}