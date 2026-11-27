#include "lemlib/api.hpp" // IWYU pragma: keep
#pragma once

namespace robot {
    void init();
    void auton();
    void opcontrol();

    extern pros::Controller controller;

    extern pros::MotorGroup left_motors;
    extern pros::MotorGroup right_motors;
    extern pros::MotorGroup lift;

    extern pros::Motor intake;
    extern pros::Motor claw;
    extern pros::Motor wrist;

    extern pros::Rotation liftEnc;

    extern lemlib::Chassis chassis;

} // namespace robot
