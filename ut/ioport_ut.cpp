#include <gtest/gtest.h>

#include "ioport.h"

enum portNo {
    B,
    C,
    D
};

class ioport_ut: public ::testing::Test {
public:
    virtual void SetUp() {
        _ioportB = {};
        _ioportC = {};
        _ioportD = {};
        _cbS = {};
        ioport::_cbS = &_cbS;
    }
    virtual void TearDown() {
    }
protected:
    ioport_Struct _ioportB;
    ioport_Struct _ioportC;
    ioport_Struct _ioportD;
    combined_Struct _cbS;

    ioport::ioportXFunct _func;

    void ioportB(void) {
        ioport::_io = &_ioportB;
    }
    void ioportC(void) {
        ioport::_io = &_ioportC;
    }
    void ioportD(void) {
        ioport::_io = &_ioportD;
    }

        unsigned char getPIN(portNo no) {
        switch (no) {
            case portNo::B:
                return _ioportB._PINx;
            case portNo::C:
                return _ioportC._PINx;
            case portNo::D:
                return _ioportD._PINx;
        }
    }

    unsigned char getDDR(portNo no) {
        switch (no) {
            case portNo::B:
                return _ioportB._DDRx;
            case portNo::C:
                return _ioportC._DDRx;
            case portNo::D:
                return _ioportD._DDRx;
        }
    }

    unsigned char getPORT(portNo no) {
        switch (no) {
            case portNo::B:
                return _ioportB._PORTx;
            case portNo::C:
                return _ioportC._PORTx;
            case portNo::D:
                return _ioportD._PORTx;
        }
    }

    void setFullPORT(portNo no) {
        switch (no) {
            case B:
                _ioportB._PORTx = 0xFF;
                break;
            case C:
                _ioportC._PORTx = 0xFF;
                break;
            case D:
                _ioportD._PORTx = 0xFF;
                break;
        }

    }

    void setFullDDR(portNo no) {
        switch (no) {
            case B:
                _ioportB._DDRx = 0xFF;
                break;
            case C:
                _ioportC._DDRx = 0xFF;
                break;
            case D:
                _ioportD._DDRx = 0xFF;
                break;
        }

    }

    void setFullPIN(portNo no) {
        switch (no) {
            case B:
                _ioportB._PINx = 0xFF;
                break;
            case C:
                _ioportC._PINx = 0xFF;
                break;
            case D:
                _ioportD._PINx = 0xFF;
                break;
        }
    }

    void writeSFIOR(unsigned char val) {
        _cbS._SFIOR = 0xFF;
    }
    unsigned char readSFIOR() {
        return _cbS._SFIOR;
    }
private:
};

/* TEST CODES */
TEST_F(ioport_ut, setOutputHigh)
{
    unsigned char pinNo = 5;

    _func = &(ioport::ioportB);
    ioport::_io = &_ioportB;
    ioport::setOutputPinHigh(_func, pinNo);

    EXPECT_EQ((1<<pinNo), getDDR(B));
    EXPECT_EQ((1<<pinNo), getPORT(B));
}

TEST_F(ioport_ut, setOuputLow)
{
    unsigned char pinNo = 0;
    unsigned char revPinNo = ~(1<<pinNo);
    setFullPORT(C);

    _func = &(ioport::ioportC);
    ioport::_io = &_ioportC;
    ioport::setOutputPinLow(_func, pinNo);

    EXPECT_EQ((1<<pinNo), getDDR(C));
    EXPECT_EQ(revPinNo, getPORT(C));
}

TEST_F(ioport_ut, setInputPulledUp)
{
    unsigned char pinNo = 3;
    unsigned char revPinNo = ~(1<<pinNo);
    setFullDDR(D);

    _func = &(ioport::ioportD);
    ioport::_io = &_ioportD;
    ioport::setInputPulledUp(_func, pinNo);

    EXPECT_EQ(revPinNo, getDDR(D));
    EXPECT_EQ((1<<pinNo), getPORT(D));
}

TEST_F(ioport_ut, readPin)
{
    unsigned char pinNo = 7;
    setFullPIN(B);

    unsigned char ret = 10;
    bool read = false;

    _func = &(ioport::ioportB);
    ioport::_io = &_ioportB;
    ret = ioport::readPin(_func, pinNo, &read);

    EXPECT_EQ(2, ret);

    ret = 10;
    setFullDDR(B);
    ret = ioport::readPin(_func, pinNo, &read);

    EXPECT_EQ(0, ret);
    EXPECT_EQ(true, read);
}

TEST_F(ioport_ut, setPullUpDisable)
{
    ioport::setPullUpDisable();
    EXPECT_EQ(0x04, readSFIOR());
    ioport::clearPullUpDisable();
    EXPECT_EQ(0x00, readSFIOR());
}

TEST_F(ioport_ut, clearPullUpDisable)
{
    ioport::setPullUpDisable();
    EXPECT_EQ(0x04, readSFIOR());
    ioport::clearPullUpDisable();
    EXPECT_EQ(0x00, readSFIOR());
}

TEST_F(ioport_ut, getPullUpDisable)
{
    ioport::setPullUpDisable();
    EXPECT_EQ(true, ioport::getPullUpDisable());
    ioport::clearPullUpDisable();
    EXPECT_EQ(false, ioport::getPullUpDisable());
}