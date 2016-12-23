#include "bootLoaderSupport.h"

bootLoaderSupport_Struct volatile *bootLoaderSupport::_btsS;

void bootLoaderSupport::bootLoaderSupport() {
    _btsS = _bootLoaderSupport;
}

void bootLoaderSupport::setInterruptEnable() {
    unsigned char tmp;

    tmp = _btsS->_SPMCR;
    tmp |= (1 << 7);
    _btsS->_SPMCR = tmp;
}

void bootLoaderSupport::clearInterruptEnable() {
    unsigned char tmp;

    tmp = _btsS->_SPMCR;
    tmp &= ~(1 << 7);
    _btsS->_SPMCR = tmp;
}

bool bootLoaderSupport::getInterruptEnable() {
    unsigned char tmp;

    tmp = _btsS->_SPMCR;
    return ((tmp & 0x80)==0x80)? true: false;
}

bool bootLoaderSupport::readReadWhileWriteSectionBusyFlag() {
    unsigned char tmp;

    tmp = _btsS->_SPMCR;
    return ((tmp & 0x40)==0x40)? true: false;
}

void bootLoaderSupport::setReadWhileWriteSectionBusyEnable() {
    unsigned char tmp;

    tmp = _btsS->_SPMCR;
    tmp |= (1 << 4);
    _btsS->_SPMCR = tmp;
}

void bootLoaderSupport::clearReadWhileWriteSectionBusyEnable() {
    unsigned char tmp;

    tmp = _btsS->_SPMCR;
    tmp &= ~(1 << 4);
    _btsS->_SPMCR = tmp;
}

bool bootLoaderSupport::getReadWhileWriteSectionBusyEnable() {
    unsigned char tmp;

    tmp = _btsS->_SPMCR;
    return ((tmp & 0x10)==0x10)? true: false;
}

void bootLoaderSupport::setBootLockBit() {
    unsigned char tmp;

    tmp = _btsS->_SPMCR;
    tmp |= (1 << 3);
    _btsS->_SPMCR = tmp;
}

void bootLoaderSupport::clearBootLockBit() {
    unsigned char tmp;

    tmp = _btsS->_SPMCR;
    tmp &= ~(1 << 3);
    _btsS->_SPMCR = tmp;
}

bool bootLoaderSupport::getBootLockBit() {
    unsigned char tmp;

    tmp = _btsS->_SPMCR;
    return ((tmp & 0x08)==0x08)? true: false;
}

void bootLoaderSupport::setPageWrite() {
    unsigned char tmp;

    tmp = _btsS->_SPMCR;
    tmp |= (1 << 2);
    _btsS->_SPMCR = tmp;
}

void bootLoaderSupport::clearPageWrite() {
    unsigned char tmp;

    tmp = _btsS->_SPMCR;
    tmp &= ~(1 << 2);
    _btsS->_SPMCR = tmp;
}

bool bootLoaderSupport::getPageWrite() {
    unsigned char tmp;

    tmp = _btsS->_SPMCR;
    return ((tmp & 0x04)==0x04)? true: false;
}

void bootLoaderSupport::setPageErase() {
    unsigned char tmp;

    tmp = _btsS->_SPMCR;
    tmp |= (1 << 1);
    _btsS->_SPMCR = tmp;
}

void bootLoaderSupport::clearPageErase() {
    unsigned char tmp;

    tmp = _btsS->_SPMCR;
    tmp &= ~(1 << 1);
    _btsS->_SPMCR = tmp;
}

bool bootLoaderSupport::getPageErase() {
    unsigned char tmp;

    tmp = _btsS->_SPMCR;
    return ((tmp & 0x02)==0x02)? true: false;
}

void bootLoaderSupport::setStoreProgramMemory() {
    unsigned char tmp;

    tmp = _btsS->_SPMCR;
    tmp |= (1 << 0);
    _btsS->_SPMCR = tmp;
}

void bootLoaderSupport::clearStoreProgramMemory() {
    unsigned char tmp;

    tmp = _btsS->_SPMCR;
    tmp &= ~(1 << 0);
    _btsS->_SPMCR = tmp;
}

bool bootLoaderSupport::getStoreProgramMemory() {
    unsigned char tmp;

    tmp = _btsS->_SPMCR;
    return ((tmp & 0x01)==0x01)? true: false;
}