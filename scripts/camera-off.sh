#!/bin/bash
modprobe -r uvcvideo
xinput --disable $(xinput --list | grep -i 'webcam' | grep -o 'id=[0-9]*' | sed 's/id=//') &&
notify-send -i "camera-off" 'Webcam' 'Disabled'
