#!/bin/bash
if [ $(connmanctl technologies | grep -A1 wifi | awk '/Powered/ { print $NF }') == "True" || $(rfkill list | grep -A1 wifi | awk '/Soft blocked/ { print $NF }') == "no" || $(nmcli radio wifi) == "enabled" ]; then
echo "enabled"

elif [ $(connmanctl technologies | grep -A1 wifi | awk '/Powered/ { print $NF }') == "False" || $(rfkill list | grep -A1 wifi | awk '/Soft blocked/ { print $NF }') == "yes" || $(nmcli radio wifi) == "disabled" ]; then
echo "disabled"
fi


