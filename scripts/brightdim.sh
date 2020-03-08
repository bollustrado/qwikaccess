#!/bin/bash
if [ "`which brightnessctl`" ]; then
brightnessctl s 50%
fi
if [ $XDG_SESSION_TYPE == "x11" ]; then
MON="$(xrandr | egrep -o '^.+ connected' | cut -d " " -f 1)"    # Discover monitor name with: xrandr | grep " connected"
xrandr --output $(xrandr | egrep -o '^.+ connected' | cut -d " " -f 1) --brightness 0.5
printf "Monitor $MON "
echo $( xrandr --verbose --current | grep ^"$MON" -A5 | tail -n1 ) | while read OUTPUT; do notify-send "$OUTPUT"; done
fi
