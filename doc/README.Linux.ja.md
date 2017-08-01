# ChibiOS/RTのVeriFastによる検証 (Linux版)

[ChibiOS/RT](http://www.chibios.org/)上で動作するアプリケーションを[VeriFast](https://people.cs.kuleuven.be/~bart.jacobs/verifast/)で検証します。

## 開発環境の構築

関連パッケージをインストールしてください。

```
$ sudo apt-get install wget git libgtk2.0-0 libgtksourceview2.0-0 libusb-1.0-0-dev libgtk-3-dev build-essential cmake gcc-arm-none-eabi gdb-arm-none-eabi picocom
```

[stlink](https://github.com/texane/stlink)をダウンロードしてビルドしてください。

```
$ git clone https://github.com/texane/stlink.git
$ (cd stlink && make)
$ (cd stlink/build/Release && sudo make install)
$ sudo ldconfig
```

[VeriFastの最新版をダウンロード](https://github.com/verifast/verifast#binaries)し、展開してPATHを通してください。

```
$ wget http://82076e0e62875f063ae8-929808a701855dfb71539d0a4342d4be.r54.cf5.rackcdn.com/verifast-nightly.tar.gz
$ tar xf verifast-nightly.tar.gz
$ mv verifast-*/ verifast
$ export PATH=`pwd`/verifast/bin:$PATH
```

本ソースコードをダウンロードしてください。

```
$ git clone https://github.com/fpiot/chibios-verifast.git
```

## ChibiOSアプリケーションのビルド

ソースコードをビルドしてください。

```
$ cd chibios-verifast/verifast_demo/STM32/RT-STM32F091RC-NUCLEO
$ make
```

## ChibiOSアプリケーションの実行

ボードとLinux PCをUSBケーブルで接続した後、ファームウェアを書き込みます。

```
$ cd chibios-verifast/verifast_demo/STM32/RT-STM32F091RC-NUCLEO
$ make flash
```

シリアルコンソールを開いた後、ボードの`USER`スイッチを押下してください。以下のようなログが表示されます。

```
$ picocom -b 9600 /dev/ttyACM0
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

## ChibiOSアプリケーションの検証

VeriFastでソースコードを検証するには、以下のようにしてVeriFast IDEを起動してください。

```
$ cd chibios-verifast/verifast_demo/STM32/RT-STM32F091RC-NUCLEO
$ make vfide
```
