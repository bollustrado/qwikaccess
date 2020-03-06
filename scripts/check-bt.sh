#!/bin/bash
if [ $(bluetoothctl show | grep 'Powered' | cut -d ' ' -f2) == "yes" || $(rfkill list | grep -A1 bluetooth | awk '/Soft blocked/ { print $NF }') == "no" || $(connmanctl technologies | grep -A1 bluetooth | awk '/Powered/ { print $NF }') == "True" ]; then
echo "enabled"

elif [ $(bluetoothctl show | grep 'Powered' | cut -d ' ' -f2) == "no" || $(rfkill list | grep -A1 bluetooth | awk '/Soft blocked/ { print $NF }') == "yes" || $(connmanctl technologies | grep -A1 bluetooth | awk '/Powered/ { print $NF }') == "False" ]; then
echo "disabled"
fi


