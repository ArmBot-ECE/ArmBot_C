#!/bin/bash

#
#  Change_group
#  ArmBot Raspberry Configuration
#
#  Created by Evann De Castro on 25/01/2022.
#  Copyright © 2022 ArmBot. All rights reserved.
#


sudo usermod --gid $1 $2 
groups $2
