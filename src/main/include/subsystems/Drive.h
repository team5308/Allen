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

class Drive : public frc::Subsystem {
 private:

 public:
  Drive();
  void InitDefaultCommand() override;
  void Periodic() override;
  void temp();
  void setSol();

  static std::shared_ptr<frc::Joystick> joy1;
  
  static std::shared_ptr<WPI_TalonSRX> tal1;
  static std::shared_ptr<WPI_TalonSRX> tal2;
  static std::shared_ptr<WPI_VictorSPX> vic1;

  static std::shared_ptr<WPI_TalonSRX> tal3;
  static std::shared_ptr<WPI_TalonSRX> tal4;
  static std::shared_ptr<WPI_VictorSPX> vic2;

  static std::shared_ptr<frc::SpeedControllerGroup> scg1;
  static std::shared_ptr<frc::SpeedControllerGroup> scg2;

  static std::shared_ptr<frc::DifferentialDrive> diff;
  
<<<<<<< HEAD
  static std::shared_ptr<frc::Solenoid> sol;/*sol is Solenoid*/

  static std::shared_ptr<frc::Compressor> comp;

  static std::shared_ptr<frc::JoystickButton> joyButton1;
  static std::shared_ptr<frc::JoystickButton> joyButton2;
  static std::shared_ptr<frc::JoystickButton> joyButton3;
=======
  static std::shared_ptr<frc::Solenoid> sol1;/*sol is Solenoid*/
  static std::shared_ptr<frc::Solenoid> sol2;

>>>>>>> parent of 388ad6a... Revert "Revert "Revert "merge all subsystems together  (#6)"""
};
