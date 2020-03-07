#!/bin/bash
if [ "`which brightnessctl`" ]; then
brightnessctl s 5%-
fi


MON="$(xrandr | egrep -o '^.+ connected' | cut -d " " -f 1)"    # Discover monitor name with: xrandr | grep " connected"
STEP=5          # Step Up/Down brightnes by: 5 = ".05", 10 = ".10", etc.

CurrBright=$( xrandr --verbose --current | grep ^"$MON" -A5 | tail -n1 )
CurrBright="${CurrBright##* }"  # Get brightness level with decimal place

Left=${CurrBright%%"."*}        # Extract left of decimal point
Right=${CurrBright#*"."}        # Extract right of decimal point

MathBright="0"
[[ "$Left" != 0 && "$STEP" -lt 10 ]] && STEP=10     # > 1.0, only .1 works
[[ "$Left" != 0 ]] && MathBright="$Left"00          # 1.0 becomes "100"
[[ "${#Right}" -eq 1 ]] && Right="$Right"0          # 0.5 becomes "50"
MathBright=$(( MathBright + Right ))

#[[ "$1" == "Up" || "$1" == "+" ]] && 
#MathBright=$(( MathBright + STEP ))
#[[ "$1" == "Down" || "$1" == "-" ]] && 
MathBright=$(( MathBright - STEP ))
[[ "${MathBright:0:1}" == "-" ]] && MathBright=0    # Negative not allowed
[[ "$MathBright" -gt 999  ]] && MathBright=999      # Can't go over 9.99

if [[ "${#MathBright}" -eq 3 ]] ; then
    MathBright="$MathBright"000         # Pad with lots of zeros
    CurrBright="${MathBright:0:1}.${MathBright:1:2}"
else
    MathBright="$MathBright"000         # Pad with lots of zeros
    CurrBright=".${MathBright:0:2}"
fi

xrandr --output "$MON" --brightness "$CurrBright" 
# && # Set new brightness

# Display current brightness
#printf "Monitor $MON "
#echo $( xrandr --verbose --current | grep ^"$MON" -A5 | tail -n1 ) | while read OUTPUT; do notify-send "$OUTPUT"; done
