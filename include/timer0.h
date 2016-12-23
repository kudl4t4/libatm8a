#ifndef LIBATM8A_TIMER0_H
#define LIBATM8A_TIMER0_H

#include "common.h"

namespace timer0 {

    extern timer0_Struct volatile *_t0;
    extern combined_Struct volatile *_cbS;

    void timer0();

    enum clock {
        no_clk_source,
        clk_1_no_prescaling,
        clk_8_from_prescaler,
        clk_64_from_prescaler,
        clk_256_from_prescaler,
        clk_1024_from_prescaler,
        external_falling_edge,
        external_rising_edge
    };

    void setClockSelect(clock clk);
    clock getClockSelect();

    void setCounterValue(unsigned char value);
    unsigned char getCounterValue();

    void setOverflowInterrput();
    void clearOverflowInterrput();
    bool getOverflowInterrputInfo();

    void clearOverflowFlag();
    bool readOverflowFlag();

    void timerResetPrescale();
    bool timerCheckIfReset();
};


#endif //LIBATM8A_TIMER0_H
