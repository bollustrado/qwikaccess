#!/bin/bash
pacmd list-sinks | grep -A11 $(pacmd stat | awk -F": " '/^Default sink name: /{print $2}') | grep "volume: f" | cut -d ' ' -f6
