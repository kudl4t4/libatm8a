#ifndef LIBATM8A_IOPORT_H
#define LIBATM8A_IOPORT_H

#include "common.h"

namespace ioport {
    extern ioport_Struct volatile *_io;
    extern combined_Struct volatile *_cbS;

    void ioportB();
    void ioportC();
    void ioportD();

    void setOuputPinLow(unsigned char pinNo);
    void setOutputPinHigh(unsigned char pinNo);
    void setOutputPinToggle(unsigned char pinNo);
    void setOutputPin(unsigned char pinNo);

    void setOuputBitsLow(unsigned char bits);
    void setOutputBitsHigh(unsigned char bits);
    void setOutputBitsToggle(unsigned char bits);
    void setOutputBits(unsigned char bits);

    void setInputPulledUp(unsigned char pinNo);

    unsigned char readPin(unsigned char pinNo, bool *retValue);

    void setPullUpDisable();
    void clearPullUpDisable();
    bool getPullUpDisable();

};


#endif //LIBATM8A_IOPORT_H
