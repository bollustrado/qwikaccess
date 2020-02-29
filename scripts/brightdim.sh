#!/bin/bash
xrandr --output $(xrandr | egrep -o '^.+ connected' | cut -d " " -f 1) --brightness 0.5
brightnessctl s 50%
