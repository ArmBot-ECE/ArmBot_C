# !/bin/python

#
#  Shutdown
#  ArmBot Raspberry Configuration
#
#  Created by Evann De Castro on 25/01/2022.
#  Copyright Â© 2022 ArmBot. All rights reserved.
#


# Simple script to restart your Raspberry Pi by clicking on the button

 

import RPi.GPIO as GPIO

import time

import os

 

# Pin numbers usage 

# Initialization of the pin in read mode with intern pullups activation 

GPIO.setmode(GPIO.BCM)

GPIO.setup(21, GPIO.IN, pull_up_down=GPIO.PUD_UP)

 

# Code of the function when the button is pushed

def Shutdown(channel):

    print("Arrêt du Pi...")

    time.sleep(1)

    os.system("sudo shutdown -r now")

 

# Add the function when the event of pushing the button is called

GPIO.add_event_detect(21, GPIO.FALLING, callback=Shutdown, bouncetime=2000)


# We wait !

#while 1:

#    time.sleep (1)
