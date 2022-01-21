//
//  stepperMotorControl.h
//  RaspberryPi
//
//  Created by Troyan Hugo on 04/01/2022.
//  Copyright © 2022 Troyan Hugo. All rights reserved.
//

#ifndef stepperMotorControl_h
#define stepperMotorControl_h

#include <stdio.h>

void initializeStepperMotor();
void decrementAngleStepper(int *currentAngle, int steppermotorPosition);
void incrementAngleStepper(int *currentAngle, int steppermotorPosition);
void incrementAngleTest();
void decrementAngleTest();

#endif /* stepperMotorControl_h */
