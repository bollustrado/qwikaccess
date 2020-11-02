#!/bin/bash
playerctl metadata --format '{{ title }} \n{{ status }}:- {{ duration(position) }}' #|{{ duration(mpris:length) }}' #--follow 
