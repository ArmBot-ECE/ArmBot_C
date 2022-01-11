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

#define SERVO 1 //Equivalent WiringPi 0 : GPIO 23


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


void initializeServoMotor(){
    //set as PWM
    pinMode(SERVO, PWM_OUTPUT);
    //set MarkSpaced mode
    pwmSetMode(PWM_MODE_MS);

    //Frequency : 19.2MHz/ (PMWC * PWMR)
    //PWMR
    //PWMC is clock divider

    // We want 300 Hz : 300 = 19.2MHz / (PWMC * PWMR)
    // PWMC = 64
    // PWMR = 1000
    // We start at angle 90° (central position)
//    pwmSetRange(2000);
//    pwmSetClock(192);
//    setPulse(90);
    pwmSetRange(1000);
    pwmSetClock(64);
    setPulse(90);
}

void setPulse(int angle) {
    //TODO définir une loi de commande propre
    // Valeur_PWM = 1.1056*Angle + 64
    //Min = 64
    //Max = 263

    if (angle < 180 && angle > 0) {
        pwmWrite(SERVO, round(1.1056*angle + 64));
    } else {
        printf("Error with angle : %d", angle);
    }
}

//Attention avec cette fonction, le signal recu doit être périodique
// S'il recoit 5000 1 par seconde il va très vite atteindre sa valeur max
void incrementAngle(int* currentAngle) {
    if (*currentAngle < 180) {
        *currentAngle++;
        pwmWrite(SERVO, round(1.1056*(*currentAngle) + 64));
    }
}

void decrementAngle(int* currentAngle) {
    if (*currentAngle > 0) {
        *currentAngle--;
        pwmWrite(SERVO, round(1.1056*(*currentAngle) + 64));
    }
}

//void setRightAngle() {
//    setPulse(0);
//}
//
//void setCenterAngle() {
//    setPulse(90);
//}
//
//void setLeftAngle() {
//    setPulse(180);
//}
