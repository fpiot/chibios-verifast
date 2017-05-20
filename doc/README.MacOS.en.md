# Verification of ChibiOS/RT using VeriFast (MacOS)

Let's verify sample application on [ChibiOS/RT](http://www.chibios.org/) using [VeriFast](https://people.cs.kuleuven.be/~bart.jacobs/verifast/).

## Get the devel-environment

Install brew packages:

```
$ brew tap PX4/homebrew-px4
$ brew update
$ brew install wget git gcc-arm-none-eabi cmake picocom libusb
```

Checkout [stlink](https://github.com/texane/stlink) and build/install it:

```
$ git clone https://github.com/texane/stlink.git
$ (cd stlink && make)
$ (cd stlink/build/Release && sudo make install)
```

Download [latast VeriFast](https://github.com/verifast/verifast#binaries), unzip it and set PATH:

```
$ wget http://82076e0e62875f063ae8-929808a701855dfb71539d0a4342d4be.r54.cf5.rackcdn.com/verifast-nightly-osx.tar.gz
$ tar xf verifast-nightly-osx.tar.gz
$ mv verifast-*/ verifast
$ export PATH=`pwd`/verifast/bin:$PATH
```

Checkout custom ChibiOS/RT source code:

```
$ git clone https://github.com/fpiot/chibios-verifast.git
```

## Build a ChibiOS application

Build the code:

```
$ cd chibios-verifast/verifast_demo/STM32/RT-STM32F091RC-NUCLEO
$ make
```

## Run the ChibiOS application

After connect the board to your Mac using USB cable, kick `st-util`:

```
$ st-util
```

Open another terminal, and download application into the board:

```
$ cd chibios-verifast/verifast_demo/STM32/RT-STM32F091RC-NUCLEO
$ make gdbwrite
```

Continue application from GDB prompt:

```
(gdb) c
```

Open another terminal to open serial console, and push `USER` button on the board. You will see following log on serial console:

```
$ picocom -b 9600 /dev/tty.usbmodem1423
picocom v1.7
--snip--
Terminal ready

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

Simply kick GNU make on your terminal to open VeriFast IDE:

```
$ cd chibios-verifast/verifast_demo/STM32/RT-STM32F091RC-NUCLEO
$ make vfide
```
