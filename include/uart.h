#ifndef LIBATM8A_UART_H
#define LIBATM8A_UART_H

#include "common.h"

namespace uart {
    extern uart_Struct volatile *_utS;

    void uart();

    enum mode {
        asynchronous,
        synchronous
    };

    enum parity {
        disabled,
        even_parity,
        odd_parity
    };

    enum stopBit {
        one_bit,
        two_bit
    };

    enum characterSize {
        _5_bit,
        _6_bit,
        _7_bit,
        _8_bit,
        _9_bit
    };

    enum clockPolarity {
        risingTX_fallingRX,
        fallingTX_risingRX
    };

    enum baudRate {
        _2400,
        _4800,
        _9600,
        _14400,
        _19200,
        _28800,
        _38400,
        _57600,
        _76800,
        _115200,
        _230400,
        _250000,
        _500000,
        _1000000
    };

    extern baudRate _setBaud;

    bool readReceiveCompleteFlag();
    bool readDataRegisterEmptyFlag();
    bool readFrameErrorFlag();
    bool readDataOverRunFlag();
    bool readParityErrorFlag();

    bool readTransmitCompleteFlag();
    void clearTransmitCompleteFlag();
    void setDoubleTransmissionSpeed();
    void clearDoubleTransmissionSpeed();
    bool getDoubleTransmissionSpeed();

    void setMultiprocessorCommunicationMode();
    void clearMultiprocessorCommunicationMode();
    bool getMultiprocessorCommunicationMode();


    void setRXCompleteInterrupt();
    void clearRXCompleteInterrupt();
    bool getRXCompleteInterrupt();

    void setTXCompleteInterrupt();
    void clearTXCompleteInterrupt();
    bool getTXCompleteInterrupt();

    void setDataRegisterEmptyInterrupt();
    void clearDataRegisterEmptyInterrupt();
    bool getDataRegisterEmptyInterrupt();

    void setReceiverEnable();
    void clearReceiverEnable();
    bool getReceiverEnable();

    void setTransmitterEnable();
    void clearTransmitterEnable();
    bool getTransmitterEnable();

    void setMode(mode md);
    mode getMode();

    void setParity(parity pp);
    parity getParity();

    void setStopBit(stopBit sb);
    stopBit getStopBit();

    void setCharacterSize(characterSize chs);
    characterSize getCharacterSize();

    void setClockPolarity(clockPolarity cp);
    clockPolarity getClockPolarity();

    void setBaudRate(baudRate val);
    baudRate getBaudRate();
    unsigned long int getRealBaudRate();

    void writeData(unsigned int val);
    unsigned int readData();
};


#endif //LIBATM8A_UART_H
