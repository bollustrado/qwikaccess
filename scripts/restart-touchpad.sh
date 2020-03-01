#!/bin/bash

modules=(psmouse hid_multitouch elan_i2c i2c_hid)

for mod in "${modules[@]}"; do
    modprobe -r "$mod" 2> /dev/null
    modprobe -v "$mod" 2> /dev/null
done
