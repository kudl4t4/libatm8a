#ifndef LIBATM8A_ANALOGCOMPARATOR_H
#define LIBATM8A_ANALOGCOMPARATOR_H

#include "common.h"

namespace analogComparator {
    extern analogComparator_Struct volatile *_acS;
    extern combined_Struct volatile *_cbS;

    void analogComparator();

    enum mode {
        interrupt_on_Output_Toggle,
        interrupt_on_Falling_Output_Edge,
        interrupt_on_Rising_Output_Egde
    };

    void offAnalogComparatorMultiplexer();
    void onAnalogComparatorMultiplexer();
    /*!
     * @brief
     *
     * @return 1 - Analog Comparator Multiplexer on
     */
    bool getAnalogComparatorMultiplexer();

    void offAnalogComparator();
    void onAnalogComparator();
    /*!
     * @brief
     *
     * @return 1 - Analog Comparator on
     */
    bool getAnalogComparator();

    void setBandgap();
    void clearBandgap();
    bool getBandgap();

    bool readOutput();

    bool readInterruptFlag();
    void clearInterruptFlag();

    void setInterruptEnable();
    void clearInterruptEnable();
    bool getInterruptEnable();

    void setInputCaptureEnable();
    void clearInputCaptureEnable();
    bool getInputCaptureEnable();

    void setInterruptMode(mode md);
    mode getInterruptMode();
};


#endif //LIBATM8A_ANALOGCOMPARATOR_H
