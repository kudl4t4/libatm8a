#include <gtest/gtest.h>

#include "eeprom.h"

class eeprom_ut: public ::testing::Test {
public:
    virtual void SetUp() {
        _eepS = {};
        eeprom::_ees =&_eepS;
    }
    virtual void TearDown() {
    }
protected:
    void writeEEARL(unsigned char val) {
        _eepS._EEARL = val;
    }
    unsigned char readEEARL() {
        return _eepS._EEARL;
    }

    void writeEEARH(unsigned char val) {
        _eepS._EEARH = val;
    }
    unsigned char readEEARH() {
        return _eepS._EEARH;
    }

    void writeEEDR(unsigned char val) {
        _eepS._EEDR = val;
    }
    unsigned char readEEDR() {
        return _eepS._EEDR;
    }

    void writeEECR(unsigned char val) {
        _eepS._EECR = val;
    }
    unsigned char readEECR() {
        return _eepS._EECR;
    }
private:
    eeprom_Struct _eepS;
};

/* TEST CODES */
TEST_F(eeprom_ut, setAddress)
{
    unsigned int val = 0x0134;
    unsigned char ret;

    ret = eeprom::setAddress(0xFFFF);
    EXPECT_EQ(0x02, ret);
    EXPECT_EQ(0x00, readEEARL());
    EXPECT_EQ(0x00, readEEARH());

    ret = eeprom::setAddress(val);
    EXPECT_EQ(0x00, ret);
    EXPECT_EQ((val & 0x00FF), readEEARL());
    EXPECT_EQ((val >> 8), readEEARH());
}

TEST_F(eeprom_ut, getAddress)
{
    unsigned int val;
    unsigned char val1 = 0x56;
    unsigned char val2 = 0x01;

    writeEEARL(val1);
    writeEEARH(val2);
    val = eeprom::getAddress();
    EXPECT_EQ(((val2 << 8) | val1), val);
}

TEST_F(eeprom_ut, setData)
{
    unsigned char data = 0x43;

    eeprom::setData(data);
    EXPECT_EQ(data, readEEDR());
}

TEST_F(eeprom_ut, getData)
{
    unsigned char data = 0x89;

    writeEEDR(data);
    EXPECT_EQ(data, eeprom::getData());
}

TEST_F(eeprom_ut, setReadyInterrupt)
{
    eeprom::setReadyInterrupt();
    EXPECT_EQ((1 << 3), readEECR());
}

TEST_F(eeprom_ut, clearReadyInterrupt)
{
    writeEECR(0x0F);
    eeprom::clearReadyInterrupt();
    EXPECT_EQ(0x07, readEECR());
}

TEST_F(eeprom_ut, getReadyInterrupt)
{
    writeEECR(0x0F);
    EXPECT_EQ(true, eeprom::getReadyInterrupt());
    writeEECR(0x00);
    EXPECT_EQ(false, eeprom::getReadyInterrupt());
}

TEST_F(eeprom_ut, setMasterWriteEnable)
{
    eeprom::setMasterWriteEnable();
    EXPECT_EQ((1 << 2), readEECR());
}

TEST_F(eeprom_ut, clearMasterWriteEnable)
{
    writeEECR(0x0F);
    eeprom::clearMasterWriteEnable();
    EXPECT_EQ(0x0B, readEECR());
}

TEST_F(eeprom_ut, getMasterWriteEnable)
{
    writeEECR(0x0F);
    EXPECT_EQ(true, eeprom::getMasterWriteEnable());
    writeEECR(0x00);
    EXPECT_EQ(false, eeprom::getMasterWriteEnable());
}

TEST_F(eeprom_ut, setWriteEnable)
{
    eeprom::setWriteEnable();
    EXPECT_EQ((1 << 1), readEECR());
}

TEST_F(eeprom_ut, clearWriteEnable)
{
    writeEECR(0x0F);
    eeprom::clearWriteEnable();
    EXPECT_EQ(0x0D, readEECR());
}

TEST_F(eeprom_ut, getWriteEnable)
{
    writeEECR(0x0F);
    EXPECT_EQ(true, eeprom::getWriteEnable());
    writeEECR(0x00);
    EXPECT_EQ(false, eeprom::getWriteEnable());
}

TEST_F(eeprom_ut, setReadEnable)
{
    eeprom::setReadEnable();
    EXPECT_EQ((1 << 0), readEECR());
}

TEST_F(eeprom_ut, clearReadEnable)
{
    writeEECR(0x0F);
    eeprom::clearReadEnable();
    EXPECT_EQ(0x0E, readEECR());
}

TEST_F(eeprom_ut, getReadEnable)
{
    writeEECR(0x0F);
    EXPECT_EQ(true, eeprom::getReadEnable());
    writeEECR(0x00);
    EXPECT_EQ(false, eeprom::getReadEnable());
}
