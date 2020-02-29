#!/bin/bash
ffmpeg -f pulse -ac 2 -i default ~/Music/qwikaudiorecorder-$(date "+%Y-%m-%d-%H-%M-%S").mp3 ;
notify-send -i "microphone-sensitivity-high" 'qwikaudiorecorder' 'recording started. will be saved in ~/Music'
