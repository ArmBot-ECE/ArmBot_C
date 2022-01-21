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
int incrementAngleStepper(int stepperMotorPosition);
int decrementAngleStepper(int stepperMotorPosition);

#endif /* stepperMotorControl_h */
