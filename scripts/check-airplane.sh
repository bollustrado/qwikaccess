#!/bin/bash
if [ $(connmanctl state | awk '/OfflineMode/ { print $NF }') == "True" || $(nmcli networking) == "disabled" ]; then
echo "enabled"
fi

if [ $(connmanctl state | awk '/OfflineMode/ { print $NF }') == "False" || $(nmcli networking) == "enabled" ]; then
echo "disabled"
fi
