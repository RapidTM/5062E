#include "main.h"
#include "comp.hpp"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "ui/ui.hpp"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 *
 * Initializes PROS and LemLib objects
 *
 * You must call any robot object (like chassis) in the "robot" namespace.
 * Use either 'robot::' or the function 'namespace robot {}'
 * around any usages.
 */

void initialize() {
  robot::init();
  ui::init();
}

/**
 * Runs while the robot is disabled
 */
void disabled() {}

/**
 * Runs after initialize if the robot is connected to field control
 */
void competition_initialize() {}


/**
 * Runs during auto
 */
void autonomous() {
  robot::auton();
}

/**
 * Runs in driver control
 */
void opcontrol() {
  robot::opcontrol();
}