#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
//Include C files
#include "servoMotorControl.c"
#include "camera_V2.c"
#include "DCMotor.c"
#include "Ultrason.c"
#include "Led.c"

// Include prototype function
void initialize_AllFunctions();

// Commande pour compiler :
//gcc -o main main.c -lwiringPi -lrt -lpthread -lm -lrt -lcrypt


// A MODIFIER  : le delay lors du move sur la gauche ou la droite (l50-60)
// le setServoMotor qui bloque assez longtemps sans bloquer le processus et qu'il fasse la capteur de la distance ? (l30 - 40)
int main(int argc, char *argv[]){
    
    // Initialize all sensors and functions
    initialize_AllFunctions();
    
    int leftDistance;
    int rightDistance;
    int centerDistance;
    
    while (1)
    {

        //Start first move by checking best direction to go

/* ----------------------------------------------------
*  -         Check left and right for direction       -
*  ---------------------------------------------------- */

        // Left check
        setLeftAngle();
        delay(1000);
        leftDistance = getDistance();
        delay(100);
        
        // Right check
        setRightAngle();
        delay(1000);
        rightDistance = getDistance();
        delay(100);
        
        // Back to center position
        setCenterAngle();
        delay(1000);
        centerDistance = getDistance();
        delay(100);

        //----- Compare distance for direction -------
        //Move forward if nothing blocks the way
        if(centerDistance == 1000000){
            moveForward();
        }
        else if (leftDistance == rightDistance) {
        // It can be right or left so let's say right because right is always right ;)
            turnRight();
            delay(1000);
        }
        else if (leftDistance > rightDistance) {
            turnLeft();
            delay(1000);
        }
        else if (leftDistance < rightDistance) {
            turnRight();
            delay(1000);
        }
        

/* ----------------------------------------------------
*  -     Move forward until it reaches an obstacle    -
*  ---------------------------------------------------- */
        
        // Moving = green LED
        LedGreen();
        
        // Start to check distance
        centerDistance = getDistance();

        // Move forward until obstacle
        while(centerDistance > 30) {
// il faudrait afficher la distance dans la console sans spam de milliers de print par seconde...
            //printf("Distance: %dcm\n", dist);
            moveForward();
            centerDistance = getDistance();
        }
        // Stop motors
        stopMotors();
        // Stop = red light
        LedRed();
        // Take a picture
        initializeCamera();   
    // Back to beginning of loop 
    }

    printf("Exiting the loop.\nA problem happened...\n");
    return 0;
}

void initialize_AllFunctions(){
    // Setup de wiringPi
    wiringPiSetup();

    // Setup camera
    initializeCamera();

    // Setup DC motors
    initializeDCMotors();
    
    // Setup ultrasonic sensor
    initializeUS_sensor();
    
    // Setup servo motor
    initializeServoMotor();
    
    // Setup led
    initialize_Led();
}
