#!/bin/bash
playerctl metadata --format '{{ playerName }}: {{ status }} - {{ title }} {{ duration(position) }}' #|{{ duration(mpris:length) }}' #--follow 
