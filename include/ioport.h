#ifndef LIBATM8A_IOPORT_H
#define LIBATM8A_IOPORT_H

#include "common.h"

namespace ioport {
    extern combined_Struct volatile *_cbS;
    extern ioport_Struct volatile *_io;

    void ioport();

    typedef void (*ioportXFunct)(void);
    inline void ioportB() __attribute__((always_inline));
	void ioportB() {
#ifndef T_UNITTEST
		_io = _iportB;
#endif
	}
    inline void ioportC() __attribute__((always_inline));
	void ioportC() {
#ifndef T_UNITTEST
		_io = _iportC;
#endif
	}
    inline void ioportD() __attribute__((always_inline));
	void ioportD() {
#ifndef T_UNITTEST
		_io = _iportD;
#endif
	}

    void setOutputPinLow(ioportXFunct func, unsigned char pinNo);
    void setOutputPinHigh(ioportXFunct func, unsigned char pinNo);
    void setOutputPinToggle(ioportXFunct func, unsigned char pinNo);
    void setOutputPin(ioportXFunct func, unsigned char pinNo);

    void setOutputBitsLow(ioportXFunct func, unsigned char bits);
    void setOutputBitsHigh(ioportXFunct func, unsigned char bits);
    void setOutputBitsToggle(ioportXFunct func, unsigned char bits);
    void setOutputBits(ioportXFunct func, unsigned char bits);

    void setInputPulledUp(ioportXFunct func, unsigned char pinNo);

    unsigned char readPin(ioportXFunct func, unsigned char pinNo, bool *retValue);

    void setPullUpDisable();
    void clearPullUpDisable();
    bool getPullUpDisable();

};


#endif //LIBATM8A_IOPORT_H
