/*#include "master.h"
const double DISTANCE_THRESHOLD = 1.0;
double getEncoderDistance() {
    double leftDistance = (leftFront.get_position() + leftBack.get_position() + leftMid.get_position()) / 3.0;
    double rightDistance = (rightFront.get_position() + rightBack.get_position() + rightMid.get_position()) / 3.0;
    return (leftDistance + rightDistance) / 2.0;
}
void resetEncoders() {
    leftDrive.tare_position();
    rightDrive.tare_position();
}

void setMotorPower(double power) {
    leftDrive.move_voltage(power * 12000 / 127); 
    rightDrive.move_voltage(power * 12000 / 127);
}

void stopMotors() {
    leftDrive.move_voltage(0);
    rightDrive.move_voltage(0);
}


bool isMovementComplete(double targetDistance) {
    double currentDistance = getEncoderDistance();
    return fabs(targetDistance - currentDistance) < DISTANCE_THRESHOLD;
}

*/