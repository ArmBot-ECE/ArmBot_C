#!/bin/bash

#
#  Adduser
#  ArmBot Raspberry Configuration
#
#  Created by Evann De Castro on 25/01/2022.
#  Copyright © 2022 ArmBot. All rights reserved.
#


FORBIDDEN_GROUPS_LIST="root"

for i in ${FORBIDDEN_GROUPS_LIST}; do
	if [[ $2 == $i ]] ; then
		echo "This group name : $2 is forbidden ; please choose a different group for the user"
		exit 1
	fi
done

sudo useradd $1 -g $2

		echo "Please enter the password"

sudo passwd $1
