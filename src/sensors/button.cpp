#include <iostream>
#include <string>

#include "master.h"
// typedef pros::controller_digital_e_t controller_button;
//  how long you have to hold for program to run
int hold_D = 2000;

//
int ButtonPressTime(controller_button key) {
  pros::Controller master(pros::E_CONTROLLER_MASTER);
  int run_num = 0;
  while (master.get_digital(key)) {
    run_num++;
    pros::delay(100);
  }

  return run_num;
}

int autonomousRouteCount = 0;

void (*routes[])() = {autonomousPath1, autonomousPath2};

int numberOfRoutes{sizeof(routes) / sizeof(routes[0])};

void runAutonomousRoutines() {
  int mod_var = autonomousRouteCount % numberOfRoutes;
  if (ButtonPressTime(Controller::A) > hold_D) {
    controller.set_text(0, 0, ("Running " + std::to_string(routes[mod_var])));

    routes[mod_var]();
  } else {
    autonomousRouteCount++;
    controller.set_text(0, 0,
                        ("Useing : " + std::to_string(routes[mod_var + 1])));
  }
}