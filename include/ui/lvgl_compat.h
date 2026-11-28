#pragma once

#include "liblvgl/lvgl.h"

#if LVGL_VERSION_MAJOR == 9

// Screen management
#define lv_scr_act lv_screen_active
#define lv_scr_load lv_screen_load
#define lv_scr_load_anim lv_screen_load_anim
#define lv_scr_load_anim_t lv_screen_load_anim_t

// Display management
#define lv_disp_t lv_display_t
#define lv_disp_get_default lv_display_get_default
#define lv_disp_set_default lv_display_set_default
#define lv_disp_set_theme lv_display_set_theme
#define lv_disp_get_theme lv_display_get_theme

// Images
#define lv_img_dsc_t lv_image_dsc_t
#define lv_img_create lv_image_create
#define lv_img_set_src lv_image_set_src
#define lv_img_get_src lv_image_get_src
#define lv_img_set_angle lv_image_set_rotation
#define lv_img_set_zoom lv_image_set_scale

// Buttons
#define lv_btn_create lv_button_create
#define lv_btnmatrix_create lv_buttonmatrix_create

// Object management
#define lv_obj_del lv_obj_delete
#define lv_obj_del_async lv_obj_delete_async
#define lv_obj_clear_flag lv_obj_remove_flag
#define lv_obj_clear_state lv_obj_remove_state
#define lv_obj_get_child_cnt lv_obj_get_child_count
#define lv_obj_get_disp lv_obj_get_display

// Tabviews
#define lv_tabview_get_tab_btns lv_tabview_get_tab_bar
#define lv_tabview_get_tab_act lv_tabview_get_tab_active
#define lv_tabview_set_act lv_tabview_set_active

// Timers
#define lv_timer_del lv_timer_delete

// Animations
#define lv_anim_del lv_anim_delete
#define lv_anim_del_all lv_anim_delete_all
#define lv_anim_set_ready_cb lv_anim_set_completed_cb

// Styles
#define lv_obj_set_style_img_opa lv_obj_set_style_image_opa
#define lv_obj_set_style_img_recolor lv_obj_set_style_image_recolor
#define lv_obj_set_style_anim_time lv_obj_set_style_anim_duration
#define lv_obj_set_style_shadow_ofs_x lv_obj_set_style_shadow_offset_x
#define lv_obj_set_style_shadow_ofs_y lv_obj_set_style_shadow_offset_y
#define lv_style_set_img_opa lv_style_set_image_opa
#define lv_style_set_img_recolor lv_style_set_image_recolor
#define lv_style_set_anim_time lv_style_set_anim_duration
#define lv_style_set_shadow_ofs_x lv_style_set_shadow_offset_x
#define lv_style_set_shadow_ofs_y lv_style_set_shadow_offset_y

// Constants
#define LV_RES_OK LV_RESULT_OK
#define LV_RES_INV LV_RESULT_INVALID
#define LV_ZOOM_NONE LV_SCALE_NONE

// Types
#define lv_coord_t int32_t
#define lv_res_t lv_result_t
#define lv_anim_ready_cb_t lv_anim_completed_cb_t

#endif