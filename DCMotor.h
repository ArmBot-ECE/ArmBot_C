//
//  DCMotor.h
//  RaspberryPi
//
//  Created by Troyan Hugo on 05/01/2022.
//  Copyright © 2022 Troyan Hugo. All rights reserved.
//

#ifndef DCMotor_h
#define DCMotor_h

#include <stdio.h>

void initializeDCMotors(void);
void moveForward(void);
void moveBackward(void);
void turnLeft(void);
void turnRight(void);
void stopMotors(void);

#endif /* DCMotor_h */
