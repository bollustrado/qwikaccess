#!/bin/bash
module=$(hwinfo --wlan | grep "Driver Status" | cut -d " " -f7)

modprobe -r $module
modprobe -v $module
