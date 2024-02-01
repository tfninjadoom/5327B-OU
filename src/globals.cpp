/**
 * @file globals.cpp
 * @date 2023-10-11
 * 
 * @brief 
 * This file contains the initializations of the different electronic 
 * components on the robot and the assignment of ports.
 */
#include "master.h"


// MACROS
#define DRIVE_GEARSET pros::E_MOTOR_GEARSET_06

// MOTOR PORTS
const int 
LEFT_DRIVE_PORTS[3] {5, 4, 3};
const int 
RIGHT_DRIVE_PORTS[3] {1, 11, 2};

static const int
INTAKE_PORTS[2] {20, 0};

static const int SLAPPER_PORTS[1] {12};

// V5 SENSOR PORTS

const int
IMU_PORT {14};
static const int 
VISION_PORT {0};
static const int 
DISTANCE_PORT {0};
static const int 
OPTICAL_PORT {0};
static const int 
ROTATION_PORTS[3] {17, 18, 19};
static const int 
GPS_PORT {0};

//----------------------------------------------------------------------------
// OBJECT INITIALIZATION

// Motors
pros::Motor         leftFront(LEFT_DRIVE_PORTS[0], DRIVE_GEARSET);
pros::Motor         leftBack(LEFT_DRIVE_PORTS[1], DRIVE_GEARSET);
pros::Motor         leftMid(LEFT_DRIVE_PORTS[2], DRIVE_GEARSET);

pros::Motor         rightFront(RIGHT_DRIVE_PORTS[0], DRIVE_GEARSET);
pros::Motor         rightBack(RIGHT_DRIVE_PORTS[1], DRIVE_GEARSET);
pros::Motor         rightMid(RIGHT_DRIVE_PORTS[2], DRIVE_GEARSET);

pros::Motor         intake(INTAKE_PORTS[0], pros::E_MOTOR_GEARSET_18);
pros::Motor         intake2(INTAKE_PORTS[1], pros::E_MOTOR_GEARSET_18);
pros::Motor         slapper(SLAPPER_PORTS[0], pros::E_MOTOR_GEARSET_36);   
//Motor Groups
pros::MotorGroup    leftDrive  ( {leftFront, leftBack, leftMid} );
pros::MotorGroup    rightDrive ( {rightFront, rightBack, rightMid} );


// V5 Sensors
pros::IMU           imu(IMU_PORT);
pros::Vision        vision(VISION_PORT);
pros::Distance      distance(DISTANCE_PORT);
pros::Optical       optical(OPTICAL_PORT);
pros::Rotation      rotationP(ROTATION_PORTS[0]);
pros::Rotation      rotationI(ROTATION_PORTS[1]);
pros::Rotation      rotationD(ROTATION_PORTS[2]);
pros::GPS           gps(GPS_PORT);

// 3-Wire Sensors
// pros::ADIEncoder    encoder x4
// pros::ADIDigitalIn  bumper x2
// pros::ADIDigitalIn  limitSwitch x2
// pros::ADIAnalogIn   lineTracker x3


// Pneumatics
// pros::ADIDigitalOut single-acting
pros::ADIDigitalOut elevationWing('A');
//pros::ADIDigitalOut plowWings('B');
pros::ADIDigitalOut rightWing('D');
pros::ADIDigitalOut leftWing('H');
// pros::ADIDigitalOut double-acting x6


//----------------------------------------------------------------------------
// OBJECT GROUPS

namespace Wing {
    bool wingsExtended { false };
    bool elevated { false };
    bool left_extend = false;
    bool right_extend = false;
    
    void extendWings(bool extendOrNot) {
        leftWing.set_value(extendOrNot);
        rightWing.set_value(extendOrNot);
        left_extend = extendOrNot;
        right_extend = extendOrNot;
    }
    void extendleftWing(bool extendOrNot) {
        leftWing.set_value(extendOrNot);
        left_extend = extendOrNot;
    }
    void extendRightWing(bool extendOrNot) {
        rightWing.set_value(extendOrNot);
        right_extend = extendOrNot;
    }
    void extendElevation(bool extendOrNot) {
        elevationWing.set_value(extendOrNot);
        elevated = extendOrNot;
    }
}  // namespace Wing

