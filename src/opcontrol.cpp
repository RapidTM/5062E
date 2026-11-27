#include "comp.hpp"
#include "lemlib/api.hpp" // IWYU pragma: keep

void robot::opcontrol() {
  // reset lift and wrist to 0 degrees
  liftEnc.reset_position();
  wrist.tare_position();
  // set assembly motors to lock position when not moving
  lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  wrist.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  bool clawFwd = false;
  bool clawRev = false;

  // controller
  // loop to continuously update motors
  while (true) {
    // get joystick positions
    int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    // move the chassis with curvature drive
    chassis.arcade(leftY, rightX);
    // delay to save resources
    pros::delay(10);

    // intake control - L1 for intake, L2 for outtake, otherwise stop (no lock)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      intake.move(85);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      intake.move(-85);
    } else {
      intake.move(0);
    }

    // lift control - R1/R2 for slow lift, left/right for fast lift, otherwise
    // stop (lock)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) and
        liftEnc.get_position() < 200000) {
      lift.move(60);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) and
               liftEnc.get_position() > 200) {
      lift.move(-60);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) and
               liftEnc.get_position() < 200000) {
      lift.move(127);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT) and
               liftEnc.get_position() > 200) {
      lift.move(-127);
    } else {
      lift.move_velocity(0);
    }

    // double toggle for claw control - A for forward, B for reverse, otherwise
    // stop (no lock) (it's janky!)
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
      if (!clawFwd and !clawRev) {
        clawFwd = true;
      } else {
        clawFwd = false;
        clawRev = false;
      }
    } else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
      if (!clawFwd and !clawRev) {
        clawRev = true;
      } else {
        clawFwd = false;
        clawRev = false;
      }
    }

    // move the claw based on the toggle state
    if (clawFwd) {
      claw.move(127);
    } else if (clawRev) {
      claw.move(-127);
    } else {
      claw.move(0);
    }

    // wrist control - up for forward, down for reverse, otherwise stop (lock)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
      wrist.move(60);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
      wrist.move(-60);
    } else {
      wrist.move_velocity(0);
    }

    // goal height macro - X button for goal height 17000 (in centidegrees)
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
      while (liftEnc.get_position() < 17000) {
        lift.move(90);
        // pros::delay(200);
        // wrist.move_absolute(0, 127);
      }
      while (liftEnc.get_position() > 17000) {
        lift.move(-90);
        // pros::delay(200);
        // wrist.move_absolute(0, 127);
      }
    }
  }
}