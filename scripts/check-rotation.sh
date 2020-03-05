#!/bin/bash
xrandr -q --verbose| grep $(xrandr | egrep -o '^.+ connected' | cut -d " " -f 1)| cut -d ' ' -f6
