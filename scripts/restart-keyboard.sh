#!/bin/bash
modprobe -r atkbd ; 
modprobe -v atkbd reset=1 ;
modprobe -r usbhid ; 
modprobe -v usbhid reset=1
