/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "rev/SparkMax.h"
#include "rev/CANSparkMax.h"
#include "frc/Encoder.h"
#include <frc/WPILib.h>
#include <ctre/Phoenix.h>


class Elevator : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  Elevator();
  void InitDefaultCommand() override;

  static std::shared_ptr<rev::CANSparkMax> spaMain1;
  static std::shared_ptr<rev::CANSparkMax> spaMain2;
  static std::shared_ptr<rev::CANEncoder> encoMain;
  
  static std::shared_ptr<frc::SpeedControllerGroup> eleMain;

  static std::shared_ptr<WPI_TalonSRX> talSub;
  static std::shared_ptr<frc::Encoder> encoSub;

};
