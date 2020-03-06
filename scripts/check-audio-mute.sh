#!/bin/bash
if [ $(pacmd list-sinks | grep -A11 $(pacmd stat | awk -F": " '/^Default sink name: /{print $2}') | awk '/muted/ { print $NF }') == "yes" ]; then
echo "muted"
elif [ $(pacmd list-sinks | grep -A11 $(pacmd stat | awk -F": " '/^Default sink name: /{print $2}') | awk '/muted/ { print $NF }') == "no" ]; then
echo "unmuted"
fi
