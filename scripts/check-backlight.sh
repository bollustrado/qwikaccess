#!/bin/bash
if [ $(cat /sys/class/leds/*::kbd_backlight/brightness) -gt 0 ]; then
echo "enabled"
fi
