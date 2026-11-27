#include "comp.hpp"
#include "lemlib-tarball/api.hpp"
#include "lemlib/api.hpp" // IWYU pragma: keep


// get a path used for pure pursuit
// this needs to be put outside a function
ASSET(project_example_txt);

void robot::auton() {

  /**
   * Alliance goal score (5pt)
   * Start at -60, -59, 270
   * Preload with alliance color facing the claw
   * (such that yellow will be oriented downwards)
   */

  // set assembly motors to lock position when not moving
  wrist.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  // reset the pose of the robot to the known starting position
  chassis.setPose(-60, -59, 270);

  // drive to -48, -59 backwards (heading is still 270 degrees) with speed limit
  // 70
  chassis.moveToPoint(-48, -59, 4000, {.forwards = false, .maxSpeed = 70});

  // turn towards, then drive to -48, -32 backwards (heading is still 270
  // degrees) with speed limit 70
  chassis.turnToPoint(-48, -32, 1000, {.forwards = false, .maxSpeed = 70});
  chassis.moveToPoint(-48, -32, 4000, {.forwards = false, .maxSpeed = 70});

  // move the wrist to goal position 800 (in decadegrees)
  wrist.move_relative(800, 127);

  // outtake preload pin
  claw.move_relative(-1000, 127);

  // wait until the movement is done
  chassis.waitUntilDone();
}