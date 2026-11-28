#pragma once

#include <cstddef>

// UI-only configuration model. No motor, sensor, or LemLib calls.
// All functions are called from the LVGL context
namespace pid_tuner {

enum class Controller { Lateral, Angular, Lift };
enum class Gain { kP, kI, kD };

struct Settings {
    double kP, kI, kD;
    double windupRange, smallError;
    int smallErrorTimeout;
    double largeError;
    int largeErrorTimeout;
    double slew;
};

struct Profile {
    Settings gains;
    double target;
    int timeoutMs;
    bool defaultsKnown;
};

Controller selectedController();
bool selectController(std::size_t index);
const Profile& edited();
const Profile& saved();
const Profile& defaults();
double increment();
void cycleIncrement();
void adjust(Gain gain, int direction);
void reset(); // restore last RAM-saved profile
void save();  // RAM only; does not apply to chassis
void requestTest(); // intentionally no motion
void requestStop();
const char* statusText();

} // namespace pid_tuner
