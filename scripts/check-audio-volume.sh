#!/bin/bash
pacmd list-sinks|grep -A 15 '* index'| awk '/volume: front/{ print $5 }'
