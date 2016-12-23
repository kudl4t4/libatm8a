#include "ioport.h"

ioport_Struct volatile *ioport::_io;
combined_Struct volatile *ioport::_cbS;

void ioport::ioportB() {
    _io = _iportB;
    _cbS = _combined;
}
void ioport::ioportC() {
    _io = _iportC;
    _cbS = _combined;
}
void ioport::ioportD() {
    _io = _iportD;
    _cbS = _combined;
}

void ioport::setOuputPinLow(unsigned char pinNo) {
    unsigned char tmp;

    tmp = _io->_DDRx;
    tmp |= 1 << pinNo;
    _io->_DDRx = tmp;

    tmp = _io->_PORTx;
    tmp &= ~(1 << pinNo);
    _io->_PORTx = tmp;
}

void ioport::setOutputPinHigh(unsigned char pinNo) {
    unsigned char tmp;

    tmp = _io->_DDRx;
    tmp |= 1 << pinNo;
    _io->_DDRx = tmp;

    tmp = _io->_PORTx;
    tmp |= 1 << pinNo;
    _io->_PORTx = tmp;
}

void ioport::setOutputPinToggle(unsigned char pinNo) {
    unsigned char tmp;

    tmp = _io->_DDRx;
    tmp |= 1 << pinNo;
    _io->_DDRx = tmp;

    tmp = _io->_PORTx;
    tmp ^= 1 << pinNo;
    _io->_PORTx = tmp;
}

void ioport::setOutputPin(unsigned char pinNo) {
    unsigned char tmp;

    tmp = _io->_DDRx;
    tmp |= 1 << pinNo;
    _io->_DDRx = tmp;
}

void ioport::setOuputBitsLow(unsigned char bits) {
    unsigned char tmp;

    tmp = _io->_DDRx;
    tmp |= bits;
    _io->_DDRx = tmp;

    tmp = _io->_PORTx;
    tmp &= ~(bits);
    _io->_PORTx = tmp;
}

void ioport::setOutputBitsHigh(unsigned char bits) {
    unsigned char tmp;

    tmp = _io->_DDRx;
    tmp |= bits;
    _io->_DDRx = tmp;

    tmp = _io->_PORTx;
    tmp |= bits;
    _io->_PORTx = tmp;
}

void ioport::setOutputBitsToggle(unsigned char bits) {
    unsigned char tmp;

    tmp = _io->_DDRx;
    tmp |= bits;
    _io->_DDRx = tmp;

    tmp = _io->_PORTx;
    tmp ^= bits;
    _io->_PORTx = tmp;
}

void ioport::setOutputBits(unsigned char bits) {
    unsigned char tmp;

    tmp = _io->_DDRx;
    tmp |= bits;
    _io->_DDRx = tmp;
}

void ioport::setInputPulledUp(unsigned char pinNo) {
    unsigned char tmp;

    tmp = _io->_DDRx;
    tmp &= ~(1 << pinNo);
    _io->_DDRx = tmp;

    tmp = _io->_PORTx;
    tmp |= 1 << pinNo;
    _io->_PORTx = tmp;
}

unsigned char ioport::readPin(unsigned char pinNo, bool *retValue) {
    unsigned char tmp;

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