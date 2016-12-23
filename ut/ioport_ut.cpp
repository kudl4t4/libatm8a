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
            case C:
                _ioportC._PORTx = 0xFF;
            case D:
                _ioportD._PORTx = 0xFF;
        }

    }

    void setFullDDR(portNo no) {
        switch (no) {
            case B:
                _ioportB._DDRx = 0xFF;
            case C:
                _ioportC._DDRx = 0xFF;
            case D:
                _ioportD._DDRx = 0xFF;
        }

    }

    void setFullPIN(portNo no) {
        switch (no) {
            case B:
                _ioportB._PINx = 0xFF;
            case C:
                _ioportC._PINx = 0xFF;
            case D:
                _ioportD._PINx = 0xFF;
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

    ioport::_io = &_ioportB;
    ioport::setOutputPinHigh(pinNo);

    EXPECT_EQ((1<<pinNo), getDDR(B));
    EXPECT_EQ((1<<pinNo), getPORT(B));
}

TEST_F(ioport_ut, setOuputLow)
{
    unsigned char pinNo = 0;
    unsigned char revPinNo = ~(1<<pinNo);
    setFullPORT(C);

    ioport::_io = &_ioportC;
    ioport::setOuputPinLow(pinNo);

    EXPECT_EQ((1<<pinNo), getDDR(C));
    EXPECT_EQ(revPinNo, getPORT(C));
}

TEST_F(ioport_ut, setInputPulledUp)
{
    unsigned char pinNo = 3;
    unsigned char revPinNo = ~(1<<pinNo);
    setFullDDR(D);

    ioport::_io = &_ioportD;
    ioport::setInputPulledUp(pinNo);

    EXPECT_EQ(revPinNo, getDDR(D));
    EXPECT_EQ((1<<pinNo), getPORT(D));
}

TEST_F(ioport_ut, readPin)
{
    unsigned char pinNo = 7;
    setFullPIN(B);

    unsigned char ret = 10;
    bool read = false;

    ioport::_io = &_ioportB;
    ret = ioport::readPin(pinNo, &read);

    EXPECT_EQ(2, ret);

    ret = 10;
    setFullDDR(B);
    ret = ioport::readPin(pinNo, &read);

    EXPECT_EQ(0, ret);
    EXPECT_EQ(true, read);
}

TEST_F(ioport_ut, setPullUpDisable)
{
    ioport::_io = &_ioportB;
    ioport::setPullUpDisable();
    EXPECT_EQ(0x04, readSFIOR());
    ioport::clearPullUpDisable();
    EXPECT_EQ(0x00, readSFIOR());
}

TEST_F(ioport_ut, clearPullUpDisable)
{
    ioport::_io = &_ioportD;
    ioport::setPullUpDisable();
    EXPECT_EQ(0x04, readSFIOR());
    ioport::clearPullUpDisable();
    EXPECT_EQ(0x00, readSFIOR());
}

TEST_F(ioport_ut, getPullUpDisable)
{
    ioport::_io = &_ioportD;
    ioport::setPullUpDisable();
    ioport::_io = &_ioportC;
    EXPECT_EQ(true, ioport::getPullUpDisable());
    ioport::clearPullUpDisable();
    EXPECT_EQ(false, ioport::getPullUpDisable());
}