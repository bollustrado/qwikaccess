#!/bin/bash

# Get the gamma values from xrandr. When redshift isn't on, all values are 1.0.
GAMMAX=$(xrandr --verbose | grep 'Gamma' | awk -F ':' '{print $2}' | tr -d ' ')
GAMMAY=$(xrandr --verbose | grep 'Gamma' | awk -F ':' '{print $3}' | tr -d ' ')
GAMMAZ=$(xrandr --verbose | grep 'Gamma' | awk -F ':' '{print $4}' | tr -d ' ')

# Check for at least one value not being 1.0. X appears to stay as 1.0, but Y and Z change.
if [ $GAMMAX != 1.0 ] | [ $GAMMAY != 1.0 ] | [ $GAMMAZ != 1.0 ]; then
echo "enabled"
elif [ $(gsettings set org.gnome.settings-daemon.plugins.color night-light-enabled) == "true" ] ; then
echo "enabled"
elif [ $(cat ~/.config/kwinrc | grep -A1 NightColor | awk '/Active/ { print $NF }') == "Active=true"  ; then
echo "enabled"
fi


