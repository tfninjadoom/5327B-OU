/**
 * @file controller.cpp
 * @date 2023-10-11
 * 
 * @brief
 * This file and its header initialize the controller and shorten the calling 
 * of buttons in opcontrol().
 * 
 * @details 
 * Contents:
 * - initialize controller
 * - namespace Controller
 *   - function newPress()
 *   - !! HEADER-ONLY !!: button aliases
 */
#include "master.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);


namespace Controller {
    typedef pros::controller_digital_e_t Button;
    // returns true if button pressed
    bool newPress(const pros::controller_digital_e_t& button ) {
        if (controller.get_digital_new_press(button)) {
            return true;
        } else {
            return false;
        }
    }

    bool newPressShift(const Button& button, const Button& shift) {
        if (controller.get_digital_new_press(button) && controller.get_digital(shift)) {
            return true;
        } else {
            return false;
        }
    }
    
}