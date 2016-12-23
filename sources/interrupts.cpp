#include "interrupts.h"

interrupts_Struct volatile *interrupts::_intS;

void interrupts::interrupts() {
    _intS = _interrupts;
}

void interrupts::setInterruptVectorPlaceSelect() {
    unsigned char tmp;

    tmp = _intS->_GICR;
    tmp |= (1 << 1);
    _intS->_GICR = tmp;
}

void interrupts::clearInterruptVectorPlaceSelect() {
    unsigned char tmp;

    tmp = _intS->_GICR;
    tmp &= ~(1 << 1);
    _intS->_GICR = tmp;
}

bool interrupts::getInterruptVectorPlaceSelect() {
    unsigned char tmp;

    tmp = _intS->_GICR;
    return (((tmp >> 1) & 0x01) == 0x00)? false: true;
}

void interrupts::setInterruptVectorChangeEnable() {
    unsigned char tmp;

    tmp = _intS->_GICR;
    tmp |= (1 << 0);
    _intS->_GICR = tmp;
}

void interrupts::clearInterruptVectorChangeEnable() {
    unsigned char tmp;

    tmp = _intS->_GICR;
    tmp &= ~(1 << 0);
    _intS->_GICR = tmp;
}

bool interrupts::getInterruptVectorChangeEnable() {
    unsigned char tmp;

    tmp = _intS->_GICR;
    return ((tmp & 0x01) == 0x00)? false: true;
}

void interrupts::setExternalInterruptRequest(interrupts::externalInterrupt ex) {
    unsigned char tmp;
    unsigned char val =0;

    switch (ex) {
        case interrupts::externalInterrupt::interrupt_0:
            val = 0x01;
            break;
        case interrupts::externalInterrupt::interrupt_1:
            val = 0x02;
            break;
    }
    tmp = _intS->_GICR;
    tmp |= (val << 6);
    _intS->_GICR = tmp;
}

void interrupts::clearExternalInterruptRequest(interrupts::externalInterrupt ex) {
    unsigned char tmp;
    unsigned char val =0;

    switch (ex) {
        case interrupts::externalInterrupt::interrupt_0:
            val = 0x01;
            break;
        case interrupts::externalInterrupt::interrupt_1:
            val = 0x02;
            break;
    }
    tmp = _intS->_GICR;
    tmp &= ~(val << 6);
    _intS->_GICR = tmp;
}

bool interrupts::getExternalInterruptRequest(interrupts::externalInterrupt ex) {
    unsigned char tmp;

    tmp = _intS->_GICR;
    if ( interrupts::externalInterrupt::interrupt_0 == ex ) {
        return (((tmp >> 6) & 0x01) == 0x00)? false: true;
    } else {
        return (((tmp >> 7) & 0x01) == 0x00)? false: true;
    }
}

void interrupts::setInterruptSenseControl(interrupts::externalInterrupt ex, interrupts::senseControl sc) {
    unsigned char tmp;
    unsigned char val =0;
    unsigned char bitShift =0;

    if ( interrupts::externalInterrupt::interrupt_1 == ex ) {
        bitShift = 2;
    }

    switch (sc) {
        case interrupts::senseControl::low_level:
            val = 0x00;
            break;
        case interrupts::senseControl::any_logical:
            val = 0x01;
            break;
        case interrupts::senseControl::falling_edge:
            val = 0x02;
            break;
        case interrupts::senseControl::rising_edge:
            val = 0x03;
            break;
    }

    tmp = _intS->_MCUCR;
    tmp &= ~(0x03 << bitShift);
    tmp |= (val << bitShift);
    _intS->_MCUCR = tmp;
}

interrupts::senseControl interrupts::getInterruptSenseControl(interrupts::externalInterrupt ex) {
    unsigned char tmp;
    unsigned char bitShift =0;

    if ( interrupts::externalInterrupt::interrupt_1 == ex ) {
        bitShift = 2;
    }

    tmp = _intS->_MCUCR;
    tmp = (tmp >> bitShift) & 0x03;

    switch (tmp) {
        case 0x00:
            return interrupts::senseControl::low_level;
        case 0x01:
            return interrupts::senseControl::any_logical;
        case 0x02:
            return interrupts::senseControl::falling_edge;
        case 0x03:
            return interrupts::senseControl::rising_edge;
    }
}

void interrupts::clearExternalInterruptFlag(interrupts::externalInterrupt ex) {
    unsigned char tmp;
    unsigned char bitShift =0;

    if ( interrupts::externalInterrupt::interrupt_1 == ex ) {
        bitShift = 7;
    } else {
        bitShift = 6;
    }

    tmp = _intS->_GIFR;
    tmp &= ~(1 << bitShift);
    _intS->_GIFR = tmp;
}

bool interrupts::getExternalInterruptFlag(interrupts::externalInterrupt ex) {
    unsigned char tmp;

    tmp = _intS->_GIFR;
    if ( interrupts::externalInterrupt::interrupt_0 == ex ) {
        return (((tmp >> 6) & 0x01) == 0x00)? false: true;
    } else {
        return (((tmp >> 7) & 0x01) == 0x00)? false: true;
    }
}