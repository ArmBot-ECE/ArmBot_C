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
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <math.h>

#define XMOVE 8 // GPIO 2 - pin 3
#define XDIR 9 // GPIO 3 - pin 5

void initializeStepperMotor(){
    // I/O
    pinMode(XMOVE, OUTPUT);
    pinMode(XDIR, OUTPUT);
}

// TODO
//Attention avec cette fonction, le signal recu doit être périodique
// S'il recoit 5000 1 par seconde il va très vite atteindre sa valeur max
void incrementAngle(int *currentAngle, int steppermotorPosition) {
    if (*currentAngle < 180 && *currentAngle >= 0) {
//        // TODO Increment by 1° ?
//        *currentAngle++;
//        // TODO Handle errors ?
//        setPulse(*currentAngle, steppermotorPosition);
    }
}

void incrementAngleTest() {
    digitalWrite(XMOVE,1);
    digitalWrite(XDIR,1);
}

void decrementAngle(int *currentAngle, int steppermotorPosition) {
    if (*currentAngle > 0 && *currentAngle <= 180) {
//        // TODO Decrement by 1° ?
//        *currentAngle--;
//        // TODO Handle errors ?
//        setPulse(*currentAngle, steppermotorPosition);
    }
}

/*
    Set PWM command signal for servomotor with specific angle
    Between 0° and 180°
*/
int setPulse(int angle, int steppermotorPosition) {
    int steppermotorPin;

//    //Setup which servomotor to control
//    switch (servomotorPosition) {
//        case 1:
//            servomotorPin = SERVO1;
//            break;
//        case 2:
//            servomotorPin = SERVO2;
//            break;
//        case 3:
//            servomotorPin = SERVO3;
//            break;
//        default:
//            printf("No servomotor selected.\nExit...\n");
//            return 1;
//    }
//
//    printf("-----------------------------\n");
//    printf("-    Set angle to servo %d   -\n", servomotorPosition);
//    printf("-----------------------------\n");
//
//    printf("* Angle : %d°\n", angle);
//
//    //TODO définir une loi de commande propre
//    // Valeur_PWM = 1.1056*Angle + 64
//    //Min = 64 (0°)
//    //Max = 263 (180°)
//
//    // It shouldn't be necessary but it's there for now
//    if (angle < 180 && angle > 0) {
//        pwmWrite(servomotorPin, round(1.1056*angle + 64));
//        return 0;
//    } else {
//        printf("Error with angle : %d\n", angle);
//        return 1;
//    }
}

