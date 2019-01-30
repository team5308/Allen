/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019-2020 FRC Team 5308. All Rights Reserved.                */
/* Author: Cetian Liu                                                         */
/* Date: 2019/01/28                                                           */
/* Filename: BasicPID.cpp                                                     */
/* Project: FRC-2019-Allen                                                    */
/*----------------------------------------------------------------------------*/

#include "BasicPID.h"

BasicPID::BasicPID() {
}

BasicPID::BasicPID(double p, double i, double d) : kp(p), ki(i), kd(d) {
}

void BasicPID::setP(double p) {
    this->kp = p;
}

void BasicPID::setI(double i) {
    this->ki = i;
}

void BasicPID::setD(double d) {
    this->kd = d;
}

void BasicPID::setPara(double p, double i, double d) {
    this->kp = p;
    this->ki = i;
    this->kd = d;
}