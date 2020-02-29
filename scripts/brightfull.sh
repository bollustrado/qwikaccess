#!/bin/bash
xrandr --output $(xrandr | egrep -o '^.+ connected' | cut -d " " -f 1) --brightness 1.0
brightnessctl s 100%
