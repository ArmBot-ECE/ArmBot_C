                                                                                                                                   //
//  DCMotor.c
//  RaspberryPi
//
//  Created by Boulon Marie on 09/11/2020.
//  Copyright © 2020 Troyan Hugo. All rights reserved.
//

#include "DCMotor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>


// Pin de controle du moteur 1
#define Motor1InputA    8 // GPIO 2
#define Motor1InputB    9 // GPIO 3
#define Motor1Enable    7 // GPIO 4

// Pin de controle du moteur 2
#define Motor2InputA    12 // GPIO 10
#define Motor2InputB    13 // GPIO 9
#define Motor2Enable    14 // GPIO 11


// Un L293D est nécessaire afin de piloter les moteurs dans les 2 sens

// A MODIFIER : TPSACTIONMOTEUR s'il est bien reglé
// Peut etre le sortir du fichier


void initializeDCMotors()
{
    // Motor 1
    pinMode(Motor1InputA, OUTPUT);
    pinMode(Motor1InputB, OUTPUT);
    pinMode(Motor1Enable, OUTPUT);
    // Motor 2
    pinMode(Motor2InputA, OUTPUT);
    pinMode(Motor2InputB, OUTPUT);
    pinMode(Motor2Enable, OUTPUT);

    // No move
    digitalWrite(Motor1Enable,0);
    digitalWrite(Motor2Enable,0);
}


void moveForward() {
    
    printf("Forward...\n");
    // La rotation est effectuée sur le temps :TPSACTIONMOTEUR
    // Motor 1
    digitalWrite(Motor1Enable,1);
    digitalWrite(Motor1InputA,1);
    digitalWrite(Motor1InputB,0);
    // Motor 2
    digitalWrite(Motor2Enable,1);
    digitalWrite(Motor2InputA,1);
    digitalWrite(Motor2InputB,0);
}


void moveBackward() {
    
    // La rotation est effectuée sur le temps :TPSACTIONMOTEUR
    // Motor 1
    digitalWrite(Motor1Enable,1);
    digitalWrite(Motor1InputA,0);
    digitalWrite(Motor1InputB,1);
    // Motor 2
    digitalWrite(Motor2Enable,1);
    digitalWrite(Motor2InputA,0);
    digitalWrite(Motor2InputB,1);
}


void turnLeft() {
    
    // La rotation est effectuée sur le temps :TPSACTIONMOTEUR
    // Motor 1
    digitalWrite(Motor1Enable,1);
    digitalWrite(Motor1InputA,0);
    digitalWrite(Motor1InputB,1);
    // Motor 2
    digitalWrite(Motor2Enable,1);
    digitalWrite(Motor2InputA,1);
    digitalWrite(Motor2InputB,0);
    
    // Stop motion
    delay(500);
    digitalWrite(Motor1Enable,0);
    digitalWrite(Motor2Enable,0);

}

void turnRight() {
    // La rotation est effectuée sur le temps :TPSACTIONMOTEUR
    // Motor 1
    digitalWrite(Motor1Enable,1);
    digitalWrite(Motor1InputA,1);
    digitalWrite(Motor1InputB,0);
    // Motor 2
    digitalWrite(Motor2Enable,1);
    digitalWrite(Motor2InputA,0);
    digitalWrite(Motor2InputB,1);
    
    // Stop motion
    delay(500);
    digitalWrite(Motor1Enable,0);
    digitalWrite(Motor2Enable,0);

}


void stopMotors() {
    // Stop motors
    digitalWrite(Motor1Enable,0);
    digitalWrite(Motor2Enable,0);
}
