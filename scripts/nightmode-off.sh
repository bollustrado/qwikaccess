#!/bin/bash
redshift -x
killall redshift
gsettings set org.gnome.settings-daemon.plugins.color night-light-enabled false
kwriteconfig5 --file /home/$YOU/.config/kwinrc --group "NightColor" --key "Active" "false"
sed -i 's/Active=true/Active=false/g' ~/.config/kwinrc 
