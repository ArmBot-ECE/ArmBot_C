//
//  Ultrason.h
//  RaspberryPi
//
//  Created by Troyan Hugo on 05/01/2022.
//  Copyright © 2022 Troyan Hugo. All rights reserved.
//

#ifndef Ultrason_h
#define Ultrason_h

#include <stdio.h>

void initializeUS_sensor(void);
int getDistance(void);
void testDistance(int *distance);

#endif /* Ultrason_h */
