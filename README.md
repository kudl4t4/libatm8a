# libatm8a
Atmega8A C++ library
 <br />
TOOLCHAIN_PATH & F_CPU needs to be set. <br />
 <br />
Built on: <br />
./avr-g++ --version <br />
avr-g++ (GCC) 6.2.0 <br />
Copyright (C) 2016 Free Software Foundation, Inc. <br />
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. <br />
 <br />
Library size <br />
---------------- <br />
/home/kudl4t4/avr-toolchain/linux/bin/avr-size --totals libatm8a.0.2.3.a <br />
<table>
<tr><td>text</td><td>data</td><td>bss</td><td>dec</td><td>hex</td><td>filename</td></tr>
<tr><td>494</td><td>0</td><td>4</td><td>470</td><td>1d6</td><td>ioport.o</td></tr>
<tr><td>190</td><td>0</td><td>2</td><td>192</td><td>c0</td><td>powerManagement.o</td></tr>
<tr><td>278</td><td>0</td><td>2</td><td>280</td><td>118</td><td>eeprom.o</td></tr>
<tr><td>38</td><td>0</td><td>2</td><td>40</td><td>28</td><td>oscillator.o</td></tr>
<tr><td>682</td><td>0</td><td>2</td><td>684</td><td>2ac</td><td>adc.o</td></tr>
<tr><td>285</td><td>0</td><td>4</td><td>289</td><td>121</td><td>timer0.o</td></tr>
<tr><td>324</td><td>0</td><td>2</td><td>326</td><td>146</td><td>bootLoaderSupport.o</td></tr>
<tr><td>339</td><td>0</td><td>2</td><td>341</td><td>155</td><td>watchdog.o</td></tr>
<tr><td>1434</td><td>0</td><td>4</td><td>1438</td><td>59e</td><td>timer1.o</td></tr>
<tr><td>404</td><td>0</td><td>4</td><td>408</td><td>198</td><td>analogComparator.o</td></tr>
<tr><td>463</td><td>0</td><td>2</td><td>465</td><td>1d1</td><td>interrupts.o</td></tr>
<tr><td>1404</td><td>0</td><td>3</td><td>1407</td><td>57f</td><td>uart.o</td></tr>
<tr><td>659</td><td>0</td><td>2</td><td>661</td><td>295</td><td>twi.o</td></tr>
<tr><td>758</td><td>0</td><td>4</td><td>762</td><td>2fa</td><td>timer2.o</td></tr>
<tr><td>182</td><td>0</td><td>2</td><td>184</td><td>b8</td><td>avrStatus.o</td></tr>
<tr><td>580</td><td>0</td><td>2</td><td>582</td><td>246</td><td>spi.o</td></tr>
<tr><td>8486</td><td>0</td><td>43</td><td>8529</td><td>2151</td><td>(TOTALS)</td></tr>
</table>
