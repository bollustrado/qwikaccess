#!/bin/bash
if [ "`which connmanctl`" ]; then
$(connmanctl disable bluetooth) &&
notify-send -i "network-bluetooth" 'Bluetooth' 'turned off via connmanctl'
else
$(rfkill block Bluetooth)&&
notify-send -i "network-bluetooth" 'Bluetooth' 'turned off via rfkill'
fi

if [ "`which bluetoothctl`" ]; then
$(bluetoothctl discoverable off) && $(bluetoothctl power off) &&
notify-send -i "network-bluetooth" 'Bluetooth' 'turned off via bluetoothctl'
fi
