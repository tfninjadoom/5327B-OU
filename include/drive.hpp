#pragma once
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
    int curveJoystick(StickCurve stickCurve, int input, double t);

    void arcadeDrive(StickCurve stickCurve);
    void singleStickDrive(StickCurve stickCurve);
    void tankDrive(StickCurve stickCurve);
}