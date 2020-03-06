#!/bin/bash
xinput --disable $(xinput --list | grep -i 'Touchscreen' | grep -o 'id=[0-9]*' | sed 's/id=//') &&
notify-send -i "input-tablet" 'Touchscreen' 'Disabled'
