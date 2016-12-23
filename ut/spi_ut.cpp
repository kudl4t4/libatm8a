#include <gtest/gtest.h>

#include "spi.h"

class spi_ut: public ::testing::Test {
public:
    virtual void SetUp() {
        _spiS = {};
        spi::_sp = &_spiS;
    }
    virtual void TearDown() {
    }
protected:
    void writeSPCR(unsigned char val) {
        _spiS._SPCR = val;
    }
    unsigned char readSPCR() {
        return _spiS._SPCR;
    }

    void writeSPSR(unsigned char val) {
        _spiS._SPSR = val;
    }
    unsigned char readSPSR() {
        return _spiS._SPSR;
    }

    void writeSPDR(unsigned char val) {
        _spiS._SPDR = val;
    }
    unsigned char readSPDR() {
        return _spiS._SPDR;
    }
private:
    spi_Struct _spiS;
};

/* TEST CODES */
TEST_F(spi_ut, setEnableSpi)
{
    spi::setEnableSpi();
    EXPECT_EQ((1<<6), readSPCR());
}
TEST_F(spi_ut, clearEnableSpi)
{
    writeSPCR(0xFF);
    spi::clearEnableSpi();
    EXPECT_EQ(0xBF, readSPCR());
}
TEST_F(spi_ut, getEnableSpi)
{
    writeSPCR(1<<6);
    EXPECT_EQ(true, spi::getEnableSpi());
    writeSPCR(static_cast<unsigned char>(~(1 << 6)));
    EXPECT_EQ(false, spi::getEnableSpi());
}
TEST_F(spi_ut, setInterruptEnable)
{
    spi::setInterruptEnable();
    EXPECT_EQ((1<<7), readSPCR());
}
TEST_F(spi_ut, clearInterruptEnable)
{
    writeSPCR(0xFF);
    spi::clearInterruptEnable();
    EXPECT_EQ(0x7F, readSPCR());
}
TEST_F(spi_ut, getInterruptEnable)
{
    writeSPCR(1<<7);
    EXPECT_EQ(true, spi::getInterruptEnable());
    writeSPCR(static_cast<unsigned char>(~(1 << 7)));
    EXPECT_EQ(false, spi::getInterruptEnable());
}
TEST_F(spi_ut, setDataOrder)
{
    spi::setDataOrder(spi::dataOrder::LSB_fisrt);
    EXPECT_EQ((1<<5), readSPCR());
    writeSPCR(0xFF);
    spi::setDataOrder(spi::dataOrder::MSB_first);
    EXPECT_EQ(0xDF, readSPCR());

}
TEST_F(spi_ut, getDataOrder)
{
    writeSPCR(1<<5);
    EXPECT_EQ(spi::dataOrder::LSB_fisrt, spi::getDataOrder());
    writeSPCR(static_cast<unsigned char>(~(1 << 5)));
    EXPECT_EQ(spi::dataOrder::MSB_first, spi::getDataOrder());
}
TEST_F(spi_ut, setModeSelect)
{
    spi::setModeSelect(spi::mode::master);
    EXPECT_EQ((1<<4), readSPCR());
    writeSPCR(0xFF);
    spi::setModeSelect(spi::mode::slave);
    EXPECT_EQ(0xEF, readSPCR());
}
TEST_F(spi_ut, getModeSelect)
{
    writeSPCR(1<<4);
    EXPECT_EQ(spi::mode::master, spi::getModeSelect());
    writeSPCR(static_cast<unsigned char>(~(1 << 4)));
    EXPECT_EQ(spi::mode::slave, spi::getModeSelect());
}
TEST_F(spi_ut, setClockPolarity)
{
    spi::setClockPolarity(spi::clockPolarity::sck_high_when_idle);
    EXPECT_EQ((1<<3), readSPCR());
    writeSPCR(0xFF);
    spi::setClockPolarity(spi::clockPolarity::sck_low_when_idle);
    EXPECT_EQ(0xF7, readSPCR());
}
TEST_F(spi_ut, getClockPolarity)
{
    writeSPCR(1<<3);
    EXPECT_EQ(spi::clockPolarity::sck_high_when_idle, spi::getClockPolarity());
    writeSPCR(static_cast<unsigned char>(~(1 << 3)));
    EXPECT_EQ(spi::clockPolarity::sck_low_when_idle, spi::getClockPolarity());
}
TEST_F(spi_ut, setClockPhase)
{
    spi::setClockPhase(spi::clockPhase::leading_edge);
    EXPECT_EQ((1<<2), readSPCR());
    writeSPCR(0xFF);
    spi::setClockPhase(spi::clockPhase::trailing_edge);
    EXPECT_EQ(0xFB, readSPCR());
}
TEST_F(spi_ut, getClockPhase)
{
    writeSPCR(1<<2);
    EXPECT_EQ(spi::clockPhase::leading_edge, spi::getClockPhase());
    writeSPCR(static_cast<unsigned char>(~(1 << 2)));
    EXPECT_EQ(spi::clockPhase::trailing_edge, spi::getClockPhase());
}
TEST_F(spi_ut, setClockRate)
{
    spi::setClockRate(spi::clockRate::fosc_4);
    EXPECT_EQ(0x00, readSPCR());
    EXPECT_EQ(0x00, readSPSR());
    spi::setClockRate(spi::clockRate::fosc_16);
    EXPECT_EQ(0x01, readSPCR());
    EXPECT_EQ(0x00, readSPSR());
    spi::setClockRate(spi::clockRate::fosc_64_1);
    EXPECT_EQ(0x02, readSPCR());
    EXPECT_EQ(0x00, readSPSR());
    spi::setClockRate(spi::clockRate::fosc_128);
    EXPECT_EQ(0x03, readSPCR());
    EXPECT_EQ(0x00, readSPSR());

    spi::setClockRate(spi::clockRate::fosc_2);
    EXPECT_EQ(0x00, readSPCR());
    EXPECT_EQ(0x01, readSPSR());
    spi::setClockRate(spi::clockRate::fosc_8);
    EXPECT_EQ(0x01, readSPCR());
    EXPECT_EQ(0x01, readSPSR());
    spi::setClockRate(spi::clockRate::fosc_32);
    EXPECT_EQ(0x02, readSPCR());
    EXPECT_EQ(0x01, readSPSR());
    spi::setClockRate(spi::clockRate::fosc_64_2);
    EXPECT_EQ(0x03, readSPCR());
    EXPECT_EQ(0x01, readSPSR());
}
TEST_F(spi_ut, getClockRate)
{
    writeSPSR(0x00);
    writeSPCR(0x00);
    EXPECT_EQ(spi::clockRate::fosc_4, spi::getClockRate());
    writeSPCR(0x01);
    EXPECT_EQ(spi::clockRate::fosc_16, spi::getClockRate());
    writeSPCR(0x02);
    EXPECT_EQ(spi::clockRate::fosc_64_1, spi::getClockRate());
    writeSPCR(0x03);
    EXPECT_EQ(spi::clockRate::fosc_128, spi::getClockRate());

    writeSPSR(0x01);
    writeSPCR(0x00);
    EXPECT_EQ(spi::clockRate::fosc_2, spi::getClockRate());
    writeSPCR(0x01);
    EXPECT_EQ(spi::clockRate::fosc_8, spi::getClockRate());
    writeSPCR(0x02);
    EXPECT_EQ(spi::clockRate::fosc_32, spi::getClockRate());
    writeSPCR(0x03);
    EXPECT_EQ(spi::clockRate::fosc_64_2, spi::getClockRate());
}
TEST_F(spi_ut, getInterruptFlag)
{
    writeSPSR(0x80);
    EXPECT_EQ(true, spi::getInterruptFlag());
    writeSPSR(0x00);
    EXPECT_EQ(false, spi::getInterruptFlag());
}
TEST_F(spi_ut, getWriteCollisionFlag)
{
    writeSPSR(0x40);
    EXPECT_EQ(true, spi::getWriteCollisionFlag());
    writeSPSR(0x00);
    EXPECT_EQ(false, spi::getWriteCollisionFlag());
}
TEST_F(spi_ut, setData)
{
    unsigned char val = 0x56;
    spi::setData(val);
    EXPECT_EQ(val, readSPDR());
}
TEST_F(spi_ut, getData)
{
    unsigned char val = 0x73;
    writeSPDR(val);
    EXPECT_EQ(val, spi::getData());
}