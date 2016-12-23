#ifndef LIBATM8A_TIMER1_H
#define LIBATM8A_TIMER1_H

#include "common.h"

namespace timer1 {
    extern timer1_Struct volatile *_t1;
    extern combined_Struct volatile *_cbS;

    void timer1();

    enum channel {
        channel_A,
        channel_B
    };
    enum compareMode {
        normal_port_operation,
        toggle_on_Compare_Match,
        clear_on_Compare_Match,
        set_on_Compare_Match
    };

    enum waveformMode {
        normal,
        PWM_phaseCorrect_08bit,
        PWM_phaseCorrect_09bit,
        PWM_phaseCorrect_10bit,
        clearTimerOnCompareMatch_Output,
        FastPWM_08bit,
        FastPWM_09bit,
        FastPWM_10bit,
        PWM_phaseFreqCorrect_Input,
        PWM_phaseFreqCorrect_Output,
        PWM_phaseCorrect_Input,
        PWM_phaseCorrect_Output,
        clearTimerOnCompareMatch_Input,
        FastPWM_Input,
        FastPWM_Output
    };

    enum edge {
        rising,
        falling
    };

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

    void setCompareOutputMode(channel ch, compareMode md);
    compareMode getCompareOutputMode(channel ch);

    void setForceOutputCompare(channel ch);
    void clearForceOutputCompare(channel ch);

    void setWaveformGenerationMode(waveformMode md);
    waveformMode getWaveformGenerationMode();

    void setInputCaptureNoiseCanceler();
    void clearInputCaptureNoiseCanceler();
    bool getInputCaptureNoiseCanceler();

    void setInputCaptureEdgeSelect(edge e);
    edge getInputCaptureEdgeSelect();

    void setClockSelect(clock clk);
    clock getClockSelect();

    void setCounterValue(unsigned int value);
    unsigned int getCounterValue();

    void setOutputCompareValue(channel ch, unsigned int value);
    unsigned int getOutputCompareValue(channel ch);

    void setInputCompareValue(unsigned int value);
    unsigned int getInputCompareValue();

    void setInputCaptureInterrupt();
    void clearInputCaptureInterrupt();
    bool getInputCaptureInterrupt();

    void setOutputCompareMatchInterrupt(channel ch);
    void clearOutputCompareMatchInterrupt(channel ch);
    bool getOutputCompareMatchInterrupt(channel ch);

    void setOverflowInterrput();
    void clearOverflowInterrput();
    bool getOverflowInterrputInfo();

    void clearInputCaptureFlag();
    bool readInputCaptureFlag();

    void clearOutputCompareMatchFlag(channel ch);
    bool readOutputCompareMatchFlag(channel ch);

    void clearOverflowFlag();
    bool readOverflowFlag();

    void timerResetPrescale();
    bool timerCheckIfReset();

};


#endif //LIBATM8A_TIMER1_H
