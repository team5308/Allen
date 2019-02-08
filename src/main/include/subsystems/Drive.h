/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include "rev/CANSparkMax.h"

class Drive : public frc::Subsystem {
 private:

 public:
  Drive();
  void InitDefaultCommand() override;
  void Periodic() override;

  static std::shared_ptr<frc::Joystick> joy1;
  
  static std::shared_ptr<WPI_TalonSRX> tal1;
  static std::shared_ptr<WPI_TalonSRX> tal2;
  static std::shared_ptr<rev::CANSparkMax> spa1;

  static std::shared_ptr<WPI_TalonSRX> tal3;
  static std::shared_ptr<WPI_TalonSRX> tal4;
  static std::shared_ptr<rev::CANSparkMax> spa2;

  static std::shared_ptr<frc::SpeedControllerGroup> scg1;
  static std::shared_ptr<frc::SpeedControllerGroup> scg2;

  static std::shared_ptr<frc::DifferentialDrive> diff;
  
  static std::shared_ptr<frc::Solenoid> sol1;/*sol is Solenoid*/
  static std::shared_ptr<frc::Solenoid> sol2;

};
