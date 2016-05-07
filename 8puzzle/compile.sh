#!/bin/bash

make
make install
cd ../../
sudo make install
qemu-system-i386 -fda ics-os-floppy.img