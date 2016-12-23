#include <gtest/gtest.h>

#include "timer2.h"

class timer2_ut: public ::testing::Test {
public:
    virtual void SetUp() {
        _tim2 = {};
        _cbS = {};
        timer2::_t2 = &_tim2;
        timer2::_cbS = &_cbS;
    }

    virtual void TearDown() {
    }
protected:
    void setTCCR2(unsigned char value) {
        _tim2._TCCR2 = value;
    }
    unsigned char getTCCR2() {
        return _tim2._TCCR2;
    }

    void setTCNT2(unsigned char value) {
        _tim2._TCNT2 = value;
    }
    unsigned char getTCNT2() {
        return _tim2._TCNT2;
    }

    void setOCR2(unsigned char value) {
        _tim2._OCR2 = value;
    }
    unsigned char getOCR2() {
        return _tim2._OCR2;
    }

    void setASSR(unsigned char value) {
        _tim2._ASSR = value;
    }
    unsigned char getASSR() {
        return _tim2._ASSR;
    }

    void setTIMSK(unsigned char value) {
        _cbS._TIMSK = value;
    }
    unsigned char getTIMSK() {
        return _cbS._TIMSK;
    }

    void setTIFR(unsigned char value) {
        _cbS._TIFR = value;
    }
    unsigned char getTIFR() {
        return _cbS._TIFR;
    }

    void setSFIOR(unsigned char value) {
        _cbS._SFIOR = value;
    }
    unsigned char readSFIOR() {
        return _cbS._SFIOR;
    }
private:
    timer2_Struct _tim2;
    combined_Struct _cbS;
};

/* TEST CODES */
TEST_F(timer2_ut, setForceOutputCompare)
{
    timer2::setForceOutputCompare();
    EXPECT_EQ(0x80, getTCCR2());
}

TEST_F(timer2_ut, clearForceOutputCompare)
{
    setTCCR2(0xFF);
    timer2::clearForceOutputCompare();
    EXPECT_EQ(0x7F, getTCCR2());
}

TEST_F(timer2_ut, setWaveformGenerationMode)
{
    timer2::setWaveformGenerationMode(timer2::waveformMode::normal);
    EXPECT_EQ(0x00, getTCCR2());
    timer2::setWaveformGenerationMode(timer2::waveformMode::PWM_phaseCorrect);
    EXPECT_EQ(0x40, getTCCR2());
    timer2::setWaveformGenerationMode(timer2::waveformMode::clearTimerOnCompareMatch_Output);
    EXPECT_EQ(0x08, getTCCR2());
    timer2::setWaveformGenerationMode(timer2::waveformMode::FastPWM);
    EXPECT_EQ(0x48, getTCCR2());
}

TEST_F(timer2_ut, getWaveformGenerationMode)
{
    setTCCR2(0xB7);
    EXPECT_EQ(timer2::waveformMode::normal, timer2::getWaveformGenerationMode());
    setTCCR2(0xF7);
    EXPECT_EQ(timer2::waveformMode::PWM_phaseCorrect, timer2::getWaveformGenerationMode());
    setTCCR2(0xBF);
    EXPECT_EQ(timer2::waveformMode::clearTimerOnCompareMatch_Output, timer2::getWaveformGenerationMode());
    setTCCR2(0xFF);
    EXPECT_EQ(timer2::waveformMode::FastPWM, timer2::getWaveformGenerationMode());
}

TEST_F(timer2_ut, setCompareOutputMode)
{
    timer2::setCompareOutputMode(timer2::compareMode::normal_port_operation);
    EXPECT_EQ(0x00, getTCCR2());
    timer2::setCompareOutputMode(timer2::compareMode::toggle_on_Compare_Match);
    EXPECT_EQ(0x10, getTCCR2());
    timer2::setCompareOutputMode(timer2::compareMode::clear_on_Compare_Match);
    EXPECT_EQ(0x20, getTCCR2());
    timer2::setCompareOutputMode(timer2::compareMode::set_on_Compare_Match);
    EXPECT_EQ(0x30, getTCCR2());
}

TEST_F(timer2_ut, getCompareOutputMode)
{
    setTCCR2(0x0F);
    EXPECT_EQ(timer2::compareMode::normal_port_operation, timer2::getCompareOutputMode());
    setTCCR2(0xDF);
    EXPECT_EQ(timer2::compareMode::toggle_on_Compare_Match, timer2::getCompareOutputMode());
    setTCCR2(0x2F);
    EXPECT_EQ(timer2::compareMode::clear_on_Compare_Match, timer2::getCompareOutputMode());
    setTCCR2(0xFF);
    EXPECT_EQ(timer2::compareMode::set_on_Compare_Match, timer2::getCompareOutputMode());
}

TEST_F(timer2_ut, setClockSelect)
{
    timer2::setClockSelect(timer2::clock::no_clk_source);
    EXPECT_EQ(0x00, getTCCR2());
    timer2::setClockSelect(timer2::clock::clk_1_no_prescaling);
    EXPECT_EQ(0x01, getTCCR2());
    timer2::setClockSelect(timer2::clock::clk_8_from_prescaler);
    EXPECT_EQ(0x02, getTCCR2());
    timer2::setClockSelect(timer2::clock::clk_32_from_prescaler);
    EXPECT_EQ(0x03, getTCCR2());
    timer2::setClockSelect(timer2::clock::clk_64_from_prescaler);
    EXPECT_EQ(0x04, getTCCR2());
    timer2::setClockSelect(timer2::clock::clk_128_from_prescaler);
    EXPECT_EQ(0x05, getTCCR2());
    timer2::setClockSelect(timer2::clock::clk_256_from_prescaler);
    EXPECT_EQ(0x06, getTCCR2());
    timer2::setClockSelect(timer2::clock::clk_1024_from_prescaler);
    EXPECT_EQ(0x07, getTCCR2());
}

TEST_F(timer2_ut, getClockSelect)
{
    setTCCR2(0xF8);
    EXPECT_EQ(timer2::clock::no_clk_source, timer2::getClockSelect());
    setTCCR2(0xF9);
    EXPECT_EQ(timer2::clock::clk_1_no_prescaling, timer2::getClockSelect());
    setTCCR2(0xFA);
    EXPECT_EQ(timer2::clock::clk_8_from_prescaler, timer2::getClockSelect());
    setTCCR2(0xFB);
    EXPECT_EQ(timer2::clock::clk_32_from_prescaler, timer2::getClockSelect());
    setTCCR2(0xFC);
    EXPECT_EQ(timer2::clock::clk_64_from_prescaler, timer2::getClockSelect());
    setTCCR2(0xFD);
    EXPECT_EQ(timer2::clock::clk_128_from_prescaler, timer2::getClockSelect());
    setTCCR2(0xFE);
    EXPECT_EQ(timer2::clock::clk_256_from_prescaler, timer2::getClockSelect());
    setTCCR2(0xFF);
    EXPECT_EQ(timer2::clock::clk_1024_from_prescaler, timer2::getClockSelect());
}

TEST_F(timer2_ut, setCounterValue)
{
    unsigned char val = 0x56;
    timer2::setCounterValue(val);
    EXPECT_EQ(val, getTCNT2());
}

TEST_F(timer2_ut, getCounterValue)
{
    unsigned char val = 0xDB;
    setTCNT2(val);
    EXPECT_EQ(val, timer2::getCounterValue());
}

TEST_F(timer2_ut, setOutputCompareValue)
{
    unsigned char val = 0x56;
    timer2::setOutputCompareValue(val);
    EXPECT_EQ(val, getOCR2());
}

TEST_F(timer2_ut, getOutputCompareValue)
{
    unsigned char val = 0xDB;
    setOCR2(val);
    EXPECT_EQ(val, timer2::getOutputCompareValue());
}

TEST_F(timer2_ut, setAsynchronous)
{
    timer2::setAsynchronous();
    EXPECT_EQ(0x08, getASSR());
}

TEST_F(timer2_ut, getAsynchronous)
{
    setASSR(0x0F);
    EXPECT_EQ(true, timer2::getAsynchronous());
    setASSR(0x00);
    EXPECT_EQ(false, timer2::getAsynchronous());
}

TEST_F(timer2_ut, getTimerCounterUpdateBusy)
{
    setASSR(0x0F);
    EXPECT_EQ(true, timer2::getTimerCounterUpdateBusy());
    setASSR(0x00);
    EXPECT_EQ(false, timer2::getTimerCounterUpdateBusy());
}

TEST_F(timer2_ut, getOutputCompareUpdateBusy)
{
    setASSR(0x0F);
    EXPECT_EQ(true, timer2::getOutputCompareUpdateBusy());
    setASSR(0x00);
    EXPECT_EQ(false, timer2::getOutputCompareUpdateBusy());
}

TEST_F(timer2_ut, getTimerCounterControlUpdateBusy)
{
    setASSR(0x0F);
    EXPECT_EQ(true, timer2::getTimerCounterControlUpdateBusy());
    setASSR(0x00);
    EXPECT_EQ(false, timer2::getTimerCounterControlUpdateBusy());
}

TEST_F(timer2_ut, setOutputCompareMatchInterrupt)
{
    timer2::setOutputCompareMatchInterrupt();
    EXPECT_EQ(0x80, getTIMSK());
}

TEST_F(timer2_ut, clearOutputCompareMatchInterrupt)
{
    setTIMSK(0xC0);
    timer2::clearOutputCompareMatchInterrupt();
    EXPECT_EQ(0x40, getTIMSK());
}

TEST_F(timer2_ut, getOutputCompareMatchInterrupt)
{
    setTIMSK(0xC0);
    EXPECT_EQ(true, timer2::getOutputCompareMatchInterrupt());
}

TEST_F(timer2_ut, setOverflowInterrput)
{
    timer2::setOverflowInterrput();
    EXPECT_EQ(0x40, getTIMSK());
}

TEST_F(timer2_ut, clearOverflowInterrput)
{
    setTIMSK(0xC0);
    timer2::clearOverflowInterrput();
    EXPECT_EQ(0x80, getTIMSK());
}

TEST_F(timer2_ut, getOverflowInterrputInfo)
{
    setTIMSK(0xC0);
    EXPECT_EQ(true, timer2::getOverflowInterrputInfo());
}

TEST_F(timer2_ut, clearOutputCompareMatchFlag)
{
    timer2::clearOutputCompareMatchFlag();
    EXPECT_EQ(0x80, getTIFR());
}

TEST_F(timer2_ut, readOutputCompareMatchFlag)
{
    setTIFR(0xC0);
    EXPECT_EQ(true, timer2::readOutputCompareMatchFlag());
}

TEST_F(timer2_ut, clearOverflowFlag)
{
    timer2::clearOverflowFlag();
    EXPECT_EQ(0x40, getTIFR());
}

TEST_F(timer2_ut, readOverflowFlag)
{
    setTIFR(0xC0);
    EXPECT_EQ(true, timer2::readOverflowFlag());
}

TEST_F(timer2_ut, timerResetPrescale)
{
    timer2::timerResetPrescale();
    EXPECT_EQ(0x02, readSFIOR());
}
