#ifndef PID_FUNC_HPP
#define PID_FUNC_HPP

#include "master.h"

// Function to get the average distance traveled by the left and right drive motors
double getEncoderDistance();

// Function to reset the encoders of the left and right drive motors
void resetEncoders();

// Function to set the power of the left and right drive motors
void setMotorPower(double power);

// Function to stop the left and right drive motors
void stopMotors();

// Function to check if the robot has reached a target distance
bool isMovementComplete(double targetDistance);

#endif 
