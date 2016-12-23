#include "analogComparator.h"

analogComparator_Struct volatile *analogComparator::_acS;
combined_Struct volatile *analogComparator::_cbS;

void analogComparator::analogComparator() {
    _acS = _analogComparator;
    _cbS = _combined;
}

void analogComparator::offAnalogComparatorMultiplexer() {
    unsigned char tmp;

    tmp = _cbS->_SFIOR;
    tmp |= (1 << 3);
    _cbS->_SFIOR = tmp;
}

void analogComparator::onAnalogComparatorMultiplexer() {
    unsigned char tmp;

    tmp = _cbS->_SFIOR;
    tmp &= ~(1 << 3);
    _cbS->_SFIOR = tmp;
}

bool analogComparator::getAnalogComparatorMultiplexer() {
    unsigned char tmp;

    tmp = _cbS->_SFIOR;
    return ((tmp & 0x08) == 0x08)? false: true;
}

void analogComparator::offAnalogComparator() {
    unsigned char tmp;

    tmp = _acS->_ACSR;
    tmp |= (1 << 7);
    _acS->_ACSR = tmp;
}

void analogComparator::onAnalogComparator() {
    unsigned char tmp;

    tmp = _acS->_ACSR;
    tmp &= ~(1 << 7);
    _acS->_ACSR = tmp;
}

bool analogComparator::getAnalogComparator() {
    unsigned char tmp;

    tmp = _acS->_ACSR;
    return ((tmp & 0x80) == 0x80)? false: true;
}

void analogComparator::setBandgap() {
    unsigned char tmp;

    tmp = _acS->_ACSR;
    tmp |= (1 << 6);
    _acS->_ACSR = tmp;
}

void analogComparator::clearBandgap() {
    unsigned char tmp;

    tmp = _acS->_ACSR;
    tmp &= ~(1 << 6);
    _acS->_ACSR = tmp;
}

bool analogComparator::getBandgap() {
    unsigned char tmp;

    tmp = _acS->_ACSR;
    return ((tmp & 0x40) == 0x40)? true: false;
}

bool analogComparator::readOutput() {
    unsigned char tmp;

    tmp = _acS->_ACSR;
    return ((tmp & 0x20) == 0x20)? true: false;
}

bool analogComparator::readInterruptFlag() {
    unsigned char tmp;

    tmp = _acS->_ACSR;
    return ((tmp & 0x10) == 0x10)? true: false;
}

void analogComparator::clearInterruptFlag() {
    unsigned char tmp;

    tmp = _acS->_ACSR;
    tmp |= (1 << 4);
    _acS->_ACSR = tmp;
}

void analogComparator::setInterruptEnable() {
    unsigned char tmp;

    tmp = _acS->_ACSR;
    tmp |= (1 << 3);
    _acS->_ACSR = tmp;
}

void analogComparator::clearInterruptEnable() {
    unsigned char tmp;

    tmp = _acS->_ACSR;
    tmp &= ~(1 << 3);
    _acS->_ACSR = tmp;
}

bool analogComparator::getInterruptEnable() {
    unsigned char tmp;

    tmp = _acS->_ACSR;
    return ((tmp & 0x08) == 0x08)? true: false;
}

void analogComparator::setInputCaptureEnable() {
    unsigned char tmp;

    tmp = _acS->_ACSR;
    tmp |= (1 << 2);
    _acS->_ACSR = tmp;
}

void analogComparator::clearInputCaptureEnable() {
    unsigned char tmp;

    tmp = _acS->_ACSR;
    tmp &= ~(1 << 2);
    _acS->_ACSR = tmp;
}

bool analogComparator::getInputCaptureEnable() {
    unsigned char tmp;

    tmp = _acS->_ACSR;
    return ((tmp & 0x04) == 0x04)? true: false;
}

void analogComparator::setInterruptMode(analogComparator::mode md) {
    unsigned char tmp;
    unsigned char val = 0x00;

    switch (md) {
        case analogComparator::mode::interrupt_on_Output_Toggle:
            break;
        case analogComparator::mode::interrupt_on_Falling_Output_Edge:
            val = 0x02;
            break;
        case analogComparator::mode::interrupt_on_Rising_Output_Egde:
            val = 0x03;
            break;
    }

    tmp = _acS->_ACSR;
    tmp &= ~(0x03);
    tmp |= (val << 0);
    _acS->_ACSR = tmp;
}

analogComparator::mode analogComparator::getInterruptMode() {
    unsigned char tmp;

    tmp = _acS->_ACSR;
    tmp &= (0x03);

    switch (tmp) {
        case 0x00:
            return analogComparator::mode::interrupt_on_Output_Toggle;
        case 0x02:
            return analogComparator::mode::interrupt_on_Falling_Output_Edge;
        case 0x03:
            return analogComparator::mode::interrupt_on_Rising_Output_Egde;
    }
}