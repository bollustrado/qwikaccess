#!/bin/bash
if [ $(connmanctl technologies | grep -A1 bluetooth | awk '/Powered/ { print $NF }') == "False" ]; then
$(connmanctl enable bluetooth) &&
notify-send -i "network-bluetooth" 'Bluetooth' 'turned on via connmanctl'

elif [ $(bluetoothctl show | grep 'Powered' | cut -d ' ' -f2) == "no" ]; then
$(bluetoothctl discoverable on) && $(bluetoothctl power on) &&
notify-send -i "network-bluetooth" 'Bluetooth' 'turned on via bluetoothctl'

elif [ $(rfkill list | grep -A1 bluetooth | awk '/Soft blocked/ { print $NF }') == "yes" ]; then
$(pkexec rfkill unblock bluetooth)&&
notify-send -i "network-bluetooth" 'Bluetooth' 'turned on via rfkill'
fi
