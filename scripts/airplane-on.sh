#!/bin/bash
if [ "`which connmanctl`" ]; then
$(connmanctl enable offline) &&
notify-send -i "airplane-mode" 'Airplane Mode' 'turned on via connmanctl'
else
$(rfkill block all)&&
notify-send -i "airplane-mode" 'Airplane Mode' 'turned on via rfkill'
fi

if [ "`which nmcli`" ]; then
$(nmcli networking off) &&
notify-send -i "airplane-mode" 'Airplane Mode' 'turned on via nmcli'
fi
