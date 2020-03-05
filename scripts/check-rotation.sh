#!/bin/bash
xrandr -q --verbose| grep HDMI| cut -d ' ' -f6
