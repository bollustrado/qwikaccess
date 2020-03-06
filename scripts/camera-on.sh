#!/bin/bash
modprobe uvcvideo
xinput --enable $(xinput --list | grep -i 'webcam' | grep -o 'id=[0-9]*' | sed 's/id=//') &&
notify-send -i "camera-on" 'Webcam' 'enabled'
