//
//  servoMotorControl.c
//  RaspberryPi
//
//  Created by Troyan Hugo on 04/01/2022.
//  Copyright © 2022 Troyan Hugo. All rights reserved.
//

#include "servoMotorControl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <math.h>

#define SERVO1 23 // GPIO 13 - pin 33
#define SERVO2 24 // GPIO 19 - pin 35
#define SERVO3 1 // GPIO 18 - pin 12

// TODO A traduire
// ---------------------------------------------------
// -                  ANALOGIQUE                     -
// ---------------------------------------------------

// Le servo moteur tourne avec un angle de 0 à 180° en fonction du signal PWM qu'on lui injecte.
// Le signal est carré de période 20 ms (50Hz)
// Un angle de 0 ° correspond a 1ms à l'état haut
// Un angle de 90° correspond a 1.5ms à l'état haut
// Un angle de 180° correspond a 2ms à l'état haut

// ---------------------------------------------------
// -                  NUMERIQUE                      -
// ---------------------------------------------------
// Le signal est carré de période 3.33 ms (300Hz)
// Un angle de 0 ° correspond a 500µs à l'état haut
// Un angle de 90° correspond a 1500µs à l'état haut
// Un angle de 180° correspond a 2500µs à l'état haut

/*
    Initialize all pins for servomotors
    Frequency = 19.2MHz / (PMWC * PWMR)
    PWMR
    PWMC is clock divider

    We want 300 Hz : 300 = 19.2MHz / (PWMC * PWMR)
    PWMC = 64
    PWMR = 1000
*/
void initializeServoMotor(){
    // Set as PWM
    pinMode(SERVO1, PWM_OUTPUT);
    pinMode(SERVO2, PWM_OUTPUT);
    pinMode(SERVO3, PWM_OUTPUT);
    // Set MarkSpaced mode
    pwmSetMode(PWM_MODE_MS);

    // Setup PWM
    pwmSetRange(1000);
    pwmSetClock(128);
//    setPulseServo(90);
}

void incrementAngleServo(int *currentAngle, int servomotorPosition) {
    if (*currentAngle < 180 && *currentAngle >= 0) {
        // TODO Increment by 1° ?
        *currentAngle++;
        // TODO Handle errors ?
        setPulseServo(*currentAngle, servomotorPosition);
    }
}

void decrementAngleServo(int *currentAngle, int servomotorPosition) {
    if (*currentAngle > 0 && *currentAngle <= 180) {
        // TODO Decrement by 1° ?
        *currentAngle--;
        // TODO Handle errors ?
        setPulseServo(*currentAngle, servomotorPosition);
    }
}

/*
    Set PWM command signal for servomotor with specific angle
    Between 0° and 180°
*/
int setPulseServo(int angle, int servomotorPosition) {
    int servomotorPin;

    //Setup which servomotor to control
    switch (servomotorPosition) {
        case 1:
            servomotorPin = SERVO1;
            break;
        case 2:
            servomotorPin = SERVO2;
            break;
        case 3:
            servomotorPin = SERVO3;
            break;
        default:
            printf("No servomotor selected.\nExit...\n");
            return 1;
    }

    printf("-----------------------------\n");
    printf("-    Set angle to servo %d   -\n", servomotorPosition);
    printf("-----------------------------\n");

    printf("* Angle : %d°\n", angle);

    //TODO définir une loi de commande propre
    // Valeur_PWM = 1.1056*Angle + 64
    //Min = 64 (0°)
    //Max = 263 (180°)

    // It shouldn't be necessary but it's there for now
    if (angle < 180 && angle > 0) {
        pwmWrite(servomotorPin, round(1.5*angle + 64));
        return 0;
    } else {
        printf("Error with angle : %d\n", angle);
        return 1;
    }
}

