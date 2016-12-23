#ifndef LIBATM8A_EEPROMMEMORY_H
#define LIBATM8A_EEPROMMEMORY_H

#include "common.h"

namespace eeprom {
    extern eeprom_Struct volatile *_ees;

    void eeprom();

    unsigned char setAddress(unsigned int addr);
    unsigned int getAddress();

    void setData(unsigned char data);
    unsigned char getData();

    void setReadyInterrupt();
    void clearReadyInterrupt();
    bool getReadyInterrupt();

    void setMasterWriteEnable();
    void clearMasterWriteEnable();
    bool getMasterWriteEnable();

    void setWriteEnable();
    void clearWriteEnable();
    bool getWriteEnable();

    void setReadEnable();
    void clearReadEnable();
    bool getReadEnable();
};


#endif //LIBATM8A_EEPROMMEMORY_H
