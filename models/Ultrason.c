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
#define ECHO3 27 // GPIO 16 - pin 36
// Fourth ultrasonic sensor
#define ECHO4 28 // GPIO 20 - pin 38

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
int *getAllDistances() {

    // Distance variable for each ultrasonic sensors
    static int distance[4];

    printf("-------------------------\n");
    printf("-    Getting distance   -\n");
    printf("-------------------------\n");

    distance[0] = getDistance(1);
    distance[1] = getDistance(2);
    distance[2] = getDistance(3);
    distance[3] = getDistance(4);

    return distance;
}


/*
    Private function to get distance for each ultrasonic sensor
*/
int getDistance(int sensorPosition) {

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