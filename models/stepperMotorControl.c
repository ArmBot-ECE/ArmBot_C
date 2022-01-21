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

#define XMOVE 8 // GPIO 2 - pin 3
#define XDIR 9 // GPIO 3 - pin 5

void initializeStepperMotor(){
    // I/O
    pinMode(XMOVE, OUTPUT);
    pinMode(XDIR, OUTPUT);
    printf("hello\n");
}

// TODO
//Attention avec cette fonction, le signal recu doit être périodique
// S'il recoit 5000 1 par seconde il va très vite atteindre sa valeur max
void incrementAngleStepper(int *currentAngle, int steppermotorPosition) {
    if (*currentAngle < 180 && *currentAngle >= 0) {
//        // TODO Increment by 1° ?
//        *currentAngle++;
//        // TODO Handle errors ?
//        setPulse(*currentAngle, steppermotorPosition);
        printf("Hello");
    }
}

void incrementAngleTest() {
//    printf("Test XMOVE 0 XDIR 1\n");
//    digitalWrite(XMOVE,0);
    digitalWrite(XDIR,1);
    printf("Test XMOVE 1 XDIR 1\n");
    digitalWrite(XMOVE,1);
//    digitalWrite(XDIR,1);
//    printf("Test XMOVE 1 XDIR 0\n");
//    digitalWrite(XMOVE,1);
//    digitalWrite(XDIR,0);
    printf("Test XMOVE 0 XDIR 0\n");
    digitalWrite(XMOVE,0);
//    digitalWrite(XDIR,0);

}

void decrementAngleStepper(int *currentAngle, int steppermotorPosition) {
    if (*currentAngle > 0 && *currentAngle <= 180) {
//        // TODO Decrement by 1° ?
//        *currentAngle--;
//        // TODO Handle errors ?
//        setPulse(*currentAngle, steppermotorPosition);
        printf("Hello");
    }
}