#include "master.h"

// Chassis constructor
Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {-LEFT_DRIVE_PORTS[0], -LEFT_DRIVE_PORTS[1], LEFT_DRIVE_PORTS[2]}

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  ,{RIGHT_DRIVE_PORTS[0], RIGHT_DRIVE_PORTS[1], -RIGHT_DRIVE_PORTS[2]}


  // IMU Port
  ,IMU_PORT

  // Wheel Diameter (Remember, 4" wheels are actually 4.125!)
  //    (or tracking wheel diameter)
  ,3.25

  // Cartridge RPM
  //   (or tick per rotation if using tracking wheels)
  ,600

  // External Gear Ratio (MUST BE DECIMAL)
  //    (or gear ratio of tracking wheel)
  // eg. if your drive is 84:36 where the 36t is powered, your RATIO would be 2.333.
  // eg. if your drive is 36:60 where the 60t is powered, your RATIO would be 0.6.
  ,0.6

  // Uncomment if using tracking wheels
  /*
  // Left Tracking Wheel Ports (negative port will reverse it!)
  ,{1, 2}

  // Right Tracking Wheel Ports (negative port will reverse it!)
  ,{3, 4}
  */

  // Uncomment if tracking wheels are plugged into a 3 wire expander
  // 3 Wire Port Expander Smart Port
  // ,9
);

void default_constants() {
  chassis.set_slew_min_power(80,70);
  chassis.set_slew_distance(7,7);
  chassis.set_pid_constants(&chassis.headingPID, 11,0,20,0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45,0,5,0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45,0,5,0);
  chassis.set_pid_constants(&chassis.turnPID, 5,0.003,35,15);
  chassis.set_pid_constants(&chassis.swingPID, 7,0,45,0);
}



void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100,3,500,7,500,500);
  chassis.set_exit_condition(chassis.swing_exit, 100,3,500,7,500,500);
  chassis.set_exit_condition(chassis.drive_exit, 80,50,300,150,500,500);
}