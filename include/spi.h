#ifndef LIBATM8A_SPI_H
#define LIBATM8A_SPI_H

#include "common.h"

namespace spi {
    extern spi_Struct volatile *_sp;

    void spi();

    enum dataOrder {
        LSB_fisrt,
        MSB_first
    };

    enum mode {
        master,
        slave
    };

    enum clockPolarity {
        sck_low_when_idle,
        sck_high_when_idle
    };

    enum clockPhase {
        leading_edge,
        trailing_edge
    };

    enum clockRate {
        fosc_4,
        fosc_16,
        fosc_64_1,
        fosc_128,
        fosc_2,
        fosc_8,
        fosc_32,
        fosc_64_2
    };

    void setEnableSpi();
    void clearEnableSpi();
    bool getEnableSpi();

    void setInterruptEnable();
    void clearInterruptEnable();
    bool getInterruptEnable();

    void setDataOrder(dataOrder dt);
    dataOrder getDataOrder();

    void setModeSelect(mode md);
    mode getModeSelect();

    void setClockPolarity(clockPolarity cp);
    clockPolarity getClockPolarity();

    void setClockPhase(clockPhase cp);
    clockPhase getClockPhase();

    void setClockRate(clockRate cr);
    clockRate getClockRate();

    bool getInterruptFlag();
    bool getWriteCollisionFlag();

    void setData(unsigned char data);
    unsigned char getData();
};


#endif //LIBATM8A_SPI_H
