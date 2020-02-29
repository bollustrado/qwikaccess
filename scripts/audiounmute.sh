#!/bin/bash
DEFAULT_SINK=$(pactl info | grep "Default Sink" | cut -d " " -f3)
        pactl set-sink-mute "$DEFAULT_SINK" 0 &&
notify-send -i "audio-on" 'Audio' 'unmuted'
