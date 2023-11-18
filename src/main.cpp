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
int INTAKE_SPEED{150}; // for the speed of the intakezzz
// Function to grab the ball
void moveForward(double inches,int speed, bool wait=true) {
  chassis.set_drive_pid(inches*2, speed);
  if(wait){
  	chassis.wait_drive();
  }
  else{
	pros::delay(500);
  
  }
  
  //pros::delay(100);
  //chassis.wait_drive();
}
void moveBackward(double inches, int speed, bool wait= 	true) {
  chassis.set_drive_pid(-inches*2, speed);
  if(wait){
  	chassis.wait_drive();
  }
  else{
	pros::delay(500);
  
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
  intake2.move(speed);
  if(move){
    moveForward(dis,DRIVE_SPEED, true);
  }
  pros::delay(duration);
  intake.move(0);
  intake2.move(0);
}

void stopIntake(){
	intake.move(0);
  intake2.move(0);
}

void startintake(int speed){
  intake.move(-speed);
  intake2.move(speed);
}	

void realease(int speed){
  intake.move(speed);
  intake2.move(-speed);
}
void  turn(int speed, int degrees, bool right) {
  
  if(right){
  	
  	chassis.set_turn_pid(degrees, speed);
  	chassis.wait_drive();
  }
  else{
	chassis.set_turn_pid(-degrees, speed);
  	chassis.wait_drive();
  }

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

void extendWings(bool extendOrNot) {
    //Wing::extendLeft(extendOrNot);
    Wing::extendRight(extendOrNot);
     
    
}
void test(){
	startintake(100);
	moveForward(5, 100);
	
	pros::delay(100);
	stopIntake();
	moveBackward(42, 100);
	turn(100, 180, true);
	swing(100, 135, true);
	moveForward(30, 127, false);
	extendWings(true);
	swing(100, 90, true);
	//push
	realease(127);
	pros::delay(100);
	moveForward(25, 127, false);
	
	moveBackward(15, 100, false);
	moveForward(20, 127, false);
	stopIntake();
	moveBackward(15, 100);
	extendWings(false);
	imu.reset(90);
	//turn(100, 45, false);
	//imu.set_heading(90);
	//chassis.set_angle(15);
	turn(100, 70, false);
	//swing(100, 0, false);
	//imu.set_heading(45);
	//pros::delay(1000);
	
	
	moveForward(75, 100);
	pros::delay(100);
	startintake(100);

	moveForward(5, 100);
	pros::delay(100);
	stopIntake();
	moveBackward(10, 100);
	extendWings(true);
	swing(100, 90, false);
	realease(100);
	moveForward(30, 127);
	//moveForward(5, 100);
	

}

void fiveballAuton(){
  startintake(127);
  moveForward(7,100);
  //pros::delay(200);
  stopIntake();
  moveBackward(35, 100);
  turn(100, 180, true);
  //extendboth(true);
  moveForward(30, 100);
  turn(100, 155, true);
  realease(INTAKE_SPEED);
  moveForward(20, 100);
  turn(100, 10, true);
  moveForward(40, 120);
  moveBackward(20, 100);
  turn(100, 60, false);

  //extendboth(false);
  moveForward(40, 75);
  turn(100, 60, true);
  startintake(100);
  moveForward(30, 100);
  stopIntake();
  
  moveBackward(10, 75);
  /*turn(75, 75, false);
  //extendboth(true);
  moveForward(24, 75);
  turn(75, 90, true);
  realease(INTAKE_SPEED);
  moveForward(35, 125);
  pros::delay(300);
  moveBackward(15, 75);
  turn(75, 180, false);
  startintake(INTAKE_SPEED);
  moveForward(40, 75);
  pros::delay(200);
  stopIntake();
  moveBackward(10, 75);
  turn(75, 180, false);
  moveForward(40, 125);
  pros::delay(200);
  moveBackward(10, 75);
  */
}
void oneballAuton() {
 	moveForward(35, 100);
	realease(100);
	
	pros::delay(500);
	stopIntake();
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
	Wing::extendLeft(false);
    Wing::extendRight(false);

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
	Wing::extendLeft(false);
    Wing::extendRight(false);
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
	//Wing::extendLeft(false);
    //Wing::extendRight(false);

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

	test();
	//fiveballAuton();

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

    Wing::extendLeft(false);
    Wing::extendRight(false);

	//--------Chassis Reconfiguration---------//
	//chassis.set_active_brake(0);
	chassis.set_drive_brake(MOTOR_BRAKE_COAST);

	while (true) {
		// pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		//                 				(pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		//                 				(pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

		// set drive brakes to coast
		chassis.set_drive_brake(MOTOR_BRAKE_COAST);
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


        // intake buttons
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


        // Wing
        if ( newPress(L2) ) {
			if (Wing::left != true) {
				Wing::extendLeft(true);
				Wing::left = true;
			} else {
				Wing::extendLeft(false);
				Wing::left = false;
			}
		}
		if ( newPress(R2) ) {
			if (Wing::right != true) {
				Wing::extendRight(true);
				Wing::right = true;
			} else {
				Wing::extendRight(false);
				Wing::right = false;
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
