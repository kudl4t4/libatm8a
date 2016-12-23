#include <gtest/gtest.h>

#include "powerManagement.h"

class powerManagement_ut: public ::testing::Test {
public:
    virtual void SetUp() {
        _pm = {};
        powerManagement::_pm = &_pm;
    }
    virtual void TearDown() {
    }
protected:
    void writeMCUCR(unsigned char val) {
        _pm._MCUCR = val;
    }
    unsigned char readMCUCR() {
        return _pm._MCUCR;
    }
private:
    powerManagement_Struct _pm;
};

/* TEST CODES */
TEST_F(powerManagement_ut, setSleepEnable)
{
    powerManagement::setSleepEnable();
    EXPECT_EQ((1<<5), readMCUCR());
}

TEST_F(powerManagement_ut, clearSleepEnable)
{
    writeMCUCR(1<<5);
    EXPECT_EQ((1<<5), readMCUCR());
    powerManagement::clearSleepEnable();
    EXPECT_EQ(0x00, readMCUCR());
}

TEST_F(powerManagement_ut, getSleepEnable)
{
    writeMCUCR(1<<5);
    EXPECT_EQ((1<<5), readMCUCR());
    EXPECT_EQ(true, powerManagement::getSleepEnable());
    writeMCUCR(0x00);
    EXPECT_EQ(false, powerManagement::getSleepEnable());
}

TEST_F(powerManagement_ut, setSleepMode)
{
    powerManagement::setSleepMode(powerManagement::sleepMode::idle);
    EXPECT_EQ(0x00, readMCUCR());
    powerManagement::setSleepMode(powerManagement::sleepMode::adc_noise_reduction);
    EXPECT_EQ(0x10, readMCUCR());
    powerManagement::setSleepMode(powerManagement::sleepMode::power_down);
    EXPECT_EQ(0x20, readMCUCR());
    powerManagement::setSleepMode(powerManagement::sleepMode::power_save);
    EXPECT_EQ(0x30, readMCUCR());
    powerManagement::setSleepMode(powerManagement::sleepMode::standby);
    EXPECT_EQ(0x60, readMCUCR());
}

TEST_F(powerManagement_ut, getSleepMode)
{
    writeMCUCR(0x80);
    EXPECT_EQ(powerManagement::sleepMode::idle, powerManagement::getSleepMode());
    writeMCUCR(0x90);
    EXPECT_EQ(powerManagement::sleepMode::adc_noise_reduction, powerManagement::getSleepMode());
    writeMCUCR(0xA0);
    EXPECT_EQ(powerManagement::sleepMode::power_down, powerManagement::getSleepMode());
    writeMCUCR(0xB0);
    EXPECT_EQ(powerManagement::sleepMode::power_save, powerManagement::getSleepMode());
    writeMCUCR(0xE0);
    EXPECT_EQ(powerManagement::sleepMode::standby, powerManagement::getSleepMode());
}