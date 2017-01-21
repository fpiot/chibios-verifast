# ChibiOS/RTのVeriFastによる検証 (MacOS版)

[ChibiOS/RT](http://www.chibios.org/)上で動作するアプリケーションを[VeriFast](https://people.cs.kuleuven.be/~bart.jacobs/verifast/)で検証します。

## 準備

関連パッケージをインストールしてください。

```
$ brew tap PX4/homebrew-px4
$ brew update
$ brew install wget git gcc-arm-none-eabi stlink
```

[VeriFastの最新版をダウンロード](https://github.com/verifast/verifast#binaries)し、展開してPATHを通してください。

```
$ wget http://82076e0e62875f063ae8-929808a701855dfb71539d0a4342d4be.r54.cf5.rackcdn.com/verifast-nightly-osx.tar.gz
$ tar xf verifast-nightly-osx.tar.gz
$ mv verifast-*/ verifast
$ export PATH=`pwd`/verifast/bin:$PATH
```

本ソースコードをダウンロードしてください。

```
$ git clone https://github.com/fpiot/chibios-verifast.git
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

ボードとMacをUSBケーブルで接続した後、st-utilを起動して待機中にしてください。

```
$ st-util
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
