# ChibiOS/RTアプリケーションのVeriFastによる検証

[ChibiOS/RT](http://www.chibios.org/)上で動作するアプリケーションを[VeriFast](https://people.cs.kuleuven.be/~bart.jacobs/verifast/)で検証します。

## 準備

```
$ sudo apt-get install git python-pip
$ git clone https://github.com/fpiot/chibios-verifast.git
$ cd chibios-verifast
$ make setup
```

## 検証

```
$ cd chibios-verifast/verifast_demo/STM32/RT-STM32F091RC-NUCLEO
$ make vfide
```

## ビルド

```
$ cd chibios-verifast/verifast_demo/STM32/RT-STM32F091RC-NUCLEO
$ make
```

## 実機動作
