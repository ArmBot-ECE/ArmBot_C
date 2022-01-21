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
#include "models/servoMotorControl.c"
#include "models/Ultrason.c"
#include "models/bluetooth.c"
#include "models/stepperMotorControl.c"

// Include prototype function
void initialize_AllFunctions();
void checkDistance();

// Command to compile with gcc:
// gcc -o main main.c -lwiringPi -lrt -lpthread -lm -lrt -lcrypt



// --------------------------------------
// -              MAIN                  -
// --------------------------------------

int main(int argc, char *argv[]){

    // Initialize all sensors and functions
    initialize_AllFunctions();

    //Current angle of each servomotors
    int *currentAngle1, *currentAngle2, *currentAngle3;
    // Distance of 4 ultrasonic sensors
    int *distanceSensors;


    while (1) {
        // TODO Retrieve action sent by the smartphone
        // getCommand();
        // Check for obstacles with ultrasonic sensors
//        checkDistance();

        printf("* Moving 1st steppermotor...\n");
        for(int i=0; i<200; i++) {
            incrementAngleStepper(1);
            delay(10);
        }

        for(int i=0; i<200; i++) {
            decrementAngleStepper(1);
            delay(10);
        }

        printf("* Moving 2nd steppermotor...\n");
        for(int i=0; i<200; i++) {
            incrementAngleStepper(2);
            delay(10);
        }

        for(int i=0; i<200; i++) {
            decrementAngleStepper(2);
            delay(10);
        }

        // TODO Action moveServomotor by 5° for example and check for distance again
        // Do action on motors
        //incrementAngle
        // Sleep for 200ms
        delay(1000);
    }

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

    // Setup wiringPi
    wiringPiSetup();

    // Setup steppermotors
    printf("* Initializing steppermotors...\n");
    initializeStepperMotor();

    // Setup ultrasonic sensors
    printf("* Initializing ultrasonic sensors...\n");
    initializeUS_sensor();

    // Setup servomotors
    printf("* Initializing servomotors...\n");
    initializeServoMotor();

    printf("------------------------------------------------\n");
    printf("-             Initialize complete              -\n");
    printf("------------------------------------------------\n\n\n");
}

/*
    Check distance of all 4 ultrasonic sensors to make
    sure there is no obstacle
*/
void checkDistance(int *distanceSensors) {
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
}

