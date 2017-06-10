#include "PID.h"

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  d_error = 0;
  p_error = 0;
  i_error = 0;

  this->Kp = Kp;
  this->Kd = Kd;
  this->Ki = Ki;
}

void PID::UpdateError(double cte) {
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {
  return -Kp*p_error - Kd*d_error - Ki*i_error;
}

