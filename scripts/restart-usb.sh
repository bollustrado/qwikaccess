#!/bin/bash
#Restart all USB devices
set -euo pipefail
IFS=$'\n\t'

VENDOR="****"
PRODUCT="****"

for DIR in $(find /sys/bus/usb/devices/ -maxdepth 1 -type l); do
  if [[ -f $DIR/idVendor && -f $DIR/idProduct &&
        $(cat $DIR/idVendor) == $VENDOR && $(cat $DIR/idProduct) == $PRODUCT ]]; then
    echo 0 > $DIR/authorized
    sleep 2 
    echo 1 > $DIR/authorized
  fi
done
