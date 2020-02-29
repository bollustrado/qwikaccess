#!/bin/bash
DEFAULT_SOURCE=$(pactl info | grep "Default Source" | cut -d " " -f3)
pactl set-source-mute "$DEFAULT_SOURCE" 0 &&
notify-send -i "mic-on" 'Mic' 'unmuted'
