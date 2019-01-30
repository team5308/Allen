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


class Cargon : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  Cargon();
  void InitDefaultCommand() override;
  void Periodic() override;
  void rotate(int);
  void catIn();
  void dragonOut();
  double calDiff(int);

  static std::shared_ptr<frc::Joystick> joy1;

  static std::shared_ptr<WPI_VictorSPX> draVic1; /*Dragon VictorSPX*/
  static std::shared_ptr<WPI_VictorSPX> draVic2;

  static std::shared_ptr<WPI_VictorSPX> catVic; /*Cat VictorSPX*/
  static std::shared_ptr<rev::CANSparkMax> catSpark; /*Cat SparkMax*/

  static std::shared_ptr<rev::CANEncoder> catEncoder;
};
