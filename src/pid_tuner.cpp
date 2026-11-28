#include "pid_tuner.hpp"
#include <array>
#include <cmath>

namespace pid_tuner {
namespace {
// Lateral/angular settings copied from init.cpp.
// THESE ARE NOT SYNCED YET
const std::array<Profile, 3> initial{{
    {{10, 0, 5, 3, 1, 100, 3, 500, 20}, 24, 2000, true},
    {{2, 0.5, 10, 3, 1, 100, 3, 500, 0}, 90, 2000, true},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 2000, false}
}};
std::array<Profile, 3> working = initial;
std::array<Profile, 3> stored = initial;
std::size_t current = 0;
constexpr double steps[] = {0.001, 0.01, 0.1, 1.0, 10.0};
std::size_t step = 2;
const char* status = "UI only - no motion";

void selectionStatus() {
    status = working[current].defaultsKnown
        ? "UI only - no motion" : "Lift defaults not configured";
}
} // namespace

Controller selectedController() { return static_cast<Controller>(current); }
bool selectController(std::size_t index) {
    if (index >= working.size()) return false;
    current = index;
    selectionStatus();
    return true;
}
const Profile& edited() { return working[current]; }
const Profile& saved() { return stored[current]; }
const Profile& defaults() { return initial[current]; }
double increment() { return steps[step]; }
void cycleIncrement() { step = (step + 1) % (sizeof(steps)/sizeof(steps[0])); }

void adjust(Gain gain, int direction) {
    if (direction != 1 && direction != -1) return;
    auto& s = working[current].gains;
    double* value = nullptr;
    switch (gain) {
        case Gain::kP: value = &s.kP; break;
        case Gain::kI: value = &s.kI; break;
        case Gain::kD: value = &s.kD; break;
    }
    if (!value) return;
    double next = std::round((*value + increment()*direction)*1000.0)/1000.0;
    // Display bounds only, not validated physical-controller limits.
    if (next < 0.0) next = 0.0;
    if (next > 999.999) next = 999.999;
    *value = next;
    status = "Edited - not applied";
}
void reset() {
    working[current] = stored[current];
    status = "Restored RAM-saved values";
}
void save() {
    stored[current] = working[current];
    status = "Saved in RAM only";
}
void requestTest() { status = "Run unavailable - UI only"; }
void requestStop() { status = "No active test"; }
const char* statusText() { return status; }
} // namespace pid_tuner
