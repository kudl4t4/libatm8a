#include <gtest/gtest.h>

#include "twi.h"

class twi_ut: public ::testing::Test {
public:
    virtual void SetUp() {
        _twiS = {};
        twi::_twiS = &_twiS;
    }
    virtual void TearDown() {
    }
protected:
    void writeTWBR(unsigned char val) {
        _twiS._TWBR = val;
    }
    unsigned char readTWBR() {
        return _twiS._TWBR;
    }

    void writeTWCR(unsigned char val) {
        _twiS._TWCR = val;
    }
    unsigned char readTWCR() {
        return _twiS._TWCR;
    }

    void writeTWSR(unsigned char val) {
        _twiS._TWSR = 0x08;
        _twiS._TWSR |= val;
    }
    unsigned char readTWSR() {
        _twiS._TWSR |= 0x08;
        return _twiS._TWSR;
    }

    void writeTWDR(unsigned char val) {
        _twiS._TWDR = val;
    }
    unsigned char readTWDR() {
        return _twiS._TWDR;
    }

    void writeTWAR(unsigned char val) {
        _twiS._TWAR = val;
    }
    unsigned char readTWAR() {
        return _twiS._TWAR;
    }
private:
    twi_Struct _twiS;
};

/* TEST CODES */
TEST_F(twi_ut, readInterruptFlag)
{
    writeTWCR(0x80);
    EXPECT_EQ(true, twi::readInterruptFlag());
    writeTWCR(0x00);
    EXPECT_EQ(false, twi::readInterruptFlag());
}
TEST_F(twi_ut, clearInterruptFlag)
{
    twi::clearInterruptFlag();
    EXPECT_EQ(0x80, readTWCR());
}
TEST_F(twi_ut, setEnableAcknowledge)
{
    twi::setEnableAcknowledge();
    EXPECT_EQ(0x40, readTWCR());
}
TEST_F(twi_ut, clearEnableAcknowledge)
{
    writeTWCR(0x40);
    twi::clearEnableAcknowledge();
    EXPECT_EQ(0x00, readTWCR());
}
TEST_F(twi_ut, getEnableAcknowledge)
{
    writeTWCR(0x40);
    EXPECT_EQ(true, twi::getEnableAcknowledge());
    writeTWCR(0x00);
    EXPECT_EQ(false, twi::getEnableAcknowledge());
}
TEST_F(twi_ut, setStartCondition)
{
    twi::setStartCondition();
    EXPECT_EQ(0x20, readTWCR());
}
TEST_F(twi_ut, clearStartCondition)
{
    writeTWCR(0x20);
    twi::clearStartCondition();
    EXPECT_EQ(0x00, readTWCR());
}
TEST_F(twi_ut, getStartCondition)
{
    writeTWCR(0x20);
    EXPECT_EQ(true, twi::getStartCondition());
    writeTWCR(0x00);
    EXPECT_EQ(false, twi::getStartCondition());
}
TEST_F(twi_ut, setStopCondition)
{
    twi::setStopCondition();
    EXPECT_EQ(0x10, readTWCR());
}
TEST_F(twi_ut, clearStopCondition)
{
    writeTWCR(0x10);
    twi::clearStopCondition();
    EXPECT_EQ(0x00, readTWCR());
}
TEST_F(twi_ut, getStopCondition)
{
    writeTWCR(0x10);
    EXPECT_EQ(true, twi::getStopCondition());
    writeTWCR(0x00);
    EXPECT_EQ(false, twi::getStopCondition());
}
TEST_F(twi_ut, readWriteCollisionFlag)
{
    writeTWCR(0x08);
    EXPECT_EQ(true, twi::readWriteCollisionFlag());
    writeTWCR(0x00);
    EXPECT_EQ(false, twi::readWriteCollisionFlag());

}
TEST_F(twi_ut, setTWIEnable)
{
    twi::setTWIEnable();
    EXPECT_EQ(0x04, readTWCR());
}
TEST_F(twi_ut, clearTWIEnable)
{
    writeTWCR(0x04);
    twi::clearTWIEnable();
    EXPECT_EQ(0x00, readTWCR());
}
TEST_F(twi_ut, getTWIEnable)
{
    writeTWCR(0x04);
    EXPECT_EQ(true, twi::getTWIEnable());
    writeTWCR(0x00);
    EXPECT_EQ(false, twi::getTWIEnable());
}
TEST_F(twi_ut, setInterruptEnable)
{
    twi::setInterruptEnable();
    EXPECT_EQ(0x01, readTWCR());
}
TEST_F(twi_ut, clearInterruptEnable)
{
    writeTWCR(0x01);
    twi::clearInterruptEnable();
    EXPECT_EQ(0x00, readTWCR());
}
TEST_F(twi_ut, getInterruptEnable)
{
    writeTWCR(0x01);
    EXPECT_EQ(true, twi::getInterruptEnable());
    writeTWCR(0x00);
    EXPECT_EQ(false, twi::getInterruptEnable());
}
TEST_F(twi_ut, getStatus)
{
    writeTWSR(0xAA);
    EXPECT_EQ(0x15, twi::getStatus());
}
TEST_F(twi_ut, setPrescaler)
{
    twi::setPrescaler(twi::prescaler::_1);
    EXPECT_EQ(0x08, readTWSR());
    twi::setPrescaler(twi::prescaler::_4);
    EXPECT_EQ(0x09, readTWSR());
    twi::setPrescaler(twi::prescaler::_16);
    EXPECT_EQ(0x0A, readTWSR());
    twi::setPrescaler(twi::prescaler::_64);
    EXPECT_EQ(0x0B, readTWSR());
}
TEST_F(twi_ut, getPrescaler)
{
    writeTWSR(0xA0);
    EXPECT_EQ(twi::prescaler::_1, twi::getPrescaler());
    writeTWSR(0xA1);
    EXPECT_EQ(twi::prescaler::_4, twi::getPrescaler());
    writeTWSR(0xA2);
    EXPECT_EQ(twi::prescaler::_16, twi::getPrescaler());
    writeTWSR(0xA3);
    EXPECT_EQ(twi::prescaler::_64, twi::getPrescaler());
}
TEST_F(twi_ut, writeData)
{
    unsigned char val = 0x56;

    twi::writeData(val);
    EXPECT_EQ(val, readTWDR());
}
TEST_F(twi_ut, readData)
{
    unsigned char val = 0x98;
    writeTWDR(val);
    EXPECT_EQ(val, twi::readData());
}
TEST_F(twi_ut, setSlaveAddress)
{
    twi::setSlaveAddress(0xCA);
    EXPECT_EQ(0x94, readTWAR());
}
TEST_F(twi_ut, getSlaveAddress)
{
    writeTWAR(0xCA);
    EXPECT_EQ(0x65, twi::getSlaveAddress());
}
TEST_F(twi_ut, setGeneralCallRecognition)
{
    twi::setGeneralCallRecognition();
    EXPECT_EQ(0x01, readTWAR());
}
TEST_F(twi_ut, clearGeneralCallRecognition)
{
    writeTWAR(0x01);
    twi::clearGeneralCallRecognition();
    EXPECT_EQ(0x00, readTWAR());
}
TEST_F(twi_ut, getGeneralCallRecognition)
{
    writeTWAR(0x01);
    EXPECT_EQ(true, twi::getGeneralCallRecognition());
    writeTWAR(0x00);
    EXPECT_EQ(false, twi::getGeneralCallRecognition());
}
TEST_F(twi_ut, setBitRate)
{
    unsigned char val = 0x67;
    twi::setBitRate(val);
    EXPECT_EQ(val, readTWBR());
}
TEST_F(twi_ut, getBitRate)
{
    unsigned char val = 0x93;
    writeTWBR(val);
    EXPECT_EQ(val, twi::getBitRate());
}
TEST_F(twi_ut, countBitRate)
{
    //F_CPU 1000000
    EXPECT_EQ(0x08, twi::countBitRate(31250, twi::prescaler::_1));
    EXPECT_EQ(0x20, twi::countBitRate(3676, twi::prescaler::_4));
    EXPECT_EQ(0x02, twi::countBitRate(12500, twi::prescaler::_16));
    EXPECT_EQ(0x7F, twi::countBitRate(61, twi::prescaler::_64));
}

