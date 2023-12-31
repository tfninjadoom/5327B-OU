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
        pros::lcd::set_text(1, "StickCurve::old");
        pros::lcd::set_text(2, "DriveMode::arcade");
        // pros::lcd::register_btn1_cb(on_center_button);


	//--------Piston Starting States---------//
	Wing::extendWings(false);
    Wing::extendElevation(false);
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
	
    Wing::extendWings(false);
    Wing::extendElevation(false);

	if 
	(Autonomous::selection==Autonomous::Select::left) 
	{ Autonomous::left(); } 
	else if 
	(Autonomous::selection==Autonomous::Select::right) 
	{ Autonomous::right(); } 
	else 
	{ Autonomous::skills(); }

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

	StickCurve stickCurveMode { StickCurve::old };

    int intakeMode { 0 };

    Wing::extendWings(false);
    Wing::extendElevation(false);

	while (true) {
		// pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		//                 				(pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		//                 				(pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);


        // drive modes
		if (driveMode == DriveMode::tank) {
			Drive::tankDrive(stickCurveMode);
            pros::lcd::set_text(2, "DriveMode::tank");
        } else if (driveMode == DriveMode::arcade) {
			Drive::arcadeDrive(stickCurveMode);
            pros::lcd::set_text(2, "DriveMode::arcade");
        } else if (driveMode == DriveMode::singleStick) {
			Drive::singleStickDrive(stickCurveMode);
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
			autonomous();
		}


        // slow drive
        if ( newPress(B) ) {
            if ( stickCurveMode == StickCurve::latest ) {
                stickCurveMode = StickCurve::slow;
                pros::lcd::set_text(1, "StickCurve::slow");
            } else if ( stickCurveMode == StickCurve::slow ) {
                stickCurveMode = StickCurve::old;
                pros::lcd::set_text(1, "StickCurve::old");
            } else if ( stickCurveMode == StickCurve::old ) {
                stickCurveMode = StickCurve::latest;
                pros::lcd::set_text(1, "StickCurve::latest");
            }
        }

        pros::delay(20);
    }
}
