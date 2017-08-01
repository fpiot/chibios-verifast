# Verification of ChibiOS/RT using VeriFast (Windows)

Let's verify sample application on [ChibiOS/RT](http://www.chibios.org/) using [VeriFast](https://people.cs.kuleuven.be/~bart.jacobs/verifast/).

## Get the devel-environment

Install following:

* [Git](https://git-for-windows.github.io/)
* [Latest GCC](https://launchpad.net/gcc-arm-embedded/5.0/5-2016-q3-update/+download/gcc-arm-none-eabi-5_4-2016q3-20160926-win32.exe) on [gcc-arm-none-eabi](https://launchpad.net/gcc-arm-embedded/+download)
* [TeraTerm](https://ttssh2.osdn.jp/index.html.ja)
* [cygwin](https://cygwin.com/install.html)
* [ST-LINK USB driver](http://www.st.com/en/embedded-software/stsw-link009.html)

Note needing to set PATH to avobe tools. And install following cygwin packages:

* cmake
* gcc-core (5.3.0)
* libusb1.0-devel
* make

Open cygwin terminal, checkout [stlink](https://github.com/texane/stlink) and build/install it:

```
$ git clone https://github.com/texane/stlink.git
$ (cd stlink && make)
$ (cd stlink/build/Release && make install)
```

Download [latest VeriFast](https://github.com/verifast/verifast#binaries), unzip it and set PATH to `verifast-XXXXXXX/bin` directory.

Open cygwin terminal, checkout custom ChibiOS/RT source code:

```
$ git clone https://github.com/fpiot/chibios-verifast.git
```

## Build a ChibiOS application

Open cygwin terminal, and build the code:

```
$ cd chibios-verifast/verifast_demo/STM32/RT-STM32F091RC-NUCLEO
$ make
```

## Run the ChibiOS application

After connect the board to your PC using USB cable, dowload application into the board:

```
$ cd chibios-verifast/verifast_demo/STM32/RT-STM32F091RC-NUCLEO
$ make flash
```

Open serial console "STMicroelectronics STLink Virtual COM Port" using TeraTerm with baud rate 9600, and push `USER` button on the board. You will see following log on serial console:

```
*** ChibiOS/RT test suite
***
*** Kernel:       3.1.5
*** Compiled:     Jan 15 2017 - 20:38:01
*** Compiler:     GCC 4.8.4 20140725 (release) [ARM/embedded-4_8-branch revision 213147]
*** Architecture: ARMv6-M
*** Core Variant: Cortex-M0
*** Port Info:    Preemption through NMI
*** Platform:     STM32F091xC Entry Level Access Line devices
*** Test Board:   STMicroelectronics NUCLEO-F091RC
--snip--
```

## Verify the ChibiOS application

Simply kick GNU make on cygwin terminal to open VeriFast IDE:

```
$ cd chibios-verifast/verifast_demo/STM32/RT-STM32F091RC-NUCLEO
$ make vfide
```
