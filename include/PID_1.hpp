#ifndef PID2_HPP
#define PID2_HPP

#include "master.h" 

class PID2 {
public:
    PID2(double kP, double kI, double kD);
    void setTarget(double target);
    void setConstants(double kP, double kI, double kD);
    double compute(double currentValue);

private:
    double kP, kI, kD;
    double target;
    double integral;
    double previousError;
};

#endif // PID2_HPP