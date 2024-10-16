#ifndef OBSTACLE_DETECTION_H 
#define OBSTACLE_DETECTION_H 
 
class ObstacleDetection { 
private: 
    int trigPin; 
    int echoPin; 
 
public: 
    ObstacleDetection(int trigPin, int echoPin); 
    void init(); 
    long getDistance(); 
}; 
 
#endif