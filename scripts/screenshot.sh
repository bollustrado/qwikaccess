#!/bin/bash
if [ $XDG_SESSION_TYPE == "x11" ]; then
ffmpeg -f x11grab -video_size $(xrandr | grep \* | cut -d' ' -f4) -i $DISPLAY -vframes 1 ~/qwikscreenshot-$(date "+%Y-%m-%d-%H-%M-%S").jpg &&
notify-send -i "camera" 'qwikscreenshot' 'screenshot saved in ~/Home'
else
grim $HOME/qwikscreenshot-$(date "+%Y-%m-%d-%H-%M-%S").png
notify-send -i "camera" 'qwikscreenshot' 'screenshot saved in ~/Home'
fi
