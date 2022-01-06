//test pour afficher la distance en cm avec le capteur ultrason

#include <stdio.h>
#include <stdlib.h>
#include "Ultrason.h"
#include <wiringPi.h>

#define TRIG 4 // GPIO 23 - pin 16
#define ECHO 5 // GPIO 24 - pin 18


void initializeUS_sensor() {
    // I/O
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);

    //TRIG starts LOW
    digitalWrite(TRIG, LOW);
    delay(30);
}
 
int getDistance() {

    int distance;

    // Send trig pulse
    digitalWrite(TRIG, HIGH);
    // Pulse 20 microsec long
    delayMicroseconds(20);
    // Back to LOW
    digitalWrite(TRIG, LOW);
    // Wait for echo start during ~2000 µs
    int isSignalBack = 0;
    for (int i = 0; i < 2000; i++) {
        if (digitalRead(ECHO) == HIGH) {
            isSignalBack = 1;
            break;
        }
        delayMicroseconds(1);
    }
    //while(digitalRead(ECHO) == LOW);
    
    // If we have an echo we calculate travelTime
    if (isSignalBack) {
        //Wait for echo end
        long startTime = micros();
        while(digitalRead(ECHO) == HIGH);
        long travelTime = micros() - startTime;

        //Get distance in cm
        distance = travelTime / 58;
    }
    else {
        distance = 1000000;
    }

    return distance;
}

/*
int printDistance(){

    while(1)
    {
        int dist=getDistance();
        printf("Distance: %dcm\n", dist);
        LED(dist);
        delay(500);
    }
    return 0;
}

*/
