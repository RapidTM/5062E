#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <ui/lvgl_compat.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_pid_kp_inc(lv_event_t * e);
extern void action_pid_kp_dec(lv_event_t * e);
extern void action_pid_ki_inc(lv_event_t * e);
extern void action_pid_ki_dec(lv_event_t * e);
extern void action_pid_kd_inc(lv_event_t * e);
extern void action_pid_kd_dec(lv_event_t * e);
extern void action_pid_increment_changed(lv_event_t * e);
extern void action_pid_controller_changed(lv_event_t * e);
extern void action_pid_run(lv_event_t * e);
extern void action_pid_stop(lv_event_t * e);
extern void action_pid_reset(lv_event_t * e);
extern void action_pid_save(lv_event_t * e);

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/