//
//  stepperMotorControl.c
//  RaspberryPi
//
//  Created by Troyan Hugo on 04/01/2022.
//  Copyright © 2022 Troyan Hugo. All rights reserved.
//

#include "stepperMotorControl.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <wiringPi.h>

#define XMOVE1 8 // GPIO 2 - pin 3
#define XDIR1 9 // GPIO 3 - pin 5
#define XMOVE2 0 // GPIO 17 - pin 11
#define XDIR2 2 // GPIO 27 - pin 13

void initializeStepperMotor(){
    // I/O
    pinMode(XMOVE1, OUTPUT);
    pinMode(XDIR1, OUTPUT);
    pinMode(XMOVE2, OUTPUT);
    pinMode(XDIR2, OUTPUT);
}

int incrementAngleStepper(int stepperMotorPosition) {
    int stepperMotorPin;
    int stepperMotorPinDirection;
    switch(stepperMotorPosition) {
        case 1:
            stepperMotorPin = XMOVE1;
            stepperMotorPinDirection = XDIR1;
            break;
        case 2:
            stepperMotorPin = XMOVE2;
            stepperMotorPinDirection = XDIR2;
            break;
        default:
            return 1;
            break;
    }
    digitalWrite(stepperMotorPinDirection,1);
    digitalWrite(stepperMotorPin,1);
    digitalWrite(stepperMotorPin,0);
    return 0;
}

int decrementAngleStepper(int stepperMotorPosition) {
    int stepperMotorPin;
    int stepperMotorPinDirection;
    switch(stepperMotorPosition) {
        case 1:
            stepperMotorPin = XMOVE1;
            stepperMotorPinDirection = XDIR1;
            break;
        case 2:
            stepperMotorPin = XMOVE2;
            stepperMotorPinDirection = XDIR2;
            break;
        default:
            return 1;
            break;
    }
    digitalWrite(stepperMotorPinDirection,0);
    digitalWrite(stepperMotorPin,1);
    digitalWrite(stepperMotorPin,0);
    return 0;
}
