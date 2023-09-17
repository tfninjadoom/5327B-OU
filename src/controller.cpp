#include "master.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

namespace Controller {
    
    bool newPress(const pros::controller_digital_e_t button) {
        if (controller.get_digital_new_press(button)) {
            return true;
        } else {
            return false;
        }
    }
    
}