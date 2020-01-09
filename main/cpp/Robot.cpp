/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/GenericHID.h>
#include <frc/PWMVictorSPX.h>
#include <frc/TimedRobot.h>
#include <frc/XboxController.h>
#include <frc/drive/DifferentialDrive.h>
#include "rev/CANSparkMax.h"

/**
 * This is a demo program showing the use of the DifferentialDrive class.
 * Runs the motors with tank steering and an Xbox controller.
 */
class Robot : public frc::TimedRobot {
  rev::CANSparkMax m_leftMotor{2, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_rightMotor{5, rev::CANSparkMax::MotorType::kBrushless};
  frc::DifferentialDrive m_robotDrive{m_leftMotor, m_rightMotor};
  frc::XboxController m_driverController{0};

 public:
  void TeleopPeriodic() {
    // Drive with tank style
    m_robotDrive.TankDrive(
        m_driverController.GetY(frc::GenericHID::JoystickHand::kLeftHand),
        m_driverController.GetY(frc::GenericHID::JoystickHand::kRightHand));
  }
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
