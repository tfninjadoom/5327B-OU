#pragma once
/**
 * @file controller.hpp
 * @date 2023-10-11
 * 
 * @brief
 * This header and its source file initialize the controller and shorten the 
 * calling of buttons in opcontrol().
 * 
 * @details 
 * Contents:
 * - initialize controller
 * - namespace Controller
 *   - function newPress()
 *   - button aliases
 */
#include "master.h"

extern pros::Controller controller;

namespace Controller {

    // returns true if button pressed
    bool newPress(const pros::controller_digital_e_t& button);
    bool newPressShift(const pros::controller_digital_e_t& button, const pros::controller_digital_e_t& shift);

    // button shortcuts
    const pros::controller_digital_e_t L1   {pros::E_CONTROLLER_DIGITAL_L1};
    const pros::controller_digital_e_t L2   {pros::E_CONTROLLER_DIGITAL_L2};
    const pros::controller_digital_e_t R1   {pros::E_CONTROLLER_DIGITAL_R1};
    const pros::controller_digital_e_t R2   {pros::E_CONTROLLER_DIGITAL_R2};
    const pros::controller_digital_e_t LEFT {pros::E_CONTROLLER_DIGITAL_LEFT};
    const pros::controller_digital_e_t RIGHT{pros::E_CONTROLLER_DIGITAL_RIGHT};
    const pros::controller_digital_e_t UP   {pros::E_CONTROLLER_DIGITAL_UP};
    const pros::controller_digital_e_t DOWN {pros::E_CONTROLLER_DIGITAL_DOWN};
    const pros::controller_digital_e_t A    {pros::E_CONTROLLER_DIGITAL_A};
    const pros::controller_digital_e_t B    {pros::E_CONTROLLER_DIGITAL_B};
    const pros::controller_digital_e_t X    {pros::E_CONTROLLER_DIGITAL_X};
    const pros::controller_digital_e_t Y    {pros::E_CONTROLLER_DIGITAL_Y};
    
}