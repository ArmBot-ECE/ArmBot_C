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
void checkDistance();
void moveServomotor(int angle, int servomotorPosition);
void stopServomotor(int servomotorPosition);

// Command to compile with gcc:
// gcc -o main main.c -lwiringPi -lrt -lpthread -lm -lrt -lcrypt



// --------------------------------------
// -              MAIN                  -
// --------------------------------------

int main(int argc, char *argv[]){
    
    // Initialize all sensors and functions
    initialize_AllFunctions();

    //Current angle of each servomotors
    int *currentAngle1;
    int *currentAngle2;
    int *currentAngle3;

    while (1) {
        // Check for obstacles with ultrasonic sensors
        checkDistance();

        // TODO Action moveServomotor by 5° for example and check for distance again

        // Sleep for 200ms
        delay(200);
    }

    // We shouldn't be here
    return 1;
}






void initialize_AllFunctions(){
    printf("------------------------------------------------\n");
    printf("-  Starting initialize all peripheral devices  -\n");
    printf("------------------------------------------------\n");

    // Setup wiringPi
    wiringPiSetup();

    // Setup DC motors
//    initializeDCMotors();
    
    // Setup ultrasonic sensor
    printf("* Initializing ultrasonic sensor...\n");
    initializeUS_sensor();

    // Setup servomotor
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
void checkDistance() {
    // Distance of 4 ultrasonic sensors
    int *distanceSensors;

    distanceSensors = getDistance();

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

/*
    Rotate specific servomotor with an angle between 0° and 180°
*/
void moveServomotor(int angle, int servomotorPosition) {
    // Get order from smartphone

    // setPulse(int angle, int servomotorPosition);
    // incrementAngle(int *currentAngle);
    // decrementAngle(int *currentAngle);
}

/*
    Stop movement of specific servomotor
*/
void stopServomotor(int servomotorPosition) {
    // Cancel order to move received from the smartphone
    // Stop servo if moving
}