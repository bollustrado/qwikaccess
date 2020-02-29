#!/bin/bash
xrandr --output $(xrandr | egrep -o '^.+ connected' | cut -d " " -f 1) --rotate right
