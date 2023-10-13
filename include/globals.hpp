#pragma once
/**
 * @file globals.hpp
 * @date 2023-10-11
 * 
 * @brief
 * !! PENDING !!
 */
#include "master.h"


// Motors

extern pros::Motor leftFront;
extern pros::Motor leftBack;
extern pros::Motor leftMid;
extern pros::Motor rightFront;
extern pros::Motor rightBack;
extern pros::Motor rightMid;
extern const int 
LEFT_DRIVE_PORTS[3];
extern const int 
RIGHT_DRIVE_PORTS[3];
extern const int IMU_PORT;



extern pros::Motor intake;
extern pros::Motor intake2;

// Motor Groups

//extern pros::MotorGroup leftDrive;
//extern pros::MotorGroup rightDrive;

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

namespace Wing {
    extern bool left;
    extern bool right;

    void extendLeft(bool extendOrNot);
    void extendRight(bool extendOrNot);
} //namespace Wing
