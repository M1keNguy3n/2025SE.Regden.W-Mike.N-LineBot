#include "LineDetection.h"
#include "Control.h"
#include "Movement.h"
#include "ObstacleDetection.h"

Movement movement(5, 6); 
Control control; 
LineDetection lineDetection(A0, A1); 
ObstacleDetection obstacleDetection(2, 3); // Adjust pins as needed 
 
void setup() { 
    movement.init(); 
    control.init(); 
    lineDetection.init(); 
    obstacleDetection.init(); 
     
    control.displayVersion("1.00.00"); 
} 
 
void loop() { 
    int leftAnalog = lineDetection.readLeftAnalog(); 
    int rightAnalog = lineDetection.readRightAnalog(); 
    long distance = obstacleDetection.getDistance(); 
 
    bool onBlack = (leftAnalog < 512 && rightAnalog < 512); 
    control.displayLineStatus(onBlack); 
 
    if (distance < 10) { // If an obstacle is detected within 10 cm 
        movement.stop(); 
        delay(500); // Pause to avoid collision 
        // Implement obstacle avoidance logic 
        movement.turnRight(2300, 1000); // Example: turn right to avoid 
    } else if (onBlack) { 
        movement.moveForward(2300, 1000); 
    } else if (leftAnalog < 512) { 
        int speedAdjustment = map(leftAnalog, 0, 1023, 2300, 1500); 
        movement.turnRight(speedAdjustment, 1000); 
    } else if (rightAnalog < 512) { 
        int speedAdjustment = map(rightAnalog, 0, 1023, 2300, 1500); 
        movement.turnLeft(speedAdjustment, 1000); 
    } else { 
        movement.stop(); 
    } 
} 