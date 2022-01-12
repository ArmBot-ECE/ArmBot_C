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


// A MODIFIER  : le delay lors du move sur la gauche ou la droite (l50-60)
// le setServoMotor qui bloque assez longtemps sans bloquer le processus et qu'il fasse la capteur de la distance ? (l30 - 40)
int main(int argc, char *argv[]){
    
    // Initialize all sensors and functions*
    initialize_AllFunctions();
    
    int leftDistance;
    int rightDistance;
    int centerDistance;

    int distance;
    
    while (1)
    {

//        //Start first move by checking best direction to go
//
///* ----------------------------------------------------
//*  -         Check left and right for direction       -
//*  ---------------------------------------------------- */
//
//        // Left check
////        setLeftAngle();
//        delay(1000);
//        leftDistance = getDistance();
//        delay(100);
//
//        // Right check
////        setRightAngle();
//        delay(1000);
//        rightDistance = getDistance();
//        delay(100);
//
//        // Back to center position
////        setCenterAngle();
//        delay(1000);
//        centerDistance = getDistance();
//        delay(100);
//
//        //----- Compare distance for direction -------
//        //Move forward if nothing blocks the way
//        if(centerDistance == 1000000){
//            moveForward();
//        }
//        else if (leftDistance == rightDistance) {
//        // It can be right or left so let's say right because right is always right ;)
//            turnRight();
//            delay(1000);
//        }
//        else if (leftDistance > rightDistance) {
//            turnLeft();
//            delay(1000);
//        }
//        else if (leftDistance < rightDistance) {
//            turnRight();
//            delay(1000);
//        }
//
//
///* ----------------------------------------------------
//*  -     Move forward until it reaches an obstacle    -
//*  ---------------------------------------------------- */
//
//        // Start to check distance
//        centerDistance = getDistance();
//
//        // Move forward until obstacle
//        while(centerDistance > 30) {
//// il faudrait afficher la distance dans la console sans spam de milliers de print par seconde...
//            //printf("Distance: %dcm\n", dist);
//            moveForward();
//            centerDistance = getDistance();
//        }
//        // Stop motors
//        stopMotors();
//
//    // Back to beginning of loop
//    }
//
//    printf("Exiting the loop.\nA problem happened...\n");

    distance = getDistance();
    if(distance == 1000000) {
        printf("No obstacle found\n\n");
    } else {
        printf("Distance : %d\n\n", distance);
    }
    //Sleep for 500ms
    delay(5000);

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

    // TODO handle errors during initialization
    printf("Done\n\n");
}
