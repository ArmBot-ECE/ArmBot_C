#!/bin/bash 

#
#  Monitor
#  ArmBot Raspberry Configuration
#
#  Created by Evann De Castro on 25/01/2022.
#  Copyright © 2022 ArmBot. All rights reserved.
#


until /etc/repo/main; do
    echo "Server 'myserver' crashed with exit code $?.  Respawning.." >&2
    sleep 1
done
