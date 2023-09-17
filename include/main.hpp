#pragma once
#include "master.h"

enum class DriveMode {
	tank,
	arcade,
	singleStick,
};

enum class StickCurve {
	strong,
	weak,
	slow,
};

extern pros::Motor intake;