#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    // Initialize parameters
    Kp_ = Kp;
    Ki_ = Ki;
    Kd_ = Kd;

    // Initial errors
    p_error_ = 0.0;
    i_error_ = 0.0;
    d_error_ = 0.0;  

    // Set previous cte to negative as flag
    pre_cte_ = -1.0;
}

void PID::UpdateError(double cte) {
    // Check if has previous cte
    if (pre_cte_ < 0) {
        pre_cte_ = cte;
    }

    // Update errors
    p_error_ = cte;
    d_error_ = cte - pre_cte_;
    i_error_ += cte;
    pre_cte_ = cte;
}

double PID::TotalError() {
    return Kp_ * p_error_ + Ki_ * i_error_ + Kd_ * d_error_;
}

