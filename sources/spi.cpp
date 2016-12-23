#include "spi.h"

spi_Struct volatile *spi::_sp;

void spi::spi() {
    _sp = _spi;
}

void spi::setEnableSpi() {
    unsigned char tmp;

    tmp = _sp->_SPCR;
    tmp |= (1 << 6);
    _sp->_SPCR = tmp;
}

void spi::clearEnableSpi() {
    unsigned char tmp;

    tmp = _sp->_SPCR;
    tmp &= ~(1 << 6);
    _sp->_SPCR = tmp;
}

bool spi::getEnableSpi() {
    unsigned char tmp;

    tmp = _sp->_SPCR;
    return (((tmp >> 6) & 0x01) == 0x00)? false: true;
}

void spi::setInterruptEnable() {
    unsigned char tmp;

    tmp = _sp->_SPCR;
    tmp |= (1 << 7);
    _sp->_SPCR = tmp;
}

void spi::clearInterruptEnable() {
    unsigned char tmp;

    tmp = _sp->_SPCR;
    tmp &= ~(1 << 7);
    _sp->_SPCR = tmp;
}

bool spi::getInterruptEnable() {
    unsigned char tmp;

    tmp = _sp->_SPCR;
    return (((tmp >> 7) & 0x01) == 0x00)? false: true;
}

void spi::setDataOrder(spi::dataOrder dt) {
    unsigned char tmp;
    unsigned char val = 0x00;

    if ( spi::dataOrder::LSB_fisrt == dt )
        val = 0x01;

    tmp = _sp->_SPCR;
    tmp &= ~(1 << 5);
    tmp |= (val << 5);
    _sp->_SPCR = tmp;
}

spi::dataOrder spi::getDataOrder() {
    unsigned char tmp;

    tmp = _sp->_SPCR;

    return (((tmp >> 5) & 0x01) == 0x00)? spi::dataOrder::MSB_first: spi::dataOrder::LSB_fisrt;
}

void spi::setModeSelect(spi::mode md) {
    unsigned char tmp;
    unsigned char val = 0x00;

    if ( spi::mode::master == md )
        val = 0x01;

    tmp = _sp->_SPCR;
    tmp &= ~(1 << 4);
    tmp |= (val << 4);
    _sp->_SPCR = tmp;
}

spi::mode spi::getModeSelect() {
    unsigned char tmp;

    tmp = _sp->_SPCR;

    return (((tmp >> 4) & 0x01) == 0x00)? spi::mode::slave: spi::mode::master;
}

void spi::setClockPolarity(spi::clockPolarity cp) {
    unsigned char tmp;
    unsigned char val = 0x00;

    if ( spi::clockPolarity::sck_high_when_idle == cp )
        val = 0x01;

    tmp = _sp->_SPCR;
    tmp &= ~(1 << 3);
    tmp |= (val << 3);
    _sp->_SPCR = tmp;
}

spi::clockPolarity spi::getClockPolarity() {
    unsigned char tmp;

    tmp = _sp->_SPCR;

    return (((tmp >> 3) & 0x01) == 0x00)? spi::clockPolarity::sck_low_when_idle: spi::clockPolarity::sck_high_when_idle;
}

void spi::setClockPhase(spi::clockPhase cp) {
    unsigned char tmp;
    unsigned char val = 0x00;

    if ( spi::clockPhase::leading_edge == cp )
        val = 0x01;

    tmp = _sp->_SPCR;
    tmp &= ~(1 << 2);
    tmp |= (val << 2);
    _sp->_SPCR = tmp;
}

spi::clockPhase spi::getClockPhase() {
    unsigned char tmp;

    tmp = _sp->_SPCR;

    return (((tmp >> 2) & 0x01) == 0x00)? spi::clockPhase::trailing_edge: spi::clockPhase::leading_edge;
}

void spi::setClockRate(spi::clockRate cr) {
    unsigned char tmp1;
    unsigned char tmp2;
    unsigned char spr =0x00;
    unsigned char spi2x = 0x00;

    switch (cr) {
        case spi::clockRate::fosc_4:
            break;
        case spi::clockRate::fosc_16:
            spr = 0x01;
            break;
        case spi::clockRate::fosc_64_1:
            spr = 0x02;
            break;
        case spi::clockRate::fosc_128:
            spr = 0x03;
            break;
        case spi::clockRate::fosc_2:
            spi2x = 0x01;
            break;
        case spi::clockRate::fosc_8:
            spr = 0x01;
            spi2x = 0x01;
            break;
        case spi::clockRate::fosc_32:
            spr = 0x02;
            spi2x = 0x01;
            break;
        case spi::clockRate::fosc_64_2:
            spr = 0x03;
            spi2x = 0x01;
            break;
    }

    tmp1 = _sp->_SPCR;
    tmp1 &= ~(3 << 0);
    tmp1 |= (spr << 0);
    _sp->_SPCR = tmp1;

    tmp2 = _sp->_SPSR;
    tmp2 &= ~(1 << 0);
    tmp2 |= (spi2x << 0);
    _sp->_SPSR = tmp2;
}

spi::clockRate spi::getClockRate() {
    unsigned char tmp;

    tmp = _sp->_SPSR;
    tmp = (tmp << 2);
    tmp |= _sp->_SPCR;
    tmp &= 0x07;

    switch (tmp) {
        case 0x00:
            return spi::clockRate::fosc_4;
        case 0x01:
            return spi::clockRate::fosc_16;
        case 0x02:
            return spi::clockRate::fosc_64_1;
        case 0x03:
            return spi::clockRate::fosc_128;
        case 0x04:
            return spi::clockRate::fosc_2;
        case 0x05:
            return spi::clockRate::fosc_8;
        case 0x06:
            return spi::clockRate::fosc_32;
        case 0x07:
            return spi::clockRate::fosc_64_2;
    }
}

bool spi::getInterruptFlag() {
    unsigned char tmp;

    tmp = _sp->_SPSR;
    return (((tmp >> 7) & 0x01) == 0x00)? false: true;
}

bool spi::getWriteCollisionFlag() {
    unsigned char tmp;

    tmp = _sp->_SPSR;
    return (((tmp >> 6) & 0x01) == 0x00)? false: true;
}

void spi::setData(unsigned char data) {
    _sp->_SPDR = data;
}

unsigned char spi::getData() {
    return _sp->_SPDR;
}