#!/bin/bash
ffmpeg -video_size $(xrandr | grep \* | cut -d' ' -f4) -framerate 30 -f x11grab -i $DISPLAY -f pulse -ac 2 -i default ~/Videos/qwikscreenrecorder-$(date "+%Y-%m-%d-%H-%M-%S").mkv ;
notify-send -i "camera-video" 'qwikscreenrecorder' 'recording started. will be saved in ~/Videos'


