#!/bin/bash
if [ $(pacmd list-sources | grep -A11 $(pacmd stat | awk -F": " '/^Default source name: /{print $2}') | awk '/muted/ { print $NF }') == "yes" ]; then
echo "muted"
elif [ $(pacmd list-sources | grep -A11 $(pacmd stat | awk -F": " '/^Default source name: /{print $2}') | awk '/muted/ { print $NF }') == "no" ]; then
echo "unmuted"
fi
