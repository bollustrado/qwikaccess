#!/usr/bin/env bash
#                         hidpify.sh                        #
## This script will automate DPI settings for a KDE system ##
#####                        cscs                       #####

# You are powerless. Explain yourself.
#if [ "$EUID" -ne 0 ]
#  then echo "Please run using sudo";
#  exit;
#fi

# Who are you anyways
YOU=$(who -am | awk '{print $1}')
# And what do you want?
DPI=$(xrdb -query | grep dpi | grep -o '[^Xft.dpi:]\+$')
# Generate a "fractional value" (FV) from a 96dpi default (ie: 120 = 1.25)
FV=$(bc <<< "scale = 2;  $DPI / 96")
# And where are your firefox and thunderbird profiles?
FFPRO=$(find /home/$YOU/.mozilla/firefox -name "*.default" -print)
TBPRO=$(find /home/$YOU/.thunderbird/ -name "*.default" -print)
MPPP=$(printf 'user_pref("layout.css.devPixelsPerPx", "'"$FV"'");')

# sed -i -e "/$MPPP/d" $TBPRO/user.js ;
# sed -i -e "/$MPPP/d" $FFPRO/user.js ;
 sed -i -e "/GDK_SCALE=$FV/d" /etc/environment ;
 sed -i -e "/QT_AUTO_SCREEN_SCALE_FACTOR=1/d" /etc/environment ;
 sed -i -e "s/ -dpi $DPI//g" /etc/sddm.conf ;
 sudo -H -u $YOU kwriteconfig5 --file /home/$YOU/.config/kcmfonts --group "General" --key "forceFontDPI" "96" ; 

exit
