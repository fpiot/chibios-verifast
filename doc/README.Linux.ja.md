# ChibiOS/RTのVeriFastによる検証 (Linux版)

[ChibiOS/RT](http://www.chibios.org/)上で動作するアプリケーションを[VeriFast](https://people.cs.kuleuven.be/~bart.jacobs/verifast/)で検証します。

## 準備

関連パッケージをインストールしてください。

```
$ sudo apt-get install wget git python-pip libgtk2.0-0
```

[VeriFastの最新版をダウンロード](https://github.com/verifast/verifast#binaries)し、展開してPATHを通してください。

```
$ wget http://82076e0e62875f063ae8-929808a701855dfb71539d0a4342d4be.r54.cf5.rackcdn.com/verifast-nightly.tar.gz
$ tar xf verifast-nightly.tar.gz
$ mv verifast-*/ verifast
$ export PATH=`pwd`/verifast/bin:$PATH
```

本ソースコードをダウンロードして、ツールチェーンを設定してください。

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

ボードとLinux PCをUSBケーブルで接続した後、st-utilを起動して待機中にしてください。

```
$ cd chibios-verifast/verifast_demo/STM32/RT-STM32F091RC-NUCLEO
$ make st-util
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
