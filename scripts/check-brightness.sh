#!/bin/bash
bright=$(xrandr --verbose --current | grep "$(xrandr | egrep -o '^.+ connected' | cut -d " " -f 1)" -A5 | awk '/Brightness/ { print $2}')

value=$(bc <<< "scale = 0; ($bright * 100)/1")

echo "$value%"
