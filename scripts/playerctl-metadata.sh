#!/bin/bash
playerctl metadata --format '{{ status }}:-{{ title }} {{ duration(position) }}' #|{{ duration(mpris:length) }}' #--follow 
