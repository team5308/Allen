/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Elevator.h"
#include <stdio.h>
#include <iostream>
#include <time.h>

std::shared_ptr<rev::CANSparkMax> Elevator::spaMain1;
std::shared_ptr<rev::CANSparkMax> Elevator::spaMain2;
std::shared_ptr<rev::CANEncoder> Elevator::encoMain;
  
std::shared_ptr<frc::SpeedControllerGroup> Elevator::eleMain;

std::shared_ptr<WPI_TalonSRX> Elevator::talSub;
std::shared_ptr<frc::Encoder> Elevator::encoSub;


Elevator::Elevator() : Subsystem("ExampleSubsystem") {
  spaMain1.reset(new rev::CANSparkMax(0, rev::CANSparkMax::MotorType::kBrushless));
  spaMain2.reset(new rev::CANSparkMax(1, rev::CANSparkMax::MotorType::kBrushless));
  encoMain.reset(new rev::CANEncoder(*spaMain1));

  eleMain = std::make_shared<frc::SpeedControllerGroup>(*spaMain1,*spaMain2);

  talSub.reset(new WPI_TalonSRX(0));
  encoSub.reset(new frc::Encoder(0,1));

}

void Elevator::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
