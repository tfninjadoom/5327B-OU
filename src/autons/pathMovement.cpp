#include "master.h"
#include <iostream> // not used currently
#include <cmath>   // Include cmath library for sqrt function
#include "autons/chassis.hpp"

// constants for the speed of the robot

const int DRIVE_SPEED = 100;
int INTAKE_DURATION{1000}; // duration of intake before stopping
int INTAKE_SPEED{150}; // for the speed of the intake
// Function to grab the ball
void moveForward(double inches,int speed) {
  chassis.set_drive_pid(inches*2, speed);
  chassis.wait_drive();
}
void moveBackward(double inches,int speed) {
  chassis.set_drive_pid(-inches, speed);
  chassis.wait_drive();
}
// the move parameter is if moveing forward would help grab the ball for example if the ball if against a barrier, the same for realeing the ball
void grabBall(int speed, int duration, bool move, int dis) {
  intake.move(-speed);
  intake2.move(speed);
  if(move){
    moveForward(dis,DRIVE_SPEED);
  }
  /*pros::delay(duration);
  intake.move(0);
  intake2.move(0);*/
}
void stopIntake(){
	intake.move(0);
  	intake2.move(0);
}
void open_LW(){
        Wing::extendLeft(true);
        Wing::left = true;

}

void open_RW(){
        Wing::extendRight(true);
        Wing::right = true;
}
void close_RW(){
    Wing::extendRight(false);
    Wing::right = false;

}
void close_LW(){

  Wing::extendLeft(false);
  Wing::left = false;
}
void open_BW(){
  Wing::extendLeft(true);
  Wing::left = true;
  Wing::extendRight(true);
  Wing::right = true;

}
void close_BW(){
   Wing::extendLeft(false);
  Wing::left = false;
  Wing::extendRight(false);
  Wing::right = false;

}
void releaseBall(int speed, int duration,bool move, int dis) {
  intake.move(speed);
  intake2.move(-speed);
  pros::delay(1000);
  if(move){
    moveForward(dis,DRIVE_SPEED);
  }
  /*pros::delay(duration);
  intake.move(0);
  intake2.move(0);*/
}


void swing(int speed, int degrees, bool right) {
  
  if(right){
  	
  	chassis.set_swing_pid(ez::RIGHT_SWING, degrees, speed);
  	chassis.wait_drive();
  }
  else{
	chassis.set_swing_pid(ez::LEFT_SWING, degrees, speed);
  	chassis.wait_drive();
  }
}

void  turn(int speed, int degrees, bool right) {
  
  if(right){
  	
  	chassis.set_turn_pid(-degrees, speed);
  	chassis.wait_drive();
  }
  else{
	chassis.set_turn_pid(degrees, speed);
  	chassis.wait_drive();
  }
}
int dd = 0;
void autonomousPath1() {
  moveForward(40, DRIVE_SPEED);
  releaseBall(INTAKE_SPEED, INTAKE_DURATION, false, 0);
  stopIntake();
  moveBackward(25, DRIVE_SPEED );
  turn(50, 180, true);
  moveBackward(40, DRIVE_SPEED);

  //moveBackward(15, DRIVE_SPEED);
  //turn(50, 45, true);
  /*grabBall(INTAKE_SPEED, INTAKE_DURATION, false, 0);
  moveForward(180, DRIVE_SPEED);
  stopIntake();
  turn(50, 135, false);
  moveForward(40, DRIVE_SPEED);
  releaseBall(INTAKE_SPEED, INTAKE_DURATION, false, 0);
  moveForward(10, DRIVE_SPEED);
  pros::delay(1000);
  return;
  //moveForward(10,DRIVE_SPEED);
  //moveBackward(10,DRIVE_SPEED);
  /*turn(50, -45);
  moveForward(40,DRIVE_SPEED);
  grabBall(INTAKE_SPEED, INTAKE_DURATION, false, 0);
  turn(DRIVE_SPEED,135);
  moveForward(24,DRIVE_SPEED);
  releaseBall(INTAKE_SPEED, INTAKE_DURATION, true, 10);
  //moveForward(10,DRIVE_SPEED);
  moveBackward(10,DRIVE_SPEED);
  turn(DRIVE_SPEED,180);
  moveForward(40,DRIVE_SPEED);
  grabBall(INTAKE_SPEED, INTAKE_DURATION, true, 10);
  moveBackward(10,DRIVE_SPEED);
  turn(DRIVE_SPEED,180);
  releaseBall(INTAKE_SPEED, INTAKE_DURATION, true, 40);*/


}

void autonomousPath2() {
  // the code for the second autonomous path woudl go here
  }
void Skills() {

  moveForward(25, DRIVE_SPEED);
  turn(DRIVE_SPEED, 45, true);
  moveForward(55, DRIVE_SPEED);
  releaseBall(INTAKE_SPEED, INTAKE_DURATION, false, 0);
  moveBackward(25, DRIVE_SPEED);
  turn(DRIVE_SPEED, 135, false);

  grabBall(INTAKE_SPEED, INTAKE_DURATION, false, 200 );
  moveForward(30, DRIVE_SPEED);
  stopIntake();
  moveBackward(30, DRIVE_SPEED);
  turn(DRIVE_SPEED, 135, false);
  moveForward(25 DRIVE_SPEED);
  releaseBall(INTAKE_SPEED, INTAKE_DURATION, false, 200 );
  stopIntake();
  moveBackward(35, DRIVE_SPEED);
  turn(DRIVE_SPEED, 45, false);
  moveForward(30, DRIVE_SPEED);
  turn(DRIVE_SPEED, 90, true);
  open_BW()
  moveForward(100, DRIVE_SPEED);
}



