#pragma once

#include "master.h"
void swing(int speed, int degrees, bool right);
void  turn(int speed, int degrees, bool right);
void moveForward(double inches,int speed);
void moveForward(double inches,int speed);
void startintake(int speed);
void stopIntake();
void releaseBall(int speed, int duration,bool move, int dis);
void autonomousPath1();
void realease(int speed);
void testpath();
void curve_drive(int speed, int distance, int degrees_per_turn, int curvedegrees, bool right);
void autonomousPath2();
void Skills();
