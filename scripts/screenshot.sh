#!/bin/bash
if [ "`which coreshot`" ]; then
coreshot
else
ffmpeg -f x11grab -video_size $(xrandr | grep \* | cut -d' ' -f4) -i $DISPLAY -vframes 1 ~/Pictures/qwikscreenshot-$(date "+%Y-%m-%d-%H-%M-%S").jpg &&
notify-send -i "camera" 'qwikscreenshot' 'screenshot saved in ~/Pictures'
fi
