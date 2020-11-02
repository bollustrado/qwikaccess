#!/bin/bash
DEFAULT_SINK=$(pacmd list-sinks|awk '/\* index:/{ print $3 }')
 pactl set-sink-volume "$DEFAULT_SINK" +5% 
#&& notify-send -i "audio-off" 'Audio' 'volume incresed by +5'
