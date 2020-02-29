#!/bin/bash
DEFAULT_SINK=$(pactl info | grep "Default Sink" | cut -d " " -f3)
        pactl set-sink-mute "$DEFAULT_SINK" 1 &&
notify-send -i "audio-off" 'Audio' 'muted'
