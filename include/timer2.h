#ifndef LIBATM8A_TIMER2_H
#define LIBATM8A_TIMER2_H

#include "common.h"

namespace timer2 {
    extern timer2_Struct volatile *_t2;
    extern combined_Struct volatile *_cbS;

    void timer2();

    enum compareMode {
        normal_port_operation,
        toggle_on_Compare_Match,
        clear_on_Compare_Match,
        set_on_Compare_Match
    };

    enum waveformMode {
        normal,
        PWM_phaseCorrect,
        clearTimerOnCompareMatch_Output,
        FastPWM
    };

    enum clock {
        no_clk_source,
        clk_1_no_prescaling,
        clk_8_from_prescaler,
        clk_32_from_prescaler,
        clk_64_from_prescaler,
        clk_128_from_prescaler,
        clk_256_from_prescaler,
        clk_1024_from_prescaler
    };

    void setForceOutputCompare();
    void clearForceOutputCompare();

    void setWaveformGenerationMode(waveformMode md);
    waveformMode getWaveformGenerationMode();

    void setCompareOutputMode(compareMode md);
    compareMode getCompareOutputMode();

    void setClockSelect(clock clk);
    clock getClockSelect();

    void setCounterValue(unsigned char value);
    unsigned char getCounterValue();

    void setOutputCompareValue(unsigned char value);
    unsigned char getOutputCompareValue();

    void setAsynchronous();
    bool getAsynchronous();

    bool getTimerCounterUpdateBusy();
    bool getOutputCompareUpdateBusy();
    bool getTimerCounterControlUpdateBusy();

    void setOutputCompareMatchInterrupt();
    void clearOutputCompareMatchInterrupt();
    bool getOutputCompareMatchInterrupt();

    void setOverflowInterrput();
    void clearOverflowInterrput();
    bool getOverflowInterrputInfo();

    void clearOutputCompareMatchFlag();
    bool readOutputCompareMatchFlag();

    void clearOverflowFlag();
    bool readOverflowFlag();

    void timerResetPrescale();
    bool timerCheckIfReset();
};


#endif //LIBATM8A_TIMER2_H
