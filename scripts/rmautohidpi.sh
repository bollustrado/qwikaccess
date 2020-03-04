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
YOU=$(who | awk '{print $1}')
# And what do you want?
RV=$(xrdb -query | grep dpi | grep -o '[^Xft.dpi:]\+$')
# to get only number 
DPI=$(bc <<< "scale = 0;  $RV / 1")
# Generate a "fractional value" (FV) from a 96dpi default (ie: 120 = 1.25)
FV=$(bc <<< "scale = 2;  $DPI / 96")
# And where are your firefox and thunderbird profiles?

MPPP=$(printf 'user_pref("layout.css.devPixelsPerPx", "'"$FV"'");')
if [ "`which thunderbird`" ]; then
TBPRO=$(find /home/$YOU/.thunderbird/ -name "*.default" -print)
 sed -i -e "/$MPPP/d" $TBPRO/user.js ;
fi


if [ "`which firefox`" ]; then
FFPRO=$(find /home/$YOU/.mozilla/firefox -name "*.default" -print)
 sed -i -e "/$MPPP/d" $FFPRO/user.js ;
fi


 sed -i -e "/export GDK_SCALE=$FV/d" /home/$YOU/.profile ;
 sed -i -e "/export QT_AUTO_SCREEN_SCALE_FACTOR=1/d" /home/$YOU/.profile ;
 #sed -i -e "s/ -dpi $DPI//g" /etc/sddm.conf ;
# sudo -H -u $YOU 
if [ "`which kwriteconfig5`" ]; then
kwriteconfig5 --file /home/$YOU/.config/kcmfonts --group "General" --key "forceFontDPI" "96" ; 
fi

exit
