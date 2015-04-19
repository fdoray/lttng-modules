#!/bin/bash

control-addons.sh unload
make -j4
sudo make modules_install
sudo depmod -a

sudo dmesg -c > /dev/null
control-addons.sh load
sudo dmesg -c
