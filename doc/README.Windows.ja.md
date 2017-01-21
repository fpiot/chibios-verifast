# ChibiOS/RTのVeriFastによる検証 (Windows版)

[ChibiOS/RT](http://www.chibios.org/)上で動作するアプリケーションを[VeriFast](https://people.cs.kuleuven.be/~bart.jacobs/verifast/)で検証します。

## 準備

以下をインストールしてください。

* [Git](https://git-for-windows.github.io/)

[gcc-arm-none-eabi](https://launchpad.net/gcc-arm-embedded/+download)から[最新版のGCC](https://launchpad.net/gcc-arm-embedded/5.0/5-2016-q3-update/+download/gcc-arm-none-eabi-5_4-2016q3-20160926-win32.exe)をダウンロードしてインストールしてください。この時ツールチェーンにPATHを通してください。

[MinGW-W64](https://mingw-w64.org/)から[mingw-w64-install.exe](https://downloads.sourceforge.net/project/mingw-w64/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe)をダウンロードし、以下の設定でインストールしてください。

* Thread: win32
* Exception: sjlj

MinGW-W64のコンソールを開いて、[stlink](https://github.com/texane/stlink)をダウンロードしてビルドしてください。

```
$ git clone https://github.com/texane/stlink.git
$ (cd stlink && make)
$ (cd stlink/build/Release && sudo make install)
$ sudo ldconfig
```

[VeriFastの最新版をダウンロード](https://github.com/verifast/verifast#binaries)し、展開して `verifast-XXXXXXX\bin` ディレクトリにPATHを通してください。

`C:\MinGW\msys\1.0\msys.bat` によって起動されるコンソールから、本ソースコードをダウンロードして、ツールチェーンを設定してください。

```
$ git clone https://github.com/fpiot/chibios-verifast.git
$ cd chibios-verifast
$ make setup
```

## 検証

VeriFastでソースコードを検証するには、以下のようにしてVeriFast IDEを起動してください。

```
$ cd chibios-verifast/verifast_demo/STM32/RT-STM32F091RC-NUCLEO
$ make vfide
```

## ビルド

ソースコードをビルドしてください。

```
$ cd chibios-verifast/verifast_demo/STM32/RT-STM32F091RC-NUCLEO
$ make
```

## 実機動作

ボードとWindows PCをUSBケーブルで接続した後、st-utilを起動して待機中にしてください。

```
xxx
```

別のコンソールを開いて、gdbserver経由でファームウェアを書き込み

```
$ cd chibios-verifast/verifast_demo/STM32/RT-STM32F091RC-NUCLEO
$ make gdbwrite
```

gdbのプロンプトが出るので、実行継続してください。

```
(gdb) c
```
