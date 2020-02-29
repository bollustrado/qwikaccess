#!/bin/bash
if [ "`which connmanctl`" ]; then
$(connmanctl enable wifi) &&
notify-send -i "network-wireless" 'Wifi' 'turned on via connmanctl'
else
$(rfkill unblock wifi)&&
notify-send -i "network-wireless" 'Wifi' 'turned on via rfkill'
fi

if [ "`which nmcli`" ]; then
$(nmcli radio wifi on) &&
notify-send -i "network-wireless" 'Wifi' 'turned on via nmcli'
fi
