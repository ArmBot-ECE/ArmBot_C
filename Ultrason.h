//
//  Ultrason.h
//  RaspberryPi
//
//  Created by Boulon Marie on 09/11/2020.
//  Copyright © 2020 Troyan Hugo. All rights reserved.
//

#ifndef Ultrason_h
#define Ultrason_h

#include <stdio.h>

void initializeUS_sensor(void);
int getDistance(void);
void testDistance(int *distance);

#endif /* Ultrason_h */
