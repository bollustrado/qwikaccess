#!/bin/bash
redshift -O 4500k
gsettings set org.gnome.settings-daemon.plugins.color night-light-enabled true
kwriteconfig5 --file /home/$YOU/.config/kwinrc --group "NightColor" --key "Active" "true"
sed -i 's/Active=false/Active=true/g' ~/.config/kwinrc 
