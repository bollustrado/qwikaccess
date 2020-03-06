#!/bin/bash
modprobe -r uvcvideo
xinput --disable $(xinput --list | grep -i 'Webcam' | grep -o 'id=[0-9]*' | sed 's/id=//') &&
notify-send -i "camera-off" 'Webcam' 'Disabled'
