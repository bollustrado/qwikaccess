#!/bin/bash
DEFAULT_SINK=$(pacmd list-sinks|awk '/\* index:/{ print $3 }')
        pactl set-sink-mute "$DEFAULT_SINK" 1 &&
notify-send -i "audio-off" 'Audio' 'muted'
