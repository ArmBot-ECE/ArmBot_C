//
//  servoMotorControl.h
//  RaspberryPi
//
//  Created by Boulon Marie on 09/11/2020.
//  Copyright © 2020 Troyan Hugo. All rights reserved.
//

#ifndef servoMotorControl_h
#define servoMotorControl_h

#include <stdio.h>

int setServoMotor(int *angle, int *timeSetAngle);
void initializeServoMotor(void);
void setLeftAngle(void);
void setRightAngle(void);
void setCenterAngle(void);
void setPulse(int angle);

#endif /* servoMotorControl_h */
