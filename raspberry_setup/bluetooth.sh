#!/usr/bin/expect -f

#
#  Bluetooth
#  ArmBot Raspberry Configuration
#
#  Created by Evann De Castro on 25/01/2022.
#  Copyright © 2022 ArmBot. All rights reserved.
#


set prompt "#"
set address [lindex $argv 0]

spawn sudo bluetoothctl 
expect -re $prompt
#send -- "remove $address\r"
sleep 1
expect -re $prompt
send "agent on\r"
send "scan on\r"
#send_user "\nSleeping\r"
send_user "\nRecherche du téléphone\r"
sleep 10
send_user "\nJumelage\r"
send "scan off\r"
expect "Controller"
send  "trust $address\r"
sleep 2
send  "pair $address\r"
send_user "\nValider le jumelage sur le téléphone\r"
sleep 20
send "yes\r"
sleep 3
send_user "\nShould be paired now.\r"
send "exit\r"
expect eof
