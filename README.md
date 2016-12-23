# libatm8a
Atmega8A C++ library

TOOLCHAIN_PATH & F_CPU needs to be set.
ut/gtest submodule for UTs need to be included

Built on:
./avr-g++ --version
avr-g++ (GCC) 6.2.0
Copyright (C) 2016 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

Library size\n
----------------\n
/home/kudl4t4/avr-toolchain/linux/bin/avr-size --totals libatm8a.0.1.a
   text	   data	    bss	    dec	    hex	filename
    466	      0	      4	    470	    1d6	ioport.o (ex libatm8a.0.1.a)
    190	      0	      2	    192	     c0	powerManagement.o (ex libatm8a.0.1.a)
    278	      0	      2	    280	    118	eeprom.o (ex libatm8a.0.1.a)
     38	      0	      2	     40	     28	oscillator.o (ex libatm8a.0.1.a)
    682	      0	      2	    684	    2ac	adc.o (ex libatm8a.0.1.a)
    285	      0	      4	    289	    121	timer0.o (ex libatm8a.0.1.a)
    324	      0	      2	    326	    146	bootLoaderSupport.o (ex libatm8a.0.1.a)
    339	      0	      2	    341	    155	watchdog.o (ex libatm8a.0.1.a)
   1434	      0	      4	   1438	    59e	timer1.o (ex libatm8a.0.1.a)
    404	      0	      4	    408	    198	analogComparator.o (ex libatm8a.0.1.a)
    463	      0	      2	    465	    1d1	interrupts.o (ex libatm8a.0.1.a)
   1404	      0	      3	   1407	    57f	uart.o (ex libatm8a.0.1.a)
    659	      0	      2	    661	    295	twi.o (ex libatm8a.0.1.a)
    758	      0	      4	    762	    2fa	timer2.o (ex libatm8a.0.1.a)
    182	      0	      2	    184	     b8	avrStatus.o (ex libatm8a.0.1.a)
    580	      0	      2	    582	    246	spi.o (ex libatm8a.0.1.a)
   8486	      0	     43	   8529	   2151	(TOTALS)
