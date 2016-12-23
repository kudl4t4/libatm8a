#include <gtest/gtest.h>

#include "watchdog.h"

class watchdog_ut: public ::testing::Test {
public:
    virtual void SetUp() {
        _wtchS = {};
        watchdog::_wtch = &_wtchS;
    }
    virtual void TearDown() {
    }
protected:
    void writeMCUCSR(unsigned char val) {
        _wtchS._MCUCSR = val;
    }
    unsigned char readMCUSR() {
        return _wtchS._MCUCSR;
    }

    void writeWDTCR(unsigned char val) {
        _wtchS._WDTCR = val;
    }
    unsigned char readWDTCR() {
        return _wtchS._WDTCR;
    }

private:
    watchdog_Struct _wtchS;
};

/* TEST CODES */
TEST_F(watchdog_ut, getResetSourceFlag)
{
    writeMCUCSR(0x08);
    EXPECT_EQ(watchdog::resetSource::watchDog, watchdog::getResetSourceFlag());
    writeMCUCSR(0x04);
    EXPECT_EQ(watchdog::resetSource::brown_out, watchdog::getResetSourceFlag());
    writeMCUCSR(0x02);
    EXPECT_EQ(watchdog::resetSource::external, watchdog::getResetSourceFlag());
    writeMCUCSR(0x01);
    EXPECT_EQ(watchdog::resetSource::power_on, watchdog::getResetSourceFlag());
}

TEST_F(watchdog_ut, clearResetSourceFlag)
{
    writeMCUCSR(0x0F);
    watchdog::clearResetSourceFlag(watchdog::resetSource::watchDog);
    EXPECT_EQ(0x07, readMCUSR());
    watchdog::clearResetSourceFlag(watchdog::resetSource::brown_out);
    EXPECT_EQ(0x03,readMCUSR());
    watchdog::clearResetSourceFlag(watchdog::resetSource::external);
    EXPECT_EQ(0x01,readMCUSR());
    watchdog::clearResetSourceFlag(watchdog::resetSource::power_on);
    EXPECT_EQ(0x00, readMCUSR());
}

TEST_F(watchdog_ut, setWatchdogChangeEnable)
{
    watchdog::setWatchdogChangeEnable();
    EXPECT_EQ(0x10, readWDTCR());
}

TEST_F(watchdog_ut, clearWatchdogChangeEnable)
{
    writeWDTCR(0x1F);
    watchdog::clearWatchdogChangeEnable();
    EXPECT_EQ(0x0F, readWDTCR());
}

TEST_F(watchdog_ut, getWatchdogChangeEnable)
{
    writeWDTCR(0x1F);
    EXPECT_EQ(true, watchdog::getWatchdogChangeEnable());
    writeWDTCR(0x0F);
    EXPECT_EQ(false, watchdog::getWatchdogChangeEnable());
}

TEST_F(watchdog_ut, setWatchdogEnable)
{
    watchdog::setWatchdogEnable();
    EXPECT_EQ(0x08, readWDTCR());
}

TEST_F(watchdog_ut, clearWatchdogEnable)
{
    writeWDTCR(0x1F);
    watchdog::clearWatchdogEnable();
    EXPECT_EQ(0x17, readWDTCR());
}

TEST_F(watchdog_ut, getWatchdogEnable)
{
    writeWDTCR(0x1F);
    EXPECT_EQ(true, watchdog::getWatchdogEnable());
    writeWDTCR(0x17);
    EXPECT_EQ(false, watchdog::getWatchdogEnable());
}

TEST_F(watchdog_ut, setWatchdogTimerPrescaler)
{
    watchdog::setWatchdogTimerPrescaler(watchdog::timerPrescale::oscillatorCycles_16K);
    EXPECT_EQ(0x00, readWDTCR());
    watchdog::setWatchdogTimerPrescaler(watchdog::timerPrescale::oscillatorCycles_32K);
    EXPECT_EQ(0x01, readWDTCR());
    watchdog::setWatchdogTimerPrescaler(watchdog::timerPrescale::oscillatorCycles_64K);
    EXPECT_EQ(0x02, readWDTCR());
    watchdog::setWatchdogTimerPrescaler(watchdog::timerPrescale::oscillatorCycles_128K);
    EXPECT_EQ(0x03, readWDTCR());
    watchdog::setWatchdogTimerPrescaler(watchdog::timerPrescale::oscillatorCycles_256K);
    EXPECT_EQ(0x04, readWDTCR());
    watchdog::setWatchdogTimerPrescaler(watchdog::timerPrescale::oscillatorCycles_512K);
    EXPECT_EQ(0x05, readWDTCR());
    watchdog::setWatchdogTimerPrescaler(watchdog::timerPrescale::oscillatorCycles_1024K);
    EXPECT_EQ(0x06, readWDTCR());
    watchdog::setWatchdogTimerPrescaler(watchdog::timerPrescale::oscillatorCycles_2048K);
    EXPECT_EQ(0x07, readWDTCR());
}

TEST_F(watchdog_ut, getWatchdogTimerPrescaler)
{
    writeWDTCR(0x18);
    EXPECT_EQ(watchdog::timerPrescale::oscillatorCycles_16K, watchdog::getWatchdogTimerPrescaler());
    writeWDTCR(0x19);
    EXPECT_EQ(watchdog::timerPrescale::oscillatorCycles_32K, watchdog::getWatchdogTimerPrescaler());
    writeWDTCR(0x1A);
    EXPECT_EQ(watchdog::timerPrescale::oscillatorCycles_64K, watchdog::getWatchdogTimerPrescaler());
    writeWDTCR(0x1B);
    EXPECT_EQ(watchdog::timerPrescale::oscillatorCycles_128K, watchdog::getWatchdogTimerPrescaler());
    writeWDTCR(0x1C);
    EXPECT_EQ(watchdog::timerPrescale::oscillatorCycles_256K, watchdog::getWatchdogTimerPrescaler());
    writeWDTCR(0x1D);
    EXPECT_EQ(watchdog::timerPrescale::oscillatorCycles_512K, watchdog::getWatchdogTimerPrescaler());
    writeWDTCR(0x1E);
    EXPECT_EQ(watchdog::timerPrescale::oscillatorCycles_1024K, watchdog::getWatchdogTimerPrescaler());
    writeWDTCR(0x1F);
    EXPECT_EQ(watchdog::timerPrescale::oscillatorCycles_2048K, watchdog::getWatchdogTimerPrescaler());
}

