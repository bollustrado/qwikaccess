#!/bin/bash
playerctl metadata mpris:artUrl | grep -o -P '.{0,1}home.{0,}' 
