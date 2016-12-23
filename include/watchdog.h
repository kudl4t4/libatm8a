#ifndef LIBATM8A_WATCHDOG_H
#define LIBATM8A_WATCHDOG_H

#include "common.h"

namespace watchdog {
    extern watchdog_Struct volatile *_wtch;

    void watchdog();

    enum resetSource {
        watchDog,
        brown_out,
        external,
        power_on
    };

    enum timerPrescale {
        oscillatorCycles_16K,
        oscillatorCycles_32K,
        oscillatorCycles_64K,
        oscillatorCycles_128K,
        oscillatorCycles_256K,
        oscillatorCycles_512K,
        oscillatorCycles_1024K,
        oscillatorCycles_2048K
    };

    resetSource getResetSourceFlag();
    void clearResetSourceFlag(resetSource fl);

    void setWatchdogChangeEnable();
    void clearWatchdogChangeEnable();
    bool getWatchdogChangeEnable();

    void setWatchdogEnable();
    void clearWatchdogEnable();
    bool getWatchdogEnable();

    void setWatchdogTimerPrescaler(timerPrescale tp);
    timerPrescale getWatchdogTimerPrescaler();
};


#endif //LIBATM8A_WATCHDOG_H
