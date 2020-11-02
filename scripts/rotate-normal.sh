#!/bin/bash
kscreen-doctor output."$(kscreen-doctor -o | grep "primary" | awk '/Output/ { print $3 }')".rotation.normal
xrandr --output $(xrandr | egrep -o '^.+ connected' | cut -d " " -f 1) --rotate normal
xinput set-prop $touchscreenid  "Device Enabled" 1
xinput set-prop $touchscreenid 'Coordinate Transformation Matrix' 1 0 0 0 1 0 0 0 1
