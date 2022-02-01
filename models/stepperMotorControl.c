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
#define XMOVE3 3 // GPIO 22 - pin 15
#define XDIR3 12 // GPIO 10 - pin 19

void initializeStepperMotor(){
    // I/O
    pinMode(XMOVE1, OUTPUT);
    pinMode(XDIR1, OUTPUT);
    pinMode(XMOVE2, OUTPUT);
    pinMode(XDIR2, OUTPUT);
    pinMode(XMOVE3, OUTPUT);
    pinMode(XDIR3, OUTPUT);
}

int setDirectionStepper(int stepperMotorPosition, int direction) {
    int stepperMotorPinDirection;
    if(direction != 0 && direction != 1) {
        printf("Wrong argument for direction !\nClockwise = 1\nAnti-clockwise = 0\n");
        return 1;
    }
    switch(stepperMotorPosition) {
        case 1:
            stepperMotorPinDirection = XDIR1;
            break;
        case 2:
            stepperMotorPinDirection = XDIR2;
            break;
        case 3:
            stepperMotorPinDirection = XDIR3;
            break;
        default:
            printf("Wrong argument for stepper position !\n1, 2 or 3 available\n");
            return 1;
            break;
    }
    digitalWrite(stepperMotorPinDirection, direction);
    return 0;
}

int rotateStepper(int stepperMotorPosition) {
    int stepperMotorPin;
    switch(stepperMotorPosition) {
        case 1:
            stepperMotorPin = XMOVE1;
            break;
        case 2:
            stepperMotorPin = XMOVE2;
            break;
        case 3:
            stepperMotorPin = XMOVE3;
            break;
        default:
            printf("Wrong argument for stepper position !\n1, 2 or 3 available\n");
            return 1;
            break;
    }

    digitalWrite(stepperMotorPin,1);
    digitalWrite(stepperMotorPin,0);
    return 0;
}
