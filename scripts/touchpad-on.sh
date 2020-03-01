#!/bin/bash
xinput --enable $(xinput --list | grep -i 'touchpad' | grep -o 'id=[0-9]*' | sed 's/id=//') &&
notify-send -i "input-touchpad" 'Touchpad' 'Enabled'
