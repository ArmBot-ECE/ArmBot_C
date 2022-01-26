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
#include "models/servoMotorControl.c"
#include "models/Ultrason.c"
#include "models/bluetooth.c"
#include "models/stepperMotorControl.c"
#include "controllers/commandInterface.c"

// Include prototype function
void initialize_GPIODevices();
void checkDistance();
_Bool startServerBluetooth(void);

// Command to compile with gcc:
// gcc -o main main.c -lwiringPi -lrt -lpthread -lm -lrt -lcrypt -lbluetooth


// --------------------------------------
// -              MAIN                  -
// --------------------------------------

int main(int argc, char *argv[]){
    // TODO Security

    // Initialize all sensors and functions
    initialize_GPIODevices();


    //Current angle of each servomotors
    int *currentAngle1, *currentAngle2, *currentAngle3;
    // Distance of 4 ultrasonic sensors
    int *distanceSensors;

    bool success = startServerBluetooth();

    // TODO Warning exit program
    // We shouldn't be here
    return 1;
}




/*
        CONTROLLER METHODS
*/

void initialize_GPIODevices(){
    printf("------------------------------------------------\n");
    printf("-     Starting initialize all GPIO devices     -\n");
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
    printf("-             Initialize completed             -\n");
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

bool startServerBluetooth() {
    // TODO modifier la taille du buf si possible
    char buf[1024] = { 0 };
    int s, bytes_read = -1;
    int client = init_server();
    int port = 3;

    do {
        // read data from the client
        memset(buf, 0, sizeof(buf));
        bytes_read = read(client, buf, sizeof(buf));

        /* ---------------------------------------------------
         *
         * ---------------------------------------------------
         */
        if( bytes_read > 0 ) {
            printf("received [%s]\n", buf);
//            checkDistance();
//            if () {
//                printf("Attention");
//                continue;
//            }
            switch (buf[0]) {
                case '1':
                    printf("Moving up...\n");
                    moveForwardButton();
                    break;
                case '2':
                    printf("Moving down...\n");
                    moveForwardButton();
                    break;
                case '6':
                    printf("Moving backward...\n");
                    moveBackwardButton();
                    break;
                case '7':
                    printf("Left rotation...\n");
                    leftRotationButton();
                    break;
                case '8':
                    printf("Right rotation...\n");
                    rightRotationButton();
                    break;
                default:
                    printf("Default\n");
                    break;
//
            }
        }
    } while (bytes_read > 0);

    // close connection
    printf("Closing connection.\n");
    close(client);
    close(s);
    //sdp_close( session );

    return true;
}

