#!/bin/bash
if [ "`which connmanctl`" ]; then
$(connmanctl enable bluetooth) &&
notify-send -i "network-bluetooth" 'Bluetooth' 'turned on via connmanctl'
else
$(rfkill unblock Bluetooth)&&
notify-send -i "network-bluetooth" 'Bluetooth' 'turned on via rfkill'
fi

if [ "`which bluetoothctl`" ]; then
$(bluetoothctl discoverable on) && $(bluetoothctl power on) &&
notify-send -i "network-bluetooth" 'Bluetooth' 'turned on via bluetoothctl'
fi
