/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019-2020 FRC Team 5308. All Rights Reserved.                */
/* Author: Cetian Liu                                                         */
/* Date: 2019/01/28                                                           */
/* Filename: BasicPID.h                                                       */
/* Project: FRC-2019-Allen                                                    */
/*----------------------------------------------------------------------------*/

#pragma once

#include <queue>

class BasicPID {
 private:

  double kp;
  double ki;
  double kd;

  double cp;
  double ci;
  double cd;

  int cycNum;

  std::queue<double> rm;
  long double rm_sum;

 public:
  
  double outputValue;

  BasicPID();
  BasicPID(double, double, double, int);
  
  void setP(double);
  void setI(double);
  void setD(double);
  void setPara(double, double, double);

  void push(double);
  void output();
};
