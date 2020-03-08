#!/bin/bash
bright=$(xrandr --verbose --current | grep "$(xrandr | egrep -o '^.+ connected' | cut -d " " -f 1)" -A5 | awk '/Brightness/ { print $2}')
wvalue=$(brightnessctl | grep Current | awk '/Current brightness/ { print $NF }' | grep -Eo '[0-9]{0,9}')
xvalue=$(bc <<< "scale = 0; ($bright * 100)/1")
if [ $XDG_SESSION_TYPE == "x11" ]; then
echo "$xvalue%"
elif
echo "$wvalue%"
fi
