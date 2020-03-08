#!/bin/bash
if [ $XDG_SESSION_TYPE == "x11" ]; then
ffmpeg -video_size $(xrandr | grep \* | cut -d' ' -f4) -framerate 30 -f x11grab -i $DISPLAY -f pulse -ac 2 -i default ~/Videos/qwikscreenrecorder-$(date "+%Y-%m-%d-%H-%M-%S").mkv ;
notify-send -i "camera-video" 'qwikscreenrecorder' 'recording saved in ~/Videos'
else
wf-recorder -f ~/Videos/qwikscreenrecorder-$(date "+%Y-%m-%d-%H-%M-%S").mkv ;
notify-send -i "camera-video" 'qwikscreenrecorder' 'recording saved in ~/Videos'
fi


