#ifndef LIBATM8A_AVRSTATUS_H
#define LIBATM8A_AVRSTATUS_H

#include "common.h"

namespace avrStatus {
    extern avrStatus_Struct volatile *_sregS;

    void avrStatus();

    void setGlobalInterruptEnable();
    void clearGlobalInterruptEnable();
    bool getGlobalInterruptEnable();

    bool getCopyStorageFlag();
    bool getHalfCarryFlag();
    bool getSignBitFlag();
    bool getTwoComplementOverflowFlag();
    bool getNegativeFlag();
    bool getZeroFlag();
    bool getCarryFlag();
};


#endif //LIBATM8A_AVRSTATUS_H
