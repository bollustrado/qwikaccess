#!/bin/bash
xinput --enable $(xinput --list | grep -i 'touchscreen' | grep -o 'id=[0-9]*' | sed 's/id=//') &&
notify-send -i "input-tablet" 'Touchscreen' 'Enabled'
