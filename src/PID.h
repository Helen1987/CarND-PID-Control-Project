#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  PID();

  virtual ~PID();

  /**
  * Initializes PID with coefficients
  * @param Kp the farther from the trajectory the bigger the error
  * @param Ki cumulative error: if we keep moving too far from the trajectory, we should increase the error
  * @param Kd the larger difference between current and previous cte, the larger error we have
  */
  void Init(double Kp, double Ki, double Kd);

  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
