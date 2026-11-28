#include "ui/pid_ui.hpp"
#include "pid_tuner.hpp"
#include "generated/actions.h"
#include "generated/screens.h"
#include <cstdio>

namespace {
using pid_tuner::Gain;

void setNumber(lv_obj_t* label, double value, int decimals) {
    if (!label) return;
    char buffer[32];
    std::snprintf(buffer, sizeof(buffer), "%.*f", decimals, value);
    lv_label_set_text(label, buffer);
}
void setText(lv_obj_t* label, const char* text) {
    if (label) lv_label_set_text(label, text);
}
void adjustAndRefresh(Gain gain, int direction) {
    pid_tuner::adjust(gain, direction);
    pid_ui::refresh();
}
} // namespace

namespace pid_ui {
void init() {
    if (objects.pid_controller) {
        lv_dropdown_set_selected(objects.pid_controller,
            static_cast<unsigned>(pid_tuner::selectedController()));
    }
    refresh();
}
void refresh() {
    const auto& profile = pid_tuner::edited();
    setNumber(objects.pid_kp_value, profile.gains.kP, 3);
    setNumber(objects.pid_ki_value, profile.gains.kI, 3);
    setNumber(objects.pid_kd_value, profile.gains.kD, 3);
    setNumber(objects.pid_step_value, pid_tuner::increment(), 3);
    switch (pid_tuner::selectedController()) {
        case pid_tuner::Controller::Lateral:
            setText(objects.pid_target_caption, "Target (in)");
            setNumber(objects.pid_target_value, profile.target, 1);
            break;
        case pid_tuner::Controller::Angular:
            setText(objects.pid_target_caption, "Target (deg)");
            setNumber(objects.pid_target_value, profile.target, 1);
            break;
        case pid_tuner::Controller::Lift:
            setText(objects.pid_target_caption, "Target");
            setText(objects.pid_target_value, "N/A");
            break;
    }
    setNumber(objects.pid_timeout_value, profile.timeoutMs, 0);
    setText(objects.pid_status, pid_tuner::statusText());
}
} // namespace pid_ui

// Native Actions in generated actions.h.
extern "C" {
void action_pid_kp_inc(lv_event_t*) { adjustAndRefresh(Gain::kP, 1); }
void action_pid_kp_dec(lv_event_t*) { adjustAndRefresh(Gain::kP, -1); }
void action_pid_ki_inc(lv_event_t*) { adjustAndRefresh(Gain::kI, 1); }
void action_pid_ki_dec(lv_event_t*) { adjustAndRefresh(Gain::kI, -1); }
void action_pid_kd_inc(lv_event_t*) { adjustAndRefresh(Gain::kD, 1); }
void action_pid_kd_dec(lv_event_t*) { adjustAndRefresh(Gain::kD, -1); }

// For Step, each click cycles to the next value.
void action_pid_increment_changed(lv_event_t*) {
    pid_tuner::cycleIncrement();
    pid_ui::refresh();
}
void action_pid_controller_changed(lv_event_t*) {
    if (objects.pid_controller && pid_tuner::selectController(
            lv_dropdown_get_selected(objects.pid_controller))) {
        pid_ui::refresh();
    }
}
void action_pid_reset(lv_event_t*) { pid_tuner::reset(); pid_ui::refresh(); }
void action_pid_save(lv_event_t*) { pid_tuner::save(); pid_ui::refresh(); }
void action_pid_run(lv_event_t*) { pid_tuner::requestTest(); pid_ui::refresh(); }
void action_pid_stop(lv_event_t*) { pid_tuner::requestStop(); pid_ui::refresh(); }
} // extern "C"
