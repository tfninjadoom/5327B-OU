#include "master.h"
using namespace Controller;

// FORWARD-DECLARED GLOBAL VARIABLES
// DriveMode driveMode;
// StickCurve stickCurve;
// int intakeMode;

/**
 * A (boilerplate) callback function for LLEMU's center button.
 *
void on_center_button() {
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	}
} //*/

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
        pros::lcd::set_text(1, "StickCurve::weak");
        pros::lcd::set_text(2, "DriveMode::arcade");
        // pros::lcd::register_btn1_cb(on_center_button);

	Wings::extend(false);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

	DriveMode driveMode { DriveMode::arcade };

	StickCurve stickCurve { StickCurve::weak };

    int intakeMode { 0 };

	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                				(pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                				(pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
	
		if (driveMode == DriveMode::tank) {
			Drive::tankDrive(stickCurve);
            pros::lcd::set_text(2, "DriveMode::tank");
        }

        if (driveMode == DriveMode::arcade) {
			Drive::arcadeDrive(stickCurve);
            pros::lcd::set_text(2, "DriveMode::arcade");
        }

		if (driveMode == DriveMode::singleStick) {
			Drive::singleStickDrive(stickCurve);
            pros::lcd::set_text(2, "DriveMode::singleStick");
        }

        if ( newPress(L1) ) {
			if (intakeMode != 1) {
				intake.move(110);
				intakeMode = 1;
			} else {
				intake.move(0);
				intakeMode = 0;
			}
		}

		if ( newPress(R1) ) {
			if (intakeMode != -1) {
				intake.move(-110);
				intakeMode = -1;
			} else {
				intake.move(0);
				intakeMode = 0;
			}
		}

        if ( newPress(L2) ) {
            if (driveMode == DriveMode::tank) {
                driveMode = DriveMode::arcade;
            } else if (driveMode == DriveMode::arcade) {
                driveMode = DriveMode::singleStick;
            } else if (driveMode == DriveMode::singleStick) {
                driveMode = DriveMode::tank;
            }
        }

        if ( newPress(R2) ) {
            if (stickCurve != StickCurve::weak) {
                stickCurve = StickCurve::weak;
                pros::lcd::set_text(1, "StickCurve::weak");
            } else if (stickCurve != StickCurve::strong) {
                stickCurve = StickCurve::strong;
                pros::lcd::set_text(1, "StickCurve::strong");
            }
        }

        if ( newPress(B) ) {
            stickCurve = StickCurve::slow;
            pros::lcd::set_text(1, "StickCurve::slow");
        }

        pros::delay(20);
    }
}
