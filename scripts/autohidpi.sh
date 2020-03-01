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

#while getopts 'i:r:' opt ; do
# Apply KDE DPI through system settings
 sudo -H -u $YOU kwriteconfig5 --file /home/$YOU/.config/kcmfonts --group "General" --key "forceFontDPI" "$DPI" ;

# Apply SDDM DPI
 sed -i '/^ServerArguments/ s/$/ '"-dpi $DPI"'/' /etc/sddm.conf ;

# Apply GTK scaling using the FV
 sed -i '$a\' /etc/environment ;
 printf "GDK_SCALE=$FV" >> /etc/environment ;
 export GDK_SCALE=$FV

# Apply Automatic QT scaling which *should* force screen DPI
 sed -i '$a\' /etc/environment ;
 printf "QT_AUTO_SCREEN_SCALE_FACTOR=1" >> /etc/environment ;
 export QT_AUTO_SCREEN_SCALE_FACTOR=1

# Apply Firefox pixelsperpx using FV
# sudo -H -u $YOU touch -a $FFPRO/user.js ;
# sudo -H -u $YOU sed -i '$a\' $FFPRO/user.js ;
# sudo -H -u $YOU printf "$MPPP" >> $FFPRO/user.js ;

# Apply Thunderbird pixelsperpx using FV
# sudo -H -u $YOU touch -a $TBPRO/user.js ;
# sudo -H -u $YOU sed -i '$a\' $TBPRO/user.js ;
# sudo -H -u $YOU printf "$MPPP" >> $TBPRO/user.js ;

exit
