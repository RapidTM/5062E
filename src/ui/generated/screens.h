#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <ui/lvgl_compat.h>

#ifdef __cplusplus
extern "C" {
#endif

// Screens

enum ScreensEnum {
    _SCREEN_ID_FIRST = 1,
    SCREEN_ID_MAIN = 1,
    _SCREEN_ID_LAST = 1
};

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *pid_controller;
    lv_obj_t *obj2;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *pid_kp_value;
    lv_obj_t *obj6;
    lv_obj_t *obj7;
    lv_obj_t *obj8;
    lv_obj_t *obj9;
    lv_obj_t *pid_ki_value;
    lv_obj_t *obj10;
    lv_obj_t *obj11;
    lv_obj_t *obj12;
    lv_obj_t *obj13;
    lv_obj_t *pid_kd_value;
    lv_obj_t *obj14;
    lv_obj_t *obj15;
    lv_obj_t *pid_step_button;
    lv_obj_t *pid_step_value;
    lv_obj_t *pid_advanced_button;
    lv_obj_t *pid_target_caption;
    lv_obj_t *pid_target_value;
    lv_obj_t *obj16;
    lv_obj_t *pid_timeout_value;
    lv_obj_t *pid_chart;
    lv_obj_t *pid_status;
    lv_obj_t *pid_run_button;
    lv_obj_t *pid_stop_button;
    lv_obj_t *pid_reset_button;
    lv_obj_t *pid_save_button;
} objects_t;

extern objects_t objects;

typedef struct {
    lv_chart_series_t *series;
} screen_main_state_t;

extern screen_main_state_t screen_main_state;

void create_screen_main();
void tick_screen_main();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();

// Color themes

enum Themes {
    THEME_ID_RED,
    THEME_ID_BLUE,
};
enum Colors {
    COLOR_ID_PRIMDARK,
    COLOR_ID_PRIM,
    COLOR_ID_PRIMLIGHT,
    COLOR_ID_BG,
    COLOR_ID_SURFACE,
    COLOR_ID_SUBSURFACE,
    COLOR_ID_TEXT,
    COLOR_ID_SUCCESS,
    COLOR_ID_ERROR,
    COLOR_ID_BLUELIGHT,
};
void change_color_theme(uint32_t themeIndex);
extern uint32_t theme_colors[2][10];
extern uint32_t active_theme_index;

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/