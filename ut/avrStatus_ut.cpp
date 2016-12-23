#include <gtest/gtest.h>

#include "avrStatus.h"

class avrStatus_ut: public ::testing::Test {
private:
    avrStatus_Struct _sregS;
protected:
    unsigned char readSREG() {
        return _sregS._SREG;
    }
    void writeSREG(unsigned char value) {
        _sregS._SREG = value;
    }
public:
    virtual void SetUp() {
        _sregS = {};
        avrStatus::_sregS = &_sregS;
    }
    virtual void TearDown() {
    }
};

/* TEST CODES */
TEST_F(avrStatus_ut, setGlobalInterruptEnable)
{
    avrStatus::setGlobalInterruptEnable();
    EXPECT_EQ(0x80, readSREG());
}
TEST_F(avrStatus_ut, clearGlobalInterruptEnable)
{
    writeSREG(0x80);
    avrStatus::clearGlobalInterruptEnable();
    EXPECT_EQ(0x00, readSREG());
}
TEST_F(avrStatus_ut, getGlobalInterruptEnable)
{
    writeSREG(0x80);
    EXPECT_EQ(true, avrStatus::getGlobalInterruptEnable());
    writeSREG(0x0F);
    EXPECT_EQ(false, avrStatus::getGlobalInterruptEnable());
}
TEST_F(avrStatus_ut, getCopyStorageFlag)
{
    writeSREG(0x40);
    EXPECT_EQ(true, avrStatus::getCopyStorageFlag());
    writeSREG(0x0F);
    EXPECT_EQ(false, avrStatus::getCopyStorageFlag());
}
TEST_F(avrStatus_ut, getHalfCarryFlag)
{
    writeSREG(0x20);
    EXPECT_EQ(true, avrStatus::getHalfCarryFlag());
    writeSREG(0x0F);
    EXPECT_EQ(false, avrStatus::getHalfCarryFlag());
}
TEST_F(avrStatus_ut, getSignBitFlag)
{
    writeSREG(0x10);
    EXPECT_EQ(true, avrStatus::getSignBitFlag());
    writeSREG(0x0F);
    EXPECT_EQ(false, avrStatus::getSignBitFlag());
}
TEST_F(avrStatus_ut, getTwoComplementOverflowFlag)
{
    writeSREG(0x08);
    EXPECT_EQ(true, avrStatus::getTwoComplementOverflowFlag());
    writeSREG(0xF0);
    EXPECT_EQ(false, avrStatus::getTwoComplementOverflowFlag());
}
TEST_F(avrStatus_ut, getNegativeFlag)
{
    writeSREG(0x04);
    EXPECT_EQ(true, avrStatus::getNegativeFlag());
    writeSREG(0xF0);
    EXPECT_EQ(false, avrStatus::getNegativeFlag());
}
TEST_F(avrStatus_ut, getZeroFlag)
{
    writeSREG(0x02);
    EXPECT_EQ(true, avrStatus::getZeroFlag());
    writeSREG(0xF0);
    EXPECT_EQ(false, avrStatus::getZeroFlag());
}
TEST_F(avrStatus_ut, getCarryFlag)
{
    writeSREG(0x01);
    EXPECT_EQ(true, avrStatus::getCarryFlag());
    writeSREG(0xF0);
    EXPECT_EQ(false, avrStatus::getCarryFlag());
}

