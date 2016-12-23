#ifndef LIBATM8A_BOOTLOADERSUPPORT_H
#define LIBATM8A_BOOTLOADERSUPPORT_H

#include "common.h"

namespace bootLoaderSupport {
    extern bootLoaderSupport_Struct volatile *_btsS;

    void bootLoaderSupport();

    void setInterruptEnable();
    void clearInterruptEnable();
    bool getInterruptEnable();

    bool readReadWhileWriteSectionBusyFlag();

    void setReadWhileWriteSectionBusyEnable();
    void clearReadWhileWriteSectionBusyEnable();
    bool getReadWhileWriteSectionBusyEnable();

    void setBootLockBit();
    void clearBootLockBit();
    bool getBootLockBit();

    void setPageWrite();
    void clearPageWrite();
    bool getPageWrite();

    void setPageErase();
    void clearPageErase();
    bool getPageErase();

    void setStoreProgramMemory();
    void clearStoreProgramMemory();
    bool getStoreProgramMemory();
};


#endif //LIBATM8A_BOOTLOADERSUPPORT_H
