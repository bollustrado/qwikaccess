#!/bin/bash
DEFAULT_SINK=$(pacmd list-sinks|awk '/\* index:/{ print $3 }')
        pactl set-sink-mute "$DEFAULT_SINK" 0 &&
notify-send -i "audio-on" 'Audio' 'unmuted'
