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

const int
INTAKE_PORTS[2] {20, 0};
static const int SLAPPER_PORTS[1] {12};

// V5 SENSOR PORTS
const int
IMU_PORT {1};
const int 
VISION_PORT {0};
const int 
DISTANCE_PORT {0};
const int 
OPTICAL_PORT {0};
const int 
ROTATION_PORTS[3] {17, 18, 19};
const int 
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
pros::ADIDigitalOut plowWings('B');
pros::ADIDigitalOut leftWing('H');
pros::ADIDigitalOut RightWing('D');
// pros::ADIDigitalOut double-acting x6


//----------------------------------------------------------------------------
// OBJECT GROUPS

namespace Slapper{

    bool on = false;

    void turnon(bool start){
        if (start){
            slapper.move_velocity(127);
            on == true;
        }
        else{
            slapper.move_velocity(0);
            on == false;
        }

    }
}

namespace Wing {
    bool wingsExtended { false };
    bool elevated { false };

    void extendWings(bool extendOrNot) {
        plowWings.set_value(extendOrNot);
        wingsExtended = extendOrNot;
    }

    void left(bool open){
        leftWing.set_value(open);
    }

    void right(bool open){
        RightWing.set_value(open);
    }
    void extendElevation(bool extendOrNot) {
        elevationWing.set_value(extendOrNot);
        elevated = extendOrNot;
    }
}  // namespace Wing


//--------------------------LEMLIB SETUP-------------------------//

// tracking wheels
pros::Rotation horizontalEnc{7};
// horizontal tracking wheel. 2.75" diameter, 3.7" offset, back of the robot
lemlib::TrackingWheel horizontal{&horizontalEnc, lemlib::Omniwheel::NEW_275, -3.7};

// drivetrain
lemlib::Drivetrain_t drivetrain {&leftDrive, &rightDrive, 15, lemlib::Omniwheel::NEW_275, 600, 40};

// lateral motion controller
lemlib::ChassisController_t lateralController {70, 210, 1, 100, 3, 500, 20};

// angular motion controller
lemlib::ChassisController_t angularController {2, 20, 1, 100, 3, 500, 20};

// sensors for odometry
lemlib::OdomSensors_t sensors {nullptr, nullptr, nullptr, nullptr, &imu};

lemlib::Chassis chassis {drivetrain, lateralController, angularController, sensors};