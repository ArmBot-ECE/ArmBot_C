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

int setPulseServo(int angle, int servomotorPosition);
void initializeServoMotor(void);
void incrementAngleServo(int *currentAngle, int servomotorPosition);
void decrementAngleServo(int *currentAngle, int servomotorPosition);

#endif /* servoMotorControl_h */
