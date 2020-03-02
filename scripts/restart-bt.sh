#!/bin/bash
modules=(btusb bluetooth)

for mod in "${modules[@]}"; do
    modprobe -r "$mod" 2> /dev/null
    modprobe -v "$mod" 2> /dev/null
done
