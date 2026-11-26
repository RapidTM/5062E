#include "main.h"
#include "lemlib-tarball/api.hpp"
#include "lemlib/api.hpp" // IWYU pragma: keep

void init_test_ui();

// controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// motor groups
pros::MotorGroup
    left_motors({-5, -20, -7},
                pros::MotorGearset::blue); // left motor group - ports 5
                                           // (reversed), 20 (reversed), 7 (reversed)
pros::MotorGroup right_motors(
    {10, 16, 18},
    pros::MotorGearset::blue); // right motor group - ports 10, 16, 18

pros::Motor intake(13, pros::MotorGearset::blue); // intake motor - port 13
pros::MotorGroup
    lift({3, -2},
         pros::MotorGearset::blue); // lift motor group - ports 3, 2 (reversed)
pros::Motor claw(8, pros::MotorGearset::blue);  // claw motor - port 8
pros::Motor wrist(19, pros::MotorGearset::blue); // wrist motor - port 19

// extra encoder on lift - port 4
pros::Rotation liftEnc(4);

// Inertial Sensor on port 1
pros::Imu imu(1);

// tracking wheels
// horizontal tracking wheel encoder. Rotation sensor, port 11, reversed
pros::Rotation horizontalEnc(-11);
// vertical tracking wheel encoder. Rotation sensor, port 12, not reversed
pros::Rotation verticalEnc(12);
// horizontal tracking wheel. 2.75" diameter, 5.75" offset, back of the robot
// (negative)
lemlib::TrackingWheel horizontal(&horizontalEnc, lemlib::Omniwheel::NEW_275,
                                 -5.75);
// vertical tracking wheel. 2.75" diameter, 2.5" offset, left of the robot
// (negative)
lemlib::TrackingWheel vertical(&verticalEnc, lemlib::Omniwheel::NEW_275, -2.5);

// drivetrain settings
lemlib::Drivetrain drivetrain(
    &left_motors,               // left motor group
    &right_motors,              // right motor group
    10.75,                      // 10 inch track width
    lemlib::Omniwheel::NEW_325, // using new 3.25" omnis
    450,                        // drivetrain rpm is 450
    2 // horizontal drift is 2. If we had traction wheels, it would have been 8
);

// lateral motion controller
lemlib::ControllerSettings
    linearController(10,  // proportional gain (kP)
                     0,   // integral gain (kI)
                     5,   // derivative gain (kD)
                     3,   // anti windup
                     1,   // small error range, in inches
                     100, // small error range timeout, in milliseconds
                     3,   // large error range, in inches
                     500, // large error range timeout, in milliseconds
                     20   // maximum acceleration (slew)
    );

// angular motion controller
lemlib::ControllerSettings
    angularController(2,   // proportional gain (kP)
                      .5,  // integral gain (kI)
                      10,  // derivative gain (kD)
                      3,   // anti windup
                      1,   // small error range, in degrees
                      100, // small error range timeout, in milliseconds
                      3,   // large error range, in degrees
                      500, // large error range timeout, in milliseconds
                      0    // maximum acceleration (slew)
    );

// sensors for odometry
lemlib::OdomSensors sensors(&vertical, // vertical tracking wheel
                            nullptr,   // vertical tracking wheel 2, set to
                                       // nullptr as we don't have a second one
                            &horizontal, // horizontal tracking wheel
                            nullptr,     // horizontal tracking wheel 2, set to
                                     // nullptr as we don't have a second one
                            &imu // inertial sensor
);

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve
    throttleCurve(3,    // joystick deadband out of 127
                  10,   // minimum output where drivetrain will move out of 127
                  1.019 // expo curve gain
    );

// input curve for steer input during driver control
lemlib::ExpoDriveCurve
    steerCurve(3,    // joystick deadband out of 127
               10,   // minimum output where drivetrain will move out of 127
               1.019 // expo curve gain
    );

// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController,
                        sensors, &throttleCurve, &steerCurve);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  chassis.calibrate();     // calibrate sensors

  init_test_ui();
}

/**
 * Runs while the robot is disabled
 */
void disabled() {}

/**
 * runs after initialize if the robot is connected to field control
 */
void competition_initialize() {}

// get a path used for pure pursuit
// this needs to be put outside a function
ASSET(project_example_txt);

/**
 * Runs during auto
 *
 * This is an example autonomous routine which demonstrates a lot of the
 * features LemLib has to offer
 */
void autonomous() {

    /**
     * Alliance goal score (5pt)
     * Start at -60, -59, 270
     * Preload with alliance color facing the claw 
     * (such that yellow will be oriented downwards)
     */

    pros::lcd::print(4, "Autonomous started...");

    //set assembly motors to lock position when not moving
    wrist.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    //reset the pose of the robot to the known starting position
    chassis.setPose(-60, -59, 270);

    //drive to -48, -59 backwards (heading is still 270 degrees) with speed limit 70
    chassis.moveToPoint(-48, -59, 4000, {.forwards = false, .maxSpeed = 70});

    //turn towards, then drive to -48, -32 backwards (heading is still 270 degrees) with speed limit 70
    chassis.turnToPoint(-48, -32, 1000, {.forwards = false, .maxSpeed = 70});
    chassis.moveToPoint(-48, -32, 4000, {.forwards = false, .maxSpeed = 70});

    //move the wrist to goal position 800 (in decadegrees)
    wrist.move_relative(800, 127);

    //outtake preload pin 
    claw.move_relative(-1000, 127);


  // wait until the movement is done
  chassis.waitUntilDone();
  pros::lcd::print(5, "Autonomous finished!");
}

/**
 * Runs in driver control
 */
void opcontrol() {

    //reset lift and wrist to 0 degrees
    liftEnc.reset_position();
    wrist.tare_position();
    //set assembly motors to lock position when not moving
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

    //intake control - L1 for intake, L2 for outtake, otherwise stop (no lock)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      intake.move(85);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      intake.move(-85);
    } else {
      intake.move(0);
    }

    //lift control - R1/R2 for slow lift, left/right for fast lift, otherwise stop (lock)
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

    //double toggle for claw control - A for forward, B for reverse, otherwise stop (no lock) (it's janky!)
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

    //move the claw based on the toggle state
    if (clawFwd) {
      claw.move(127);
    } else if (clawRev) {
      claw.move(-127);
    } else {
      claw.move(0);
    }

    //wrist control - up for forward, down for reverse, otherwise stop (lock)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
      wrist.move(60);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
      wrist.move(-60);
    } else {
      wrist.move_velocity(0);
    }

    //goal height macro - X button for goal height 17000 (in centidegrees)
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
      while (liftEnc.get_position() < 17000) {
        lift.move(90);
        //pros::delay(200);
        //wrist.move_absolute(0, 127);
      }
      while (liftEnc.get_position() > 17000) {
        lift.move(-90);
        //pros::delay(200);
        //wrist.move_absolute(0, 127);
      }
    }

  }
}