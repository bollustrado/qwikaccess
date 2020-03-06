#!/bin/bash
if [ $(bluetoothctl show | grep 'Powered' | cut -d ' ' -f2) == "yes" ] ; then
elif [ $(connmanctl technologies | grep -A1 bluetooth | awk '/Powered/ { print $NF }') == "True" ]; then
elif [ $(rfkill list | grep -A1 bluetooth | awk '/Soft blocked/ { print $NF }') == "no" ] ; then
echo "enabled"
else
echo "disabled"
fi


