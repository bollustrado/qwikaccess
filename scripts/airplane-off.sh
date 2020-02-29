#!/bin/bash
if [ "`which connmanctl`" ]; then
$(connmanctl disable offline) &&
notify-send -i "airplane-mode" 'Airplane Mode' 'turned off via connmanctl'
else
$(rfkill unblock all)&&
notify-send -i "airplane-mode" 'Airplane Mode' 'turned off via rfkill'
fi

if [ "`which nmcli`" ]; then
$(nmcli networking on) &&
notify-send -i "airplane-mode" 'Airplane Mode' 'turned off via nmcli'
fi
