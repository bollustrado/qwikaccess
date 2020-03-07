#!/bin/bash
killall /usr/share/qwikaccess/scripts/autorotate-on.sh ; killall monitor-sensor ; killall inotifywait
gsettings set org.gnome.settings-daemon.peripherals.touchscreen orientation-lock true
gsettings set org.gnome.settings-daemon.plugins.orientation active false
