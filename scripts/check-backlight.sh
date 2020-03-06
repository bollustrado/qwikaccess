#!/bin/bash
if [ $(cat /sys/class/leds/*::kbd_backlight/brightness) > 0 ]; then
echo "enabled"
fi
