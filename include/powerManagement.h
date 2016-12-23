#ifndef LIBATM8A_MCU_H
#define LIBATM8A_MCU_H

#include "common.h"

namespace powerManagement {
    extern powerManagement_Struct volatile *_pm;

    void powerManagement();

    enum sleepMode {
        idle,
        adc_noise_reduction,
        power_down,
        power_save,
        standby
    };

    void setSleepEnable();
    void clearSleepEnable();
    bool getSleepEnable();

    void setSleepMode(sleepMode sm);
    sleepMode getSleepMode();
};


#endif //LIBATM8A_MCU_H
