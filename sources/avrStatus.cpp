#include "avrStatus.h"

avrStatus_Struct volatile *avrStatus::_sregS;

void avrStatus::avrStatus() {
    _sregS = _avrStatus;
}

void avrStatus::setGlobalInterruptEnable() {
    unsigned char tmp;
    tmp = _sregS->_SREG;
    tmp |= (1 << 7);
    _sregS->_SREG = tmp;
}

void avrStatus::clearGlobalInterruptEnable() {
    unsigned char tmp;
    tmp = _sregS->_SREG;
    tmp &= ~(1 << 7);
    _sregS->_SREG = tmp;
}

bool avrStatus::getGlobalInterruptEnable() {
    unsigned char tmp;
    tmp = _sregS->_SREG;

    return ((tmp & 0x80)==0x80)? true: false;
}

bool avrStatus::getCopyStorageFlag() {
    unsigned char tmp;
    tmp = _sregS->_SREG;

    return ((tmp & 0x40)==0x40)? true: false;
}

bool avrStatus::getHalfCarryFlag() {
    unsigned char tmp;
    tmp = _sregS->_SREG;

    return ((tmp & 0x20)==0x20)? true: false;
}

bool avrStatus::getSignBitFlag() {
    unsigned char tmp;
    tmp = _sregS->_SREG;

    return ((tmp & 0x10)==0x10)? true: false;
}

bool avrStatus::getTwoComplementOverflowFlag() {
    unsigned char tmp;
    tmp = _sregS->_SREG;

    return ((tmp & 0x08)==0x08)? true: false;
}

bool avrStatus::getNegativeFlag() {
    unsigned char tmp;
    tmp = _sregS->_SREG;

    return ((tmp & 0x04)==0x04)? true: false;
}

bool avrStatus::getZeroFlag() {
    unsigned char tmp;
    tmp = _sregS->_SREG;

    return ((tmp & 0x02)==0x02)? true: false;
}

bool avrStatus::getCarryFlag() {
    unsigned char tmp;
    tmp = _sregS->_SREG;

    return ((tmp & 0x01)==0x01)? true: false;
}