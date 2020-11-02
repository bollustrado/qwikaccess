#!/bin/bash
DEFAULT_SOURCE=$(pacmd list-sources|awk '/\* index:/{ print $3 }')
pactl set-source-mute "$DEFAULT_SOURCE" 0 &&
notify-send -i "mic-on" 'Mic' 'unmuted'
