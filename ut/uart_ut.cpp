#include <gtest/gtest.h>

#include "uart.h"

class uart_ut: public ::testing::Test {
public:
    virtual void SetUp() {
        _utS = {};
        uart::_utS = &_utS;
    }
    virtual void TearDown() {
    }
protected:
    void writeUDR(unsigned char val) {
        _utS._UDR = val;
    }
    unsigned char readUDR() {
        return _utS._UDR;
    }

    void writeUCSRA(unsigned char val) {
        _utS._UCSRA = val;
    }
    unsigned char readUCSRA() {
        return _utS._UCSRA;
    }

    void writeUCSRB(unsigned char val) {
        _utS._UCSRB = val;
    }
    unsigned char readUCSRB() {
        return _utS._UCSRB;
    }

    void writeUCSRC(unsigned char val) {
        _utS._UBBRH_UCSRC = 0x80;
        _utS._UBBRH_UCSRC |= val;
    }
    unsigned char readUCSRC() {
        _utS._UBBRH_UCSRC |= 0x80;
        return _utS._UBBRH_UCSRC;
    }

    void writeUBBRH(unsigned char val) {
        _utS._UBBRH_UCSRC = val;
    }
    unsigned char readUBBRH() {
        return _utS._UBBRH_UCSRC;
    }

    void writeUBRRL(unsigned char val) {
        _utS._UBRRL = val;
    }
    unsigned char readUBRRL() {
        return _utS._UBRRL;
    }
private:
    uart_Struct _utS;
};

/* TEST CODES */
TEST_F(uart_ut, readReceiveCompleteFlag)
{
    writeUCSRA((1<<7));
    EXPECT_EQ(true, uart::readReceiveCompleteFlag());
    writeUCSRA(static_cast<unsigned char>(~(1 << 7)));
    EXPECT_EQ(false, uart::readReceiveCompleteFlag());
}
TEST_F(uart_ut, readDataRegisterEmptyFlag)
{
    writeUCSRA((1<<5));
    EXPECT_EQ(true, uart::readDataRegisterEmptyFlag());
    writeUCSRA(static_cast<unsigned char>(~(1 << 5)));
    EXPECT_EQ(false, uart::readDataRegisterEmptyFlag());
}
TEST_F(uart_ut, readFrameErrorFlag)
{
    writeUCSRA((1<<4));
    EXPECT_EQ(true, uart::readFrameErrorFlag());
    writeUCSRA(static_cast<unsigned char>(~(1 << 4)));
    EXPECT_EQ(false, uart::readFrameErrorFlag());
}
TEST_F(uart_ut, readDataOverRunFlag)
{
    writeUCSRA((1<<3));
    EXPECT_EQ(true, uart::readDataOverRunFlag());
    writeUCSRA(static_cast<unsigned char>(~(1 << 3)));
    EXPECT_EQ(false, uart::readDataOverRunFlag());
}
TEST_F(uart_ut, readParityErrorFlag)
{
    writeUCSRA((1<<2));
    EXPECT_EQ(true, uart::readParityErrorFlag());
    writeUCSRA(static_cast<unsigned char>(~(1 << 2)));
    EXPECT_EQ(false, uart::readParityErrorFlag());
}
TEST_F(uart_ut, readTransmitCompleteFlag)
{
    writeUCSRA((1<<6));
    EXPECT_EQ(true, uart::readTransmitCompleteFlag());
    writeUCSRA(static_cast<unsigned char>(~(1 << 6)));
    EXPECT_EQ(false, uart::readTransmitCompleteFlag());
}
TEST_F(uart_ut, clearTransmitCompleteFlag)
{
    uart::clearTransmitCompleteFlag();
    EXPECT_EQ((1<<6), readUCSRA());
}
TEST_F(uart_ut, setDoubleTransmissionSpeed)
{
    uart::setDoubleTransmissionSpeed();
    EXPECT_EQ(0x02, readUCSRA());
}
TEST_F(uart_ut, clearDoubleTransmissionSpeed)
{
    writeUCSRA(0xFF);
    uart::clearDoubleTransmissionSpeed();
    EXPECT_EQ(0xFD, readUCSRA());
}
TEST_F(uart_ut, getDoubleTransmissionSpeed)
{
    writeUCSRA((1<<1));
    EXPECT_EQ(true, uart::getDoubleTransmissionSpeed());
    writeUCSRA(static_cast<unsigned char>(~(1 << 1)));
    EXPECT_EQ(false, uart::getDoubleTransmissionSpeed());
}
TEST_F(uart_ut, setMultiprocessorCommunicationMode)
{
    uart::setMultiprocessorCommunicationMode();
    EXPECT_EQ(0x01, readUCSRA());
}
TEST_F(uart_ut, clearMultiprocessorCommunicationMode)
{
    writeUCSRA(0xFF);
    uart::clearMultiprocessorCommunicationMode();
    EXPECT_EQ(0xFE, readUCSRA());
}
TEST_F(uart_ut, getMultiprocessorCommunicationMode)
{
    writeUCSRA((1<<0));
    EXPECT_EQ(true, uart::getMultiprocessorCommunicationMode());
    writeUCSRA(static_cast<unsigned char>(~(1 << 0)));
    EXPECT_EQ(false, uart::getMultiprocessorCommunicationMode());
}
TEST_F(uart_ut, setRXCompleteInterrupt)
{
    uart::setRXCompleteInterrupt();
    EXPECT_EQ(0x80, readUCSRB());
}
TEST_F(uart_ut, clearRXCompleteInterrupt)
{
    writeUCSRB(0xFF);
    uart::clearRXCompleteInterrupt();
    EXPECT_EQ(0x7F, readUCSRB());
}
TEST_F(uart_ut, getRXCompleteInterrupt)
{
    writeUCSRB((1<<7));
    EXPECT_EQ(true, uart::getRXCompleteInterrupt());
    writeUCSRB(static_cast<unsigned char>(~(1 << 7)));
    EXPECT_EQ(false, uart::getRXCompleteInterrupt());
}
TEST_F(uart_ut, setTXCompleteInterrupt)
{
    uart::setTXCompleteInterrupt();
    EXPECT_EQ(0x40, readUCSRB());
}
TEST_F(uart_ut, clearTXCompleteInterrupt)
{
    writeUCSRB(0xFF);
    uart::clearTXCompleteInterrupt();
    EXPECT_EQ(0xBF, readUCSRB());
}
TEST_F(uart_ut, getTXCompleteInterrupt)
{
    writeUCSRB((1<<6));
    EXPECT_EQ(true, uart::getTXCompleteInterrupt());
    writeUCSRB(static_cast<unsigned char>(~(1 << 6)));
    EXPECT_EQ(false, uart::getTXCompleteInterrupt());
}
TEST_F(uart_ut, setDataRegisterEmptyInterrupt)
{
    uart::setDataRegisterEmptyInterrupt();
    EXPECT_EQ(0x20, readUCSRB());
}
TEST_F(uart_ut, clearDataRegisterEmptyInterrupt)
{
    writeUCSRB(0xFF);
    uart::clearDataRegisterEmptyInterrupt();
    EXPECT_EQ(0xDF, readUCSRB());
}
TEST_F(uart_ut, getDataRegisterEmptyInterrupt)
{
    writeUCSRB((1<<5));
    EXPECT_EQ(true, uart::getDataRegisterEmptyInterrupt());
    writeUCSRB(static_cast<unsigned char>(~(1 << 5)));
    EXPECT_EQ(false, uart::getDataRegisterEmptyInterrupt());
}
TEST_F(uart_ut, setReceiverEnable)
{
    uart::setReceiverEnable();
    EXPECT_EQ(0x10, readUCSRB());
}
TEST_F(uart_ut, clearReceiverEnable)
{
    writeUCSRB(0xFF);
    uart::clearReceiverEnable();
    EXPECT_EQ(0xEF, readUCSRB());
}
TEST_F(uart_ut, getReceiverEnable)
{
    writeUCSRB((1<<4));
    EXPECT_EQ(true, uart::getReceiverEnable());
    writeUCSRB(static_cast<unsigned char>(~(1 << 4)));
    EXPECT_EQ(false, uart::getReceiverEnable());
}
TEST_F(uart_ut, setTransmitterEnable)
{
    uart::setTransmitterEnable();
    EXPECT_EQ(0x08, readUCSRB());
}
TEST_F(uart_ut, clearTransmitterEnable)
{
    writeUCSRB(0xFF);
    uart::clearTransmitterEnable();
    EXPECT_EQ(0xF7, readUCSRB());
}
TEST_F(uart_ut, getTransmitterEnable)
{
    writeUCSRB((1<<3));
    EXPECT_EQ(true, uart::getTransmitterEnable());
    writeUCSRB(static_cast<unsigned char>(~(1 << 3)));
    EXPECT_EQ(false, uart::getTransmitterEnable());
}
TEST_F(uart_ut, setMode)
{
    uart::setMode(uart::mode::synchronous);
    EXPECT_EQ(0xC0, readUCSRC());
    uart::setMode(uart::mode::asynchronous);
    EXPECT_EQ(0x80, readUCSRC());

}
TEST_F(uart_ut, getMode)
{
    EXPECT_EQ(uart::mode::asynchronous, uart::getMode());
    writeUCSRC(1<<6);
    EXPECT_EQ(uart::mode::synchronous, uart::getMode());

}
TEST_F(uart_ut, setParity)
{
    uart::setParity(uart::parity::disabled);
    EXPECT_EQ(0x80, readUCSRC());
    uart::setParity(uart::parity::even_parity);
    EXPECT_EQ(0xA0, readUCSRC());
    uart::setParity(uart::parity::odd_parity);
    EXPECT_EQ(0xB0, readUCSRC());
}
TEST_F(uart_ut, getParity)
{
    EXPECT_EQ(uart::parity::disabled, uart::getParity());
    writeUCSRC(0x20);
    EXPECT_EQ(uart::parity::even_parity, uart::getParity());
    writeUCSRC(0x30);
    EXPECT_EQ(uart::parity::odd_parity, uart::getParity());
}
TEST_F(uart_ut, setStopBit)
{
    uart::setStopBit(uart::stopBit::one_bit);
    EXPECT_EQ(0x80, readUCSRC());
    uart::setStopBit(uart::stopBit::two_bit);
    EXPECT_EQ(0x88, readUCSRC());
}
TEST_F(uart_ut, getStopBit)
{
    EXPECT_EQ(uart::stopBit::one_bit, uart::getStopBit());
    writeUCSRC(0x08);
    EXPECT_EQ(uart::stopBit::two_bit, uart::getStopBit());
}
TEST_F(uart_ut, setCharacterSize)
{
    uart::setCharacterSize(uart::characterSize::_5_bit);
    EXPECT_EQ(0x80, readUCSRC());
    EXPECT_EQ(0x00, readUCSRB());
    uart::setCharacterSize(uart::characterSize::_6_bit);
    EXPECT_EQ(0x82, readUCSRC());
    EXPECT_EQ(0x00, readUCSRB());
    uart::setCharacterSize(uart::characterSize::_7_bit);
    EXPECT_EQ(0x84, readUCSRC());
    EXPECT_EQ(0x00, readUCSRB());
    uart::setCharacterSize(uart::characterSize::_8_bit);
    EXPECT_EQ(0x86, readUCSRC());
    EXPECT_EQ(0x00, readUCSRB());
    uart::setCharacterSize(uart::characterSize::_9_bit);
    EXPECT_EQ(0x86, readUCSRC());
    EXPECT_EQ(0x04, readUCSRB());
}
TEST_F(uart_ut, getCharacterSize)
{
    EXPECT_EQ(uart::characterSize::_5_bit, uart::getCharacterSize());
    writeUCSRC(0x02);
    EXPECT_EQ(uart::characterSize::_6_bit, uart::getCharacterSize());
    writeUCSRC(0x04);
    EXPECT_EQ(uart::characterSize::_7_bit, uart::getCharacterSize());
    writeUCSRC(0x06);
    EXPECT_EQ(uart::characterSize::_8_bit, uart::getCharacterSize());
    writeUCSRC(0x06);
    writeUCSRB(0x04);
    EXPECT_EQ(uart::characterSize::_9_bit, uart::getCharacterSize());
}
TEST_F(uart_ut, setClockPolarity)
{
    uart::setClockPolarity(uart::clockPolarity::risingTX_fallingRX);
    EXPECT_EQ(0x80, readUCSRC());
    uart::setClockPolarity(uart::clockPolarity::fallingTX_risingRX);
    EXPECT_EQ(0x81, readUCSRC());
}
TEST_F(uart_ut, getClockPolarity)
{
    EXPECT_EQ(uart::clockPolarity::risingTX_fallingRX, uart::getClockPolarity());
    writeUCSRC(0x01);
    EXPECT_EQ(uart::clockPolarity::fallingTX_risingRX, uart::getClockPolarity());
}

TEST_F(uart_ut, setBaudRate)
{
    unsigned int val;

    uart::setBaudRate(uart::baudRate::_2400);
    val = readUBBRH();
    val = (val << 4);
    val |= readUBRRL();
    EXPECT_EQ(25, val);

    uart::setBaudRate(uart::baudRate::_4800);
    val = readUBBRH();
    val = (val << 4);
    val |= readUBRRL();
    EXPECT_EQ(12, val);

    uart::setBaudRate(uart::baudRate::_9600);
    val = readUBBRH();
    val = (val << 4);
    val |= readUBRRL();
    EXPECT_EQ(5, val);

    uart::setBaudRate(uart::baudRate::_14400);
    val = readUBBRH();
    val = (val << 4);
    val |= readUBRRL();
    EXPECT_EQ(3, val);

    uart::setBaudRate(uart::baudRate::_19200);
    val = readUBBRH();
    val = (val << 4);
    val |= readUBRRL();
    EXPECT_EQ(2, val);

    uart::setBaudRate(uart::baudRate::_28800);
    val = readUBBRH();
    val = (val << 4);
    val |= readUBRRL();
    EXPECT_EQ(1, val);

    uart::setBaudRate(uart::baudRate::_38400);
    val = readUBBRH();
    val = (val << 4);
    val |= readUBRRL();
    EXPECT_EQ(0, val);
}
TEST_F(uart_ut, getBaudRate)
{
    uart::setBaudRate(uart::baudRate::_14400);
    EXPECT_EQ(uart::baudRate::_14400, uart::getBaudRate());
}
TEST_F(uart_ut, getRealBaudRate)
{   uart::setBaudRate(uart::baudRate::_2400);
    EXPECT_EQ(2403, uart::getRealBaudRate());

    uart::setBaudRate(uart::baudRate::_4800);
    EXPECT_EQ(4807, uart::getRealBaudRate());

    uart::setBaudRate(uart::baudRate::_9600);
    EXPECT_EQ(10416, uart::getRealBaudRate());

    uart::setBaudRate(uart::baudRate::_14400);
    EXPECT_EQ(15625, uart::getRealBaudRate());

    uart::setBaudRate(uart::baudRate::_19200);
    EXPECT_EQ(20833, uart::getRealBaudRate());

    uart::setBaudRate(uart::baudRate::_28800);
    EXPECT_EQ(31250, uart::getRealBaudRate());

    uart::setBaudRate(uart::baudRate::_38400);
    EXPECT_EQ(62500, uart::getRealBaudRate());
}

TEST_F(uart_ut, writeData)
{
    unsigned int val = 0x00CD;

    uart::writeData(val);
    EXPECT_EQ(0xCD, readUDR());

    val = 0x01BA;
    uart::setCharacterSize(uart::characterSize::_9_bit);
    uart::writeData(val);
    EXPECT_EQ(0xBA, readUDR());
    EXPECT_EQ(0x05, readUCSRB());

}
TEST_F(uart_ut, readData)
{
    writeUDR(0x00CD);
    EXPECT_EQ(0xCD, uart::readData());

    writeUCSRB(0x02);
    uart::setCharacterSize(uart::characterSize::_9_bit);
    EXPECT_EQ(0x01CD, uart::readData());

}
