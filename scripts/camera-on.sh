#!/bin/bash
modprobe uvcvideo
xinput --enable $(xinput --list | grep -i 'Webcam' | grep -o 'id=[0-9]*' | sed 's/id=//') &&
notify-send -i "camera-on" 'Webcam' 'enabled'
