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
    setDirectionStepper(1, 1);
//    setDirectionStepper(2, 0);
    for(int i=0; i<50; i++) {
        rotateStepper(1);
        delay(5);
//        rotateStepper(2);
//        delay(5);
//        rotateStepper(2);
//        delay(5);
    }

}

/*
    move backward for X cm
*/
void moveBackwardButton() {
    // TODO
    // Do something on stepper and servo
    setPulseServo(90, 1);
    delay(200);
    setPulseServo(150, 1);
    delay(200);
    setPulseServo(10, 1);
}

/*
    left rotation for X ° cm ?
*/
void leftRotationButton() {
    // TODO
    // Do something on stepper and servo
}

/*
    right rotation for X ° cm ?
*/
void rightRotationButton() {
    // TODO
    // Do something on stepper and servo
}

/*
    move up for X cm
*/
void moveUp() {
    // TODO
    // Do something on stepper and servo
}

/*
    move down for X cm
*/
void moveDown() {
    // TODO
    // Do something on stepper and servo
}

/*
    move right for X cm
*/
void moveRight() {
    // TODO
    // Do something on stepper and servo
}

/*
    move left for X cm
*/
void moveLeft() {
    // TODO
    // Do something on stepper and servo
}
