#!/bin/bash
if [ "`which brightnessctl`" ]; then
 brightnessctl --device='*::kbd_backlight' set 0%
else
echo 0 | sudo tee /sys/class/leds/*::kbd_backlight/brightness
fi
