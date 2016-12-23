#include <gtest/gtest.h>

#include "bootLoaderSupport.h"

class bootLoaderSupport_ut: public ::testing::Test {
private:
    bootLoaderSupport_Struct _blsS;
protected:

    unsigned char readSPMCR() {
        return _blsS._SPMCR;
    }
    void writeSPMCR(unsigned char value) {
        _blsS._SPMCR = value;
    }
public:
    virtual void SetUp() {
        _blsS = {};
        bootLoaderSupport::_btsS = &_blsS;
    }
    virtual void TearDown() {
    }
};

/* TEST CODES */
TEST_F(bootLoaderSupport_ut, setInterruptEnable)
{
    bootLoaderSupport::setInterruptEnable();
    EXPECT_EQ(0x80, readSPMCR());
}
TEST_F(bootLoaderSupport_ut, clearInterruptEnable)
{
    writeSPMCR(0x80);
    bootLoaderSupport::clearInterruptEnable();
    EXPECT_EQ(0x00, readSPMCR());
}
TEST_F(bootLoaderSupport_ut, getInterruptEnable)
{
    writeSPMCR(0x80);
    EXPECT_EQ(true, bootLoaderSupport::getInterruptEnable());
    writeSPMCR(0x00);
    EXPECT_EQ(false, bootLoaderSupport::getInterruptEnable());
}
TEST_F(bootLoaderSupport_ut, readReadWhileWriteSectionBusyFlag)
{
    writeSPMCR(0x40);
    EXPECT_EQ(true, bootLoaderSupport::readReadWhileWriteSectionBusyFlag());
    writeSPMCR(0x00);
    EXPECT_EQ(false, bootLoaderSupport::readReadWhileWriteSectionBusyFlag());
}
TEST_F(bootLoaderSupport_ut, setReadWhileWriteSectionBusyEnable)
{
    bootLoaderSupport::setReadWhileWriteSectionBusyEnable();
    EXPECT_EQ(0x10, readSPMCR());
}
TEST_F(bootLoaderSupport_ut, clearReadWhileWriteSectionBusyEnable)
{
    writeSPMCR(0x10);
    bootLoaderSupport::clearReadWhileWriteSectionBusyEnable();
    EXPECT_EQ(0x00, readSPMCR());
}
TEST_F(bootLoaderSupport_ut, getReadWhileWriteSectionBusyEnable)
{
    writeSPMCR(0x10);
    EXPECT_EQ(true, bootLoaderSupport::getReadWhileWriteSectionBusyEnable());
    writeSPMCR(0x00);
    EXPECT_EQ(false, bootLoaderSupport::getReadWhileWriteSectionBusyEnable());
}
TEST_F(bootLoaderSupport_ut, setBootLockBit)
{
    bootLoaderSupport::setBootLockBit();
    EXPECT_EQ(0x08, readSPMCR());
}
TEST_F(bootLoaderSupport_ut, clearBootLockBit)
{
    writeSPMCR(0x08);
    bootLoaderSupport::clearBootLockBit();
    EXPECT_EQ(0x00, readSPMCR());
}
TEST_F(bootLoaderSupport_ut, getBootLockBit)
{
    writeSPMCR(0x08);
    EXPECT_EQ(true, bootLoaderSupport::getBootLockBit());
    writeSPMCR(0x00);
    EXPECT_EQ(false, bootLoaderSupport::getBootLockBit());
}
TEST_F(bootLoaderSupport_ut, setPageWrite)
{
    bootLoaderSupport::setPageWrite();
    EXPECT_EQ(0x04, readSPMCR());
}
TEST_F(bootLoaderSupport_ut, clearPageWrite)
{
    writeSPMCR(0x04);
    bootLoaderSupport::clearPageWrite();
    EXPECT_EQ(0x00, readSPMCR());
}
TEST_F(bootLoaderSupport_ut, getPageWrite)
{
    writeSPMCR(0x04);
    EXPECT_EQ(true, bootLoaderSupport::getPageWrite());
    writeSPMCR(0x00);
    EXPECT_EQ(false, bootLoaderSupport::getPageWrite());
}
TEST_F(bootLoaderSupport_ut, setPageErase)
{
    bootLoaderSupport::setPageErase();
    EXPECT_EQ(0x02, readSPMCR());
}
TEST_F(bootLoaderSupport_ut, clearPageErase)
{
    writeSPMCR(0x02);
    bootLoaderSupport::clearPageErase();
    EXPECT_EQ(0x00, readSPMCR());
}
TEST_F(bootLoaderSupport_ut, getPageErase)
{
    writeSPMCR(0x02);
    EXPECT_EQ(true, bootLoaderSupport::getPageErase());
    writeSPMCR(0x00);
    EXPECT_EQ(false, bootLoaderSupport::getPageErase());
}
TEST_F(bootLoaderSupport_ut, setStoreProgramMemory)
{
    bootLoaderSupport::setStoreProgramMemory();
    EXPECT_EQ(0x01, readSPMCR());
}
TEST_F(bootLoaderSupport_ut, clearStoreProgramMemory)
{
    writeSPMCR(0x01);
    bootLoaderSupport::clearStoreProgramMemory();
    EXPECT_EQ(0x00, readSPMCR());
}
TEST_F(bootLoaderSupport_ut, getStoreProgramMemory)
{
    writeSPMCR(0x01);
    EXPECT_EQ(true, bootLoaderSupport::getStoreProgramMemory());
    writeSPMCR(0x00);
    EXPECT_EQ(false, bootLoaderSupport::getStoreProgramMemory());
}

