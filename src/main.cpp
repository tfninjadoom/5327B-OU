/**
 * @file main.cpp
 * @date 2023-10-11
 * 
 * @brief 
 * This is the main file of our program, with the initialize(), autonomous(),
 * disabled(), and opcontrol() functions.
 */
#include "master.h"
using namespace Controller;
// autonumous sections: 




const int DRIVE_SPEED = 100;
int INTAKE_DURATION{5000}; // duration of intake before stopping
int INTAKE_SPEED{150}; // for the speed of the intake


void moveForward(double inches,int speed, bool wait=true) {
	chassis.set_drive_pid(inches*2, speed);
  
	if (wait) { chassis.wait_drive(); }
}

void moveBackward(double inches, int speed, bool wait=true) {
	chassis.set_drive_pid(-inches*2, speed);
  
	if (wait) { chassis.wait_drive(); }
}

// the move parameter is if moveing forward would help grab the ball for example if the ball if against a barrier, the same for realeing the ball
void grabBall(int speed, int duration, bool move, int dis) {
  intake.move(speed);
  intake2.move(-speed);
  if(move){
    moveForward(dis,DRIVE_SPEED, true);
  }
  pros::delay(duration);
  intake.move(0);
  intake2.move(0);
}

void releaseBall(int speed, int duration,bool move, int dis) {
	intake.move(-speed);
	if(move){
		moveForward(dis,DRIVE_SPEED, true);
	}
	pros::delay(duration);
	intake.move(0);
}

void intakeOn(int speed){
	intake.move(-speed);
}	

void outtakeOn(int speed){
	intake.move(speed);
}

void intakeOff(){
	intake.move(0);
}

void outtakeOff(){
	intakeOff();
}

void turn(int speed, int degrees, bool left, bool wait=true) {
  
  if(right){
  	chassis.set_turn_pid(degrees, speed);
  }
  else{
	chassis.set_turn_pid(-degrees, speed);
  }

  if (wait) { chassis.wait_drive(); };
}

void swing(int speed, int degrees, bool left, bool wait=true) {
  
  if(right){
  	chassis.set_swing_pid(ez::RIGHT_SWING, degrees, speed);
  }
  else{
	chassis.set_swing_pid(ez::LEFT_SWING, degrees, speed);
  }

  if (wait) { chassis.wait_drive(); };
}

void fiveBallAuton(){
	// grab triball under elevation bar
	intakeOn(100);
	moveForward(5, 100);
	pros::delay(100);
	intakeOff();

	// move to goal
	moveBackward(45, 100);
	turn(100, 180, true);
	swing(100, 135, true);
	Wing::extendWings(true);
	moveForward(18, 127);
	swing(100, 90, true);
	
	// push
	outtakeOn(127);
	moveForward(25, 127, false);
	pros::delay(500);
	moveBackward(15, 100, false);
	pros::delay(500);
	moveForward(20, 127, false);
	pros::delay(500);
	intakeOff();
	pros::delay(100);

	// turn toward middle ball 1
	moveBackward(15, 100);
	Wing::extendWings(false);
	chassis.set_angle(90);
	turn(100, 19, true);
	
	// move toward middle ball 1
	moveForward(75, 100);
	pros::delay(100);
	intakeOn(100);
	moveForward(5, 100, false);
	pros::delay(500);
	intakeOff();
	
	// clockwise swing scoop to score 3 triballs
	moveBackward(10, 100);
	Wing::extendWings(true);
	swing(100, 180, false);
	outtakeOn(100);
	moveForward(100, 127, false);
	pros::delay(500);
	moveBackward(100, 10);
}

void unused_fiveBallAuton(){
  intakeOn(127);
  moveForward(7,100);
  //pros::delay(200);
  intakeOff();
  moveBackward(35, 100);
  turn(100, 180, true);
  //Wing::extendWings(true);
  moveForward(30, 100);
  turn(100, 155, true);
  outtakeOn(INTAKE_SPEED);
  moveForward(20, 100);
  turn(100, 10, true);
  moveForward(40, 120);
  moveBackward(20, 100);
  turn(100, 60, false);

  //Wing::extendWings(false);
  moveForward(40, 75);
  turn(100, 60, true);
  intakeOn(100);
  moveForward(30, 100);
  intakeOff();
  
  moveBackward(10, 75);
  /*turn(75, 75, false);
  //Wing::extendWings(true);
  moveForward(24, 75);
  turn(75, 90, true);
  outtakeOn(INTAKE_SPEED);
  moveForward(35, 125);
  pros::delay(300);
  moveBackward(15, 75);
  turn(75, 180, false);
  intakeOn(INTAKE_SPEED);
  moveForward(40, 75);
  pros::delay(200);
  intakeOff();
  moveBackward(10, 75);
  turn(75, 180, false);
  moveForward(40, 125);
  pros::delay(200);
  moveBackward(10, 75);
  */
}
void oneballAuton() {
 	moveForward(35, 100);
	outtakeOn(100);
	
	pros::delay(500);
	intakeOff();
	moveBackward(15, 100);
	turn(100, 160, true);
	moveBackward(35, 100);

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


void AWP(){

	moveBackward(45, 100);
	turn(100, 180, false);
	swing(100, 135, false);
	Wing::extendWings(true);
	moveForward(18, 127);
	swing(100, 90, false);
	turn(100, 45, false);
	moveForward(65, 40);

}




void skills(){
	//turn intake on for match loading
	intakeOn(20000);
	//extend wings to push balls
	Wing::extendWings(true);
	//turn off intake to push balls forward
	intakeOff();
	// move forward to push balls forward
	moveForward(100, 100);
	//turn to push balls into the goal
	turn(100, 45, true);
	//move forward to push the balls into the goal
	moveForward(35, 120);
	//close the wings so they don't et stuck when moving backwarda
	Wing::extendWings(false);	
	// move backwards to prepare to move back

	moveBackward(35, 100);
	//turn the opacite direction as before to reposition the robot
	turn(100,  45, false );
	//move backwards to get back to the starting position
	moveBackward(100, 100);
	// restart the process
	intakeOn(20000);
	Wing::extendWings(true);
	moveForward(100, 100);
	turn(100, 45, true);
	moveForward(35, 120);
	Wing::extendWings(false);
	moveBackward(35, 100);
	turn(100, 180, false);
	moveBackward(100, 100);

}



/**
 * A (boilerplate) callback function for LLEMU's center button.
 *
void on_center_button() {
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	}
} //*/

/**
 * Set up ALL sensors and tasks in this function.
 * Runs as soon as program is started.
 * 
 * @details 
 * Use this for any and all setup/startup code that is global to autonomous 
 * and driver control. All other competition modes are blocked by initialize, 
 * so keep execution time for this mode under a few seconds.
 */


void initialize() {


	// displays stuff on the brain screen
	pros::lcd::initialize();
        pros::lcd::set_text(1, "StickCurve::strong");
        pros::lcd::set_text(2, "DriveMode::arcade");
        // pros::lcd::register_btn1_cb(on_center_button);

	pros::delay(500); // Stop the user from doing anything while legacy ports configure

	//--------Piston Starting States---------//
	Wing::extendWings(false);
    Wing::extendElevation(false);

	//--------Chassis Configuration---------//
	//chassis.set_active_brake(0.1); 	// Sets active brake kP, recommended value 0.1.
	default_constants();			// 
	exit_condition_defaults();		// 

	chassis.initialize(); 
}

/**
 * Runs while robot is disabled before/during a competition match.
 * 
 * @details 
 * Runs while the robot is in the disabled state of Field Management System or 
 * the VEX Competition Switch, following either autonomous or opcontrol. When 
 * the robot is enabled, this task will exit.
 */
void disabled() {
	//------------Pistons------------//
	Wing::extendWings(false);
}

/**
 * Match-specific initialization routines.
 * Runs while robot is disabled at the beginning of a competition match.
 * 
 * @details 
 * Runs after initialize(), and before autonomous when connected to the Field 
 * Management System or the VEX Competition Switch. This is intended for 
 * competition-specific initialization routines, such as an autonomous 
 * selector on the LCD. Followed by autonomous() or opcontrol().
 */
void competition_initialize() {}

/**
 * Sets up, then runs selected autonomous function.
 * Called at the start of the autonomous mode.
 * 
 * @details 
 * This function will be started in its own task with the default priority and 
 * stack size whenever the robot is enabled via the Field Management System or 
 * the VEX Competition Switch in the autonomous mode. Alternatively, this 
 * function may be called in initialize or opcontrol for non-competition 
 * testing purposes.
 */
void autonomous() {
	//Autonomous::selection=Autonomous::Select::left;
	Wing::extendWings(false);
    Wing::extendElevation(false);

	chassis.reset_pid_targets();				// Resets PID targets to 0.
	chassis.reset_gyro();						// Resets gyro position to 0.
	chassis.reset_drive_sensor();				// Resets drive sensors to 0.
	chassis.set_drive_brake(MOTOR_BRAKE_COAST);	// Set motors to hold. This helps autonomous consistency.

	/*if 
	(Autonomous::selection==Autonomous::Select::left) 
	{ Autonomous::left(); } 
	else if 
	(Autonomous::selection==Autonomous::Select::right) 
	{ Autonomous::right(); } 
	else 
	{ Autonomous::skills(); }

	*/
	AWP();
	//fiveBallAuton();
}


//-----------DRIVER CONTROL------------//
/**
 * (Robot is driven by a human.) 
 * Run the robot based on controller and joystick inputs.
 * 
 * @details 
 * This function will be started in its own task with the default priority and 
 * stack size.
 */
void opcontrol() {

	DriveMode driveMode { DriveMode::arcade };

	StickCurve stickCurve { StickCurve::strong };

    int intakeMode { 0 };

    Wing::extendWings(false);
    Wing::extendElevation(false);

	//--------Chassis Reconfiguration---------//
	//chassis.set_active_brake(0);
	chassis.set_drive_brake(MOTOR_BRAKE_COAST);

	while (true) {
		// pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		//                 				(pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		//                 				(pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

        // drive modes
		if (driveMode == DriveMode::tank) {
			Drive1::tankDrive(stickCurve);
            pros::lcd::set_text(2, "DriveMode::tank");
        } else if (driveMode == DriveMode::arcade) {
			Drive1::arcadeDrive(stickCurve);
            pros::lcd::set_text(2, "DriveModepros ::arcade");
        } else if (driveMode == DriveMode::singleStick) {
			Drive1::singleStickDrive(stickCurve);
            pros::lcd::set_text(2, "DriveMode::singleStick");
        }


        // Intake
        if ( newPress(L1) ) {
			if (intakeMode != 1) {
				intake.move(110);
                intake2.move(-110);
				intakeMode = 1;
			} else {
				intake.move(0);
                intake2.move(0);
				intakeMode = 0;
			}
		}
		// Outtake
		if ( newPress(R1) ) {
			if (intakeMode != -1) {
				intake.move(-110);
                intake2.move(110);
				intakeMode = -1;
			} else {
				intake.move(0);
                intake2.move(0);
				intakeMode = 0;
			}
		}


        // Wings (Plow)
        if ( newPress(L2) ) {
			if (Wing::wingsExtended != true) {
				Wing::extendWings(true);
				Wing::wingsExtended = true;
			} else {
				Wing::extendWings(false);
				Wing::wingsExtended = false;
			}
		}
		if ( newPress(R2) ) {
			// MACRO GOES HERE IN THE FUTURE
		}

		// Elevation Wing
		if ( newPress(RIGHT) ) {
			if (Wing::elevated != true) {
				Wing::extendElevation(true);
				Wing::elevated = true;
			} else {
				Wing::extendElevation(false);
				Wing::elevated = false;
			}
		}


		// autonomous
		if ( newPress(A) ) {
			//1ballauton();
		}


        // slow drive
        if ( newPress(B) ) {
            if ( stickCurve != StickCurve::slow ) {
                stickCurve = StickCurve::slow;
                pros::lcd::set_text(1, "StickCurve::slow");
            } else if ( stickCurve == StickCurve::slow ) {
                stickCurve = StickCurve::strong;
                pros::lcd::set_text(1, "StickCurve::strong");
            }
        }

        pros::delay(20);
    }
}
