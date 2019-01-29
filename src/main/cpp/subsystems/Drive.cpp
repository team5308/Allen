/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drive.h"

std::shared_ptr<frc::Joystick> Drive::joy1;

std::shared_ptr<WPI_TalonSRX> Drive::tal1;
std::shared_ptr<WPI_TalonSRX> Drive::tal2;
std::shared_ptr<WPI_VictorSPX> Drive::vic1;

std::shared_ptr<WPI_TalonSRX> Drive::tal3;
std::shared_ptr<WPI_TalonSRX> Drive::tal4;
std::shared_ptr<WPI_VictorSPX> Drive::vic2;

std::shared_ptr<frc::SpeedControllerGroup> Drive::scg1;
std::shared_ptr<frc::SpeedControllerGroup> Drive::scg2;

std::shared_ptr<frc::DifferentialDrive> Drive::diff;

std::shared_ptr<frc::Solenoid> Drive::sol1;
std::shared_ptr<frc::Solenoid> Drive::sol2;

Drive::Drive() : Subsystem("Drive") {
    joy1.reset(new frc::Joystick(0));

    tal1.reset(new WPI_TalonSRX(0));
    tal2.reset(new WPI_TalonSRX(1));
    vic1.reset(new WPI_VictorSPX(2));

    tal3.reset(new WPI_TalonSRX(3));
    tal4.reset(new WPI_TalonSRX(4));
    vic2.reset(new WPI_VictorSPX(5));

    // scg1 = std::shared_ptr<frc::SpeedControllerGroup>(*tal1, *tal2, *vic1);
    // scg2 = std::shared_ptr<frc::SpeedControllerGroup>(*tal3, *tal4, *vic2);

    scg1.reset(new frc::SpeedControllerGroup(*tal1, *tal2, *vic1));
    scg2.reset(new frc::SpeedControllerGroup(*tal3, *tal4, *vic2));
    diff.reset(new frc::DifferentialDrive(*scg1, *scg2));
}

void Drive::InitDefaultCommand() {

}

double abs(double x){
    if(x < 0){
        return -x;
    }else{
        return x;
    }
}

double suoqu(double x){
    if(abs(x) < 0.14){
        return 0.0;
    }else{
        return x;
    }
}

void Drive::Periodic(){
    diff -> ArcadeDrive(suoqu(joy1 -> GetY()), suoqu(joy1 -> GetX()));

}
