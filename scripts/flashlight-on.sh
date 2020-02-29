#!/bin/bash
	echo 90 > /sys/class/leds/led:torch_0/brightness
	echo 90 > /sys/class/leds/led:torch_1/brightness
	echo 1 > /sys/class/leds/led:switch/brightness
	notify-send -i "flashlight-on" 'Flashlight' 'on'

