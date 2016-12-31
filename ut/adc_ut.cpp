#include <gtest/gtest.h>

#include "adc.h"

class adc_ut: public ::testing::Test {
private:
    adc_Struct _adS;
protected:

    unsigned char readADMUX() {
        return _adS._ADMUX;
    }
    void writeADMUX(unsigned char value) {
        _adS._ADMUX = value;
    }

    unsigned char readADCSRA() {
        return _adS._ADCSRA;
    }
    void writeADCSRA(unsigned char value) {
        _adS._ADCSRA = value;
    }

    unsigned char readADCH() {
        return _adS._ADCH;
    }
    void writeADCH(unsigned char value) {
        _adS._ADCH = value;
    }

    unsigned char readADCL() {
        return _adS._ADCL;
    }
    void writeADCL(unsigned char value) {
        _adS._ADCL = value;
    }
public:
    virtual void SetUp() {
        _adS = {};
        adc::_adS = &_adS;
    }
    virtual void TearDown() {
    }
};

/* TEST CODES */
TEST_F(adc_ut, setReference)
{
    adc::setReference(adc::reference::aref_internal_turned_off);
    EXPECT_EQ(0x00, readADMUX());
    adc::setReference(adc::reference::avcc_external_capacitor_at_aref_pin);
    EXPECT_EQ(0x40, readADMUX());
    adc::setReference(adc::reference::internal_2_56V_vol_reference_with_external_capacitor_at_aref_pin);
    EXPECT_EQ(0xC0, readADMUX());
}
TEST_F(adc_ut, getReference)
{
    writeADMUX(0x00);
    EXPECT_EQ(adc::reference::aref_internal_turned_off, adc::getReference());
    writeADMUX(0x40);
    EXPECT_EQ(adc::reference::avcc_external_capacitor_at_aref_pin, adc::getReference());
    writeADMUX(0xC0);
    EXPECT_EQ(adc::reference::internal_2_56V_vol_reference_with_external_capacitor_at_aref_pin, adc::getReference());
}
TEST_F(adc_ut, setLeftAdjustResult)
{
    adc::setLeftAdjustResult();
    EXPECT_EQ(0x20, readADMUX());
}
TEST_F(adc_ut, clearLeftAdjustResult)
{
    writeADMUX(0x20);
    adc::clearLeftAdjustResult();
    EXPECT_EQ(0x00, readADMUX());
}
TEST_F(adc_ut, getLeftAdjustResult)
{
    writeADMUX(0x20);
    EXPECT_EQ(true, adc::getLeftAdjustResult());
    writeADMUX(0x00);
    EXPECT_EQ(false, adc::getLeftAdjustResult());
}
TEST_F(adc_ut, setChannel)
{
    adc::setChannel(adc::channel::single_ended_input_adc0);
    EXPECT_EQ(0x00, readADMUX());
    adc::setChannel(adc::channel::single_ended_input_adc1);
    EXPECT_EQ(0x01, readADMUX());
    adc::setChannel(adc::channel::single_ended_input_adc2);
    EXPECT_EQ(0x02, readADMUX());
    adc::setChannel(adc::channel::single_ended_input_adc3);
    EXPECT_EQ(0x03, readADMUX());
    adc::setChannel(adc::channel::single_ended_input_adc4);
    EXPECT_EQ(0x04, readADMUX());
    adc::setChannel(adc::channel::single_ended_input_adc5);
    EXPECT_EQ(0x05, readADMUX());
    adc::setChannel(adc::channel::single_ended_input_adc6);
    EXPECT_EQ(0x06, readADMUX());
    adc::setChannel(adc::channel::single_ended_input_adc7);
    EXPECT_EQ(0x07, readADMUX());
    adc::setChannel(adc::channel::single_ended_input_1_30V_Vbg);
    EXPECT_EQ(0x0E, readADMUX());
    adc::setChannel(adc::channel::single_ended_input_0_00V_Gnd);
    EXPECT_EQ(0x0F, readADMUX());
}
TEST_F(adc_ut, getChannel)
{
    writeADMUX(0x0F);
    EXPECT_EQ(adc::channel::single_ended_input_0_00V_Gnd, adc::getChannel());
    writeADMUX(0x0E);
    EXPECT_EQ(adc::channel::single_ended_input_1_30V_Vbg, adc::getChannel());
    writeADMUX(0x07);
    EXPECT_EQ(adc::channel::single_ended_input_adc7, adc::getChannel());
    writeADMUX(0x06);
    EXPECT_EQ(adc::channel::single_ended_input_adc6, adc::getChannel());
    writeADMUX(0x05);
    EXPECT_EQ(adc::channel::single_ended_input_adc5, adc::getChannel());
    writeADMUX(0x04);
    EXPECT_EQ(adc::channel::single_ended_input_adc4, adc::getChannel());
    writeADMUX(0x03);
    EXPECT_EQ(adc::channel::single_ended_input_adc3, adc::getChannel());
    writeADMUX(0x02);
    EXPECT_EQ(adc::channel::single_ended_input_adc2, adc::getChannel());
    writeADMUX(0x01);
    EXPECT_EQ(adc::channel::single_ended_input_adc1, adc::getChannel());
    writeADMUX(0x00);
    EXPECT_EQ(adc::channel::single_ended_input_adc0, adc::getChannel());
}
TEST_F(adc_ut, setEnable)
{
    adc::setEnable();
    EXPECT_EQ(0x80, readADCSRA());
}
TEST_F(adc_ut, clearEnable)
{
    writeADCSRA(0x80);
    adc::clearEnable();
    EXPECT_EQ(0x00, readADCSRA());
}
TEST_F(adc_ut, getEnable)
{
    writeADCSRA(0x80);
    EXPECT_EQ(true, adc::getEnable());
    writeADCSRA(0x00);
    EXPECT_EQ(false, adc::getEnable());
}
TEST_F(adc_ut, setStartConversion)
{
    adc::setStartConversion();
    EXPECT_EQ(0x40, readADCSRA());
}
TEST_F(adc_ut, clearStartConversion)
{
    writeADCSRA(0x40);
    adc::clearStartConversion();
    EXPECT_EQ(0x00, readADCSRA());
}
TEST_F(adc_ut, getStartConversion)
{
    writeADCSRA(0x40);
    EXPECT_EQ(true, adc::getStartConversion());
    writeADCSRA(0x00);
    EXPECT_EQ(false, adc::getStartConversion());
}
TEST_F(adc_ut, setFreeRunning)
{
    adc::setFreeRunning();
    EXPECT_EQ(0x20, readADCSRA());
}
TEST_F(adc_ut, clearFreeRunning)
{
    writeADCSRA(0x20);
    adc::clearFreeRunning();
    EXPECT_EQ(0x00, readADCSRA());
}
TEST_F(adc_ut, getFreeRunning)
{
    writeADCSRA(0x20);
    EXPECT_EQ(true, adc::getFreeRunning());
    writeADCSRA(0x00);
    EXPECT_EQ(false, adc::getFreeRunning());
}
TEST_F(adc_ut, readInterruptFlag)
{
    writeADCSRA(0x10);
    EXPECT_EQ(true, adc::readInterruptFlag());
    writeADCSRA(0x00);
    EXPECT_EQ(false, adc::readInterruptFlag());
}
TEST_F(adc_ut, clearInterruptFlag)
{
    adc::clearInterruptFlag();
    EXPECT_EQ(0x10, readADCSRA());
}
TEST_F(adc_ut, setInterruptEnable)
{
    adc::setInterruptEnable();
    EXPECT_EQ(0x08, readADCSRA());
}
TEST_F(adc_ut, clearInterruptEnable)
{
    writeADCSRA(0x08);
    adc::clearInterruptEnable();
    EXPECT_EQ(0x00, readADCSRA());
}
TEST_F(adc_ut, getInterruptEnable)
{
    writeADCSRA(0x08);
    EXPECT_EQ(true, adc::getInterruptEnable());
    writeADCSRA(0x00);
    EXPECT_EQ(false, adc::getInterruptEnable());
}
TEST_F(adc_ut, setPrescaler)
{
    adc::setPrescaler(adc::prescaler::_2_1);
    EXPECT_EQ(0x00, readADCSRA());
    adc::setPrescaler(adc::prescaler::_2_2);
    EXPECT_EQ(0x01, readADCSRA());
    adc::setPrescaler(adc::prescaler::_4);
    EXPECT_EQ(0x02, readADCSRA());
    adc::setPrescaler(adc::prescaler::_8);
    EXPECT_EQ(0x03, readADCSRA());
    adc::setPrescaler(adc::prescaler::_16);
    EXPECT_EQ(0x04, readADCSRA());
    adc::setPrescaler(adc::prescaler::_32);
    EXPECT_EQ(0x05, readADCSRA());
    adc::setPrescaler(adc::prescaler::_64);
    EXPECT_EQ(0x06, readADCSRA());
    adc::setPrescaler(adc::prescaler::_128);
    EXPECT_EQ(0x07, readADCSRA());
}
TEST_F(adc_ut, getPrescaler)
{
    writeADCSRA(0x07);
    EXPECT_EQ(adc::prescaler::_128, adc::getPrescaler());
    writeADCSRA(0x06);
    EXPECT_EQ(adc::prescaler::_64, adc::getPrescaler());
    writeADCSRA(0x05);
    EXPECT_EQ(adc::prescaler::_32, adc::getPrescaler());
    writeADCSRA(0x04);
    EXPECT_EQ(adc::prescaler::_16, adc::getPrescaler());
    writeADCSRA(0x03);
    EXPECT_EQ(adc::prescaler::_8, adc::getPrescaler());
    writeADCSRA(0x02);
    EXPECT_EQ(adc::prescaler::_4, adc::getPrescaler());
    writeADCSRA(0x01);
    EXPECT_EQ(adc::prescaler::_2_2, adc::getPrescaler());
    writeADCSRA(0x00);
    EXPECT_EQ(adc::prescaler::_2_1, adc::getPrescaler());
}
TEST_F(adc_ut, getData)
{
    unsigned char tmpL = 0xDE;
    unsigned char tmpH = 0x02;
    unsigned int val = (tmpH << 8) | tmpL;
    writeADCL(tmpL);
    writeADCH(tmpH);
    EXPECT_EQ(val, adc::getData());

    adc::setLeftAdjustResult();
    tmpL = 0x40;
    tmpH = 0xAD;
    writeADCL(tmpL);
    writeADCH(tmpH);
    val = (tmpL << 2) | tmpH;
    EXPECT_EQ(val, adc::getData());
}