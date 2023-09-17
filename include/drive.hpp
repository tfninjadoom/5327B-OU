#pragma once
#include "master.h"

namespace Drive {
    int curveJoystick(StickCurve stickCurve, int input, double t);

    void arcadeDrive(StickCurve stickCurve);
    void singleStickDrive(StickCurve stickCurve);
    void tankDrive(StickCurve stickCurve);
}