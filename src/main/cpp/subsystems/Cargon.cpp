/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Cargon.h"

std::shared_ptr<frc::Joystick> Cargon::joy1;

std::shared_ptr<WPI_VictorSPX> Cargon::draVic1; /*Dragon VictorSPX*/
std::shared_ptr<WPI_VictorSPX> Cargon::draVic2;

std::shared_ptr<WPI_VictorSPX> Cargon::catVic; /*Cat VictorSPX*/
std::shared_ptr<rev::CANSparkMax> Cargon::catSpark; /*Cat SparkMax*/

std::shared_ptr<rev::CANEncoder> Cargon::catEncoder;

Cargon::Cargon() : Subsystem("Cargon") {
  //Joystick Unfinished

  draVic1.reset(new WPI_VictorSPX(6));
  draVic2.reset(new WPI_VictorSPX(7));

  catVic.reset(new WPI_VictorSPX(8));
  catSpark.reset(new rev::CANSparkMax(9, rev::CANSparkMax::MotorType::kBrushless));

  catEncoder.reset(new rev::CANEncoder(*catSpark));
}

void Cargon::InitDefaultCommand() {
}

void Cargon::Periodic() {
}

double Cargon::calDiff(int target){
  const int target0 = 0; /*The mode 0 position, number of turns is 0*/
  const int target1 = 500; /*The mode 1 position, number of turns is 500*/
  const int target2 = 1000; /*The mode 2 position, number of turns is 1000*/

  double curPos = catEncoder -> GetPosition();

  if(target == 0){
    return curPos - target0;
  }
  else if(target == 1){
    return curPos - target1;
  }
  else if(target == 2){
    return curPos - target2;
  }
}
/*Target is the objective position, waiting for Rico to set itself*/

void Cargon::rotate(int target){
  double diff = calDiff(target);
  while(diff > 0){
    catSpark -> Set(1);
  }
  while(diff < 0){
    catSpark -> Set(-1);
  }
  catSpark -> Set(0);
}

void Cargon::catIn(){
  catVic -> Set(1);/*Get the cargo in*/
}

void Cargon::dragonOut(){
  draVic1 -> Set(1);/*Shoot the cargo*/
  draVic2 -> Set(-1);
}