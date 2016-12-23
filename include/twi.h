#ifndef LIBATM8A_TWI_H
#define LIBATM8A_TWI_H

#include "common.h"

namespace twi {
    extern twi_Struct volatile *_twiS;

    void twi();

    enum prescaler {
        _1,
        _4,
        _16,
        _64
    };

    bool readInterruptFlag();
    void clearInterruptFlag();

    void setEnableAcknowledge();
    void clearEnableAcknowledge();
    bool getEnableAcknowledge();

    void setStartCondition();
    void clearStartCondition();
    bool getStartCondition();

    void setStopCondition();
    void clearStopCondition();
    bool getStopCondition();

    bool readWriteCollisionFlag();

    void setTWIEnable();
    void clearTWIEnable();
    bool getTWIEnable();

    void setInterruptEnable();
    void clearInterruptEnable();
    bool getInterruptEnable();

    unsigned char getStatus();

    void setPrescaler(prescaler ps);
    prescaler getPrescaler();

    void writeData(unsigned char val);
    unsigned char readData();

    void setSlaveAddress(unsigned char addr);
    unsigned char getSlaveAddress();

    void setGeneralCallRecognition();
    void clearGeneralCallRecognition();
    bool getGeneralCallRecognition();

    void setBitRate(unsigned char val);
    unsigned char getBitRate();

    /*!
     * @brief
     * @param sclFreq
     * @param pres
     * @return
     */
    unsigned char countBitRate(unsigned long int sclFreq, prescaler pres);
};


#endif //LIBATM8A_TWI_H
