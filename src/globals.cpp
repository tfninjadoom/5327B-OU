#include "master.h"

/* globals.cpp
 * [Needs a better introduction]
 * This file contains the initializations of the different electronic components on the robot and the assignment of ports.
 * */


// MACROS
#define DRIVE_GEARSET pros::E_MOTOR_GEARSET_06

// MOTOR PORTS
static const int 
LEFT_PORTS[3] {1, 2, 3};
static const int 
RIGHT_PORTS[3] {4, 5, 6};

static const int
INTAKE_PORTS[2] {20, 19};

// V5 SENSOR PORTS
static const int
INERTIAL_PORT {7};
static const int 
VISION_PORT {8};
static const int 
DISTANCE_PORT {9};
static const int 
OPTICAL_PORT {10};
static const int 
ROTATION_PORTS[3] {11, 12, 13};
static const int 
GPS_PORT {12};

//------------------------------------------------------------------------------
// OBJECT INITIALIZATION

// Motors
pros::Motor         leftFront(LEFT_PORTS[0], DRIVE_GEARSET);
pros::Motor         leftBack(LEFT_PORTS[1], DRIVE_GEARSET);
pros::Motor         leftMid(LEFT_PORTS[2], DRIVE_GEARSET);

pros::Motor         rightFront(RIGHT_PORTS[0], DRIVE_GEARSET);
pros::Motor         rightBack(RIGHT_PORTS[1], DRIVE_GEARSET);
pros::Motor         rightMid(RIGHT_PORTS[2], DRIVE_GEARSET);

pros::Motor         intake(INTAKE_PORTS[0], pros::E_MOTOR_GEARSET_18);
pros::Motor         intake2(INTAKE_PORTS[1], pros::E_MOTOR_GEARSET_18);

//Motor Groups
pros::MotorGroup    leftDrive  ( {leftFront, leftBack, leftMid} );
pros::MotorGroup    rightDrive ( {rightFront, rightBack, rightMid} );

// V5 Sensors
pros::IMU           imu(INERTIAL_PORT);
pros::Vision        vision(VISION_PORT);
pros::Distance      distance(DISTANCE_PORT);
pros::Optical       optical(OPTICAL_PORT);
// pros::Rotation      rotation1(ROTATION_PORTS[0]);
// pros::Rotation      rotation2(ROTATION_PORTS[1]);
// pros::Rotation      rotation3(ROTATION_PORTS[2]);
pros::GPS           gps(GPS_PORT);

// 3-Wire Sensors
// pros::ADIEncoder    encoder x4
// pros::ADIDigitalIn  bumper x2
// pros::ADIDigitalIn  limitSwitch x2
// pros::ADIAnalogIn   lineTracker x3


// Pneumatics
// pros::ADIDigitalOut single-acting
pros::ADIDigitalOut leftWing('A');
pros::ADIDigitalOut rightWing('B');
// pros::ADIDigitalOut double-acting x6


//------------------------------------------------------------------------------
// OBJECT GROUPS

namespace Wings {
    void extendLeft(bool extendOrNot) {
        leftWing.set_value(extendOrNot);
    }
    void extendRight(bool extendOrNot) {
        rightWing.set_value(extendOrNot);
    }
}
