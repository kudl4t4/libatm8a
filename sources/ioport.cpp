#include "ioport.h"

ioport_Struct volatile *ioport::_io;
combined_Struct volatile *ioport::_cbS;

void ioport::ioport() {
    _cbS = _combined;
}

void ioport::setOutputPinLow(ioportXFunct func, unsigned char pinNo) {
    unsigned char tmp;

    func();

    tmp = _io->_DDRx;
    tmp |= 1 << pinNo;
    _io->_DDRx = tmp;

    tmp = _io->_PORTx;
    tmp &= ~(1 << pinNo);
    _io->_PORTx = tmp;
}

void ioport::setOutputPinHigh(ioportXFunct func, unsigned char pinNo) {
    unsigned char tmp;

    func();

    tmp = _io->_DDRx;
    tmp |= 1 << pinNo;
    _io->_DDRx = tmp;

    tmp = _io->_PORTx;
    tmp |= 1 << pinNo;
    _io->_PORTx = tmp;
}

void ioport::setOutputPinToggle(ioportXFunct func, unsigned char pinNo) {
    unsigned char tmp;

    func();

    tmp = _io->_DDRx;
    tmp |= 1 << pinNo;
    _io->_DDRx = tmp;

    tmp = _io->_PORTx;
    tmp ^= 1 << pinNo;
    _io->_PORTx = tmp;
}

void ioport::setOutputPin(ioportXFunct func, unsigned char pinNo) {
    unsigned char tmp;

    func();

    tmp = _io->_DDRx;
    tmp |= 1 << pinNo;
    _io->_DDRx = tmp;
}

void ioport::setOutputBitsLow(ioportXFunct func, unsigned char bits) {
    unsigned char tmp;

    func();

    tmp = _io->_DDRx;
    tmp |= bits;
    _io->_DDRx = tmp;

    tmp = _io->_PORTx;
    tmp &= ~(bits);
    _io->_PORTx = tmp;
}

void ioport::setOutputBitsHigh(ioportXFunct func, unsigned char bits) {
    unsigned char tmp;

    func();

    tmp = _io->_DDRx;
    tmp |= bits;
    _io->_DDRx = tmp;

    tmp = _io->_PORTx;
    tmp |= bits;
    _io->_PORTx = tmp;
}

void ioport::setOutputBitsToggle(ioportXFunct func, unsigned char bits) {
    unsigned char tmp;

    func();

    tmp = _io->_DDRx;
    tmp |= bits;
    _io->_DDRx = tmp;

    tmp = _io->_PORTx;
    tmp ^= bits;
    _io->_PORTx = tmp;
}

void ioport::setOutputBits(ioportXFunct func, unsigned char bits) {
    unsigned char tmp;

    func();

    tmp = _io->_DDRx;
    tmp |= bits;
    _io->_DDRx = tmp;
}

void ioport::setInputPulledUp(ioportXFunct func, unsigned char pinNo) {
    unsigned char tmp;

    func();

    tmp = _io->_DDRx;
    tmp &= ~(1 << pinNo);
    _io->_DDRx = tmp;

    tmp = _io->_PORTx;
    tmp |= 1 << pinNo;
    _io->_PORTx = tmp;
}

unsigned char ioport::readPin(ioportXFunct func, unsigned char pinNo, bool *retValue) {
    unsigned char tmp;

    func();

    tmp = _io->_DDRx;
    if ( (pinNo >> tmp) & 1 )
        return 2;

    tmp = _io->_PINx;
    *retValue = ((tmp >> pinNo) & 1)? true: false;
    return 0;
}

void ioport::setPullUpDisable() {
    unsigned char tmp;

    tmp = _cbS->_SFIOR;
    tmp |= (1 << 2);
    _cbS->_SFIOR = tmp;
}
void ioport::clearPullUpDisable() {
    unsigned char tmp;

    tmp = _cbS->_SFIOR;
    tmp &= ~(1 << 2);
    _cbS->_SFIOR = tmp;
}

bool ioport::getPullUpDisable() {
    unsigned char tmp;

    tmp = _cbS->_SFIOR;
    return ((tmp & 0x04)==0x04)? true: false;
}