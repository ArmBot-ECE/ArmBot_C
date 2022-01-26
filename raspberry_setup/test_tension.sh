#!/bin/bash

#
#  Test_tension
#  ArmBot Raspberry Configuration
#
#  Created by Evann De Castro on 25/01/2022.
#  Copyright © 2022 ArmBot. All rights reserved.
#


function throttleCodeMask {
  perl -e "printf \"%s\", $1 & $2 ? \"$3\" : \"$4\""
}

function throttledToText {
  throttledCode=$1
  throttleCodeMask $throttledCode 0x80000 "Raspberry temperature too high, " ""
  throttleCodeMask $throttledCode 0x40000 "An issue was detected, " ""
  throttleCodeMask $throttledCode 0x20000 "ARM frequency is limited, " ""
  throttleCodeMask $throttledCode 0x10000 "Raspberry is underpowered, " ""
  throttleCodeMask $throttledCode 0x8 "Raspberry temperature limit is active, " ""
  throttleCodeMask $throttledCode 0x4 "An issue is happening, " ""
  throttleCodeMask $throttledCode 0x2 "ARM frequency is limited, " ""
  throttleCodeMask $throttledCode 0x1 "Raspberry underpower detected, " ""
}
# Kill sysbench if interrupted
trap 'kill -HUP 0' EXIT
sysbench --test=cpu --cpu-max-prime=10000000 --num-threads=4 run > /dev/null &
maxfreq=$(( $(awk '{printf ("%0.0f",$1/1000); }' < /sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq) -15 ))
# Read system informations, print and repeat 
while true; do
  temp=$(vcgencmd measure_temp | cut -f2 -d=)
  real_clock_speed=$(vcgencmd measure_clock arm | awk -F"=" '{printf ("%0.0f", $2 / 1000000); }' )
  sys_clock_speed=$(awk '{printf ("%0.0f",$1/1000); }' </sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq)
  voltage=$(vcgencmd measure_volts | cut -f2 -d= | sed 's/000//')
  throttled_text=$(throttledToText $(vcgencmd get_throttled | cut -f2 -d=))
  echo "$temp $sys_clock_speed / $real_clock_speed MHz $voltage - $throttled_text"
  sleep 5
done
