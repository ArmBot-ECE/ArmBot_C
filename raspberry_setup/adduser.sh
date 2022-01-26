#!/bin/bash

#
#  Adduser
#  ArmBot Raspberry Configuration
#
#  Created by Evann De Castro on 25/01/2022.
#  Copyright © 2022 ArmBot. All rights reserved.
#


GROUPES_INTERDITS_LISTE="root"

for i in ${GROUPES_INTERDITS_LISTE}; do
	if [[ $2 == $i ]] ; then
		echo "Ce nom de groupe : $2 est interdit ; merci de choisir un groupe diffÃ©rent pour cet utilisateur"
		exit 1
	fi
done

sudo useradd $1 -g $2

		echo "entrer le mot de passe"

sudo passwd $1
