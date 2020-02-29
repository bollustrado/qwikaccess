#!/bin/bash
	echo 0 > /sys/class/leds/led:torch_0/brightness
	echo 0 > /sys/class/leds/led:torch_1/brightness
	echo 0 > /sys/class/leds/led:switch/brightness
	notify-send -i "flashlight-off" 'Flashlight' 'off'
