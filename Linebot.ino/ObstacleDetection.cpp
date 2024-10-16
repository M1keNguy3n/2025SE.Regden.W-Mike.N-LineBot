#include "ObstacleDetection.h" 
#include <Arduino.h> 
 
ObstacleDetection::ObstacleDetection(int trigPin, int echoPin) : trigPin(trigPin), echoPin(echoPin) {} 
 
void ObstacleDetection::init() { 
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
} 
 
long ObstacleDetection::getDistance() { 
    long duration, distance; 
     
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW); 
     
    duration = pulseIn(echoPin, HIGH); 
    distance = (duration / 2) * 0.0344; // Convert to cm 
     
    return distance; 
}