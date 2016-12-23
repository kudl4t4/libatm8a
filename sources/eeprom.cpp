#include "eeprom.h"

eeprom_Struct volatile *eeprom::_ees;

void eeprom::eeprom() {
    _ees = _eeprom;
}

unsigned char eeprom::setAddress(unsigned int addr) {
    unsigned char tmp1;
    unsigned char tmp2;

    if ( 0x01FF < addr )
        return 2;

    tmp1 = (addr & 0x00FF);
    tmp2 = (addr >> 8);
    _ees->_EEARL = tmp1;
    _ees->_EEARH = tmp2;

    return 0;
}

unsigned int eeprom::getAddress() {
    unsigned char tmp1;
    unsigned char tmp2;
    unsigned int ret;

    tmp1 = _ees->_EEARL;
    tmp2 = _ees->_EEARH;

    ret = (tmp2 << 8) | (tmp1);
    return ret;
}

void eeprom::setData(unsigned char data) {
    _ees->_EEDR = data;
}

unsigned char eeprom::getData() {
    return _ees->_EEDR;
}

void eeprom::setReadyInterrupt() {
    unsigned char tmp;

    tmp = _ees->_EECR;
    tmp |= (1 << 3);
    _ees->_EECR = tmp;
}

void eeprom::clearReadyInterrupt() {
    unsigned char tmp;

    tmp = _ees->_EECR;
    tmp &= ~(1 << 3);
    _ees->_EECR = tmp;
}

bool eeprom::getReadyInterrupt() {
    unsigned char tmp;

    tmp = _ees->_EECR;

    return (((tmp >> 3) & 0x01) == 0x00)? false: true;
}

void eeprom::setMasterWriteEnable() {
    unsigned char tmp;

    tmp = _ees->_EECR;
    tmp |= (1 << 2);
    _ees->_EECR = tmp;
}

void eeprom::clearMasterWriteEnable() {
    unsigned char tmp;

    tmp = _ees->_EECR;
    tmp &= ~(1 << 2);
    _ees->_EECR = tmp;
}

bool eeprom::getMasterWriteEnable() {
    unsigned char tmp;

    tmp = _ees->_EECR;

    return (((tmp >> 2) & 0x01) == 0x00)? false: true;
}

void eeprom::setWriteEnable() {
    unsigned char tmp;

    tmp = _ees->_EECR;
    tmp |= (1 << 1);
    _ees->_EECR = tmp;
}

void eeprom::clearWriteEnable() {
    unsigned char tmp;

    tmp = _ees->_EECR;
    tmp &= ~(1 << 1);
    _ees->_EECR = tmp;
}

bool eeprom::getWriteEnable() {
    unsigned char tmp;

    tmp = _ees->_EECR;

    return (((tmp >> 1) & 0x01) == 0x00)? false: true;
}

void eeprom::setReadEnable() {
    unsigned char tmp;

    tmp = _ees->_EECR;
    tmp |= (1 << 0);
    _ees->_EECR = tmp;
}

void eeprom::clearReadEnable() {
    unsigned char tmp;

    tmp = _ees->_EECR;
    tmp &= ~(1 << 0);
    _ees->_EECR = tmp;
}

bool eeprom::getReadEnable() {
    unsigned char tmp;

    tmp = _ees->_EECR;

    return ((tmp & 0x01) == 0x00)? false: true;
}