#!/bin/bash
DEFAULT_SINK=$(pactl info | grep "Default Sink" | cut -d " " -f3)
 pactl set-sink-volume "$DEFAULT_SINK" -5% &&
notify-send -i "audio-off" 'Audio' 'volume decresed by -5'
