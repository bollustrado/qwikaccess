#!/bin/bash
if [ "`which mmcli`" ]; then
$(mmcli -m 0 --location-enable-gps-raw --location-enable-gps-nmea --location-enable-3gpp --location-enable-cdma-bs) &&
notify-send -i "gps" 'Gps' 'turned on via mmcli'
else
$(systemctl unmask geoclue) &&
notify-send -i "gps" 'Gps' 'geoclue unmasked'
fi

systemctl mask geoclue
