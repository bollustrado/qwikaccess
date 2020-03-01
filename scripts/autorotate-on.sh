#!/bin/sh
# Auto rotate touch screen based on device orientation by tausciam on reddit.
#
#   Based off a script from bartv found at https://forums.linuxmint.com/viewtopic.php?t=239800 which
#   was based on chadm's script at https://linuxappfinder.com/blog/auto_screen_rotation_in_ubuntu.

# Receives input from monitor-sensor (part of iio-sensor-proxy package) and sets the touchscreen
# orientation based on the accelerometer position. Type "xrandr -q" to find your display if it's not 
# $(xrandr | egrep -o '^.+ connected' | cut -d " " -f 1). Type "xinput list" to find the number to use for set-prop if 12 doesn't work
# Tested on Solus Plasma with a Lenovo Yoga 730

# This script should be added in KDE autostart programs. Don't forget to "chmod u+x" it and test it 
# from the command line first.

# Kill any existing monitor-sensor instance, for example if manually invoking
# from a terminal for testing.
killall monitor-sensor

# Launch monitor-sensor and store the output in a RAM based file that can be checked by the rest of the script.
# We use the RAM based file system to save wear where an SSD is being used.
monitor-sensor > /dev/shm/sensor.log 2>&1 &

# Initialize display orientation to 'normal'
# Without this, the display often starts in 'inverted' (or 'bottom-up') mode!
xrandr --output $(xrandr | egrep -o '^.+ connected' | cut -d " " -f 1) --rotate normal
xinput set-prop $touchscreenid 'Coordinate Transformation Matrix' 1 0 0 0 1 0 0 0 1
xinput set-prop $touchscreenid  "Device Enabled" 1
#xinput set-prop $touchpadid  "Device Enabled" 1
#xinput set-prop 10  "Device Enabled" 1

# Parse output of monitor sensor to get the new orientation whenever the log file is updated
# Possibles are: normal, bottom-up, right-up, left-up
# Light data will be ignored
while inotifywait -e modify /dev/shm/sensor.log; do

# Read the last few lines that were added to the file and get the last orientation line.
ORIENTATION=$(tail /dev/shm/sensor.log | grep 'orientation' | tail -1 | grep -oE '[^ ]+$')
touchscreenid=$(xinput --list | grep -i 'touchscreen' | grep -o 'id=[0-9]*' | sed 's/id=//')
touchpadid=$(xinput --list | grep -i 'touchpad' | grep -o 'id=[0-9]*' | sed 's/id=//')
# Set the actions to be taken for each possible orientation
case "$ORIENTATION" in
bottom-up)
xrandr --output $(xrandr | egrep -o '^.+ connected' | cut -d " " -f 1) --rotate inverted
#xinput set-prop 10  "Device Enabled" 0
#xinput set-prop $touchpadid  "Device Enabled" 0
xinput set-prop $touchscreenid  "Device Enabled" 1
xinput set-prop $touchscreenid 'Coordinate Transformation Matrix' -1 0 1 0 -1 1 0 0 1;;
normal)
xrandr --output $(xrandr | egrep -o '^.+ connected' | cut -d " " -f 1) --rotate normal
#xinput set-prop 10  "Device Enabled" 1
#xinput set-prop $touchpadid  "Device Enabled" 1
xinput set-prop $touchscreenid  "Device Enabled" 1
xinput set-prop $touchscreenid 'Coordinate Transformation Matrix' 1 0 0 0 1 0 0 0 1;;
right-up)
xrandr --output $(xrandr | egrep -o '^.+ connected' | cut -d " " -f 1) --rotate right
#xinput set-prop 10  "Device Enabled" 0
#xinput set-prop $touchpadid  "Device Enabled" 0
xinput set-prop $touchscreenid  "Device Enabled" 1
xinput set-prop $touchscreenid 'Coordinate Transformation Matrix' 0 1 0 -1 0 1 0 0 1;;
left-up)
xrandr --output $(xrandr | egrep -o '^.+ connected' | cut -d " " -f 1) --rotate left
#xinput set-prop 10  "Device Enabled" 0
#xinput set-prop $touchpadid  "Device Enabled" 0
xinput set-prop $touchscreenid  "Device Enabled" 1
xinput set-prop $touchscreenid 'Coordinate Transformation Matrix' 0 -1 1 1 0 0 0 0 1;;
esac
done

# On stopping this script, don't forget that "monitor-sensor" is still running - hence the "killall" 
