#!/bin/bash
if [ "`which brightnessctl`" ]; then
 brightnessctl --device='*::kbd_backlight' set 100%
else
echo 3 | sudo tee /sys/class/leds/*::kbd_backlight/brightness 
fi
