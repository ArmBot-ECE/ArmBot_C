//
//  commandInterface.c
//  RaspberryPi
//
//  Created by Troyan Hugo on 04/01/2022.
//  Copyright © 2022 Troyan Hugo. All rights reserved.
//

#include "commandInterface.h"
#include "../models/servoMotorControl.h"
#include "../models/stepperMotorControl.h"
#include <stdio.h>
#include <stdlib.h>



/*
    move forward for X cm
*/
void moveForwardButton() {

}

/*
    move backward for X cm
*/
void moveBackwardButton() {
    // TODO
    // Do something on stepper and servo
//    setPulseServo(0, 1);
//    delay(1000);
//    setPulseServo(90, 1);
//    delay(1000);
//    setPulseServo(180, 1);
//    delay(1000);

}

/*
    left rotation for X ° cm ?
*/
void leftRotationButton() {

}

/*
    right rotation for X ° cm ?
*/
void rightRotationButton() {

}

/*
    move up for X cm
*/
void moveUp() {
    setDirectionStepper(2, 1);
    for(int i=0; i<50; i++) {
        rotateStepper(2);
        delay(5);
    }
}

/*
    move down for X cm
*/
void moveDown() {
    setDirectionStepper(2, 0);
    for(int i=0; i<50; i++) {
        rotateStepper(2);
        delay(5);
    }
}

/*
    move right for X cm
*/
void moveRight() {
    setDirectionStepper(1, 0);
    for(int i=0; i<50; i++) {
        rotateStepper(1);
        delay(5);
    }
}

/*
    move left for X cm
*/
void moveLeft() {
    setDirectionStepper(1, 1);
    for(int i=0; i<50; i++) {
        rotateStepper(1);
        delay(5);
    }
}
