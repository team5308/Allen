/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Rabbit.h"

/* static Rabbit */
std::shared_ptr<WPI_TalonSRX> Rabbit::ratTal;
std::shared_ptr<rev::CANSparkMax> Rabbit::rabSpark;
std::shared_ptr<rev::CANEncoder> Rabbit::rabEncoder;
std::shared_ptr<Solenoid> Rabbit::rabSole;

/* static Deanck*/
std::shared_ptr<Solenoid> Rabbit::deLift;
std::shared_ptr<Solenoid> Rabbit::deDick;


Rabbit::Rabbit() : Subsystem("Rabbit") 
{
    /* Rabit */
    ratTal.reset(new WPI_TalonSRX());
    rabSpark.reset(new rabSpark());
    rabEncoder.reset(new rev::CANEncoder(*rabSpark));  

    rabStPos = rabEncoder->GetPosition();
}

void Rabbit::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

double Rabbit::getPosition()
{
  return (rabEncoder->GetPosition() - rabStPos); 
}

void Rabbit::rabDown()
{
  while(getPosition()>0)
  {
    rabSpark->Set(0.5);
  }  
}

void Rabbit::rabStand()
{
  while(getPosition()<0.5)
  {
    rabSpark->Set(-0.5);
  }  
}