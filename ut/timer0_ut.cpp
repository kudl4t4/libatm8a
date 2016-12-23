#include <gtest/gtest.h>

#include "timer0.h"

class timer0_ut: public ::testing::Test {
private:
    timer0_Struct _tim0;
    combined_Struct _cbS;
protected:

    unsigned char readTCCR0() {
        return _tim0._TCCR0;
    }
    void setTCCR0(unsigned char value) {
        _tim0._TCCR0 = value;
    }
    unsigned char readTCNT0() {
        return _tim0._TCNT0;
    }
    void setTCNT0(unsigned char value) {
        _tim0._TCNT0 = value;
    }
    unsigned char readTIMSK() {
        return _cbS._TIMSK;
    }
    void setTIMSK(unsigned char value) {
        _cbS._TIMSK = value;
    }
    unsigned char readTIFR() {
        return _cbS._TIFR;
    }
    void setTIFR(unsigned char value) {
        _cbS._TIFR = value;
    }
    unsigned char readSFIOR() {
        return _cbS._SFIOR;
    }
    void setSFIOR(unsigned char value) {
        _cbS._SFIOR = value;
    }
public:
    virtual void SetUp() {
        _tim0 = {};
        _cbS = {};
        timer0::_t0 = &_tim0;
        timer0::_cbS = &_cbS;
    }
    virtual void TearDown() {
    }
};

/* TEST CODES */
TEST_F(timer0_ut, setClockSelect)
{
    
    timer0::setClockSelect(timer0::no_clk_source);
    EXPECT_EQ(0, readTCCR0());
    timer0::setClockSelect(timer0::clk_1_no_prescaling);
    EXPECT_EQ(1, readTCCR0());
    timer0::setClockSelect(timer0::clk_8_from_prescaler);
    EXPECT_EQ(2, readTCCR0());
    timer0::setClockSelect(timer0::clk_64_from_prescaler);
    EXPECT_EQ(3, readTCCR0());
    timer0::setClockSelect(timer0::clk_256_from_prescaler);
    EXPECT_EQ(4, readTCCR0());
    timer0::setClockSelect(timer0::clk_1024_from_prescaler);
    EXPECT_EQ(5, readTCCR0());
    timer0::setClockSelect(timer0::external_falling_edge);
    EXPECT_EQ(6, readTCCR0());
    timer0::setClockSelect(timer0::external_rising_edge);
    EXPECT_EQ(7, readTCCR0());
}

TEST_F(timer0_ut, getClockSelect)
{
    setTCCR0(0x00);
    EXPECT_EQ(timer0::no_clk_source, timer0::getClockSelect());
    setTCCR0(0x01);
    EXPECT_EQ(timer0::clk_1_no_prescaling, timer0::getClockSelect());
    setTCCR0(0x02);
    EXPECT_EQ(timer0::clk_8_from_prescaler, timer0::getClockSelect());
    setTCCR0(0x03);
    EXPECT_EQ(timer0::clk_64_from_prescaler, timer0::getClockSelect());
    setTCCR0(0x04);
    EXPECT_EQ(timer0::clk_256_from_prescaler, timer0::getClockSelect());
    setTCCR0(0x05);
    EXPECT_EQ(timer0::clk_1024_from_prescaler, timer0::getClockSelect());
    setTCCR0(0x06);
    EXPECT_EQ(timer0::external_falling_edge, timer0::getClockSelect());
    setTCCR0(0x07);
    EXPECT_EQ(timer0::external_rising_edge, timer0::getClockSelect());
}

TEST_F(timer0_ut, setCounterValue)
{
    timer0::setCounterValue(0x45);
    EXPECT_EQ(0x45, readTCNT0());
}

TEST_F(timer0_ut, getCounterValue)
{
    setTCNT0(0x67);
    EXPECT_EQ(0x67, timer0::getCounterValue());
}

TEST_F(timer0_ut, setOverflowInterrput)
{
    timer0::setOverflowInterrput();
    EXPECT_EQ(0x01, readTIMSK());
}

TEST_F(timer0_ut, clearOverflowInterrput)
{
    setTIMSK(0x01);
    timer0::clearOverflowInterrput();
    EXPECT_EQ(0x00, readTIMSK());
}

TEST_F(timer0_ut, getOverflowInterrputInfo)
{
    setTIMSK(0x01);
    EXPECT_EQ(true, timer0::getOverflowInterrputInfo());
}

TEST_F(timer0_ut, clearOverflowFlag)
{
    timer0::clearOverflowFlag();
    EXPECT_EQ(0x01, readTIFR());
}

TEST_F(timer0_ut, readOverflowFlag)
{
    setTIFR(0x01);
    EXPECT_EQ(0x01, timer0::readOverflowFlag());
}

TEST_F(timer0_ut, timerResetPrescale)
{
    timer0::timerResetPrescale();
    EXPECT_EQ(0x01, readSFIOR());
}