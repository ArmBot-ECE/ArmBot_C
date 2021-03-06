#!/bin/bash

#
#  start
#  ArmBot Raspberry Configuration
#
#  Created by Evann De Castro on 25/01/2022.
#  Copyright © 2022 ArmBot. All rights reserved.
#


# Raspberry update

sudo apt-get update && sudo apt-get -y upgrade && sudo apt-get -y dist-upgrade && sudo rpi-update

sleep 10 
# Packages installation

sudo apt-get install -y pi-bluetooth  
sudo apt-get install -y bluez 
sudo apt-get install -y expect 
sudo apt-get install -y gcc
sudo apt-get install -y sysbench
sudo apt-get install -y libbluetooth-dev
sudo apt-get install -y python3-pip
sudo apt-get install -y rpi.gpio
sudo apt-get install -y git-core
sudo apt-get install -y git
sudo apt-get install -y build-essential
sudo apt-get install -y lwiringPi

sleep 10

# Password modification and rights added for the 'pi' user
sudo passwd pi
sudo usermod --gid bluetooth pi  
groups pi

sleep 10

# Execution of another script due to the use of a different interpreter
# The previously required MAC address will be used for this script
sudo ./bluetooth.sh $1

sleep 10

# Getting the repository
sudo apt-get purge -y wiringpi 
hash -r 
git clone https://github.com/WiringPi/WiringPi.git 
cd WiringPi 
git pull origin 
./build 
gpio -v

sleep 10

# Bluez package beug correction
sudo cp -r /etc/repo/ArmBot_C-main/raspberry_setup/dbus-org.bluez.service /etc/systemd/system/
sudo systemctl daemon-reload
sudo systemctl restart bluetooth
sudo chmod 777 /var/run/sdp

sleep 10

# Copy of the file rc.local in /etc/
sudo cp -r /etc/repo/ArmBot_C-main/raspberry_setup/rc.local /etc/

sleep 10

# Compilation of the code 
cd /etc/repo/ArmBot_C-main/
gcc -o main main.c -lwiringPi -lrt -lpthread -lm -lrt -lcrypt -lbluetooth

sleep 10

# Reboot of the Raspberry 
echo "Your Raspberry will reboot in..."
echo 3
sleep 1
echo 2
sleep 1
echo 1
sleep 1
sudo reboot
