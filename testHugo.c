#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
//Include C files
#include "servoMotorControl.c"
//#include "camera_V2.c"
#include "DCMotor.c"
#include "Ultrason.c"

// Commande pour compiler :
//gcc -o testHugo testHugo.c -lwiringPi -lrt -lpthread -lm -lrt -lcrypt

int main(int argc, char *argv[]){
    // Setup de wiringPi
    wiringPiSetup();
/*
    initializeUS_sensor();
    while(1){
        printf("Test");
        int dist = getDistance();
        printf("La distance : %d", dist);
    }
*/


// ------------------ DC Motors OK ----------------------
/*
    initializeDCMotors();
    printf("Move forward\n");
    moveForward();
    printf("Move backward\n");
    moveBackward();
    printf("Turn left\n");
    turnLeft();
    printf("Turn right\n");
    turnRight();

        //Mise de la pin GPIO 17 en sortie
    pinMode(15, OUTPUT);
    digitalWrite(15, 0);
    delay(500);
    digitalWrite(15,1);
    delay(500);
    digitalWrite(15,0);
*/

//--------------- Ultrason ----------------------
/*             NOK
    initializeUS_sensor();
    for(int i = 0; i < 100; i++){
        int distance = getDistance();
        printf("Distance : %d\n", distance);
        delay(100);
    }
    
*/

//------------------- Servo motor ------------------
    initializeServoMotor();
    printf("Central position \n");
    delay(500);
    printf("Look right\n");
    setRightAngle();
    delay(500);
    printf("Look left\n");
    setLeftAngle();
    delay(500);
    printf("Back to central position\n");
    setCenterAngle();
    
    return 0;
}
