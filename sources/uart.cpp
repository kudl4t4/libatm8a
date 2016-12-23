#include "uart.h"

uart_Struct volatile *uart::_utS;
uart::baudRate uart::_setBaud;

static unsigned char readUCSRC()
{
    unsigned char tmp;
#ifndef T_UNITTEST
    asm volatile ("\
                    in %0, 0x20\n\
                    in %0, 0x20\n\
                    "
                   : "=r" (tmp));
#else
    tmp = uart::_utS->_UBBRH_UCSRC;
#endif
    return tmp;
}

void uart::uart() {
    _utS = _uart;
}

/*!
 * \brief This flag bit is set when there are unread data in the receive buffer
 * and cleared when the receive buffer is empty.
 *
 * \return 1 - unread data available
 */
bool uart::readReceiveCompleteFlag() {
     return (((_utS->_UCSRA >> 7) & 0x01) == 0x00)? false : true;
}
/*!
 * \brief The flag indicates if the transmit buffer is ready to receive new data.
 * If the flag is one, the buffer is empty, and therefore ready to be written.
 *
 * \return 1 - the buffer is empty
 */
bool uart::readDataRegisterEmptyFlag() {
    return (((_utS->_UCSRA >> 5) & 0x01) == 0x00)? false : true;
}
/*!
 * \brief This flag is set if the next character in the receive buffer had a Frame Error when received.
 *
 * \return 1 - frame error set
 */
bool uart::readFrameErrorFlag() {
    return (((_utS->_UCSRA >> 4) & 0x01) == 0x00)? false : true;
}
/*!
 * \brief This bit is set if a Data OverRun condition is detected. A Data OverRun occurs when the
 * receive buffer is full (two characters), it is a new character waiting in the Receive Shift Register,
 * and a new start bit is detected.
 *
 * \return 1 - data overrun set
 */
bool uart::readDataOverRunFlag() {
    return (((_utS->_UCSRA >> 3) & 0x01) == 0x00)? false : true;
}
/*!
 * \brief This bit is set if the next character in the receive buffer had a Parity Error when received
 * and the parity checking was enabled at that point.
 *
 * \return 1 - parity error set
 */
bool uart::readParityErrorFlag() {
    return (((_utS->_UCSRA >> 2) & 0x01) == 0x00)? false : true;
}
/*!
 * \brief This flag bit is set when the entire frame in the Transmit Shift Register has been shifted out
 * and there are no new data currently present in the transmit buffer.
 *
 * \return 1 - no new data currently present
 */
bool uart::readTransmitCompleteFlag() {
    return (((_utS->_UCSRA >> 6) & 0x01) == 0x00)? false : true;
}
/*!
 * \brief The flag bit is automatically cleared when a transmit complete interrupt is executed,
 * or it can be cleared by writing a one to its bit location.
 */
void uart::clearTransmitCompleteFlag() {
    unsigned char tmp;

    tmp = _utS->_UCSRA;
    tmp |= (1 << 6);
    _utS->_UCSRA = tmp;
}
/*!
 * \brief Writing this bit to one will reduce the divisor of the baud rate divider from 16 to 8
 * effectively doubling the transfer rate for asynchronous communication.
 */
void uart::setDoubleTransmissionSpeed() {
    unsigned char tmp;

    tmp = _utS->_UCSRA;
    tmp |= (1 << 1);
    _utS->_UCSRA = tmp;
}
/*!
 * \brief This bit only has effect for the asynchronous operation.
 * Write this bit to zero when using synchronous operation.
 */
void uart::clearDoubleTransmissionSpeed() {
    unsigned char tmp;

    tmp = _utS->_UCSRA;
    tmp &= ~(1 << 1);
    _utS->_UCSRA = tmp;
}
/*!
 * \brief  Gets information about the setting of double the USART Transmission Speed bit.
 *
 * \return 1 - set
 */
bool uart::getDoubleTransmissionSpeed() {
    return (((_utS->_UCSRA >> 1) & 0x01) == 0x00)? false : true;
}
/*!
 * \brief This bit enables the Multi-processor Communication mode. When the MPCM bit is written to one,
 * all the incoming frames received by the USART Receiver that do not contain address information will be
 * ignored.
 */
void uart::setMultiprocessorCommunicationMode() {
    unsigned char tmp;

    tmp = _utS->_UCSRA;
    tmp |= (1 << 0);
    _utS->_UCSRA = tmp;
}
/*!
 * \brief This bit disables the Multi-processor Communication mode.
 */
void uart::clearMultiprocessorCommunicationMode() {
    unsigned char tmp;

    tmp = _utS->_UCSRA;
    tmp &= ~(1 << 0);
    _utS->_UCSRA = tmp;
}
/*!
 * \brief This bit gets the Multi-processor Communication mode.
 *
 * \return 1 - set
 */
bool uart::getMultiprocessorCommunicationMode() {
    return ((_utS->_UCSRA & 0x01) == 0x00)? false : true;
}

void uart::setRXCompleteInterrupt() {
    unsigned char tmp;

    tmp = _utS->_UCSRB;
    tmp |= (1 << 7);
    _utS->_UCSRB = tmp;
}

void uart::clearRXCompleteInterrupt() {
    unsigned char tmp;

    tmp = _utS->_UCSRB;
    tmp &= ~(1 << 7);
    _utS->_UCSRB = tmp;
}

bool uart::getRXCompleteInterrupt() {
    return (((_utS->_UCSRB >> 7) & 0x01) == 0x00)? false : true;
}

void uart::setTXCompleteInterrupt() {
    unsigned char tmp;

    tmp = _utS->_UCSRB;
    tmp |= (1 << 6);
    _utS->_UCSRB = tmp;
}

void uart::clearTXCompleteInterrupt() {
    unsigned char tmp;

    tmp = _utS->_UCSRB;
    tmp &= ~(1 << 6);
    _utS->_UCSRB = tmp;
}

bool uart::getTXCompleteInterrupt() {
    return (((_utS->_UCSRB >> 6) & 0x01) == 0x00)? false : true;
}

void uart::setDataRegisterEmptyInterrupt() {
    unsigned char tmp;

    tmp = _utS->_UCSRB;
    tmp |= (1 << 5);
    _utS->_UCSRB = tmp;
}

void uart::clearDataRegisterEmptyInterrupt() {
    unsigned char tmp;

    tmp = _utS->_UCSRB;
    tmp &= ~(1 << 5);
    _utS->_UCSRB = tmp;
}

bool uart::getDataRegisterEmptyInterrupt() {
    return (((_utS->_UCSRB >> 5) & 0x01) == 0x00)? false : true;
}

void uart::setReceiverEnable() {
    unsigned char tmp;

    tmp = _utS->_UCSRB;
    tmp |= (1 << 4);
    _utS->_UCSRB = tmp;
}

void uart::clearReceiverEnable() {
    unsigned char tmp;

    tmp = _utS->_UCSRB;
    tmp &= ~(1 << 4);
    _utS->_UCSRB = tmp;
}

bool uart::getReceiverEnable() {
    return (((_utS->_UCSRB >> 4) & 0x01) == 0x00)? false : true;
}

void uart::setTransmitterEnable() {
    unsigned char tmp;

    tmp = _utS->_UCSRB;
    tmp |= (1 << 3);
    _utS->_UCSRB = tmp;
}

void uart::clearTransmitterEnable() {
    unsigned char tmp;

    tmp = _utS->_UCSRB;
    tmp &= ~(1 << 3);
    _utS->_UCSRB = tmp;
}

bool uart::getTransmitterEnable() {
    return (((_utS->_UCSRB >> 3) & 0x01) == 0x00)? false : true;
}

void uart::setMode(uart::mode md) {
    unsigned char tmp;
    unsigned char val =0x00;

    if ( uart::mode::synchronous == md) {
        val = 0x01;
        clearDoubleTransmissionSpeed();
    }

    tmp = readUCSRC();
    tmp &= ~(1 << 6);
    tmp |= (val << 6);
    _utS->_UBBRH_UCSRC = tmp;
}

uart::mode uart::getMode() {
    unsigned char tmp;

    tmp = readUCSRC();
    return (((tmp >> 6) & 0x01) == 0x00)? uart::mode::asynchronous : uart::mode::synchronous;
}

void uart::setParity(uart::parity pp) {
    unsigned char tmp;
    unsigned char val =0x00;

    switch (pp) {
        case uart::parity::disabled:
            break;
        case uart::parity::even_parity:
            val =0x02;
            break;
        case uart::parity::odd_parity:
            val =0x03;
            break;
    }

    tmp = readUCSRC();
    tmp &= ~(0x03 << 4);
    tmp |= (val << 4);
    _utS->_UBBRH_UCSRC = tmp;
}

uart::parity uart::getParity() {
    unsigned char tmp;

    tmp = readUCSRC();
    tmp = (tmp >> 4) & 0x03;

    switch (tmp) {
        case 0x00:
            return uart::parity::disabled;
        case 0x02:
            return uart::parity::even_parity;
        case 0x03:
            return uart::parity::odd_parity;
    }
}

void uart::setStopBit(uart::stopBit sb) {
    unsigned char tmp;
    unsigned char val =0x00;

    if ( uart::stopBit::two_bit == sb)
        val = 0x01;

    tmp = readUCSRC();
    tmp &= ~(1 << 3);
    tmp |= (val << 3);
    _utS->_UBBRH_UCSRC = tmp;
}

uart::stopBit uart::getStopBit() {
    unsigned char tmp;

    tmp = readUCSRC();
    return (((tmp >> 3) & 0x01) == 0x00)? uart::stopBit::one_bit: uart::stopBit::two_bit;
}

void uart::setCharacterSize(uart::characterSize chs) {
    unsigned char tmp;
    unsigned char val1 =0x00;
    unsigned char val2 =0x00;

    switch (chs) {
        case uart::characterSize::_5_bit:
            break;
        case uart::characterSize::_6_bit:
            val1 = 0x01;
            break;
        case uart::characterSize::_7_bit:
            val1 = 0x02;
            break;
        case uart::characterSize::_8_bit:
            val1 = 0x03;
            break;
        case uart::characterSize::_9_bit:
            val1 = 0x03;
            val2 = 0x01;
            break;
    }
    tmp = readUCSRC();
    tmp &= ~(0x03 << 1);
    tmp |= (val1 << 1);
    _utS->_UBBRH_UCSRC = tmp;

    tmp = _utS->_UCSRB;
    tmp &= ~(1 << 2);
    tmp |= (val2 << 2);
    _utS->_UCSRB = tmp;
}

uart::characterSize uart::getCharacterSize() {
    unsigned char tmp;

    tmp = readUCSRC();
    tmp = ((tmp >> 1) & 0x03) | (_utS->_UCSRB & 0x04);

    switch (tmp) {
        case 0x00:
            return uart::characterSize::_5_bit;
        case 0x01:
            return uart::characterSize::_6_bit;
        case 0x02:
            return uart::characterSize::_7_bit;
        case 0x03:
            return uart::characterSize::_8_bit;
        case 0x07:
            return uart::characterSize::_9_bit;
    }
}

void uart::setClockPolarity(uart::clockPolarity cp) {
    unsigned char tmp;
    unsigned char val =0x00;

    if ( uart::clockPolarity::fallingTX_risingRX == cp)
        val = 0x01;

    tmp = readUCSRC();
    tmp &= ~(1 << 0);
    tmp |= (val << 0);
    _utS->_UBBRH_UCSRC = tmp;
}

uart::clockPolarity uart::getClockPolarity() {
    unsigned char tmp;

    tmp = readUCSRC();
    return ((tmp  & 0x01) == 0x00)? uart::clockPolarity::risingTX_fallingRX: uart::clockPolarity::fallingTX_risingRX;
}

void uart::setBaudRate(uart::baudRate val) {
    unsigned char tmp;
    unsigned char div = 2;
    unsigned long int baud = 0;
    unsigned int reg;

    if ( uart::mode::asynchronous == getMode()  )
        div = 16;

    if ( true == getDoubleTransmissionSpeed() )
        div = 8;

    switch (val) {
        case uart::baudRate::_2400:
            baud = 2400;
            _setBaud = uart::baudRate::_2400;
            break;
        case uart::baudRate::_4800:
            baud = 4800;
            _setBaud = uart::baudRate::_4800;
            break;
        case uart::baudRate::_9600:
            baud = 9600;
            _setBaud = uart::baudRate::_9600;
            break;
        case uart::baudRate::_14400:
            baud = 14400;
            _setBaud = uart::baudRate::_14400;
            break;
        case uart::baudRate::_19200:
            baud = 19200;
            _setBaud = uart::baudRate::_19200;
            break;
        case uart::baudRate::_28800:
            baud = 28800;
            _setBaud = uart::baudRate::_28800;
            break;
        case uart::baudRate::_38400:
            baud = 38400;
            _setBaud = uart::baudRate::_38400;
            break;
        case uart::baudRate::_57600:
            baud = 57600;
            _setBaud = uart::baudRate::_57600;
            break;
        case uart::baudRate::_76800:
            baud = 76800;
            _setBaud = uart::baudRate::_76800;
            break;
        case uart::baudRate::_115200:
            baud = 115200;
            _setBaud = uart::baudRate::_115200;
            break;
        case uart::baudRate::_230400:
            baud = 230400;
            _setBaud = uart::baudRate::_230400;
            break;
        case uart::baudRate::_250000:
            baud = 250000;
            _setBaud = uart::baudRate::_250000;
            break;
        case uart::baudRate::_500000:
            baud = 50000;
            _setBaud = uart::baudRate::_500000;
            break;
        case uart::baudRate::_1000000:
            baud = 1000000;
            _setBaud = uart::baudRate::_1000000;
            break;
    }

    reg = ((F_CPU)/(baud * div)) - 1;
    tmp = _utS->_UBBRH_UCSRC;
    tmp &= ~(0x0F);
    tmp |= (reg >> 8);
    _utS->_UBBRH_UCSRC = tmp;
    _utS->_UBRRL = reg & 0x00FF;
}

uart::baudRate uart::getBaudRate() {
    return _setBaud;
}

unsigned long int uart::getRealBaudRate() {
    unsigned char div = 2;
    unsigned int reg;
    unsigned long int val;

    if ( uart::mode::asynchronous == getMode()  )
        div = 16;

    if ( true == getDoubleTransmissionSpeed() )
        div = 8;

    reg = _utS->_UBBRH_UCSRC;
    reg &= 0x0F;
    reg = (reg << 8);
    reg |= (_utS->_UBRRL);

    val = ((F_CPU)/(div*(reg+1)));
    return val;
}

void uart::writeData(unsigned int val) {
    if ( uart::characterSize::_9_bit == getCharacterSize() ) {
        unsigned char tmp;
        tmp = _utS->_UCSRB;
        tmp |= ((val >> 8) & 0x01);
        _utS->_UCSRB = tmp;
    }
    _utS->_UDR = (val & 0x00FF);
}

unsigned int uart::readData() {
    unsigned int val = 0x00;

    if ( uart::characterSize::_9_bit == getCharacterSize() ) {
        val = _utS->_UCSRB;
        val = ((val & 0x02) << 7);
    }
    val |= _utS->_UDR;

    return val;
}