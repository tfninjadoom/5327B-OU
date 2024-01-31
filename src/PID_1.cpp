#include "master.h"

PID2::PID2(double kP, double kI, double kD) : kP(kP), kI(kI), kD(kD), integral(0.0), previousError(0.0) {}

void PID2::setTarget(double target) {
    this->target = target;
    integral = 0.0;
    previousError = 0.0;
}

void PID2::setConstants(double kP, double kI, double kD) {
    this->kP = kP;
    this->kI = kI;
    this->kD = kD;
}

double PID2::compute(double currentValue) {
    double error = target - currentValue;
    integral += error;
    double derivative = error - previousError;
    previousError = error;
    return kP * error + kI * integral + kD * derivative;
}
