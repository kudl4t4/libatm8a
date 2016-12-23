/** @file adc.h
 *  @brief Namespace for the AVR Analog to Digital Converter
 *
 * Features
 * \n• 10-bit Resolution
 * \n• 0.5LSB Integral Non-Linearity
 * \n• ±2LSB Absolute Accuracy
 * \n• 13 - 260μs Conversion Time
 * \n• Up to 15kSPS at Maximum Resolution
 * \n• Six Multiplexed Single Ended Input Channels
 * \n• Two Additional Multiplexed Single Ended Input Channels (TQFP and QFN/MLF Package only)
 * \n• Optional Left Adjustment for ADC Result Readout
 * \n• 0 - VCC ADC Input Voltage Range
 * \n• Selectable 2.56V ADC Reference Voltage
 * \n• Free Running or Single Conversion Mode
 * \n• Interrupt on ADC Conversion Complete
 * \n• Sleep Mode Noise Canceler
 */

#ifndef LIBATM8A_ADC_H
#define LIBATM8A_ADC_H

#include "common.h"

namespace adc {

    extern adc_Struct volatile *_adS;

    void adc();

    enum reference {
        aref_internal_turned_off,
        avcc_external_capacitor_at_aref_pin,
        internal_2_56V_vol_reference_with_external_capacitor_at_aref_pin
    };

    enum channel {
        adc0,
        adc1,
        adc2,
        adc3,
        adc4,
        adc5,
        adc6,
        adc7,
        _1_30V_Vbg,
        _0_00V_Gnd
    };

    enum prescaler {
        _2_1,
        _2_2,
        _4,
        _8,
        _16,
        _32,
        _64,
        _128
    };

    void setReference(reference ref);
    reference getReference();

    void setLeftAdjustResult();
    void clearLeftAdjustResult();
    bool getLeftAdjustResult();

    void setChannel(channel ch);
    channel getChannel();

    void setEnable();
    void clearEnable();
    bool getEnable();

    void setStartConversion();
    void clearStartConversion();
    bool getStartConversion();

    void setFreeRunning();
    void clearFreeRunning();
    bool getFreeRunning();

    bool readInterruptFlag();
    void clearInterruptFlag();

    void setInterruptEnable();
    void clearInterruptEnable();
    bool getInterruptEnable();

    void setPrescaler(prescaler pr);
    prescaler getPrescaler();

    unsigned int getData();
};


#endif //LIBATM8A_ADC_H
