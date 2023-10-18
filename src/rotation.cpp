#include "master.h"
#include <iostream>
#include <cmath>

double calculate(int a, int x) {
    double y = a * pow((x / 36000.0), 2);
    return y;
}

double convertCentidegrees(int x) {
    const double a = 4;
    double y = a * pow((x / 36000), 2);
    return y;
}

void rotationSensorTask(void* param) {
    pros::Rotation rotation_sensor(1); 
    while (true) {
        int centidegrees = rotation_sensor.get_position();// not sure how to get position from sensor pretty sure that this is not the method
        double value = convertCentidegrees(centidegrees);
        pros::delay(20);  
    }
}