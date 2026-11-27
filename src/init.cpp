#include "comp.hpp"
#include "lemlib/api.hpp" // IWYU pragma: keep

namespace robot {
    // controller
    pros::Controller controller(pros::E_CONTROLLER_MASTER);

    // motor groups
    pros::MotorGroup left_motors(
        {-5, -20, -7},
        pros::MotorGearset::blue); // left motor group - ports 5
                                // (reversed), 20 (reversed), 7 (reversed)
    pros::MotorGroup right_motors(
        {10, 16, 18},
        pros::MotorGearset::blue); // right motor group - ports 10, 16, 18

    pros::Motor intake(13, pros::MotorGearset::blue); // intake motor - port 13
    pros::MotorGroup
        lift({3, -2},
            pros::MotorGearset::blue); // lift motor group - ports 3, 2 (reversed)
    pros::Motor claw(8, pros::MotorGearset::blue);   // claw motor - port 8
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

    void init() {
        chassis.calibrate(); // calibrate sensors
    }
}