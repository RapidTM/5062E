#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;

screen_main_state_t screen_main_state;

//
// Event handlers
//

lv_obj_t *tick_value_change_obj;

//
// Screens
//

void create_screen_main() {
    screen_main_state_t *state = &screen_main_state;
    (void)state;
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_tabview_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 240);
            lv_tabview_set_tab_bar_position(obj, LV_DIR_TOP);
            lv_tabview_set_tab_bar_size(obj, 32);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_tabview_get_tab_bar(parent_obj);
                    objects.obj1 = obj;
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_radius(obj, 6, LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_clip_corner(obj, true, LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_ITEMS | LV_STATE_PRESSED);
                    lv_obj_set_style_bg_opa(obj, 192, LV_PART_ITEMS | LV_STATE_PRESSED);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_ITEMS | LV_STATE_CHECKED | LV_STATE_PRESSED);
                    lv_obj_set_style_bg_opa(obj, 192, LV_PART_ITEMS | LV_STATE_CHECKED | LV_STATE_PRESSED);
                    lv_obj_set_style_height(obj, 28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_column(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_tabview_get_content(parent_obj);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Home");
                        }
                        {
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Auton");
                        }
                        {
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "PID");
                            lv_obj_set_style_x(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 164, 156);
                                    add_style_panel(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            // pid_controller
                                            lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                            objects.pid_controller = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 150, 24);
                                            lv_dropdown_set_options_static(obj, "Lateral PID\nAngular PID\nLift PID");
                                            lv_dropdown_set_selected(obj, 0);
                                            lv_obj_add_event_cb(obj, action_pid_controller_changed, LV_EVENT_VALUE_CHANGED, (void *)0);
                                            lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                                            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_PRESSED);
                                            lv_obj_set_style_bg_opa(obj, 192, LV_PART_MAIN | LV_STATE_PRESSED);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_dropdown_get_list(parent_obj);
                                                    objects.obj2 = obj;
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_width(obj, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_left(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_translate_y(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_line_space(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_SELECTED | LV_STATE_CHECKED);
                                                    lv_obj_set_style_radius(obj, 12, LV_PART_SELECTED | LV_STATE_CHECKED);
                                                    lv_obj_set_style_border_width(obj, 6, LV_PART_SELECTED | LV_STATE_CHECKED);
                                                    lv_obj_set_style_border_opa(obj, 255, LV_PART_SELECTED | LV_STATE_CHECKED);
                                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_SELECTED | LV_STATE_CHECKED);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_SELECTED | LV_STATE_CHECKED);
                                                    lv_obj_set_style_radius(obj, 12, LV_PART_SELECTED | LV_STATE_PRESSED);
                                                    lv_obj_set_style_border_opa(obj, 255, LV_PART_SELECTED | LV_STATE_PRESSED);
                                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_SELECTED | LV_STATE_PRESSED);
                                                    lv_obj_set_style_border_width(obj, 6, LV_PART_SELECTED | LV_STATE_PRESSED);
                                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_SELECTED | LV_STATE_PRESSED);
                                                    lv_obj_set_style_transform_height(obj, 0, LV_PART_SELECTED | LV_STATE_PRESSED);
                                                    lv_obj_set_style_transform_width(obj, 0, LV_PART_SELECTED | LV_STATE_PRESSED);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_SELECTED | LV_STATE_PRESSED);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_SELECTED | LV_STATE_PRESSED);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_SELECTED | LV_STATE_CHECKED | LV_STATE_PRESSED);
                                                    lv_obj_set_style_bg_opa(obj, 192, LV_PART_SELECTED | LV_STATE_CHECKED | LV_STATE_PRESSED);
                                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_SELECTED | LV_STATE_CHECKED | LV_STATE_PRESSED);
                                                    lv_obj_set_style_border_opa(obj, 255, LV_PART_SELECTED | LV_STATE_CHECKED | LV_STATE_PRESSED);
                                                    lv_obj_set_style_border_width(obj, 6, LV_PART_SELECTED | LV_STATE_CHECKED | LV_STATE_PRESSED);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 30);
                                            lv_obj_set_size(obj, 150, 24);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj3 = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 24, 24);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "kP");
                                                }
                                                {
                                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                                    objects.obj4 = obj;
                                                    lv_obj_set_pos(obj, 28, -2);
                                                    lv_obj_set_size(obj, 24, 24);
                                                    lv_obj_add_event_cb(obj, action_pid_kp_dec, LV_EVENT_CLICKED, (void *)0);
                                                    add_style_base(obj);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 18, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_PRESSED);
                                                    lv_obj_set_style_bg_opa(obj, 192, LV_PART_MAIN | LV_STATE_PRESSED);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "-");
                                                        }
                                                    }
                                                }
                                                {
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.obj5 = obj;
                                                    lv_obj_set_pos(obj, 58, 0);
                                                    lv_obj_set_size(obj, 62, 24);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // pid_kp_value
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.pid_kp_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "10.000");
                                                        }
                                                    }
                                                }
                                                {
                                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                                    objects.obj6 = obj;
                                                    lv_obj_set_pos(obj, 126, 0);
                                                    lv_obj_set_size(obj, 24, 24);
                                                    lv_obj_add_event_cb(obj, action_pid_kp_inc, LV_EVENT_CLICKED, (void *)0);
                                                    add_style_base(obj);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_PRESSED);
                                                    lv_obj_set_style_bg_opa(obj, 192, LV_PART_MAIN | LV_STATE_PRESSED);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "+");
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 60);
                                            lv_obj_set_size(obj, 150, 24);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj7 = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 24, 24);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "kI");
                                                }
                                                {
                                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                                    objects.obj8 = obj;
                                                    lv_obj_set_pos(obj, 28, 0);
                                                    lv_obj_set_size(obj, 24, 24);
                                                    lv_obj_add_event_cb(obj, action_pid_ki_dec, LV_EVENT_CLICKED, (void *)0);
                                                    add_style_base(obj);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 18, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_PRESSED);
                                                    lv_obj_set_style_bg_opa(obj, 192, LV_PART_MAIN | LV_STATE_PRESSED);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "-");
                                                        }
                                                    }
                                                }
                                                {
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.obj9 = obj;
                                                    lv_obj_set_pos(obj, 58, 0);
                                                    lv_obj_set_size(obj, 62, 24);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // pid_ki_value
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.pid_ki_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0.000");
                                                        }
                                                    }
                                                }
                                                {
                                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                                    objects.obj10 = obj;
                                                    lv_obj_set_pos(obj, 126, 0);
                                                    lv_obj_set_size(obj, 24, 24);
                                                    lv_obj_add_event_cb(obj, action_pid_ki_inc, LV_EVENT_CLICKED, (void *)0);
                                                    add_style_base(obj);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_PRESSED);
                                                    lv_obj_set_style_bg_opa(obj, 192, LV_PART_MAIN | LV_STATE_PRESSED);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "+");
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 90);
                                            lv_obj_set_size(obj, 150, 24);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj11 = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 24, 24);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "kD");
                                                }
                                                {
                                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                                    objects.obj12 = obj;
                                                    lv_obj_set_pos(obj, 28, 0);
                                                    lv_obj_set_size(obj, 24, 24);
                                                    lv_obj_add_event_cb(obj, action_pid_kd_dec, LV_EVENT_CLICKED, (void *)0);
                                                    add_style_base(obj);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 18, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_PRESSED);
                                                    lv_obj_set_style_bg_opa(obj, 192, LV_PART_MAIN | LV_STATE_PRESSED);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "-");
                                                        }
                                                    }
                                                }
                                                {
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.obj13 = obj;
                                                    lv_obj_set_pos(obj, 58, 0);
                                                    lv_obj_set_size(obj, 62, 24);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // pid_kd_value
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.pid_kd_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "3.000");
                                                        }
                                                    }
                                                }
                                                {
                                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                                    objects.obj14 = obj;
                                                    lv_obj_set_pos(obj, 126, 0);
                                                    lv_obj_set_size(obj, 24, 24);
                                                    lv_obj_add_event_cb(obj, action_pid_kd_inc, LV_EVENT_CLICKED, (void *)0);
                                                    add_style_base(obj);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_PRESSED);
                                                    lv_obj_set_style_bg_opa(obj, 192, LV_PART_MAIN | LV_STATE_PRESSED);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "+");
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 120);
                                            lv_obj_set_size(obj, 150, 24);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj15 = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Step");
                                                }
                                                {
                                                    // pid_step_button
                                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                                    objects.pid_step_button = obj;
                                                    lv_obj_set_pos(obj, 28, 0);
                                                    lv_obj_set_size(obj, 58, 24);
                                                    lv_obj_add_event_cb(obj, action_pid_increment_changed, LV_EVENT_CLICKED, (void *)0);
                                                    add_style_base(obj);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 18, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 192, LV_PART_MAIN | LV_STATE_PRESSED);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // pid_step_value
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.pid_step_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0.100");
                                                        }
                                                    }
                                                }
                                                {
                                                    // pid_advanced_button
                                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                                    objects.pid_advanced_button = obj;
                                                    lv_obj_set_pos(obj, 91, 0);
                                                    lv_obj_set_size(obj, 58, 24);
                                                    add_style_base(obj);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_PRESSED);
                                                    lv_obj_set_style_bg_opa(obj, 192, LV_PART_MAIN | LV_STATE_PRESSED);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "Advanced");
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 162);
                                    lv_obj_set_size(obj, 79, 32);
                                    add_style_panel(obj);
                                    lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            // pid_target_caption
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.pid_target_caption = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "Target (in)");
                                        }
                                        {
                                            // pid_target_value
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.pid_target_value = obj;
                                            lv_obj_set_pos(obj, 0, 12);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "24.0");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 85, 162);
                                    lv_obj_set_size(obj, 79, 32);
                                    add_style_panel(obj);
                                    lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj16 = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "Timeout (ms)");
                                        }
                                        {
                                            // pid_timeout_value
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.pid_timeout_value = obj;
                                            lv_obj_set_pos(obj, 0, 12);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "2000");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 170, 0);
                                    lv_obj_set_size(obj, 298, 156);
                                    add_style_panel(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            // pid_chart
                                            lv_obj_t *obj = lv_chart_create(parent_obj);
                                            objects.pid_chart = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 286, 102);
                                            lv_chart_set_point_count(obj, 10);
                                            lv_chart_set_div_line_count(obj, 3, 5);
                                            lv_chart_series_t *ser0 = lv_chart_add_series(obj, lv_color_hex(0x2196f3), LV_CHART_AXIS_PRIMARY_Y);
                                            state->series = ser0;
                                        }
                                        {
                                            // pid_status
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.pid_status = obj;
                                            lv_obj_set_pos(obj, 0, 110);
                                            lv_obj_set_size(obj, 282, 18);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "UI only - no motion");
                                        }
                                    }
                                }
                                {
                                    // pid_run_button
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.pid_run_button = obj;
                                    lv_obj_set_pos(obj, 170, 162);
                                    lv_obj_set_size(obj, 70, 32);
                                    lv_obj_add_event_cb(obj, action_pid_run, LV_EVENT_CLICKED, (void *)0);
                                    add_style_base(obj);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][7]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_transform_height(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_transform_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_bg_opa(obj, 192, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][7]), LV_PART_MAIN | LV_STATE_PRESSED);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "Run");
                                        }
                                    }
                                }
                                {
                                    // pid_stop_button
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.pid_stop_button = obj;
                                    lv_obj_set_pos(obj, 246, 162);
                                    lv_obj_set_size(obj, 70, 32);
                                    lv_obj_add_event_cb(obj, action_pid_stop, LV_EVENT_CLICKED, (void *)0);
                                    add_style_base(obj);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][8]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_shadow_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_transform_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_transform_height(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][8]), LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_bg_opa(obj, 192, LV_PART_MAIN | LV_STATE_PRESSED);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "Stop");
                                        }
                                    }
                                }
                                {
                                    // pid_reset_button
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.pid_reset_button = obj;
                                    lv_obj_set_pos(obj, 322, 162);
                                    lv_obj_set_size(obj, 70, 32);
                                    lv_obj_add_event_cb(obj, action_pid_reset, LV_EVENT_CLICKED, (void *)0);
                                    add_style_base(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "Reset");
                                        }
                                    }
                                }
                                {
                                    // pid_save_button
                                    lv_obj_t *obj = lv_button_create(parent_obj);
                                    objects.pid_save_button = obj;
                                    lv_obj_set_pos(obj, 398, 162);
                                    lv_obj_set_size(obj, 70, 32);
                                    lv_obj_add_event_cb(obj, action_pid_save, LV_EVENT_CLICKED, (void *)0);
                                    add_style_base(obj);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_shadow_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_transform_height(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_transform_width(obj, 0, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][9]), LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_bg_opa(obj, 192, LV_PART_MAIN | LV_STATE_PRESSED);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "Save");
                                        }
                                    }
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Sensors");
                        }
                        {
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Motors");
                        }
                        {
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Ports");
                        }
                    }
                }
            }
            {
                lv_obj_t *tab_bar = lv_tabview_get_tab_bar(obj);
                uint32_t tab_bar_button_cnt = lv_obj_get_child_count(tab_bar);
                for (uint32_t tab_bar_button_i = 0; tab_bar_button_i < tab_bar_button_cnt; tab_bar_button_i++) {
                    lv_obj_t *obj = lv_obj_get_child(tab_bar, tab_bar_button_i);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_obj_set_style_radius(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_obj_set_style_bg_opa(obj, 192, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                    lv_obj_set_style_bg_opa(obj, 192, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                }
            }
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
    screen_main_state_t *state = &screen_main_state;
    (void)state;
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};
void tick_screen(int screen_index) {
    if (screen_index >= 0 && screen_index < 1) {
        tick_screen_funcs[screen_index]();
    }
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen(screenId - 1);
}

//
// Fonts
//

ext_font_desc_t fonts[] = {
#if LV_FONT_MONTSERRAT_8
    { "MONTSERRAT_8", &lv_font_montserrat_8 },
#endif
#if LV_FONT_MONTSERRAT_10
    { "MONTSERRAT_10", &lv_font_montserrat_10 },
#endif
#if LV_FONT_MONTSERRAT_12
    { "MONTSERRAT_12", &lv_font_montserrat_12 },
#endif
#if LV_FONT_MONTSERRAT_14
    { "MONTSERRAT_14", &lv_font_montserrat_14 },
#endif
#if LV_FONT_MONTSERRAT_16
    { "MONTSERRAT_16", &lv_font_montserrat_16 },
#endif
#if LV_FONT_MONTSERRAT_18
    { "MONTSERRAT_18", &lv_font_montserrat_18 },
#endif
#if LV_FONT_MONTSERRAT_20
    { "MONTSERRAT_20", &lv_font_montserrat_20 },
#endif
#if LV_FONT_MONTSERRAT_22
    { "MONTSERRAT_22", &lv_font_montserrat_22 },
#endif
#if LV_FONT_MONTSERRAT_24
    { "MONTSERRAT_24", &lv_font_montserrat_24 },
#endif
#if LV_FONT_MONTSERRAT_26
    { "MONTSERRAT_26", &lv_font_montserrat_26 },
#endif
#if LV_FONT_MONTSERRAT_28
    { "MONTSERRAT_28", &lv_font_montserrat_28 },
#endif
#if LV_FONT_MONTSERRAT_30
    { "MONTSERRAT_30", &lv_font_montserrat_30 },
#endif
#if LV_FONT_MONTSERRAT_32
    { "MONTSERRAT_32", &lv_font_montserrat_32 },
#endif
#if LV_FONT_MONTSERRAT_34
    { "MONTSERRAT_34", &lv_font_montserrat_34 },
#endif
#if LV_FONT_MONTSERRAT_36
    { "MONTSERRAT_36", &lv_font_montserrat_36 },
#endif
#if LV_FONT_MONTSERRAT_38
    { "MONTSERRAT_38", &lv_font_montserrat_38 },
#endif
#if LV_FONT_MONTSERRAT_40
    { "MONTSERRAT_40", &lv_font_montserrat_40 },
#endif
#if LV_FONT_MONTSERRAT_42
    { "MONTSERRAT_42", &lv_font_montserrat_42 },
#endif
#if LV_FONT_MONTSERRAT_44
    { "MONTSERRAT_44", &lv_font_montserrat_44 },
#endif
#if LV_FONT_MONTSERRAT_46
    { "MONTSERRAT_46", &lv_font_montserrat_46 },
#endif
#if LV_FONT_MONTSERRAT_48
    { "MONTSERRAT_48", &lv_font_montserrat_48 },
#endif
};

//
// Color themes
//

uint32_t active_theme_index = 0;
void change_color_theme(uint32_t theme_index) {
    active_theme_index = theme_index;
    
    {
        screen_main_state_t *state = &screen_main_state;
        (void)state;
        lv_obj_set_style_bg_color(objects.obj0, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj1, lv_color_hex(theme_colors[theme_index][1]), LV_PART_ITEMS | LV_STATE_CHECKED);
        lv_obj_set_style_text_color(objects.obj1, lv_color_hex(theme_colors[theme_index][6]), LV_PART_ITEMS | LV_STATE_CHECKED);
        lv_obj_set_style_text_color(objects.obj1, lv_color_hex(theme_colors[theme_index][6]), LV_PART_ITEMS | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj1, lv_color_hex(theme_colors[theme_index][4]), LV_PART_ITEMS | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj1, lv_color_hex(theme_colors[theme_index][4]), LV_PART_ITEMS | LV_STATE_PRESSED);
        lv_obj_set_style_bg_color(objects.obj1, lv_color_hex(theme_colors[theme_index][1]), LV_PART_ITEMS | LV_STATE_CHECKED | LV_STATE_PRESSED);
        lv_obj_set_style_bg_color(objects.pid_controller, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.pid_controller, lv_color_hex(theme_colors[theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.pid_controller, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_bg_color(objects.pid_controller, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_bg_color(objects.obj2, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj2, lv_color_hex(theme_colors[theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj2, lv_color_hex(theme_colors[theme_index][1]), LV_PART_SELECTED | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(objects.obj2, lv_color_hex(theme_colors[theme_index][5]), LV_PART_SELECTED | LV_STATE_CHECKED);
        lv_obj_set_style_text_color(objects.obj2, lv_color_hex(theme_colors[theme_index][6]), LV_PART_SELECTED | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(objects.obj2, lv_color_hex(theme_colors[theme_index][5]), LV_PART_SELECTED | LV_STATE_PRESSED);
        lv_obj_set_style_text_color(objects.obj2, lv_color_hex(theme_colors[theme_index][6]), LV_PART_SELECTED | LV_STATE_PRESSED);
        lv_obj_set_style_bg_color(objects.obj2, lv_color_hex(theme_colors[theme_index][5]), LV_PART_SELECTED | LV_STATE_PRESSED);
        lv_obj_set_style_bg_color(objects.obj2, lv_color_hex(theme_colors[theme_index][1]), LV_PART_SELECTED | LV_STATE_CHECKED | LV_STATE_PRESSED);
        lv_obj_set_style_border_color(objects.obj2, lv_color_hex(theme_colors[theme_index][5]), LV_PART_SELECTED | LV_STATE_CHECKED | LV_STATE_PRESSED);
        lv_obj_set_style_text_color(objects.obj3, lv_color_hex(theme_colors[theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj4, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj4, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_bg_color(objects.obj5, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj5, lv_color_hex(theme_colors[theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj6, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj6, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_text_color(objects.obj7, lv_color_hex(theme_colors[theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj8, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj8, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_bg_color(objects.obj9, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj9, lv_color_hex(theme_colors[theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj10, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj10, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_text_color(objects.obj11, lv_color_hex(theme_colors[theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj12, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj12, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_bg_color(objects.obj13, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj13, lv_color_hex(theme_colors[theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj14, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj14, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_text_color(objects.obj15, lv_color_hex(theme_colors[theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.pid_step_button, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.pid_advanced_button, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.pid_advanced_button, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_text_color(objects.pid_target_caption, lv_color_hex(theme_colors[theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.pid_target_value, lv_color_hex(theme_colors[theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj16, lv_color_hex(theme_colors[theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.pid_timeout_value, lv_color_hex(theme_colors[theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.pid_status, lv_color_hex(theme_colors[theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.pid_run_button, lv_color_hex(theme_colors[theme_index][7]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.pid_run_button, lv_color_hex(theme_colors[theme_index][7]), LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_bg_color(objects.pid_stop_button, lv_color_hex(theme_colors[theme_index][8]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.pid_stop_button, lv_color_hex(theme_colors[theme_index][8]), LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_bg_color(objects.pid_save_button, lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.pid_save_button, lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_bg_color(objects.obj1, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_text_color(objects.obj1, lv_color_hex(theme_colors[theme_index][6]), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_text_color(objects.obj1, lv_color_hex(theme_colors[theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj1, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj1, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_bg_color(objects.obj1, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    }
    lv_style_set_bg_color(get_style_panel_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][4]));
    lv_style_set_bg_color(get_style_base_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][4]));
    lv_style_set_bg_color(get_style_base_MAIN_PRESSED(), lv_color_hex(theme_colors[theme_index][4]));
    lv_obj_invalidate(objects.main);
}
uint32_t theme_colors[2][10] = {
    { 0xff922e2e, 0xffc43e3e, 0xffed7777, 0xff101820, 0xff202b36, 0xff34404c, 0xffffffff, 0xff42d392, 0xffe5484d, 0xff2176cf },
    { 0xff19599c, 0xff2176cf, 0xff75b7ff, 0xff101820, 0xff202b36, 0xff303d4b, 0xffffffff, 0xff42d392, 0xffe5484d, 0xff2176cf },
};

//
//
//

void create_screens() {

// Set default LVGL theme
    lv_display_t *dispp = lv_display_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_display_set_theme(dispp, theme);
    
    // Initialize screens
    // Create screens
    create_screen_main();
}