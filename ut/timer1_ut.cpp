#include <gtest/gtest.h>

#include "timer1.h"

class timer1_ut: public ::testing::Test {
public:
    virtual void SetUp() {
        _tim1 = {};
        _cbS = {};
        timer1::_t1 = &_tim1;
        timer1::_cbS = &_cbS;
    }

    virtual void TearDown() {
    }
protected:
    void setTCCR1A(unsigned char value) {
        _tim1._TCCR1A = value;
    }
    unsigned char getTCCR1A() {
        return _tim1._TCCR1A;
    }

    void setTCCR1B(unsigned char value) {
        _tim1._TCCR1B = value;
    }
    unsigned char getTCCR1B() {
        return _tim1._TCCR1B;
    }

    void setTCNT1L(unsigned char value) {
        _tim1._TCNT1L = value;
    }
    unsigned char getTCNT1L() {
        return _tim1._TCNT1L;
    }

    void setTCNT1H(unsigned char value) {
        _tim1._TCNT1H = value;
    }
    unsigned char getTCNT1H() {
        return _tim1._TCNT1H;
    }

    void setOCR1AL(unsigned char value) {
        _tim1._OCR1AL = value;
    }
    unsigned char getOCR1AL() {
        return _tim1._OCR1AL;
    }

    void setOCR1AH(unsigned char value) {
        _tim1._OCR1AH = value;
    }
    unsigned char getOCR1AH() {
        return _tim1._OCR1AH;
    }

    void setOCR1BL(unsigned char value) {
        _tim1._OCR1BL = value;
    }
    unsigned char getOCR1BL() {
        return _tim1._OCR1BL;
    }

    void setOCR1BH(unsigned char value) {
        _tim1._OCR1BH = value;
    }
    unsigned char getOCR1BH() {
        return _tim1._OCR1BH;
    }

    void setICR1L(unsigned char value) {
        _tim1._ICR1L = value;
    }
    unsigned char getICR1L() {
        return _tim1._ICR1L;
    }

    void setICR1H(unsigned char value) {
        _tim1._ICR1H = value;
    }
    unsigned char getICR1H() {
        return _tim1._ICR1H;
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
    timer1_Struct _tim1;
    combined_Struct _cbS;
};

/* TEST CODES */
TEST_F(timer1_ut, setCompareOutputMode)
{
    timer1::setCompareOutputMode(timer1::channel::channel_A, timer1::compareMode::normal_port_operation);
    EXPECT_EQ(0x00, getTCCR1A());
    timer1::setCompareOutputMode(timer1::channel::channel_A, timer1::compareMode::toggle_on_Compare_Match);
    EXPECT_EQ(0x40, getTCCR1A());
    timer1::setCompareOutputMode(timer1::channel::channel_A, timer1::compareMode::clear_on_Compare_Match);
    EXPECT_EQ(0x80, getTCCR1A());
    timer1::setCompareOutputMode(timer1::channel::channel_A, timer1::compareMode::set_on_Compare_Match);
    EXPECT_EQ(0xC0, getTCCR1A());

    setTCCR1A(0x00);

    timer1::setCompareOutputMode(timer1::channel::channel_B, timer1::compareMode::normal_port_operation);
    EXPECT_EQ(0x00, getTCCR1A());
    timer1::setCompareOutputMode(timer1::channel::channel_B, timer1::compareMode::toggle_on_Compare_Match);
    EXPECT_EQ(0x10, getTCCR1A());
    timer1::setCompareOutputMode(timer1::channel::channel_B, timer1::compareMode::clear_on_Compare_Match);
    EXPECT_EQ(0x20, getTCCR1A());
    timer1::setCompareOutputMode(timer1::channel::channel_B, timer1::compareMode::set_on_Compare_Match);
    EXPECT_EQ(0x30, getTCCR1A());
}
TEST_F(timer1_ut, getCompareOutputMode)
{
    setTCCR1A(0x0F);
    EXPECT_EQ(timer1::compareMode::normal_port_operation, timer1::getCompareOutputMode(timer1::channel::channel_A));
    setTCCR1A(0x4F);
    EXPECT_EQ(timer1::compareMode::toggle_on_Compare_Match, timer1::getCompareOutputMode(timer1::channel::channel_A));
    setTCCR1A(0x8F);
    EXPECT_EQ(timer1::compareMode::clear_on_Compare_Match, timer1::getCompareOutputMode(timer1::channel::channel_A));
    setTCCR1A(0xCF);
    EXPECT_EQ(timer1::compareMode::set_on_Compare_Match, timer1::getCompareOutputMode(timer1::channel::channel_A));

    setTCCR1A(0x0F);
    EXPECT_EQ(timer1::compareMode::normal_port_operation, timer1::getCompareOutputMode(timer1::channel::channel_B));
    setTCCR1A(0x1F);
    EXPECT_EQ(timer1::compareMode::toggle_on_Compare_Match, timer1::getCompareOutputMode(timer1::channel::channel_B));
    setTCCR1A(0x2F);
    EXPECT_EQ(timer1::compareMode::clear_on_Compare_Match, timer1::getCompareOutputMode(timer1::channel::channel_B));
    setTCCR1A(0x3F);
    EXPECT_EQ(timer1::compareMode::set_on_Compare_Match, timer1::getCompareOutputMode(timer1::channel::channel_B));
}
TEST_F(timer1_ut, setForceOutputCompare)
{
    timer1::setForceOutputCompare(timer1::channel::channel_A);
    EXPECT_EQ(0x08, getTCCR1A());
    setTCCR1A(0x00);
    timer1::setForceOutputCompare(timer1::channel::channel_B);
    EXPECT_EQ(0x04, getTCCR1A());
    setTCCR1A(0x00);
}
TEST_F(timer1_ut, clearForceOutputCompare)
{
    setTCCR1A(0x08);
    timer1::clearForceOutputCompare(timer1::channel::channel_A);
    EXPECT_EQ(0x00, getTCCR1A());
    setTCCR1A(0x04);
    timer1::clearForceOutputCompare(timer1::channel::channel_B);
    EXPECT_EQ(0x00, getTCCR1A());
}
/*TCCR1B = wgm13:4 wgm12:3*/
/*TCCR1A = wgm11:1 wgm10:0*/
TEST_F(timer1_ut, setWaveformGenerationMode)
{
    setTCCR1A(0xF0);
    setTCCR1B(0x07);

    timer1::setWaveformGenerationMode(timer1::waveformMode::normal);
    EXPECT_EQ(0xF0, getTCCR1A());
    EXPECT_EQ(0x07, getTCCR1B());
    timer1::setWaveformGenerationMode(timer1::waveformMode::PWM_phaseCorrect_08bit);
    EXPECT_EQ(0xF1, getTCCR1A());
    EXPECT_EQ(0x07, getTCCR1B());
    timer1::setWaveformGenerationMode(timer1::waveformMode::PWM_phaseCorrect_09bit);
    EXPECT_EQ(0xF2, getTCCR1A());
    EXPECT_EQ(0x07, getTCCR1B());
    timer1::setWaveformGenerationMode(timer1::waveformMode::PWM_phaseCorrect_10bit);
    EXPECT_EQ(0xF3, getTCCR1A());
    EXPECT_EQ(0x07, getTCCR1B());
    timer1::setWaveformGenerationMode(timer1::waveformMode::clearTimerOnCompareMatch_Output);
    EXPECT_EQ(0xF0, getTCCR1A());
    EXPECT_EQ(0x0F, getTCCR1B());
    timer1::setWaveformGenerationMode(timer1::waveformMode::FastPWM_08bit);
    EXPECT_EQ(0xF1, getTCCR1A());
    EXPECT_EQ(0x0F, getTCCR1B());
    timer1::setWaveformGenerationMode(timer1::waveformMode::FastPWM_09bit);
    EXPECT_EQ(0xF2, getTCCR1A());
    EXPECT_EQ(0x0F, getTCCR1B());
    timer1::setWaveformGenerationMode(timer1::waveformMode::FastPWM_10bit);
    EXPECT_EQ(0xF3, getTCCR1A());
    EXPECT_EQ(0x0F, getTCCR1B());
    timer1::setWaveformGenerationMode(timer1::waveformMode::PWM_phaseFreqCorrect_Input);
    EXPECT_EQ(0xF0, getTCCR1A());
    EXPECT_EQ(0x17, getTCCR1B());
    timer1::setWaveformGenerationMode(timer1::waveformMode::PWM_phaseFreqCorrect_Output);
    EXPECT_EQ(0xF1, getTCCR1A());
    EXPECT_EQ(0x17, getTCCR1B());
    timer1::setWaveformGenerationMode(timer1::waveformMode::PWM_phaseCorrect_Input);
    EXPECT_EQ(0xF2, getTCCR1A());
    EXPECT_EQ(0x17, getTCCR1B());
    timer1::setWaveformGenerationMode(timer1::waveformMode::PWM_phaseCorrect_Output);
    EXPECT_EQ(0xF3, getTCCR1A());
    EXPECT_EQ(0x17, getTCCR1B());
    timer1::setWaveformGenerationMode(timer1::waveformMode::clearTimerOnCompareMatch_Input);
    EXPECT_EQ(0xF0, getTCCR1A());
    EXPECT_EQ(0x1F, getTCCR1B());
    timer1::setWaveformGenerationMode(timer1::waveformMode::FastPWM_Input);
    EXPECT_EQ(0xF2, getTCCR1A());
    EXPECT_EQ(0x1F, getTCCR1B());
    timer1::setWaveformGenerationMode(timer1::waveformMode::FastPWM_Output);
    EXPECT_EQ(0xF3, getTCCR1A());
    EXPECT_EQ(0x1F, getTCCR1B());
}
TEST_F(timer1_ut, getWaveformGenerationMode)
{
    setTCCR1A(0xF0);
    setTCCR1B(0x07);
    EXPECT_EQ(timer1::waveformMode::normal, timer1::getWaveformGenerationMode());
    setTCCR1A(0xF1);
    setTCCR1B(0x07);
    EXPECT_EQ(timer1::waveformMode::PWM_phaseCorrect_08bit, timer1::getWaveformGenerationMode());
    setTCCR1A(0xF2);
    setTCCR1B(0x07);
    EXPECT_EQ(timer1::waveformMode::PWM_phaseCorrect_09bit, timer1::getWaveformGenerationMode());
    setTCCR1A(0xF3);
    setTCCR1B(0x07);
    EXPECT_EQ(timer1::waveformMode::PWM_phaseCorrect_10bit, timer1::getWaveformGenerationMode());
    setTCCR1A(0xF0);
    setTCCR1B(0x0F);
    EXPECT_EQ(timer1::waveformMode::clearTimerOnCompareMatch_Output, timer1::getWaveformGenerationMode());
    setTCCR1A(0xF1);
    setTCCR1B(0x0F);
    EXPECT_EQ(timer1::waveformMode::FastPWM_08bit, timer1::getWaveformGenerationMode());
    setTCCR1A(0xF2);
    setTCCR1B(0x0F);
    EXPECT_EQ(timer1::waveformMode::FastPWM_09bit, timer1::getWaveformGenerationMode());
    setTCCR1A(0xF3);
    setTCCR1B(0x0F);
    EXPECT_EQ(timer1::waveformMode::FastPWM_10bit, timer1::getWaveformGenerationMode());
    setTCCR1A(0xF0);
    setTCCR1B(0x17);
    EXPECT_EQ(timer1::waveformMode::PWM_phaseFreqCorrect_Input, timer1::getWaveformGenerationMode());
    setTCCR1A(0xF1);
    setTCCR1B(0x17);
    EXPECT_EQ(timer1::waveformMode::PWM_phaseFreqCorrect_Output, timer1::getWaveformGenerationMode());
    setTCCR1A(0xF2);
    setTCCR1B(0x17);
    EXPECT_EQ(timer1::waveformMode::PWM_phaseCorrect_Input, timer1::getWaveformGenerationMode());
    setTCCR1A(0xF3);
    setTCCR1B(0x17);
    EXPECT_EQ(timer1::waveformMode::PWM_phaseCorrect_Output, timer1::getWaveformGenerationMode());
    setTCCR1A(0xF0);
    setTCCR1B(0x1F);
    EXPECT_EQ(timer1::waveformMode::clearTimerOnCompareMatch_Input, timer1::getWaveformGenerationMode());
    setTCCR1A(0xF2);
    setTCCR1B(0x1F);
    EXPECT_EQ(timer1::waveformMode::FastPWM_Input, timer1::getWaveformGenerationMode());
    setTCCR1A(0xF3);
    setTCCR1B(0x1F);
    EXPECT_EQ(timer1::waveformMode::FastPWM_Output, timer1::getWaveformGenerationMode());
}
TEST_F(timer1_ut, setInputCaptureNoiseCanceler)
{
    timer1::setInputCaptureNoiseCanceler();
    EXPECT_EQ(0x80, getTCCR1B());
}
TEST_F(timer1_ut, clearInputCaptureNoiseCanceler)
{
    setTCCR1B(0x80);
    timer1::clearInputCaptureNoiseCanceler();
    EXPECT_EQ(0x00, getTCCR1B());
}
TEST_F(timer1_ut, getInputCaptureNoiseCanceler)
{
    setTCCR1B(0x8F);
    EXPECT_EQ(true, timer1::getInputCaptureNoiseCanceler());
    setTCCR1B(0x7F);
    EXPECT_EQ(false, timer1::getInputCaptureNoiseCanceler());
}
TEST_F(timer1_ut, setInputCaptureEdgeSelect)
{
    timer1::setInputCaptureEdgeSelect(timer1::edge::rising);
    EXPECT_EQ(0x40, getTCCR1B());
    timer1::setInputCaptureEdgeSelect(timer1::edge::falling);
    EXPECT_EQ(0x00, getTCCR1B());
}
TEST_F(timer1_ut, getInputCaptureEdgeSelect)
{
    setTCCR1B(0xFF);
    EXPECT_EQ(timer1::edge::rising, timer1::getInputCaptureEdgeSelect());
    setTCCR1B(0x0F);
    EXPECT_EQ(timer1::edge::falling, timer1::getInputCaptureEdgeSelect());
}
TEST_F(timer1_ut, setClockSelect)
{
    timer1::setClockSelect(timer1::clock::no_clk_source);
    EXPECT_EQ(0, getTCCR1B());
    timer1::setClockSelect(timer1::clock::clk_1_no_prescaling);
    EXPECT_EQ(1, getTCCR1B());
    timer1::setClockSelect(timer1::clock::clk_8_from_prescaler);
    EXPECT_EQ(2, getTCCR1B());
    timer1::setClockSelect(timer1::clock::clk_64_from_prescaler);
    EXPECT_EQ(3, getTCCR1B());
    timer1::setClockSelect(timer1::clock::clk_256_from_prescaler);
    EXPECT_EQ(4, getTCCR1B());
    timer1::setClockSelect(timer1::clock::clk_1024_from_prescaler);
    EXPECT_EQ(5, getTCCR1B());
    timer1::setClockSelect(timer1::clock::external_falling_edge);
    EXPECT_EQ(6, getTCCR1B());
    timer1::setClockSelect(timer1::clock::external_rising_edge);
    EXPECT_EQ(7, getTCCR1B());
}
TEST_F(timer1_ut, getClockSelect)
{
    setTCCR1B(0x00);
    EXPECT_EQ(timer1::clock::no_clk_source, timer1::getClockSelect());
    setTCCR1B(0x01);
    EXPECT_EQ(timer1::clock::clk_1_no_prescaling, timer1::getClockSelect());
    setTCCR1B(0x02);
    EXPECT_EQ(timer1::clock::clk_8_from_prescaler, timer1::getClockSelect());
    setTCCR1B(0x03);
    EXPECT_EQ(timer1::clock::clk_64_from_prescaler, timer1::getClockSelect());
    setTCCR1B(0x04);
    EXPECT_EQ(timer1::clock::clk_256_from_prescaler, timer1::getClockSelect());
    setTCCR1B(0x05);
    EXPECT_EQ(timer1::clock::clk_1024_from_prescaler, timer1::getClockSelect());
    setTCCR1B(0x06);
    EXPECT_EQ(timer1::clock::external_falling_edge, timer1::getClockSelect());
    setTCCR1B(0x07);
    EXPECT_EQ(timer1::clock::external_rising_edge, timer1::getClockSelect());
}
TEST_F(timer1_ut, setCounterValue)
{
    unsigned int val = 198;

    timer1::setCounterValue(val);
    EXPECT_EQ(((val & 0xFF00) >> 8), getTCNT1H());
    EXPECT_EQ((val & 0x00FF), getTCNT1L());
}
TEST_F(timer1_ut, getCounterValue)
{
    unsigned char low = 0x45;
    unsigned char high = 0x67;

    setTCNT1L(low);
    setTCNT1H(high);

    unsigned int val = ((high << 8)) | (low);
    EXPECT_EQ(val, timer1::getCounterValue());
}
TEST_F(timer1_ut, setOutputCompareValue)
{
    unsigned int valA = 198;
    unsigned int valB = 203;

    timer1::setOutputCompareValue(timer1::channel::channel_A, valA);
    EXPECT_EQ(((valA & 0xFF00) >> 8), getOCR1AH());
    EXPECT_EQ((valA & 0x00FF), getOCR1AL());

    timer1::setOutputCompareValue(timer1::channel::channel_B, valB);
    EXPECT_EQ(((valB & 0xFF00) >> 8), getOCR1BH());
    EXPECT_EQ((valB & 0x00FF), getOCR1BL());
}
TEST_F(timer1_ut, getOutputCompareValue)
{
    unsigned char lowA = 0x45;
    unsigned char highA = 0x67;
    unsigned char lowB = 0x67;
    unsigned char highB = 0x45;

    setOCR1AH(highA);
    setOCR1AL(lowA);
    setOCR1BH(highB);
    setOCR1BL(lowB);

    unsigned int valA = ((highA << 8)) | (lowA);
    unsigned int valB = ((highB << 8)) | (lowB);

    EXPECT_EQ(valA, timer1::getOutputCompareValue(timer1::channel::channel_A));
    EXPECT_EQ(valB, timer1::getOutputCompareValue(timer1::channel::channel_B));
}
TEST_F(timer1_ut, setInputCompareValue)
{
    unsigned int val = 198;

    timer1::setInputCompareValue(val);
    EXPECT_EQ(((val & 0xFF00) >> 8), getICR1H());
    EXPECT_EQ((val & 0x00FF), getICR1L());
}
TEST_F(timer1_ut, getInputCompareValue)
{
    unsigned char low = 0x45;
    unsigned char high = 0x67;

    setICR1L(low);
    setICR1H(high);

    unsigned int val = ((high << 8)) | (low);
    EXPECT_EQ(val, timer1::getInputCompareValue());
}
TEST_F(timer1_ut, setInputCaptureInterrupt)
{
    timer1::setInputCaptureInterrupt();

    EXPECT_EQ(0x20, getTIMSK());
}
TEST_F(timer1_ut, clearInputCaptureInterrupt)
{
    setTIMSK(0x3C);
    timer1::clearInputCaptureInterrupt();
    EXPECT_EQ(0x1C, getTIMSK());
}
TEST_F(timer1_ut, getInputCaptureInterrupt)
{
    setTIMSK(0x3C);

    EXPECT_EQ(true, timer1::getInputCaptureInterrupt());
}
TEST_F(timer1_ut, setOutputCompareMatchInterrupt)
{
    timer1::setOutputCompareMatchInterrupt(timer1::channel::channel_A);
    timer1::setOutputCompareMatchInterrupt(timer1::channel::channel_B);

    EXPECT_EQ(0x18, getTIMSK());
}
TEST_F(timer1_ut, clearOutputCompareMatchInterrupt)
{
    setTIMSK(0x3C);
    timer1::clearOutputCompareMatchInterrupt(timer1::channel::channel_A);
    timer1::clearOutputCompareMatchInterrupt(timer1::channel::channel_B);

    EXPECT_EQ(0x24, getTIMSK());
}
TEST_F(timer1_ut, getOutputCompareMatchInterrupt)
{
    setTIMSK(0x3C);
    EXPECT_EQ(true, timer1::getOutputCompareMatchInterrupt(timer1::channel::channel_A));
    EXPECT_EQ(true, timer1::getOutputCompareMatchInterrupt(timer1::channel::channel_B));
}
TEST_F(timer1_ut, setOverflowInterrput)
{
    timer1::setOverflowInterrput();
    EXPECT_EQ(0x04, getTIMSK());
}
TEST_F(timer1_ut, clearOverflowInterrput)
{
    setTIMSK(0x3C);
    timer1::clearOverflowInterrput();
    EXPECT_EQ(0x38, getTIMSK());
}
TEST_F(timer1_ut, getOverflowInterrputInfo)
{
    setTIMSK(0x3C);
    EXPECT_EQ(true, timer1::getOverflowInterrputInfo());
}
TEST_F(timer1_ut, clearInputCaptureFlag)
{
    timer1::clearInputCaptureFlag();
    EXPECT_EQ(0x20, getTIFR());
}
TEST_F(timer1_ut, readInputCaptureFlag)
{
    setTIFR(0x3C);
    EXPECT_EQ(true, timer1::readInputCaptureFlag());
}
TEST_F(timer1_ut, clearOutputCompareMatchFlag)
{
    timer1::clearOutputCompareMatchFlag(timer1::channel::channel_A);
    timer1::clearOutputCompareMatchFlag(timer1::channel::channel_B);
    EXPECT_EQ(0x18, getTIFR());
}
TEST_F(timer1_ut, readOutputCompareMatchFlag)
{
    setTIFR(0x3C);
    EXPECT_EQ(true, timer1::readOutputCompareMatchFlag(timer1::channel::channel_A));
    EXPECT_EQ(true, timer1::readOutputCompareMatchFlag(timer1::channel::channel_B));
}
TEST_F(timer1_ut, clearOverflowFlag)
{
    timer1::clearOverflowFlag();
    EXPECT_EQ(0x04, getTIFR());
}
TEST_F(timer1_ut, readOverflowFlag)
{
    setTIFR(0x3C);
    EXPECT_EQ(true, timer1::readOverflowFlag());
}
TEST_F(timer1_ut, timerResetPrescale)
{
    timer1::timerResetPrescale();
    EXPECT_EQ(0x01, readSFIOR());
}
