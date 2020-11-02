#!/bin/bash
DEFAULT_SOURCE=$(pacmd list-sources|awk '/\* index:/{ print $3 }')
pactl set-source-volume "$DEFAULT_SOURCE" +5%
# &&
#notify-send -i "mic-on" 'Mic' 'volume incresed by +5'
