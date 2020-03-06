#!/bin/bash
pacmd list-sources|grep -A 15 '* index'| awk '/volume: front/{ print $5 }'
