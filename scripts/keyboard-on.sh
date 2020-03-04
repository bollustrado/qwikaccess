#!/bin/bash
xinput --enable $(xinput --list | grep -i 'AT Translated Set' | grep -o 'id=[0-9]*' | sed 's/id=//') &&
notify-send -i "input-keyboard" 'Keyboard' 'Enabled'
