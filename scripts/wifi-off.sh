#!/bin/bash
if [ "`which connmanctl`" ]; then
$(connmanctl disable wifi) &&
notify-send -i "network-wireless" 'Wifi' 'turned off via connmanctl'
else
$(rfkill block wifi)&&
notify-send -i "network-wireless" 'Wifi' 'turned off via rfkill'
fi

if [ "`which nmcli`" ]; then
$(nmcli radio wifi off) &&
notify-send -i "network-wireless" 'Wifi' 'turned off via nmcli'
fi
