#include "master.h"
#include <iostream> // not used currently
#include <cmath>   // Include cmath library for sqrt function
#include "autons/chassis.hpp"

// constants for the speed of the robot
const int DRIVE_SPEED = 100;
int INTAKE_DURATION{1000}; // duration of intake before stopping
int INTAKE_SPEED{150}; // for the speed of the intakezzz
// Function to grab the ball
void moveForward(double inches,int speed) {
  chassis.set_drive_pid(inches, speed);
  chassis.wait_drive();
}
void moveBackward(double inches, int speed) {
  chassis.set_drive_pid(-inches, speed);
  chassis.wait_drive();
}
// the move parameter is if moveing forward would help grab the ball for example if the ball if against a barrier, the same for realeing the ball
void grabBall(int speed, int duration, bool move, int dis) {
  intake.move(speed);
  intake2.move(-speed);
  if(move){
    moveForward(dis,DRIVE_SPEED);
  }
  pros::delay(duration);
  intake.move(0);
  intake2.move(0);
}

void releaseBall(int speed, int duration,bool move, int dis) {
  intake.move(-speed);
  intake2.move(speed);
  if(move){
    moveForward(dis,DRIVE_SPEED);
  }
  pros::delay(duration);
  intake.move(0);
  intake2.move(0);
}


void turn(int speed, int degrees) {
  chassis.set_turn_pid(degrees, speed);
  chassis.wait_drive();
}
void autonomousPath() {
  moveForward(36, DRIVE_SPEED);
  releaseBall(INTAKE_SPEED, INTAKE_DURATION, false, 0);
  moveForward(10,DRIVE_SPEED);
  moveBackward(10,DRIVE_SPEED);
  turn(DRIVE_SPEED, -45);
  moveForward(40,DRIVE_SPEED);
  grabBall(INTAKE_SPEED, INTAKE_DURATION, false, 0);
  turn(135,DRIVE_SPEED);
  moveForward(24,DRIVE_SPEED);
  releaseBall(INTAKE_SPEED, INTAKE_DURATION, true, 10);
  //moveForward(10,DRIVE_SPEED);
  moveBackward(10,DRIVE_SPEED);
  turn(DRIVE_SPEED,180);
  moveForward(40,DRIVE_SPEED);
  grabBall(INTAKE_SPEED, INTAKE_DURATION, true, 10);
  moveBackward(10,DRIVE_SPEED);
  turn(DRIVE_SPEED,180);
  releaseBall(INTAKE_SPEED, INTAKE_DURATION, true, 40);


}