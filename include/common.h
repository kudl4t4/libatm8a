/** @file common.h
 *  @brief Structures for atmega8a registers.
 *
 *  This contains the structures for the atmega8a
 *  registers and defines its beginning addresses.
 *  When there is a gab between registers, align
 *  table was set.
 *
 */

#ifndef ATMEGA8A_COMMON_H
#define ATMEGA8A_COMMON_H

/**
 * @struct adc_Struct
 * @brief Structure for the AVR Analog to Digital Converter Registers.
 *
 * An analog-to-digital converter (ADC, A/D, A–D, or A-to-D)
 * is a system that converts an analog signal, into a digital signal.
 */
/**
 * @var adc_Struct::_ADCL
 * ADC Data Register Low
 * \n\b Offset:  0x04
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x24
 * <table>
 *  <tr><th colspan="8">ADLAR=0</th></tr>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>ADC7</td>
 *      <td>ADC6</td>
 *      <td>ADC5</td>
 *      <td>ADC4</td>
 *      <td>ADC3</td>
 *      <td>ADC2</td>
 *      <td>ADC1</td>
 *      <td>ADC0</td>
 *  </tr>
 *  <tr><th colspan="8">ADLAR=1</th></tr>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>ADC1</td>
 *      <td>ADC0</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *  </tr>
 * </table>
 * \b ADCn:  ADC Conversion Result
 */
/**
 * @var adc_Struct::_ADCH
 * ADC Data Register High
 * \n\b Offset:  0x05
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x25
 * <table>
 *  <tr><th colspan="8">ADLAR=0</th></tr>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>ADC9</td>
 *      <td>ADC8</td>
 *  </tr>
 *  <tr><th colspan="8">ADLAR=1</th></tr>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>ADC7</td>
 *      <td>ADC6</td>
 *      <td>ADC5</td>
 *      <td>ADC4</td>
 *      <td>ADC3</td>
 *      <td>ADC2</td>
 *      <td>ADC1</td>
 *      <td>ADC0</td>
 *  </tr>
 * </table>
 * \b ADCn:  ADC Conversion Result
 */
/**
 * @var adc_Struct::_ADCSRA
 * ADC Control and Status Register A
 * \n\b Offset:  0x06
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x26
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>ADEN</td>
 *      <td>ADSC</td>
 *      <td>ADFR</td>
 *      <td>ADIF</td>
 *      <td>ADIE</td>
 *      <td>ADPS2</td>
 *      <td>ADPS1</td>
 *      <td>ADPS0</td>
 *  </tr>
 * </table>
 * \b ADEN: ADC Enable
 * \n\b ADSC: ADC Start Conversion
 * \n\b ADFR: ADC Free Running Select
 * \n\b ADIF: ADC Interrupt Flag
 * \n\b ADIE: ADC Interrupt Enable
 * \n\b ADPSn:  ADC Prescaler Select
 */
/**
 * @var adc_Struct::_ADMUX
 * ADC Multiplexer Selection Register
 * \n\b Offset:  0x07
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x27
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>REFS1</td>
 *      <td>REFS0</td>
 *      <td>ADLAR</td>
 *      <td>----</td>
 *      <td>MUX3</td>
 *      <td>MUX2</td>
 *      <td>MUX1</td>
 *      <td>MUX0</td>
 *  </tr>
 * </table>
 * \b REFSn: Reference Selection
 * \n\b ADLAR: ADC Left Adjust Result
 * \n\b MUXn: Analog Channel Selection
 */
typedef struct {
    unsigned char _ADCL;
    unsigned char _ADCH;
    unsigned char _ADCSRA;
    unsigned char _ADMUX;
} __attribute__((packed)) adc_Struct;

/**
 * @struct avrStatus_Struct
 * @brief Structure for the AVR Status Register Register.
 *
 * The Status Register contains information about the
 * result of the most recently executed arithmetic
 * instruction.
 */
/**
 * @var avrStatus_Struct::_SREG
 * The AVR Status Register
 * \n\b Offset:  0x3F
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x5F
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>I</td>
 *      <td>T</td>
 *      <td>H</td>
 *      <td>S</td>
 *      <td>V</td>
 *      <td>N</td>
 *      <td>Z</td>
 *      <td>C</td>
 *  </tr>
 * </table>
 * \b I: Global Interrupt Enable
 * \n\b T: Bit Copy Storage
 * \n\b H: Half Carry Flag
 * \n\b S: Sign Bit, S = N ⊕ V
 * \n\b V: Two’s Complement Overflow Flag
 * \n\b N: Negative Flag
 * \n\b Z: Zero Flag
 * \n\b C: Carry Flag
 */
typedef struct {
    unsigned char _SREG;
} __attribute__((packed)) avrStatus_Struct;

/**
 * @struct analogComparator_Struct
 * @brief Structure for the AVR Analog Comparator Register.
 *
 * Analog Comparator (AC) is a module that compares
 * two analog input voltages and outputs a signal level
 * indicating which of the inputs is greater or lesser.
 */
/**
 * @var analogComparator_Struct::_ACSR
 * Analog Comparator Control and Status Register
 * \n\b Offset:  0x08
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x28
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>ACD</td>
 *      <td>ACBG</td>
 *      <td>ACO</td>
 *      <td>ACI</td>
 *      <td>ACIE</td>
 *      <td>ACIC</td>
 *      <td>ACIS1</td>
 *      <td>ACIS0</td>
 *  </tr>
 * </table>
 * \b ACD: Analog Comparator Disable
 * \n\b ACBG: Analog Comparator Bandgap Select
 * \n\b ACO: Analog Comparator Output
 * \n\b ACI: Analog Comparator Interrupt Flag
 * \n\b ACIE: Analog Comparator Interrupt Enable
 * \n\b ACIC: Analog Comparator Input Capture Enable
 * \n\b ACISn: Analog Comparator Interrupt Mode Select
 */
typedef struct {
    unsigned char _ACSR;
} __attribute__((packed)) analogComparator_Struct;

/**
 * @struct bootLoaderSupport_Struct
 * @brief Structure for the AVR Boot Loader Support Register
 * – Read-While-Write Self-Programming.
 *
 * Analog Comparator (AC) is a module that compares
 * two analog input voltages and outputs a signal level
 * indicating which of the inputs is greater or lesser.
 */
/**
 * @var bootLoaderSupport_Struct::_SPMCR
 * Store Program Memory Control Register
 * \n\b Offset:  0x37
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x57
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>SPMIE</td>
 *      <td>RWWSB</td>
 *      <td>----</td>
 *      <td>RWWSRE</td>
 *      <td>BLBSET</td>
 *      <td>PGWRT</td>
 *      <td>PGERS</td>
 *      <td>SPMEN</td>
 *  </tr>
 * </table>
 * \b SPMIE: SPM Interrupt Enable
 * \n\b RWWSB: Read-While-Write Section Busy
 * \n\b RWWSRE: Read-While-Write Section Read Enable
 * \n\b BLBSET: Boot Lock Bit Set
 * \n\b PGWRT: Page Write
 * \n\b PGERS: Page Erase
 * \n\b SPMEN: Store Program Memory
 */
typedef struct {
    unsigned char _SPMCR;
} __attribute__((packed)) bootLoaderSupport_Struct;

/**
 * @struct eeprom_Struct
 * @brief Structure for the AVR EEPROM Data Memory Registers.
 *
 * EEPROM stands for electrically erasable programmable read-only
 * memory and is a type of non-volatile  memory used in computers
 * and other electronic devices to store relatively small amounts
 * of data but allowing individual bytes to be erased and reprogrammed.
 */
/**
 * @var eeprom_Struct::_EECR
 * The EEPROM Control Register
 * \n\b Offset:  0x1C
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x3C
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>EERIE</td>
 *      <td>EEMWE</td>
 *      <td>EEWE</td>
 *      <td>EERE</td>
 *  </tr>
 * </table>
 * \b EERIE: EEPROM Ready Interrupt Enable
 * \n\b EEMWE: EEPROM Master Write Enable
 * \n\b EEWE: EEPROM Write Enable
 * \n\b EERE: EEPROM Read Enable
 */
/**
 * @var eeprom_Struct::_EEDR
 * The EEPROM Data Register
 * \n\b Offset:  0x1D
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x3D
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>EEDR7</td>
 *      <td>EEDR6</td>
 *      <td>EEDR5</td>
 *      <td>EEDR4</td>
 *      <td>EEDR3</td>
 *      <td>EEDR2</td>
 *      <td>EEDR1</td>
 *      <td>EEDR0</td>
 *  </tr>
 * </table>
 * \b EEDRn: EEPROM Data
 */
/**
 * @var eeprom_Struct::_EEARL
 * The EEPROM Address Register Low
 * \n\b Offset:  0x1E
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x3E
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>EEAR7</td>
 *      <td>EEAR6</td>
 *      <td>EEAR5</td>
 *      <td>EEAR4</td>
 *      <td>EEAR3</td>
 *      <td>EEAR2</td>
 *      <td>EEAR1</td>
 *      <td>EEAR0</td>
 *  </tr>
 * </table>
 * \b EEARn: EEPROM Address
 */
/**
 * @var eeprom_Struct::_EEARH
 * The EEPROM Address Register High
 * \n\b Offset:  0x1F
 * \n\b Reset:  0x0X
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x3F
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>EEAR8</td>
 *  </tr>
 * </table>
 * \b EEARn: EEPROM Address
 */
typedef struct {
    unsigned char _EECR;
    unsigned char _EEDR;
    unsigned char _EEARL;
    unsigned char _EEARH;
} __attribute__((packed)) eeprom_Struct;

/**
 * @struct interrupts_Struct
 * @brief Structure for the AVR the Interrupt handling Registers.
 *
 * In computer systems programming, an interrupt handler, also
 * known as an interrupt service routine or ISR, is a callback
 * function in microcontroller firmware, an operating system,
 * or a device driver whose execution is triggered by the reception
 * of an interrupt. In general, interrupts and their handlers
 * are used to handle high-priority conditions that require the
 * interruption of the current code the processor is executing.
 */
/**
 * @var interrupts_Struct::_MCUCR
 * MCU Control Register
 * \n\b Offset:  0x35
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x55
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>ISC11</td>
 *      <td>ISC10</td>
 *      <td>ISC01</td>
 *      <td>ISC00</td>
 *  </tr>
 * </table>
 * \b ISC1n: Interrupt Sense Control 1 Bit 1 and Bit 0
 * \n\b ISC0n: Interrupt Sense Control 0 Bit 1 and Bit 0
 */
/**
 * @var interrupts_Struct::_GIFR
 * General Interrupt Control Register
 * \n\b Offset:  0x3A
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x5A
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>INT1</td>
 *      <td>INT0</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *  </tr>
 * </table>
 * \b INT1: External Interrupt Request 1 Enable
 * \n\b INT0: External Interrupt Request 0 Enable
 */
/**
 * @var interrupts_Struct::_GICR
 * General Interrupt Control Register
 * \n\b Offset:  0x3B
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x5B
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>IVSEL</td>
 *      <td>IVCE</td>
 *  </tr>
 * </table>
 * \b  IVSEL: Interrupt Vector Select
 * \n\b IVCE: Interrupt Vector Change Enable
 */
typedef struct {
    unsigned char _MCUCR;
    unsigned char _align[4];
    unsigned char _GIFR;
    unsigned char _GICR;
} __attribute__((packed)) interrupts_Struct;

/**
 * @struct ioport_Struct
 * @brief Structure for the I/O Ports Registers
 *
 * An I/O port is usually used as a technical term for a specific address
 */
/**
 * @var ioport_Struct::_PINx
 * The Port X Input Pins Address
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>PINx7</td>
 *      <td>PINx6</td>
 *      <td>PINx5</td>
 *      <td>PINx4</td>
 *      <td>PINx3</td>
 *      <td>PINx2</td>
 *      <td>PINx1</td>
 *      <td>PINx0</td>
 *  </tr>
 * </table>
 * \b PINXn: Port X Input Pins Address
 */
/**
 * @var ioport_Struct::_DDRx
 * The Port X Data Direction Register
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>DDRx7</td>
 *      <td>DDRx6</td>
 *      <td>DDRx5</td>
 *      <td>DDRx4</td>
 *      <td>DDRx3</td>
 *      <td>DDRx2</td>
 *      <td>DDRx1</td>
 *      <td>DDRx0</td>
 *  </tr>
 * </table>
 * \b DDXn: Port X Data Direction
 */
/**
 * @var ioport_Struct::_PORTx
 * The Port X Data Register
 *  <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>PORTx7</td>
 *      <td>PORTx6</td>
 *      <td>PORTx5</td>
 *      <td>PORTx4</td>
 *      <td>PORTx3</td>
 *      <td>PORTx2</td>
 *      <td>PORTx1</td>
 *      <td>PORTx0</td>
 *  </tr>
 * </table>
 * \b PORTXn: Port X Data
 */
typedef struct {
    unsigned char _PINx;
    unsigned char _DDRx;
    unsigned char _PORTx;
} __attribute__((packed)) ioport_Struct;

/**
 * @struct oscillator_Struct
 * @brief Structure for System Clock and Clock Options Registers
 *
 * A crystal oscillator is an electronic oscillator circuit that uses the mechanical resonance
 * of a vibrating crystal of piezoelectric material to create an electrical signal with a precise
 * frequency.
 * This frequency is commonly used to keep track of time, as in quartz wristwatches, to provide
 * a stable clock signal for digital integrated circuits, and to stabilize frequencies for radio
 * transmitters and receivers. The most common type of piezoelectric resonator used is the quartz
 * crystal, so oscillator circuits incorporating them became known as crystal oscillators,
 * but other piezoelectric materials including polycrystalline ceramics are used in similar circuits.
 */
/**
 * @var oscillator_Struct::_OSCCAL
 * The Oscillator Calibration Register
 * \n\b Offset:  0x31
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x51
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>CAL7</td>
 *      <td>CAL6</td>
 *      <td>CAL5</td>
 *      <td>CAL4</td>
 *      <td>CAL3</td>
 *      <td>CAL2</td>
 *      <td>CAL1</td>
 *      <td>CAL0</td>
 *  </tr>
 * </table>
 * \b CALn: Oscillator Calibration Value
 */
typedef struct {
    unsigned char _OSCCAL;
} __attribute__((packed)) oscillator_Struct;

/**
 * @struct powerManagement_Struct
 * @brief Structure for Power Management and Sleep Modes Registers
 */
/**
 * @var powerManagement_Struct::_MCUCR
 * MCU Control Register
 * \n\b Offset:  0x35
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x55
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>SE</td>
 *      <td>SM2</td>
 *      <td>SM1</td>
 *      <td>SM0</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *  </tr>
 * </table>
 * \b SE: Sleep Enable
 * \n\b SMn: Sleep Mode n Select Bits
 */
typedef struct {
    unsigned char _MCUCR;
} __attribute__((packed)) powerManagement_Struct;

/**
 * @struct spi_Struct
 * @brief Structure for Serial Peripheral Interface Registers
 *
 * The Serial Peripheral Interface (SPI) bus is a synchronous serial communication
 * interface specification used for short distance communication, primarily in embedded systems.
 * The interface was developed by Motorola in the late eighties and has become a de facto standard.
 * Typical applications include Secure Digital cards and liquid crystal displays.
 * SPI devices communicate in full duplex mode using a master-slave architecture with a single
 * master. The master device originates the frame for reading and writing. Multiple slave
 * devices are supported through selection with individual slave select (SS) lines.
 */
/**
 * @var spi_Struct::_SPCR
 * SPI Control Register
 * \n\b Offset:  0x0D
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x2D
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>SPIE</td>
 *      <td>SPE</td>
 *      <td>DORD</td>
 *      <td>MSTR</td>
 *      <td>CPOL</td>
 *      <td>CPHA</td>
 *      <td>SPR1</td>
 *      <td>SPR0</td>
 *  </tr>
 * </table>
 * \b SPIE: SPI Interrupt Enable
 * \n\b SPE: SPI Enable
 * \n\b DORD: Data Order
 * \n\b MSTR: Master/Slave Select
 * \n\b CPOL: Clock Polarity
 * \n\b CPHA: Clock Phase
 * \n\b SPRn: SPI Clock Rate Select
 */
/**
 * @var spi_Struct::_SPSR
 * SPI Status Register
 * \n\b Offset:  0x0E
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x2E
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>SPIF</td>
 *      <td>WCOL</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>SPR0</td>
 *  </tr>
 * </table>
 * \b SPIF: SPI Interrupt Flag
 * \n\b WCOL: Write Collision Flag
 * \n\b SPI2X: Double SPI Speed Bit
 */
/**
 * @var spi_Struct::_SPDR
 * SPI Data Register is a read/write register
 * \n\b Offset:  0x0F
 * \n\b Reset:  0xXX
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x2F
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>SPID7</td>
 *      <td>SPID6</td>
 *      <td>SPID5</td>
 *      <td>SPID4</td>
 *      <td>SPID3</td>
 *      <td>SPID2</td>
 *      <td>SPID1</td>
 *      <td>SPID0</td>
 *  </tr>
 * </table>
 * \b SPIDn: SPI Data (SPID7 = MSB, SPID0 = LSB)
 */
typedef struct {
    unsigned char _SPCR;
    unsigned char _SPSR;
    unsigned char _SPDR;
} __attribute__((packed)) spi_Struct;

/**
 * @struct timer0_Struct
 * @brief Structure for 8-bit Timer/Counter0 Registers
 *
 * Features
 * \n• Single Channel Counter
 * \n• Frequency Generator
 * \n• External Event Counter
 * \n• 10-bit Clock Prescaler
 */
/**
 * @var timer0_Struct::_TCNT0
 * Timer/Counter Register
 * \n\b Offset:  0x32
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x52
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td colspan="8">TCNT0</td>
 *  </tr>
 * </table>
 * \b TCNT0
 */
/**
 * @var timer0_Struct::_TCCR0
 * Timer/Counter Control Register
 * \n\b Offset:  0x33
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x53
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>CS02</td>
 *      <td>CS01</td>
 *      <td>CS00</td>
 *  </tr>
 * </table>
 * \b CS0n: Clock Select
 */
typedef struct {
    unsigned char _TCNT0;
    unsigned char _TCCR0;
} __attribute__((packed)) timer0_Struct;

/**
 * @struct timer1_Struct
 * @brief Structure for 16-bit Timer/Counter1 Registers
 *
 * Features
 * \n• True 16-bit Design (i.e., allows 16-bit PWM)
 * \n• Two independent Output Compare Units
 * \n• Double Buffered Output Compare Registers
 * \n• One Input Capture Unit
 * \n• Input Capture Noise Canceler
 * \n• Clear Timer on Compare Match (Auto Reload)
 * \n• Glitch-free, Phase Correct Pulse Width Modulator (PWM)
 * \n• Variable PWM Period
 * \n• Frequency Generator
 * \n• External Event Counter
 * \n• Four independent interrupt Sources (TOV1, OCF1A, OCF1B, and ICF1)

 */
/**
 * @var timer1_Struct::_ICR1L
 * Input Capture Register 1 Low byte
 * \n\b Offset:  0x26
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x46
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td  colspan="8">ICR1L</td>
 *  </tr>
 * </table>
 * \b ICR1L[7:0]: Input Capture 1 Low byte
 */
/**
 * @var timer1_Struct::_ICR1H
 * Input Capture Register 1 High byte
 * \n\b Offset:  0x27
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x47
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td  colspan="8">ICR1H</td>
 *  </tr>
 * </table>
 * \b ICR1H[7:0]: Input Capture 1 High byte
 */
/**
 * @var timer1_Struct::_OCR1BL
 * OCR1BL – Output Compare Register 1 B Low byte
 * \n\b Offset:  0x28
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x48
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td  colspan="8">OCR1BL</td>
 *  </tr>
 * </table>
 * \b OCR1BL[7:0]: Output Compare 1 B Low byte
 */
/**
 * @var timer1_Struct::_OCR1BH
 * Output Compare Register 1 B High byte
 * \n\b Offset:  0x29
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x49
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td  colspan="8">OCR1BH</td>
 *  </tr>
 * </table>
 * \b OCR1BH[7:0]: Output Compare 1 B High byte
 */
/**
 * @var timer1_Struct::_OCR1AL
 * Output Compare Register 1 A Low byte
 * \n\b Offset:  0x2A
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x4A
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td  colspan="8">OCR1AL</td>
 *  </tr>
 * </table>
 * \b OCR1AL[7:0]: Output Compare 1 A Low byte
 */
/**
 * @var timer1_Struct::_OCR1AH
 * Output Compare Register 1 A High byte
 * \n\b Offset:  0x2B
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x4B
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td  colspan="8">OCR1AH</td>
 *  </tr>
 * </table>
 * \b OCR1AH[7:0]: Output Compare 1 A High byte
 */
/**
 * @var timer1_Struct::_TCNT1L
 * Timer/Counter1 Low byte
 * \n\b Offset:  0x2C
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x4C
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td  colspan="8">TCNT1L</td>
 *  </tr>
 * </table>
 * \b TCNT1L[7:0]: Timer/Counter 1 Low byte
 */
/**
 * @var timer1_Struct::_TCNT1H
 * Timer/Counter1 High byte
 * \n\b Offset:  0x2D
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x4D
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td colspan="8">TCNT1H</td>
 *  </tr>
 * </table>
 * \b TCNT1H[7:0]: Timer/Counter 1 High byte
 */
/**
 * @var timer1_Struct::_TCCR1B
 * Timer/Counter1 Control Register B
 * \n\b Offset:  0x2E
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x4E
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>ICNC1</td>
 *      <td>ICES1</td>
 *      <td>----</td>
 *      <td>WGM13</td>
 *      <td>WGM12</td>
 *      <td>CS12</td>
 *      <td>CS11</td>
 *      <td>CS10</td>
 *  </tr>
 * </table>
 * \b ICNC1: Input Capture Noise Canceler
 * \n\b ICES1: Input Capture Edge Select
 * \n\b WGM1n: Waveform Generation Mode
 * \n\b CS1n: Clock Select
 */
/**
 * @var timer1_Struct::_TCCR1A
 * Timer/Counter1 Control Register A
 * \n\b Offset:  0x2F
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x4F
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>COM1A1</td>
 *      <td>COM1A0</td>
 *      <td>COM1B1</td>
 *      <td>COM1B0</td>
 *      <td>FOC1A</td>
 *      <td>FOC1B</td>
 *      <td>WGM11</td>
 *      <td>WGM10</td>
 *  </tr>
 * </table>
 * \b COM1An: Compare Output Mode for Channel A
 * \n\b COM1Bn: Compare Output Mode for Channel B
 * \n\b FOC1A: Force Output Compare for channel A
 * \n\b FOC1B: Force Output Compare for channel B
 * \n\b WGM1n: Waveform Generation Mode
 */
typedef struct {
    unsigned char _ICR1L;
    unsigned char _ICR1H;
    unsigned char _OCR1BL;
    unsigned char _OCR1BH;
    unsigned char _OCR1AL;
    unsigned char _OCR1AH;
    unsigned char _TCNT1L;
    unsigned char _TCNT1H;
    unsigned char _TCCR1B;
    unsigned char _TCCR1A;
} __attribute__((packed)) timer1_Struct;

/**
 * @struct timer2_Struct
 * @brief Structure for 8-bit Timer/Counter2 with PWM and Asynchronous Operation Registers
 *
 * Features
 * \n• Single Channel Counter
 * \n• Clear Timer on Compare Match (Auto Reload)
 * \n• Glitch-free, phase Correct Pulse Width Modulator (PWM)
 * \n• Frequency Generator
 * \n• 10-bit Clock Prescaler
 * \n• Overflow and Compare Match Interrupt Sources (TOV2 and OCF2)
 * \n• Allows Clocking from External 32kHz Watch Crystal Independent of the I/O Clock

 */
/**
 * @var timer1_Struct::_ASSR
 * Asynchronous Status Register
 * \n\b Offset:  0x22
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x42
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>AS2</td>
 *      <td>TCN2UB</td>
 *      <td>OCR2UB</td>
 *      <td>TCR2UB</td>
 *  </tr>
 * </table>
 * \b AS2: Asynchronous Timer/Counter2
 * \n\b TCN2UB: Timer/Counter2 Update Busy
 * \n\b OCR2UB: Output Compare Register2 Update Busy
 * \n\b TCR2UB: Timer/Counter Control Register2 Update Busy
 */
/**
 * @var timer1_Struct::_OCR2
 * Output Compare Register
 * \n\b Offset:  0x23
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x43
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td colspan="8">OCR2</td>
 *  </tr>
 * </table>
 * \b OCR2[7:0]
 */
/**
 * @var timer1_Struct::_TCNT2
 * Timer/Counter Register
 * \n\b Offset:  0x24
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x44
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td colspan="8">TCNT2</td>
 *  </tr>
 * </table>
 * \b TCNT2[7:0]
 */
/**
 * @var timer1_Struct::_TCCR2
 * Timer/Counter Control Register
 * \n\b Offset:  0x25
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x45
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>FOC2</td>
 *      <td>WGM20</td>
 *      <td>COM21</td>
 *      <td>COM20</td>
 *      <td>WGM21</td>
 *      <td>CS22</td>
 *      <td>CS21</td>
 *      <td>CS20</td>
 *  </tr>
 * </table>
 * \b FOC2: Force Output Compare
 * \n\b WGM20: Waveform Generation Mode
 * \n\b COM2n: Compare Match Output Mode
 * \n\b WGM21: Waveform Generation Mode
 * \n\b CS2n: Clock Select
 */
typedef struct {
    unsigned char _ASSR;
    unsigned char _OCR2;
    unsigned char _TCNT2;
    unsigned char _TCCR2;
} __attribute__((packed)) timer2_Struct;

/**
 * @struct twi_Struct
 * @brief Structure for Two-wire Serial Interface Registers
 *
 * Two-wire Serial Interface is a multi-master, multi-slave, single-ended, serial computer bus.
 * It is typically used for attaching lower-speed peripheral ICs to processors
 * and microcontrollers in short-distance, intra-board communication.
 */
/**
 * @var twi_Struct::_TWBR
 * TWI Bit Rate Register
 * \n\b Offset:  0x00
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x20
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>TWBR7</td>
 *      <td>TWBR6</td>
 *      <td>TWBR5</td>
 *      <td>TWBR4</td>
 *      <td>TWBR3</td>
 *      <td>TWBR2</td>
 *      <td>TWBR1</td>
 *      <td>TWBR0</td>
 *  </tr>
 * </table>
 * \b TWBRn: TWI Bit Rate Register
 */
/**
 * @var twi_Struct::_TWSR
 * TWI Status Register
 * \n\b Offset:  0x01
 * \n\b Reset:  0xF8
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x21
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>TWS4</td>
 *      <td>TWS3</td>
 *      <td>TWS2</td>
 *      <td>TWS1</td>
 *      <td>TWS0</td>
 *      <td>----</td>
 *      <td>TWPS1</td>
 *      <td>TWPS0</td>
 *  </tr>
 * </table>
 * \b TWSn: TWI Status Bit 7
 * \n\b TWPSn: TWI Prescaler
 */
/**
 * @var twi_Struct::_TWAR
 * TWI (Slave) Address Register
 * \n\b Offset:  0x02
 * \n\b Reset:  0x7F
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x22
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>TWA6</td>
 *      <td>TWA5</td>
 *      <td>TWA4</td>
 *      <td>TWA3</td>
 *      <td>TWA2</td>
 *      <td>TWA1</td>
 *      <td>TWA0</td>
 *      <td>TWGCE</td>
 *  </tr>
 * </table>
 * \b TWAn: TWI (Slave) Address
 * \n\b TWGCE: TWI General Call Recognition Enable Bit
 */
/**
 * @var twi_Struct::_TWDR
 * TWI Data Register
 * \n\b Offset:  0x03
 * \n\b Reset:  0xFF
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x23
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>TWD7</td>
 *      <td>TWD6</td>
 *      <td>TWD5</td>
 *      <td>TWD4</td>
 *      <td>TWD3</td>
 *      <td>TWD2</td>
 *      <td>TWD1</td>
 *      <td>TWD0</td>
 *  </tr>
 * </table>
 * \b TWDn: TWI Data
 */
/**
 * @var twi_Struct::_TWCR
 * TWI Control Register
 * \n\b Offset:  0x36
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x56
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>TWINT</td>
 *      <td>TWEA</td>
 *      <td>TWSTA</td>
 *      <td>TWSTO</td>
 *      <td>TWWC</td>
 *      <td>TWEN</td>
 *      <td>----</td>
 *      <td>TWIE</td>
 *  </tr>
 * </table>
 * \b TWINT: TWI Interrupt Flag
 * \n\b TWEA: TWI Enable Acknowledge
 * \n\b TWSTA: TWI START Condition
 * \n\b TWSTO: TWI STOP Condition
 * \n\b TWWC: TWI Write Collision Flag
 * \n\b TWEN: TWI Enable
 * \n\b TWIE: TWI Interrupt Enable
 */
typedef struct {
    unsigned char _TWBR;
    unsigned char _TWSR;
    unsigned char _TWAR;
    unsigned char _TWDR;
    unsigned char _align[50];
    unsigned char _TWCR;
} __attribute__((packed)) twi_Struct;

/**
 * @struct uart_Struct
 * @brief Structure for Universal Synchronous and Asynchronous serial Receiver and Transmitter Registers
 *
 * A Universal Synchronous/Asynchronous Receiver/Transmitter (USART) is a type of a serial interface
 * device that can be programmed to communicate asynchronously or synchronously. See Universal asynchronous
 * receiver/transmitter (UART) for a discussion of the asynchronous capabilities of these devices.
 */
/**
 * @var uart_Struct::_UBRRL
 * USART Baud Rate Register Low
 * \n\b Offset:  0x09
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x29
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td colspan="8">UBBR</td>
 *  </tr>
 * </table>
 * \b UBBR[7:0]: USART Baud Rate Register
 */
/**
 * @var uart_Struct::_UCSRB
 * USART Control and Status Register B
 * \n\b Offset:  0x0A
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x2A
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>RXCIE</td>
 *      <td>TXCIE</td>
 *      <td>UDRIE</td>
 *      <td>RXEN</td>
 *      <td>TXEN</td>
 *      <td>UCSZ2</td>
 *      <td>RXB8</td>
 *      <td>TXB8</td>
 *  </tr>
 * </table>
 * \b RXCIE: RX Complete Interrupt Enable
 * \n\b TXCIE: TX Complete Interrupt Enable
 * \n\b UDRIE: USART Data Register Empty Interrupt Enable
 * \n\b RXEN: Receiver Enable
 * \n\b TXEN: Transmitter Enable
 * \n\b UCSZ2: Character Size
 * \n\b RXB8: Receive Data Bit 8
 * \n\b TXB8: Transmit Data Bit 8
 */
/**
 * @var uart_Struct::_UCSRA
 * USART Control and Status Register A
 * \n\b Offset:  0x0B
 * \n\b Reset:  0x20
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x2B
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>RXC</td>
 *      <td>TXC</td>
 *      <td>UDRE</td>
 *      <td>FE</td>
 *      <td>DOR</td>
 *      <td>PE</td>
 *      <td>U2X</td>
 *      <td>MPCM</td>
 *  </tr>
 * </table>
 * \b RXC: USART Receive Complete
 * \n\b TXC: USART Transmit Complete
 * \n\b UDRE: USART Data Register Empty
 * \n\b FE: Frame Error
 * \n\b DOR: Data OverRun
 * \n\b PE: Parity Error
 * \n\b U2X: Double the USART Transmission Speed
 * \n\b MPCM: Multi-processor Communication Mode
 */
/**
 * @var uart_Struct::_UDR
 * USART I/O Data Register
 * \n\b Offset:  0x0C
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x2C
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td colspan="8">TXB / RXB</td>
 *  </tr>
 * </table>
 * \b TXB / RXB[7:0]: USART Transmit / Receive Data Buffer
 */
/**
 * @var uart_Struct::_UBBRH_UCSRC
 * USART Baud Rate Register High / USART Control and Status Register C
 * \n\b Offset:  0x20 / 0x20
 * \n\b Reset:  0x00 / 0x06
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x40 / 0x40
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>URSEL</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td colspan="4">UBRR</td>
 *  </tr>
 *  <tr>
 *      <td>URSEL</td>
 *      <td>UMSEL</td>
 *      <td>UPM1</td>
 *      <td>UPM0</td>
 *      <td>USBS</td>
 *      <td>UCSZ1</td>
 *      <td>UCSZ0</td>
 *      <td>UCPOL</td>
 *  </tr>
 * </table>
 * \b URSEL: Register Select
 * \n\b UBRR[3:0]: USART Baud Rate Register
 * \n
 * \n\b URSEL: Register Select
 * \n\b UMSEL: Mode Select
 * \n\b UPMn: Parity Mode
 * \n\b USBS: Stop Bit Select
 * \n\b UCSZn: Character Size
 * \n\b UCPOL: Clock Polarity
 */
typedef struct {
    unsigned char _UBRRL;
    unsigned char _UCSRB;
    unsigned char _UCSRA;
    unsigned char _UDR;
    unsigned char _align[19];
    unsigned char _UBBRH_UCSRC;
} __attribute__((packed)) uart_Struct;

/**
 * @struct watchdog_Struct
 * @brief Structure for System Control and Reset Registers
 *
 * A watchdog timer (sometimes called a computer operating properly or COP timer, or simply a watchdog)
 * is an electronic timer that is used to detect and recover from computer malfunctions. During normal operation,
 * the computer regularly resets the watchdog timer to prevent it from elapsing, or "timing out".
 * If, due to a hardware fault or program error, the computer fails to reset the watchdog, the timer will elapse
 * and generate a timeout signal. The timeout signal is used to initiate corrective action or actions.
 */
/**
 * @var watchdog_Struct::_WDTCR
 * Watchdog Timer Control Register
 * \n\b Offset:  0x21
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x41
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>WDCE</td>
 *      <td>WDE</td>
 *      <td>WDP2</td>
 *      <td>WDP1</td>
 *      <td>WDP0</td>
 *  </tr>
 * </table>
 * \b WDCE: Watchdog Change Enable
 * \n\b WDE: Watchdog Enable
 * \n\b WDPn: Watchdog Timer Prescaler 2, 1, and 0
 */
/**
 * @var watchdog_Struct::_MCUCSR
 * MCU Control and Status Register
 * \n\b Offset:  0x34
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x54
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>WDRF</td>
 *      <td>BORF</td>
 *      <td>EXTRF</td>
 *      <td>PORF</td>
 *  </tr>
 * </table>
 * \b WDRF: Watchdog Reset Flag
 * \n\b BORF: Brown-out Reset Flag
 * \n\b EXTRF: External Reset Flag
 * \n\b PORF: Power-on Reset Flag
 */
typedef struct {
    unsigned char _WDTCR;
    unsigned char _align[18];
    unsigned char _MCUCSR;
} __attribute__((packed)) watchdog_Struct;

/**
 * @struct combined_Struct
 * @brief Structure for some common to a few peripherals registers
 *
 * Common to:
 * \n• timer0-2
 * \n• ioports
 * \n• analog comparator
 */
/**
 * @var combined_Struct::_SFIOR
 * Special Function IO Register
 * \n\b Offset:  0x30
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x50
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>----</td>
 *      <td>ACME</td>
 *      <td>PUD</td>
 *      <td>PSR2</td>
 *      <td>PSR10</td>
 *  </tr>
 * </table>
 * \b ACME: Analog Comparator Multiplexer Enable
 * \n\b PUD: Pull-up Disable
 * \n\b PSR2: Prescaler Reset Timer/Counter2
 * \n\b PSR10: Prescaler Reset Timer/Counter1 and Timer/Counter0
 */
/**
 * @var combined_Struct::_TIFR
 * Timer/Counter Interrupt Flag Register
 * \n\b Offset:  0x38
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x58
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>OCF2</td>
 *      <td>TOV2</td>
 *      <td>ICF1</td>
 *      <td>OCF1A</td>
 *      <td>OCF1B</td>
 *      <td>TOV1</td>
 *      <td>----</td>
 *      <td>TOV0</td>
 *  </tr>
 * </table>
 * \b OCF2: Output Compare Flag 2
 * \n\b TOV2: Timer/Counter2 Overflow Flag
 * \n\b ICF1: Timer/Counter1, Input Capture Flag
 * \n\b OCF1A: Timer/Counter1, Output Compare A Match Flag
 * \n\b OCF1B: Timer/Counter1, Output Compare B Match Flag
 * \n\b TOV1: Timer/Counter1, Overflow Flag
 * \n\b TOV0: Timer/Counter0 Overflow Flag
 */
/**
 * @var combined_Struct::_TIMSK
 * Timer/Counter Interrupt Mask Register
 * \n\b Offset:  0x39
 * \n\b Reset:  0x00
 * \n\b Property: When addressing I/O Registers as data space the offset address is 0x59
 * <table>
 *  <tr>
 *      <th>Bit 7</th>
 *      <th>Bit 6</th>
 *      <th>Bit 5</th>
 *      <th>Bit 4</th>
 *      <th>Bit 3</th>
 *      <th>Bit 2</th>
 *      <th>Bit 1</th>
 *      <th>Bit 0</th>
 *  </tr>
 *  <tr>
 *      <td>OCIE2</td>
 *      <td>TOIE2</td>
 *      <td>TICIE1</td>
 *      <td>OCIE1A</td>
 *      <td>OCIE1B</td>
 *      <td>TOIE1</td>
 *      <td>----</td>
 *      <td>TOIE0</td>
 *  </tr>
 * </table>
 * \b OCIE2: Timer/Counter2 Output Compare Match Interrupt Enable
 * \n\b TOIE2: Timer/Counter2 Overflow Interrupt Enable
 * \n\b TICIE1: Timer/Counter1, Input Capture Interrupt Enable
 * \n\b OCIE1A: Timer/Counter1, Output Compare A Match Interrupt Enable
 * \n\b OCIE1B: Timer/Counter1, Output Compare B Match Interrupt Enable
 * \n\b TOIE1: Timer/Counter1, Overflow Interrupt Enable
 * \n\b TOIE0: Timer/Counter0 Overflow Interrupt Enable
 */
typedef struct {
    unsigned char _SFIOR;
    unsigned char _align[7];
    unsigned char _TIFR;
    unsigned char _TIMSK;
} __attribute__((packed)) combined_Struct;

/**Start address for some common to a few peripherals registers.*/
#define     _combined           (reinterpret_cast<combined_Struct volatile *>(0x50))

/**Start address for the AVR Analog to Digital Converter Registers*/
#define     _adc                (reinterpret_cast<adc_Struct volatile *>(0x24))
/**Start address for the AVR Status Register Register.*/
#define     _avrStatus          (reinterpret_cast<avrStatus_Struct volatile *>(0x5F))
/**Start address for the AVR Analog Comparator Register.*/
#define     _analogComparator   (reinterpret_cast<analogComparator_Struct volatile *>(0x28))
/**Start address for the AVR Boot Loader Support Register.*/
#define     _bootLoaderSupport  (reinterpret_cast<bootLoaderSupport_Struct volatile *>(0x57))
/**Start address for the AVR EEPROM Data Memory Registers.*/
#define     _eeprom             (reinterpret_cast<eeprom_Struct volatile *>(0x3C))
/**Start address for the AVR the Interrupt handling Registers.*/
#define     _interrupts         (reinterpret_cast<interrupts_Struct volatile *>(0x55))

/**Start address for the I/O Ports B Registers.*/
#define     _iportB             (reinterpret_cast<ioport_Struct volatile *>(0x36))
/**Start address for the I/O Ports C Registers.*/
#define     _iportC             (reinterpret_cast<ioport_Struct volatile *>(0x33))
/**Start address for the I/O Ports D Registers.*/
#define     _iportD             (reinterpret_cast<ioport_Struct volatile *>(0x30))

/**Start address for System Clock and Clock Options Registers.*/
#define     _oscillator         (reinterpret_cast<oscillator_Struct volatile *>(0x51))
/**Start address for Power Management and Sleep Modes Registers.*/
#define     _powerManagement    (reinterpret_cast<powerManagement_Struct volatile *>(0x55))
/**Start address for Serial Peripheral Interface Registers.*/
#define     _spi                (reinterpret_cast<spi_Struct volatile *>(0x2D))

/**Start address for 8-bit Timer/Counter0 Registers.*/
#define     _timer0             (reinterpret_cast<timer0_Struct volatile *>(0x52))
/**Start address for 16-bit Timer/Counter1 Registers.*/
#define     _timer1             (reinterpret_cast<timer1_Struct volatile *>(0x46))
/**Start address for 8-bit Timer/Counter2 with PWM and Asynchronous Operation Registers.*/
#define     _timer2             (reinterpret_cast<timer2_Struct volatile *>(0x42))

/**Start address for Two-wire Serial Interface Registers.*/
#define     _twi                (reinterpret_cast<twi_Struct volatile *>(0x20))
/**Start address for Universal Synchronous and Asynchronous serial Receiver and Transmitter Registers.*/
#define     _uart               (reinterpret_cast<uart_Struct volatile *>(0x29))
/**Start address for System Control and Reset Registers.*/
#define     _watchdog           (reinterpret_cast<watchdog_Struct volatile *>(0x41))

/**If F_CPU flag is not set during compilation.*/
#ifndef F_CPU
#warning "F_CPU not defined"
#define F_CPU 1000000UL
#endif

#endif //ATMEGA8A_COMMON_H
