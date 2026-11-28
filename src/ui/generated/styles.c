#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "ui.h"
#include "screens.h"

//
// Style: panel
//

void init_style_panel_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][4]));
    lv_style_set_radius(style, 6);
    lv_style_set_border_width(style, 0);
    lv_style_set_pad_top(style, 6);
    lv_style_set_pad_bottom(style, 6);
    lv_style_set_pad_left(style, 6);
    lv_style_set_pad_right(style, 6);
};

lv_style_t *get_style_panel_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_panel_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_panel(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_panel_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_panel(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_panel_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: base
//

void init_style_base_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][4]));
    lv_style_set_shadow_opa(style, 0);
    lv_style_set_shadow_width(style, 2);
    lv_style_set_radius(style, 6);
};

lv_style_t *get_style_base_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_base_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_base_MAIN_PRESSED(lv_style_t *style) {
    lv_style_set_transform_width(style, 0);
    lv_style_set_transform_height(style, 0);
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][4]));
    lv_style_set_bg_opa(style, 192);
};

lv_style_t *get_style_base_MAIN_PRESSED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_base_MAIN_PRESSED(style);
    }
    return style;
};

void add_style_base(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_base_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_base_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
};

void remove_style_base(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_base_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_base_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_panel,
        add_style_base,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_panel,
        remove_style_base,
    };
    remove_style_funcs[styleIndex](obj);
}