#!/bin/bash
if [ $(xinput --list-props $(xinput --list | grep -i 'AT Translated Set' | grep -o 'id=[0-9]*' | sed 's/id=//') | grep 'Device Enabled' | awk '/Device Enabled/ { print $NF }') == "0" ] ; then
echo "disabled"
elif [ $(xinput --list-props $(xinput --list | grep -i 'AT Translated Set' | grep -o 'id=[0-9]*' | sed 's/id=//') | grep 'Device Enabled' | awk '/Device Enabled/ { print $NF }') == "1" ] ; then
echo "enabled"
fi
