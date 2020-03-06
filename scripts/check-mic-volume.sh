#!/bin/bash
pacmd list-sources | grep -A11 $(pacmd stat | awk -F": " '/^Default source name: /{print $2}') | grep "volume: f" | cut -d ' ' -f6
