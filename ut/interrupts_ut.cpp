#include <gtest/gtest.h>

#include "interrupts.h"

class interrupts_ut: public ::testing::Test {
public:
    virtual void SetUp() {
        _intS = {};
        interrupts::_intS = &_intS;
    }
    virtual void TearDown() {
    }
protected:
    void writeGICR(unsigned char val) {
        _intS._GICR = val;
    }
    unsigned char readGICR() {
        return _intS._GICR;
    }

    void writeGIFR(unsigned char val) {
        _intS._GIFR = val;
    }
    unsigned char readGIFR() {
        return _intS._GIFR;
    }

    void writeMCUCR(unsigned char val) {
        _intS._MCUCR = val;
    }
    unsigned char readMCUCR() {
        return _intS._MCUCR;
    }
private:
    interrupts_Struct _intS;
};

/* TEST CODES */
TEST_F(interrupts_ut, setInterruptVectorPlaceSelect)
{
    interrupts::setInterruptVectorPlaceSelect();
    EXPECT_EQ(0x02, readGICR());
}
TEST_F(interrupts_ut, clearInterruptVectorPlaceSelect)
{
    writeGICR(0x03);
    interrupts::clearInterruptVectorPlaceSelect();
    EXPECT_EQ(0x01, readGICR());
}
TEST_F(interrupts_ut, getInterruptVectorPlaceSelect)
{
    writeGICR(0x03);
    EXPECT_EQ(true, interrupts::getInterruptVectorPlaceSelect());
    writeGICR(0x01);
    EXPECT_EQ(false, interrupts::getInterruptVectorPlaceSelect());
}
TEST_F(interrupts_ut, setInterruptVectorChangeEnable)
{
    interrupts::setInterruptVectorChangeEnable();
    EXPECT_EQ(0x01, readGICR());
}
TEST_F(interrupts_ut, clearInterruptVectorChangeEnable)
{
    writeGICR(0x03);
    interrupts::clearInterruptVectorChangeEnable();
    EXPECT_EQ(0x02, readGICR());
}
TEST_F(interrupts_ut, getInterruptVectorChangeEnable)
{
    writeGICR(0x03);
    EXPECT_EQ(true, interrupts::getInterruptVectorChangeEnable());
    writeGICR(0x02);
    EXPECT_EQ(false, interrupts::getInterruptVectorChangeEnable());
}
TEST_F(interrupts_ut, setExternalInterruptRequest)
{
    interrupts::setExternalInterruptRequest(interrupts::externalInterrupt::interrupt_0);
    EXPECT_EQ(0x40, readGICR());
    interrupts::setExternalInterruptRequest(interrupts::externalInterrupt::interrupt_1);
    EXPECT_EQ(0xC0, readGICR());
}
TEST_F(interrupts_ut, clearExternalInterruptRequest)
{
    writeGICR(0xC0);
    interrupts::clearExternalInterruptRequest(interrupts::externalInterrupt::interrupt_0);
    EXPECT_EQ(0x80, readGICR());
    interrupts::clearExternalInterruptRequest(interrupts::externalInterrupt::interrupt_1);
    EXPECT_EQ(0x00, readGICR());
}
TEST_F(interrupts_ut, getExternalInterruptRequest)
{
    writeGICR(0xFF);
    EXPECT_EQ(true, interrupts::getExternalInterruptRequest(interrupts::externalInterrupt::interrupt_0));
    EXPECT_EQ(true, interrupts::getExternalInterruptRequest(interrupts::externalInterrupt::interrupt_1));
    writeGICR(0x7F);
    EXPECT_EQ(true, interrupts::getExternalInterruptRequest(interrupts::externalInterrupt::interrupt_0));
    EXPECT_EQ(false, interrupts::getExternalInterruptRequest(interrupts::externalInterrupt::interrupt_1));
    writeGICR(0xBF);
    EXPECT_EQ(false, interrupts::getExternalInterruptRequest(interrupts::externalInterrupt::interrupt_0));
    EXPECT_EQ(true, interrupts::getExternalInterruptRequest(interrupts::externalInterrupt::interrupt_1));
    writeGICR(0x3F);
    EXPECT_EQ(false, interrupts::getExternalInterruptRequest(interrupts::externalInterrupt::interrupt_0));
    EXPECT_EQ(false, interrupts::getExternalInterruptRequest(interrupts::externalInterrupt::interrupt_1));
}
TEST_F(interrupts_ut, setInterruptSenseControl)
{
    interrupts::setInterruptSenseControl(interrupts::externalInterrupt::interrupt_0, interrupts::senseControl::low_level);
    EXPECT_EQ(0x00, readMCUCR());
    interrupts::setInterruptSenseControl(interrupts::externalInterrupt::interrupt_0, interrupts::senseControl::any_logical);
    EXPECT_EQ(0x01, readMCUCR());
    interrupts::setInterruptSenseControl(interrupts::externalInterrupt::interrupt_0, interrupts::senseControl::falling_edge);
    EXPECT_EQ(0x02, readMCUCR());
    interrupts::setInterruptSenseControl(interrupts::externalInterrupt::interrupt_0, interrupts::senseControl::rising_edge);
    EXPECT_EQ(0x03, readMCUCR());

    interrupts::setInterruptSenseControl(interrupts::externalInterrupt::interrupt_1, interrupts::senseControl::low_level);
    EXPECT_EQ(0x03, readMCUCR());
    interrupts::setInterruptSenseControl(interrupts::externalInterrupt::interrupt_1, interrupts::senseControl::any_logical);
    EXPECT_EQ(0x07, readMCUCR());
    interrupts::setInterruptSenseControl(interrupts::externalInterrupt::interrupt_1, interrupts::senseControl::falling_edge);
    EXPECT_EQ(0x0B, readMCUCR());
    interrupts::setInterruptSenseControl(interrupts::externalInterrupt::interrupt_1, interrupts::senseControl::rising_edge);
    EXPECT_EQ(0x0F, readMCUCR());
}
TEST_F(interrupts_ut, getInterruptSenseControl)
{
    writeMCUCR(0x0C);
    EXPECT_EQ(interrupts::senseControl::low_level, interrupts::getInterruptSenseControl(interrupts::externalInterrupt::interrupt_0));
    writeMCUCR(0x0D);
    EXPECT_EQ(interrupts::senseControl::any_logical, interrupts::getInterruptSenseControl(interrupts::externalInterrupt::interrupt_0));
    writeMCUCR(0x0E);
    EXPECT_EQ(interrupts::senseControl::falling_edge, interrupts::getInterruptSenseControl(interrupts::externalInterrupt::interrupt_0));
    writeMCUCR(0x0F);
    EXPECT_EQ(interrupts::senseControl::rising_edge, interrupts::getInterruptSenseControl(interrupts::externalInterrupt::interrupt_0));

    writeMCUCR(0x03);
    EXPECT_EQ(interrupts::senseControl::low_level, interrupts::getInterruptSenseControl(interrupts::externalInterrupt::interrupt_1));
    writeMCUCR(0x07);
    EXPECT_EQ(interrupts::senseControl::any_logical, interrupts::getInterruptSenseControl(interrupts::externalInterrupt::interrupt_1));
    writeMCUCR(0x0B);
    EXPECT_EQ(interrupts::senseControl::falling_edge, interrupts::getInterruptSenseControl(interrupts::externalInterrupt::interrupt_1));
    writeMCUCR(0x0F);
    EXPECT_EQ(interrupts::senseControl::rising_edge, interrupts::getInterruptSenseControl(interrupts::externalInterrupt::interrupt_1));
}
TEST_F(interrupts_ut, clearExternalInterruptFlag)
{
    writeGIFR(0xFF);
    interrupts::clearExternalInterruptFlag(interrupts::externalInterrupt::interrupt_1);
    EXPECT_EQ(0x7F, readGIFR());
    interrupts::clearExternalInterruptFlag(interrupts::externalInterrupt::interrupt_0);
    EXPECT_EQ(0x3F, readGIFR());
}
TEST_F(interrupts_ut, getExternalInterruptFlag)
{
    writeGIFR(0xFF);
    EXPECT_EQ(true, interrupts::getExternalInterruptFlag(interrupts::externalInterrupt::interrupt_1));
    EXPECT_EQ(true, interrupts::getExternalInterruptFlag(interrupts::externalInterrupt::interrupt_0));
    writeGIFR(0x7F);
    EXPECT_EQ(false, interrupts::getExternalInterruptFlag(interrupts::externalInterrupt::interrupt_1));
    EXPECT_EQ(true, interrupts::getExternalInterruptFlag(interrupts::externalInterrupt::interrupt_0));
    writeGIFR(0xBF);
    EXPECT_EQ(true, interrupts::getExternalInterruptFlag(interrupts::externalInterrupt::interrupt_1));
    EXPECT_EQ(false, interrupts::getExternalInterruptFlag(interrupts::externalInterrupt::interrupt_0));
    writeGIFR(0x3F);
    EXPECT_EQ(false, interrupts::getExternalInterruptFlag(interrupts::externalInterrupt::interrupt_1));
    EXPECT_EQ(false, interrupts::getExternalInterruptFlag(interrupts::externalInterrupt::interrupt_0));
}