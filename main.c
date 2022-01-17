//
//  servoMotorControl.c
//  RaspberryPi
//
//  Created by Troyan Hugo on 04/01/2022.
//  Copyright © 2022 Troyan Hugo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
//Include C files
#include "servoMotorControl.c"
#include "DCMotor.c"
#include "Ultrason.c"

// Include prototype function
void initialize_AllFunctions();

// Commande pour compiler :
//gcc -o main main.c -lwiringPi -lrt -lpthread -lm -lrt -lcrypt

int main(int argc, char *argv[]){
    
    // Initialize all sensors and functions
    initialize_AllFunctions();

    // Distance of 4 ultrasonic sensors
    int *distanceSensors;

    printf("------------------------------------------------\n");
    printf("-                 Armbot Ready                 -\n");
    printf("------------------------------------------------\n\n");
    
    while (1) {
        distance = getDistance();

        if(*distance[0] == 1000000 && *distance[1] == 1000000 && *distance[2] == 1000000 && *distance[3] == 1000000) {
            printf("No obstacle found\n\n");
        } else {
            if(*distance[0] != 1000000) {
                printf("Obstacle found by sensor 1, distance : %d\n", *distance[0]);
            }
            if(*distance[1] != 1000000) {
                printf("Obstacle found by sensor 2, distance : %d\n", *distance[1]);
            }
            if(*distance[2] != 1000000) {
                printf("Obstacle found by sensor 3, distance : %d\n", *distance[2]);
            }
            if(*distance[3] != 1000000) {
                printf("Obstacle found by sensor 4, distance : %d\n", *distance[3]);
            }

        }
        //Sleep for 200ms
        delay(200);
    }

    //We shouldn't be here
    return 1;
}

void initialize_AllFunctions(){
    printf("------------------------------------------------\n");
    printf("-  Starting initialize all peripheral devices  -\n");
    printf("------------------------------------------------\n");

    // Setup de wiringPi
    wiringPiSetup();

    // Setup DC motors
//    initializeDCMotors();
    
    // Setup ultrasonic sensor
    printf("* Initializing ultrasonic sensor...\n");
    initializeUS_sensor();

    // Setup servo motor
    printf("* Initializing servomotors...\n");
    initializeServoMotor();

    printf("------------------------------------------------\n");
    printf("-             Initialize complete              -\n");
    printf("------------------------------------------------\n\n\n");
}
