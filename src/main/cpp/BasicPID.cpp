/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019-2020 FRC Team 5308. All Rights Reserved.                */
/* Author: Cetian Liu                                                         */
/* Date: 2019/01/28                                                           */
/* Filename: BasicPID.cpp                                                     */
/* Project: FRC-2019-Allen                                                    */
/*----------------------------------------------------------------------------*/

#include "BasicPID.h"
#include <cstdio>

BasicPID::BasicPID() {
    rm_sum = 0;
    cycNum = 10;
}

BasicPID::BasicPID(double p, double i, double d, int cycle_num = 10) 
                            : kp(p), ki(i), kd(d), cycNum(cycle_num) {
    rm_sum = 0;
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

void BasicPID::push(double err) {
    rm_sum += err;
    rm.push(err);
    while(rm.size() > cycNum) {
        rm_sum -= rm.front(); 
        rm.pop();
    }
}

void BasicPID::output() {
    outputValue  = kp * rm.back();
    outputValue += ki * rm_sum / cycNum;
    outputValue += kd * (rm.back() - rm.front());
    printf("outputValue: %.2f\nPID org: %.2f", outputValue, rm.back());
}

void BasicPID::info() {
    /* info sth here.*/
}