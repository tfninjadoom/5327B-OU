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


void moveForward(double inches,int speed, bool wait=true, int wt= 500) {
	chassis.set_drive_pid(inches*2, speed);
  
	if (wait) { chassis.wait_drive(); }

	else{ pros::delay(wt);}

}
	

void moveBackward(double inches, int speed, int wt = 500, bool wait=true ) {
	chassis.set_drive_pid(-inches*2, speed);
  
	if (wait) { chassis.wait_drive(); }

	else{
	pros::delay(wt);
}
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
  
  if(left){
  	chassis.set_turn_pid(degrees, speed);
  }
  else{
	chassis.set_turn_pid(-degrees, speed);
  }

  if (wait) { chassis.wait_drive(); };
}

void swing(int speed, int degrees, bool left, bool wait=true) {
  
  if(left){
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
	moveForward(5, 100, false, 200);
	//pros::delay(100);
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
	//pros::delay(500);
	moveBackward(15, 100, false);
	//pros::delay(500);
	moveForward(20, 127, false);
	//pros::delay(500);
	intakeOff();
	pros::delay(100);

	// turn toward middle ball 1
	moveBackward(15, 100);
	Wing::extendWings(false);
	chassis.set_angle(90);
	turn(100, 19, true);
	
	// move toward middle ball 1
	moveForward(75, 100);
	//pros::delay(100);
	intakeOn(100);
	moveForward(5, 100, false );
	//pros::delay(500);
	intakeOff();
	
	// clockwise swing scoop to score 3 triballs
	moveBackward(10, 100);
	Wing::extendWings(true);
	swing(100, 180, false);
	outtakeOn(100);
	moveForward(100, 127, false);
	//pros::delay(500);
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

void fiveballautonv2(){

	

intakeOn(100);
	moveForward(5, 100, false, 200);
	//pros::delay(100);
	intakeOff();

	// move to goal
	moveBackward(55, 100);
	turn(100, 180, true);
	swing(100, 135, true);
	Wing::extendWings(true);
	moveForward(18, 127);
	swing(100, 90, true);
	
	// push
	outtakeOn(127);
	moveForward(25, 127, false);
	//pros::delay(500);
	//moveBackward(15, 100, false);
	//pros::delay(500);
	//turn(100, 180, true);

	moveBackward(20, 127, false);
	moveForward(20, 100);
	//turn(100, 180, true);
	//pros::delay(500);
	intakeOff();
	pros::delay(100);

	// turn toward middle ball 1
	moveBackward(15, 100);
	Wing::extendWings(false);
	chassis.set_angle(90);
	turn(100, 19, true);
	
	// move toward middle ball 1
	moveForward(75, 100);
	//pros::delay(100);
	intakeOn(100);
	moveForward(5, 100, false );
	//pros::delay(500);
	intakeOff();
	
	// clockwise swing scoop to score 3 triballs
	moveBackward(10, 100);
	Wing::extendWings(true);
	swing(100, 180, false);
	outtakeOn(100);
	moveForward(100, 127, false);
	//pros::delay(500);
	moveBackward(100, 10);
}


void skills(){

	intakeOn(120);
	pros::delay(12000);
	outtakeOff();
	moveForward(130, 120, false, 2000);
	//swing(127, 45, true);
	turn(70, 50, false);
	Wing::extendWings(true);
	moveForward(40, 127, false, 600);
	//moveBackward(20, 100, false, 750);
	//turn(100, 30, true, false);
	//moveForward(25, 120, false, 500);
	moveBackward(15, 127, false, 600);
	Wing::extendWings(false);
	imu.reset();
	turn(100, 195, false);
	moveBackward(30, 127, false, 760);
	moveForward(10, 100);
	imu.reset();
	turn(100, 195, true);
	
	//outtakeOff();
	moveBackward(45, 100, false, 500);
	imu.reset();
	turn(100,55, true);
	moveBackward(108, 85, false, 1500);
	//turn(100, 10, false);
	intakeOn(120);
	pros::delay(12000);
	outtakeOff();
	//outtakeOff();
	moveForward(135, 127, false, 2500);
	//swing(127, 45, true);
	turn(120, 60, false);
	Wing::extendWings(true);
	moveForward(40, 127, false, 500);
	//moveBackward(20, 100, false, 750);
	//moveForward(25, 120, false, 500);
	moveBackward(15, 127, false, 750);
	Wing::extendWings(false);
	imu.reset();
	turn(100, 195, true);
	moveBackward(30, 127, false, 750);
	moveForward(10, 100);
	imu.reset();
	turn(100, 195, false);
	
	//outtakeOff();
	moveBackward(45, 100);
	imu.reset();
	turn(100, 55, true);
	moveBackward(120, 85);

	intakeOff();
}

void skillsv2(){
	intakeOn(50);
	pros::delay(14000);
	outtakeOff();
	turn(50, 20, false);
	//Wing::extendWings(true);
	moveForward(10, 50);
	Wing::extendWings(false);
	//swing(127, 45, true);
	imu.reset();
	turn(50, 20, true);
	moveBackward(10, 50);
	
	intakeOn(50);
	pros::delay(1000);
	outtakeOff();
	

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
	//skillsv2();
	fiveballautonv2();
	//skills();
	//AWP();
	//oneballAuton();
	//AWPtwo();
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
