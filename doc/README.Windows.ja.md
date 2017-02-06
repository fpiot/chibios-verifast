# ChibiOS/RTのVeriFastによる検証 (Windows版)

[ChibiOS/RT](http://www.chibios.org/)上で動作するアプリケーションを[VeriFast](https://people.cs.kuleuven.be/~bart.jacobs/verifast/)で検証します。

## 開発環境の構築

以下をインストールしてください。

* [Git](https://git-for-windows.github.io/)
* [gcc-arm-none-eabi](https://launchpad.net/gcc-arm-embedded/+download)の[最新版のGCC](https://launchpad.net/gcc-arm-embedded/5.0/5-2016-q3-update/+download/gcc-arm-none-eabi-5_4-2016q3-20160926-win32.exe)
* [TeraTerm](https://ttssh2.osdn.jp/index.html.ja)
* [cygwin](https://cygwin.com/install.html)

この時、各ツールにはPATHを通してください。また、以下のcygwinパッケージをインストールしてください。

* cmake
* libusb1.0-devel

cygwinターミナルを開き、[stlink](https://github.com/texane/stlink)をダウンロードしてビルドしてください。

```
$ git clone https://github.com/texane/stlink.git
$ (cd stlink && make)
$ (cd stlink/build/Release && make install)
```

[VeriFastの最新版をダウンロード](https://github.com/verifast/verifast#binaries)し、展開して `verifast-XXXXXXX\bin` ディレクトリにPATHを通してください。

cygwinターミナルを開き、本ソースコードをダウンロードして、ツールチェーンを設定してください。

```
$ git clone https://github.com/fpiot/chibios-verifast.git
```

## ChibiOSアプリケーションのビルド

cygwinターミナルを開き、ソースコードをビルドしてください。

```
$ cd chibios-verifast/verifast_demo/STM32/RT-STM32F091RC-NUCLEO
$ make
```

## ChibiOSアプリケーションの実行

ボードとWindows PCをUSBケーブルで接続した後、cygwinターミナルを開き、st-utilを起動して待機中にしてください。

```
$ (cd /usr/local/lib && st-util)
```

別のcygwinターミナルを開いて、gdbserver経由でファームウェアを書き込み

```
$ cd chibios-verifast/verifast_demo/STM32/RT-STM32F091RC-NUCLEO
$ make gdbwrite
```

gdbのプロンプトが出るので、実行継続してください。

```
(gdb) c
```

TeraTermを使ってボーレート38400でシリアルコンソールを開いた後、ボードの`USER`スイッチを押下してください。以下のようなログが表示されます。

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

## ChibiOSアプリケーションの検証

VeriFastでソースコードを検証するには、cygwinターミナルを開き、以下のようにしてVeriFast IDEを起動してください。

```
$ cd chibios-verifast/verifast_demo/STM32/RT-STM32F091RC-NUCLEO
$ make vfide
```
