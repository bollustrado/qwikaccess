#!/bin/bash
bluetoothctl show | grep 'Powered' | cut -d ' ' -f2 
