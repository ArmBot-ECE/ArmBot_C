//
//  servoMotorControl.c
//  RaspberryPi
//
//  Created by Troyan Hugo on 04/01/2022.
//  Copyright © 2022 Troyan Hugo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  
#include <wiringPi.h>
//Include C files
/*#include "models/servoMotorControl.c"
#include "models/Ultrason.c"*/
#include "models/bluetooth.c"

// Include prototype function
/*void initialize_AllFunctions();
void checkDistance();*/

// Command to compile with gcc:
// gcc -o main main.c -lwiringPi -lrt -lpthread -lm -lrt -lcrypt -lbluetooth

// Global variables
//int *currentAngle1, *currentAngle2, *currentAngle3;



// --------------------------------------
// -              MAIN                  -
// --------------------------------------

int main(int argc, char *argv[]){

    // Initialize all sensors and functions
    /*initialize_AllFunctions();

    //Current angle of each servomotors
    int *currentAngle1, *currentAngle2, *currentAngle3;
    // Distance of 4 ultrasonic sensors
    int *distanceSensors;*/

    bool success = initializeBluetooth();

    /*while (1) {
        // TODO Security

        // TODO Retrieve action sent by the smartphone
        getCommand();
        // Check for obstacles with ultrasonic sensors
        checkDistance();

        // TODO Action moveServomotor by 5° for example and check for distance again
        // Do action on motors
        incrementAngle
        // Sleep for 200ms
        delay(200);
    }*/

    // We shouldn't be here
    return 1;
}




/*
        CONTROLLER METHODS
*/

void initialize_AllFunctions(){
    printf("------------------------------------------------\n");
    printf("-  Starting initialize all peripheral devices  -\n");
    printf("------------------------------------------------\n");

    /*// Setup wiringPi
    wiringPiSetup();

    // Setup DC motors
//    initializeDCMotors();
    
    // Setup ultrasonic sensor
    printf("* Initializing ultrasonic sensor...\n");
    initializeUS_sensor();

    // Setup servomotor
    printf("* Initializing servomotors...\n");
    initializeServoMotor();*/

    printf("------------------------------------------------\n");
    printf("-             Initialize complete              -\n");
    printf("------------------------------------------------\n\n\n");
}

/*
    Check distance of all 4 ultrasonic sensors to make
    sure there is no obstacle
*/
/*void checkDistance(int *distanceSensors) {
    // Fetch all distances from ultrasonic sensors
    // return an array of 4 integer
    distanceSensors = getAllDistances();

    // TODO Implement stopMotor if distance is < 3cm
    if(*distanceSensors == 1000000 && *(distanceSensors+1) == 1000000 && *(distanceSensors+2) == 1000000 && *(distanceSensors+3) == 1000000) {
        printf("No obstacle found\n\n");
    } else {
        if(*distanceSensors != 1000000) {
            printf("Obstacle found by sensor 1, distance : %d\n", *distanceSensors);
        }
        if(*(distanceSensors+1) != 1000000) {
            printf("Obstacle found by sensor 2, distance : %d\n", *(distanceSensors+1));
        }
        if(*(distanceSensors+2) != 1000000) {
            printf("Obstacle found by sensor 3, distance : %d\n", *(distanceSensors+2));
        }
        if(*(distanceSensors+3) != 1000000) {
            printf("Obstacle found by sensor 4, distance : %d\n", *(distanceSensors+3));
        }
    }
}*/

