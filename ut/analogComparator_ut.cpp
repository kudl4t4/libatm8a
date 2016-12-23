#include <gtest/gtest.h>

#include "analogComparator.h"

class analogComparator_ut: public ::testing::Test {
private:
    analogComparator_Struct _acS;
    combined_Struct _cbS;
protected:
    unsigned char readACSR() {
        return _acS._ACSR;
    }
    void writeACSR(unsigned char value) {
        _acS._ACSR = value;
    }
    unsigned char readSFIOR() {
        return _cbS._SFIOR;
    }
    void writeSFIOR(unsigned char value) {
        _cbS._SFIOR = value;
    }
public:
    virtual void SetUp() {
        _acS = {};
        _cbS = {};
        analogComparator::_acS = &_acS;
        analogComparator::_cbS = &_cbS;
    }
    virtual void TearDown() {
    }
};

/* TEST CODES */
TEST_F(analogComparator_ut, offAnalogComparatorMultiplexer)
{
    analogComparator::offAnalogComparatorMultiplexer();
    EXPECT_EQ(0x08, readSFIOR());
}
TEST_F(analogComparator_ut, onAnalogComparatorMultiplexer)
{
    writeSFIOR(0x08);
    analogComparator::onAnalogComparatorMultiplexer();
    EXPECT_EQ(0x00, readSFIOR());
}
TEST_F(analogComparator_ut, getAnalogComparatorMultiplexer)
{
    writeSFIOR(0x08);
    EXPECT_EQ(false, analogComparator::getAnalogComparatorMultiplexer());
    writeSFIOR(0x00);
    EXPECT_EQ(true, analogComparator::getAnalogComparatorMultiplexer());
}
TEST_F(analogComparator_ut, offAnalogComparator)
{
    analogComparator::offAnalogComparator();
    EXPECT_EQ(0x80, readACSR());
}
TEST_F(analogComparator_ut, onAnalogComparator)
{
    writeACSR(0x80);
    analogComparator::onAnalogComparator();
    EXPECT_EQ(0x00, readACSR());
}
TEST_F(analogComparator_ut, getAnalogComparator)
{
    writeACSR(0x80);
    EXPECT_EQ(false, analogComparator::getAnalogComparator());
    writeACSR(0x00);
    EXPECT_EQ(true, analogComparator::getAnalogComparator());
}
TEST_F(analogComparator_ut, setBandgap)
{
    analogComparator::setBandgap();
    EXPECT_EQ(0x40, readACSR());
}
TEST_F(analogComparator_ut, clearBandgap)
{
    writeACSR(0x40);
    analogComparator::clearBandgap();
    EXPECT_EQ(0x00, readACSR());
}
TEST_F(analogComparator_ut, getBandgap)
{
    writeACSR(0x40);
    EXPECT_EQ(true, analogComparator::getBandgap());
    writeACSR(0x00);
    EXPECT_EQ(false, analogComparator::getBandgap());
}
TEST_F(analogComparator_ut, readOutput)
{
    writeACSR(0x20);
    EXPECT_EQ(true, analogComparator::readOutput());
    writeACSR(0x00);
    EXPECT_EQ(false, analogComparator::readOutput());
}
TEST_F(analogComparator_ut, readInterruptFlag)
{
    writeACSR(0x10);
    EXPECT_EQ(true, analogComparator::readInterruptFlag());
    writeACSR(0x00);
    EXPECT_EQ(false, analogComparator::readInterruptFlag());
}
TEST_F(analogComparator_ut, clearInterruptFlag)
{
    analogComparator::clearInterruptFlag();
    EXPECT_EQ(0x10, readACSR());
}
TEST_F(analogComparator_ut, setInterruptEnable)
{
    analogComparator::setInterruptEnable();
    EXPECT_EQ(0x08, readACSR());
}
TEST_F(analogComparator_ut, clearInterruptEnable)
{
    writeACSR(0x08);
    analogComparator::clearInterruptEnable();
    EXPECT_EQ(0x00, readACSR());
}
TEST_F(analogComparator_ut, getInterruptEnable)
{
    writeACSR(0x08);
    EXPECT_EQ(true, analogComparator::getInterruptEnable());
    writeACSR(0x00);
    EXPECT_EQ(false, analogComparator::getInterruptEnable());
}
TEST_F(analogComparator_ut, setInputCaptureEnable)
{
    analogComparator::setInputCaptureEnable();
    EXPECT_EQ(0x04, readACSR());
}
TEST_F(analogComparator_ut, clearInputCaptureEnable)
{
    writeACSR(0x04);
    analogComparator::clearInputCaptureEnable();
    EXPECT_EQ(0x00, readACSR());
}
TEST_F(analogComparator_ut, getInputCaptureEnable)
{
    writeACSR(0x04);
    EXPECT_EQ(true, analogComparator::getInputCaptureEnable());
    writeACSR(0x00);
    EXPECT_EQ(false, analogComparator::getInputCaptureEnable());
}
TEST_F(analogComparator_ut, setInterruptMode)
{
    analogComparator::setInterruptMode(analogComparator::mode::interrupt_on_Output_Toggle);
    EXPECT_EQ(0x00, readACSR());
    analogComparator::setInterruptMode(analogComparator::mode::interrupt_on_Falling_Output_Edge);
    EXPECT_EQ(0x02, readACSR());
    analogComparator::setInterruptMode(analogComparator::mode::interrupt_on_Rising_Output_Egde);
    EXPECT_EQ(0x03, readACSR());
}
TEST_F(analogComparator_ut, getInterruptMode)
{
    EXPECT_EQ(analogComparator::mode::interrupt_on_Output_Toggle, analogComparator::getInterruptMode());
    writeACSR(0x02);
    EXPECT_EQ(analogComparator::mode::interrupt_on_Falling_Output_Edge, analogComparator::getInterruptMode());
    writeACSR(0x03);
    EXPECT_EQ(analogComparator::mode::interrupt_on_Rising_Output_Egde, analogComparator::getInterruptMode());
}
