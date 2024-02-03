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


void extend(bool elevation){
	Wing::extendElevation(true);
}

void slapperon(bool on){
	slapper::turnon(on);
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
void rightwing(bool open){
	Wing::right(open);
}
void leftwing(bool open){
	Wing::left(open);
}
void bothwings(bool open){
	Wing::right(open);
	Wing::left(open);
}
void fiveBallAuton(){
	
}
void awp_far(){
	

}
void awp_close(){
	leftwing(true);
	moveBackward(25, 127);
	leftwing(false);
	turn(100, 85, false);
	rightwing(true);
	moveBackward(42, 120);
}

void unused_fiveBallAuton(){
  
}


void skills(){

	slapperon(true);
}
void fiveballautonv2(){

}




void skillsv2(){
	
	

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
	initialize();
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
	//fiveballautonv2();
	//skills();
	//AWP();
	//oneballAuton();
	//AWPtwo();
	//fiveBallAuton();
	awp_close();
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


	bool intake_on = false;

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
				intake_on = true;
			} else {
				intake.move(0);
                intake2.move(0);
				intakeMode = 0;
				intake_on = false;
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

		if (intake_on){
			if (detect()){
				intake.move(0);
				intake2.move(0);
				intake_on = false;
			}
		}
		bool leftopen = false;
		bool rightopen = false;
		if (newPress(L2)){
			if (!leftopen){
				Wing::left(true);
				leftopen = true;

			}
		else{
			Wing::left(false);
			leftopen = false;
		}
			
		}

		if (newPress(R2)){
			if(!rightopen){
				Wing::right(true);
				rightopen = true;
			}
			else{
				Wing::right(false);
				rightopen =  false;
			}
	
			
		}

		 if(newPress(X)){
			if (rightopen && leftopen){
			Wing::right(false);
			Wing::left(false);
			rightopen = true;
			leftopen = false;
			}
			else{
				Wing::left(true);
				Wing::right(true);
				leftopen = true;
				rightopen = true;

			}
		 }
		bool ON = false;
		if ( newPress(Y)) {
			if (!ON){
			slapper::turnon(true);
			ON = true;
			}
			else{
				slapper::turnon(false);
				ON = false;
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
			autonomous();

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
