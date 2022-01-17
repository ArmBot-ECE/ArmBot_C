//
//  servoMotorControl.h
//  RaspberryPi
//
//  Created by Troyan Hugo on 04/01/2022.
//  Copyright © 2022 Troyan Hugo. All rights reserved.
//

#ifndef servoMotorControl_h
#define servoMotorControl_h

#include <stdio.h>

int setPulse(int angle, int servomotorPosition)
void initializeServoMotor(void);
void incrementAngle(int *currentAngle);
void decrementAngle(int *currentAngle);

#endif /* servoMotorControl_h */
