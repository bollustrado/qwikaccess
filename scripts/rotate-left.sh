#!/bin/bash
kscreen-doctor output."$(kscreen-doctor -o | grep "primary" | awk '/Output/ { print $3 }')".rotation.left
xrandr --output $(xrandr | egrep -o '^.+ connected' | cut -d " " -f 1) --rotate left
