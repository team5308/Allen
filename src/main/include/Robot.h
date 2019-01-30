/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019-2020 FRC Team 5308. All Rights Reserved.                */
/* Author: Cetian Liu                                                         */
/* Date: 2019/01/28                                                           */
/* Filename: Robot.cpp                                                        */
/* Project: FRC-2019-Allen                                                    */
/*----------------------------------------------------------------------------*/


#pragma once

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "OI.h"
#include "commands/MyAutoCommand.h"
#include "subsystems/Drive.h"
#include "subsystems/Rabbit.h"

class Robot : public frc::TimedRobot {
 public:
  static std::shared_ptr<Drive> DriveSystem;
  static std::shared_ptr<OI> m_oi;
  static std::shared_ptr<Rabbit> RabbitSystsem;

  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  // frc::Command* m_autonomousCommand = nullptr;
  // ExampleCommand m_defaultAuto;
  // MyAutoCommand m_myAuto;
  frc::SendableChooser<frc::Command*> m_chooser;
};
