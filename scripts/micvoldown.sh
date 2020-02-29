#!/bin/bash
DEFAULT_SOURCE=$(pactl info | grep "Default Source" | cut -d " " -f3)
pactl set-source-volume "$DEFAULT_SOURCE" -5% &&
notify-send -i "mic-on" 'Mic' 'volume decresed by -5'
