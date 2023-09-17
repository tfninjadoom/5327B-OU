#pragma once
#include "master.h"

// Miscellaneous

extern pros::Controller controller;

// Motors

extern pros::Motor leftFront;
extern pros::Motor leftBack;
extern pros::Motor leftMid;
extern pros::Motor rightFront;
extern pros::Motor rightBack;
extern pros::Motor rightMid;

// Motor Groups

extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;

// V5 Sensors

extern pros::IMU imu;
extern pros::Vision vision;
extern pros::Distance distance;
extern pros::Optical optical;
// extern pros::Rotation rotation1;   extern pros::Rotation rotation2;   extern
// pros::Rotation rotation3; extern pros::GPS gps;

// 3-Wire Sensors

// extern pros::ADIEncoder encoder x4
// extern pros::ADIDigitalIn bumper x2
// extern pros::ADIDigitalIn limitSwitch x2
// extern pros::ADIAnalogIn lineTracker x3

// Pneumatics

// extern pros::ADIDigitalOut single-acting
// extern pros::ADIDigitalOut double-acting
namespace Wings {
    void extend(bool value);
}
