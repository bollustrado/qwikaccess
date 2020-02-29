#!/bin/bash
#!/bin/bash




#####  set variables below ####

location_dir=$HOME/Videos

T="qwikscreenrecorder-camera-$(date +%d-%m-%Y-%H-%M-%S)".mkv

#echo $T

video_window_title="$T"

#echo $video_window_title




####  Place video camera on own screen & detach the process  ####
ffplay -window_title "$video_window_title" /dev/video0 &




####  Record everything on the screen  ####
ffmpeg -y -f x11grab -s \
$(xrandr | grep \* | cut -d' ' -f4) -framerate 30 \
-i $DISPLAY -f pulse -ac 2 \
-i default ~/Videos/$T ;
notify-send -i "camera-video" 'qwikscreenrecorder' 'recording saved in ~/Videos'
