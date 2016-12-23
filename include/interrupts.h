#ifndef LIBATM8A_INTERRUPTS_H
#define LIBATM8A_INTERRUPTS_H

#include "common.h"

namespace interrupts {
    extern interrupts_Struct volatile *_intS;

    void interrupts();

    enum externalInterrupt {
        interrupt_0,
        interrupt_1
    };

    enum senseControl {
        low_level,
        any_logical,
        falling_edge,
        rising_edge
    };

    void setInterruptVectorPlaceSelect();
    void clearInterruptVectorPlaceSelect();
    bool getInterruptVectorPlaceSelect();

    void setInterruptVectorChangeEnable();
    void clearInterruptVectorChangeEnable();
    bool getInterruptVectorChangeEnable();

    void setExternalInterruptRequest(externalInterrupt ex);
    void clearExternalInterruptRequest(externalInterrupt ex);
    bool getExternalInterruptRequest(externalInterrupt ex);

    void setInterruptSenseControl(externalInterrupt ex, senseControl sc);
    senseControl getInterruptSenseControl(externalInterrupt ex);

    void clearExternalInterruptFlag(externalInterrupt ex);
    bool getExternalInterruptFlag(externalInterrupt ex);
};


#endif //LIBATM8A_INTERRUPTS_H
