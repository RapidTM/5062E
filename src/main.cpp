#include "main.h"
#include "comp.hpp"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "ui.hpp"


/**
 * Initializes PROS and LemLib objects
 *
 * Must call any object (like chassis) in the "robot" namespace.
 * Use either 'robot::' or the function 'namespace robot {}'
 * around any usages.
 * 
 *       <<<<<ALSO RUNS CHASSIS CALIBRATION>>>>>
 * <<<<<DO NOT SEPARATE FROM 'void intitialize()'>>>>>
 */

void robot::init();

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize() {
  ui::ui();
}

/**
 * Runs while the robot is disabled
 */
void disabled() {}

/**
 * runs after initialize if the robot is connected to field control
 */
void competition_initialize() {}


/**
 * Runs during auto
 *
 * This is an example autonomous routine which demonstrates a lot of the
 * features LemLib has to offer
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