/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drive.h"

std::shared_ptr<frc::Joystick> Drive::joy1;

std::shared_ptr<rev::CANSparkMax> Drive::spaD1;
std::shared_ptr<rev::CANSparkMax> Drive::spaD2;
std::shared_ptr<WPI_TalonSRX> Drive::talD1;

std::shared_ptr<rev::CANSparkMax> Drive::spaD3;
std::shared_ptr<rev::CANSparkMax> Drive::spaD4;
std::shared_ptr<WPI_TalonSRX> Drive::talD2;

std::shared_ptr<frc::SpeedControllerGroup> Drive::scg1;
std::shared_ptr<frc::SpeedControllerGroup> Drive::scg2;

std::shared_ptr<frc::DifferentialDrive> Drive::diff;

std::shared_ptr<frc::Solenoid> Drive::sol1;
std::shared_ptr<frc::Solenoid> Drive::sol2;

Drive::Drive() : Subsystem("Drive") {
    joy1.reset(new frc::Joystick(0));

    spaD1.reset(new rev::CANSparkMax(6,rev::CANSparkMax::Motortype::kBrushless));
    spaD2.reset(new rev::CANSparkMax(7,rev::CANSparkMax::Motortype::kBrushed));
    talD1.reset(new WPI_TalonSRX(2));

    spaD3.reset(new rev::CANSparkMax(8,rev::CANSparkMax::Motortype::kBrushless));
    spaD4.reset(new rev::CANSparkMax(9,rev::CANSparkMax::Motortype::kBrushed));
    talD2.reset(new WPI_TalonSRX(3));

     scg1 = std::make_shared<frc::SpeedControllerGroup>(*spaD1, *spaD2, *talD1);
     scg2 = std::make_shared<frc::SpeedControllerGroup>(*spaD3, *spaD4, *talD2);

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
