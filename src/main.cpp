#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 *
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
} //*/


/* graph of red and blue lines from 5225A here
 * https://www.desmos.com/calculator/sdcgzah5ya */
int curveJoystick(StickCurve stickCurve, int input, double t) {
  int val = 0;
  if (stickCurve == StickCurve::strong) {
    val = (std::exp(-t / 10) +
           std::exp((std::abs(input) - 127) / 10) * (1 - std::exp(-t / 10))) *
          input;
  } else if (stickCurve == StickCurve::weak) {
    // blue
    val = std::exp(((std::abs(input) - 127) * t) / 1000) * input;
  }
  return val;
}

void arcadeDrive(StickCurve stickCurve) {
  int forward_raw = controller.get_analog(ANALOG_LEFT_Y);
  int turn_raw = controller.get_analog(ANALOG_RIGHT_X);

  int forward_vel = curveJoystick(stickCurve, forward_raw, 11.);
  int turn_vel = curveJoystick(stickCurve, turn_raw, 11.);
  
  int left_vel = (forward_vel + turn_vel);
  int right_vel = (forward_vel - turn_vel);

  //leftDrive.move(left_vel);
  //rightDrive.move(right_vel);

  leftFront.move(-left_vel);
  leftBack.move(-left_vel);
  leftMid.move(left_vel);
  rightFront.move(right_vel);
  rightBack.move(right_vel);
  rightMid.move(-right_vel);
}

void tankDrive(StickCurve stickCurve) {
  int left_raw = controller.get_analog(ANALOG_LEFT_Y);
  int right_raw = controller.get_analog(ANALOG_RIGHT_Y);

  int left_vel = curveJoystick(stickCurve, left_raw, 11.);
  int right_vel = curveJoystick(stickCurve, right_raw, 11.);

  //leftDrive.move(left_raw);
  //leftDrive.move(right_raw);

  leftFront.move(left_raw);
  leftBack.move(left_raw);
  leftMid.move(-left_raw);
  rightFront.move(-right_raw);
  rightBack.move(-right_raw);
  rightMid.move(right_raw);
}


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
	//pros::lcd::register_btn1_cb(on_center_button);


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
			tankDrive(stickCurve);
		}
		
		if (driveMode == DriveMode::arcade) {
			arcadeDrive(stickCurve);
		}

		if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
			if (intakeMode != 1) {
				intake.move(110);
				intakeMode = 1;
			} else {
				intake.move(0);
				intakeMode = 0;
			}
		}

		if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
			if (intakeMode != -1) {
				intake.move(-110);
				intakeMode = -1;
			} else {
				intake.move(0);
				intakeMode = 0;
			}
		}

		/*
		if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
			if (driveMode == DriveMode::tank) {
				driveMode = DriveMode::arcade;
			} else if (driveMode == DriveMode::arcade) {
				driveMode = DriveMode::tank;
			}
		}
		*/

		if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) {
			if (stickCurve == StickCurve::strong) {
				stickCurve = StickCurve::weak;
			} else if (stickCurve == StickCurve::weak) {
				stickCurve = StickCurve::strong;
			}
		}

		pros::delay(20);
	}
}
