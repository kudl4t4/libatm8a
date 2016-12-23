#include "twi.h"

twi_Struct volatile *twi::_twiS;

void twi::twi() {
    _twiS = _twi;
}

bool twi::readInterruptFlag() {
    unsigned char tmp;

    tmp = _twiS->_TWCR;
    return ((tmp & 0x80) == 0x80)? true: false;
}

void twi::clearInterruptFlag() {
    unsigned char tmp;
    tmp = _twiS->_TWCR;
    tmp |= (1 << 7);
    _twiS->_TWCR = tmp;
}

void twi::setEnableAcknowledge() {
    unsigned char tmp;
    tmp = _twiS->_TWCR;
    tmp |= (1 << 6);
    _twiS->_TWCR = tmp;
}

void twi::clearEnableAcknowledge() {
    unsigned char tmp;
    tmp = _twiS->_TWCR;
    tmp &= ~(1 << 6);
    _twiS->_TWCR = tmp;
}

bool twi::getEnableAcknowledge() {
    unsigned char tmp;

    tmp = _twiS->_TWCR;
    return ((tmp & 0x40) == 0x40)? true: false;
}

void twi::setStartCondition() {
    unsigned char tmp;
    tmp = _twiS->_TWCR;
    tmp |= (1 << 5);
    _twiS->_TWCR = tmp;
}

void twi::clearStartCondition() {
    unsigned char tmp;
    tmp = _twiS->_TWCR;
    tmp &= ~(1 << 5);
    _twiS->_TWCR = tmp;
}

bool twi::getStartCondition() {
    unsigned char tmp;

    tmp = _twiS->_TWCR;
    return ((tmp & 0x20) == 0x20)? true: false;
}

void twi::setStopCondition() {
    unsigned char tmp;
    tmp = _twiS->_TWCR;
    tmp |= (1 << 4);
    _twiS->_TWCR = tmp;
}

void twi::clearStopCondition() {
    unsigned char tmp;
    tmp = _twiS->_TWCR;
    tmp &= ~(1 << 4);
    _twiS->_TWCR = tmp;
}

bool twi::getStopCondition() {
    unsigned char tmp;

    tmp = _twiS->_TWCR;
    return ((tmp & 0x10) == 0x10)? true: false;
}

bool twi::readWriteCollisionFlag() {
    unsigned char tmp;

    tmp = _twiS->_TWCR;
    return ((tmp & 0x08) == 0x08)? true: false;
}

void twi::setTWIEnable() {
    unsigned char tmp;
    tmp = _twiS->_TWCR;
    tmp |= (1 << 2);
    _twiS->_TWCR = tmp;
}

void twi::clearTWIEnable() {
    unsigned char tmp;
    tmp = _twiS->_TWCR;
    tmp &= ~(1 << 2);
    _twiS->_TWCR = tmp;
}

bool twi::getTWIEnable() {
    unsigned char tmp;

    tmp = _twiS->_TWCR;
    return ((tmp & 0x04) == 0x04)? true: false;
}

void twi::setInterruptEnable() {
    unsigned char tmp;
    tmp = _twiS->_TWCR;
    tmp |= (1 << 0);
    _twiS->_TWCR = tmp;
}

void twi::clearInterruptEnable() {
    unsigned char tmp;
    tmp = _twiS->_TWCR;
    tmp &= ~(1 << 0);
    _twiS->_TWCR = tmp;
}

bool twi::getInterruptEnable() {
    unsigned char tmp;

    tmp = _twiS->_TWCR;
    return ((tmp & 0x01) == 0x01)? true: false;
}

unsigned char twi::getStatus() {
    unsigned char tmp;
    tmp = _twiS->_TWSR;
    tmp = ((tmp >> 3) & 0x1F);
    return tmp;
}

void twi::setPrescaler(twi::prescaler ps) {
    unsigned char tmp;
    unsigned char prescaler = 0x00;

    switch (ps) {
        case twi::prescaler::_1:
            break;
        case twi::prescaler::_4:
            prescaler = 0x01;
            break;
        case twi::prescaler::_16:
            prescaler = 0x02;
            break;
        case twi::prescaler::_64:
            prescaler = 0x03;
            break;
    }

    tmp = _twiS->_TWSR;
    tmp &= ~(0x03);
    tmp |= (prescaler);
    _twiS->_TWSR = tmp;
}

twi::prescaler twi::getPrescaler() {
    unsigned char val;

    val = _twiS->_TWSR;
    val &= 0x03;

    switch (val) {
        case 0x00:
            return twi::prescaler::_1;
        case 0x01:
            return twi::prescaler::_4;
        case 0x02:
            return twi::prescaler::_16;
        case 0x03:
            return twi::prescaler::_64;
    }
}

void twi::writeData(unsigned char val) {
    _twiS->_TWDR = val;
}

unsigned char twi::readData() {
    return _twiS->_TWDR;
}

void twi::setSlaveAddress(unsigned char addr) {
    unsigned char tmp;

    tmp = _twiS->_TWAR;
    tmp |= (addr << 1);
    _twiS->_TWAR = tmp;
}

unsigned char twi::getSlaveAddress() {
    unsigned char tmp;

    tmp = _twiS->_TWAR;
    return ((tmp >> 1) & 0x7F);
}

void twi::setGeneralCallRecognition() {
    unsigned char tmp;

    tmp = _twiS->_TWAR;
    tmp |= (1 << 0);
    _twiS->_TWAR = tmp;
}

void twi::clearGeneralCallRecognition() {
    unsigned char tmp;

    tmp = _twiS->_TWAR;
    tmp &= ~(1 << 0);
    _twiS->_TWAR = tmp;
}

bool twi::getGeneralCallRecognition() {
    unsigned char tmp;

    tmp = _twiS->_TWAR;
    return ((tmp & 0x01) == 0x00)? false: true;
}

void twi::setBitRate(unsigned char val) {
    _twiS->_TWBR = val;
}

unsigned char twi::getBitRate() {
    return _twiS->_TWBR;
}

unsigned char twi::countBitRate(unsigned long int sclFreq, twi::prescaler pres) {
    unsigned char ps = 0x00;

    switch (pres) {
        case twi::prescaler::_1:
            ps = 1;
            break;
        case twi::prescaler::_4:
            ps = 4;
            break;
        case twi::prescaler::_16:
            ps = 16;
            break;
        case twi::prescaler::_64:
            ps = 64;
            break;
    }
    return ((F_CPU - 16*sclFreq)/(2*sclFreq*ps));
}
