/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <rev/CANSparkMax.h>
#include <rev/CANEncoder.h>

class Rabbit : public frc::Subsystem {
 private:

  /*Rabit: */
  static std::shared_ptr<WPI_TalonSRX> ratTal;
  
  static std::shared_ptr<rev::CANSparkMax> rabSpark;
  static std::shared_ptr<rev::CANEncoder> rabEncoder;

  static std::shared_ptr<Solenoid> rabSole;

  /*Deanck*/
  static std::shared_ptr<Solenoid> deLift;
  static std::shared_ptr<Solenoid> deDick;


  double rabStPos;


 public:
  Rabbit();
  void InitDefaultCommand() override;
  
  void rabDown();
  void rabStand(); 
  double getPosition();
};
