/**
 * @file drive.cpp
 * @date 2023-10-11
 * 
 * @brief
 * This file contains the various drive modes that can be toggled between 
 * during Driver Control. Includes a Joystick Curve function, Tank Drive, 
 * Arcade Drive, and Single-Stick Arcade Drive. 
 */
#include "master.h"

namespace Drive1 {

	/**
	 * graph of strong(red) and weak(blue) curves from 5225A here:
 	 * https://www.desmos.com/calculator/sdcgzah5ya
	 */
	int curveJoystick(StickCurve stickCurve, int input, double t = 20.) {
		int val = 0;

		if (stickCurve == StickCurve::strong) {
			val = (std::exp(-t / 10)
					+ std::exp((std::abs(input) - 127) / 10)
					* (1 - std::exp(-t / 10))) * input;

		} else if (stickCurve == StickCurve::weak) {
			val = std::exp(((std::abs(input) - 127) * t) / 1000) * input;

		} else if (stickCurve == StickCurve::slow) {
			val = input / 3;
		}
		
		return val;
	}


	void arcadeDrive(StickCurve stickCurve) {
		int forward_raw = controller.get_analog(ANALOG_LEFT_Y);
		int turn_raw = controller.get_analog(ANALOG_RIGHT_X);

		int forward_vel = curveJoystick(stickCurve, forward_raw);
		int turn_vel = curveJoystick(stickCurve, turn_raw);
	
		int left_vel = (forward_vel + turn_raw);
		int right_vel = (forward_vel - turn_raw);

		leftFront.move(left_vel);
		leftBack.move(left_vel);
		leftMid.move(left_vel);
		rightFront.move(right_vel);
		rightBack.move(right_vel);
		rightMid.move(right_vel);
	}

	void singleStickDrive(StickCurve stickCurve) {
		int forward_raw = controller.get_analog(ANALOG_LEFT_Y);
		int turn_raw = controller.get_analog(ANALOG_LEFT_X);

		int forward_vel = curveJoystick(stickCurve, forward_raw);
		int turn_vel = curveJoystick(stickCurve, turn_raw);
	
		int left_vel = (forward_vel + turn_vel);
		int right_vel = (forward_vel - turn_vel);

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

		int left_vel = curveJoystick(stickCurve, left_raw);
		int right_vel = curveJoystick(stickCurve, right_raw);

		leftFront.move(-left_raw);
		leftBack.move(-left_raw);
		leftMid.move(left_raw);
		rightFront.move(right_raw);
		rightBack.move(right_raw);
		rightMid.move(-right_raw);
	}

} // namespace Drive