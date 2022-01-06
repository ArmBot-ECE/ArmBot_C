//
//  servoMotorControl.c
//  RaspberryPi
//
//  Created by Troyan Hugo on 09/11/2020.
//  Copyright © 2020 Troyan Hugo. All rights reserved.
//

#include "servoMotorControl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>

#define SERVO 1 //Equivalent WiringPi 0 : GPIO 23

// Le servo moteur tourne avec un angle de 0 à 180° en fonction du signal PWM qu'on lui injecte.
// Le signal est carré de période 20 ms
// Un angle de 0 ° correspond a 1ms à l'état haut
// Un angle de 90° correspond a 1.5ms à l'état haut
// Un angle de 180° correspond a 2ms à l'état haut


void initializeServoMotor(){
    //set as PWM
    pinMode(SERVO, PWM_OUTPUT);
    //set MarkSpaced mode
    pwmSetMode(PWM_MODE_MS);

    //Frequency : 19.2MHz/ (PMWC * PWMR)
    //PWMR is range defined before (2-1024)
    //PWMC is clock divider
    // We want 50 Hz : 50 = 19.2MHz / (PWMC * PWMR)
    // PWMC = 192
    // PWMR = 2000
    // We start at angle 90° (central position)
    pwmSetRange(2000);
    pwmSetClock(192);
    setPulse(90);
}

void setPulse(int angle) {
    switch(angle){
        case 0 :
            pwmWrite(SERVO, 64);
            break;
        case 90 :
            pwmWrite(SERVO, 155);
            break;
        case 180 :
            printf("Left angle\n");
            pwmWrite(SERVO, 263);
            break;
        default:
            //Wrong angle sent : back to central position
            pwmWrite(SERVO, 155);
            break;
    }
}

void setLeftAngle() {
    setPulse(180);
}

void setRightAngle() {
    setPulse(0);
}

void setCenterAngle() {
    setPulse(90);
}
