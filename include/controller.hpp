#pragma once
#include "master.h"

extern pros::Controller controller;

namespace Controller {

    bool newPress(const pros::controller_digital_e_t button);

    const pros::controller_digital_e_t L1   { pros::E_CONTROLLER_DIGITAL_L1 };
    const pros::controller_digital_e_t L2   { pros::E_CONTROLLER_DIGITAL_L2 };
    const pros::controller_digital_e_t R1   { pros::E_CONTROLLER_DIGITAL_R1 };
    const pros::controller_digital_e_t R2   { pros::E_CONTROLLER_DIGITAL_R2 };
    const pros::controller_digital_e_t LEFT { pros::E_CONTROLLER_DIGITAL_LEFT };
    const pros::controller_digital_e_t RIGHT { pros::E_CONTROLLER_DIGITAL_RIGHT };
    const pros::controller_digital_e_t UP   { pros::E_CONTROLLER_DIGITAL_UP };
    const pros::controller_digital_e_t DOWN { pros::E_CONTROLLER_DIGITAL_DOWN };
    const pros::controller_digital_e_t A    { pros::E_CONTROLLER_DIGITAL_A };
    const pros::controller_digital_e_t B    { pros::E_CONTROLLER_DIGITAL_B };
    const pros::controller_digital_e_t X    { pros::E_CONTROLLER_DIGITAL_X };
    const pros::controller_digital_e_t Y    { pros::E_CONTROLLER_DIGITAL_Y };
    
}