//
//  Ultrason.c
//  RaspberryPi
//
//  Created by Troyan Hugo on 05/01/2022.
//  Copyright © 2022 Troyan Hugo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Ultrason.h"
#include <wiringPi.h>

#define TRIG 4 // GPIO 23 - pin 16

// First ultrasonic sensor
#define ECHO1 5 // GPIO 24 - pin 18
// Second ultrasonic sensor
#define ECHO2 6 // GPIO 25 - pin 22
// Third ultrasonic sensor
#define ECHO3 10 // GPIO 8 - pin 24
// Fourth ultrasonic sensor
#define ECHO4 11 // GPIO 7 - pin 26

/*
    Initialize all pins for ultrasonic sensors
*/
void initializeUS_sensor() {
    // I/O
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO1, INPUT);
    pinMode(ECHO2, INPUT);
    pinMode(ECHO3, INPUT);
    pinMode(ECHO4, INPUT);

    //TRIG starts LOW
    digitalWrite(TRIG, LOW);
    delay(30);

}


/*
    Get distance for all 4 sensors
*/
int *getDistance() {

    // Distance variable for each ultrasonic sensors
    static int distance[4];

    printf("-------------------------\n");
    printf("-    Getting distance   -\n");
    printf("-------------------------\n");

    printf("-------------------------\n");
    printf("-    Getting distance   -\n");
    printf("-------------------------\n");

    distance[0] = checkForDistance(1);
    printf("1");
    distance[1] = checkForDistance(2);
    distance[2] = checkForDistance(3);
    distance[3] = checkForDistance(4);

    return distance;
}


/*
    Private function to get distance for each ultrasonic sensor
*/
int checkForDistance(int sensorPosition) {

    printf("1");
    char isSignalBack = 0;
    int sensorPinEcho;
    int distance;


    switch (sensorPosition) {
        case 1:
            sensorPinEcho = ECHO1;
            break;
        case 2:
            sensorPinEcho = ECHO2;
            break;
        case 3:
            sensorPinEcho = ECHO3;
            break;
        case 4:
            sensorPinEcho = ECHO4;
            break;
        default:
            sensorPinEcho = ECHO1;
            break;
    }

    printf("2");
    // Send trig pulse to all sensors
    digitalWrite(TRIG, HIGH);
    // Pulse 20 microsec long
    delayMicroseconds(20);
    // Back to LOW
    digitalWrite(TRIG, LOW);

    // Wait for echo start during ~2000 µs
    for (int i = 0; i < 2000; i++) {
        if (digitalRead(sensorPinEcho) == HIGH) {
            isSignalBack = 1;
            break;
        }
        delayMicroseconds(1);
    }

    printf("3");
    // If we have an echo we calculate travelTime
    if (isSignalBack) {
        //Wait for echo end
        long startTime = micros();
        while(digitalRead(sensorPinEcho) == HIGH);
        long travelTime = micros() - startTime;

        //Get distance in cm
        distance = travelTime / 58;
    }
    else {
        distance = 1000000;
    }

    return distance;
}