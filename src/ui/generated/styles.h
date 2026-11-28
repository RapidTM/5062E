#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <ui/lvgl_compat.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: panel
lv_style_t *get_style_panel_MAIN_DEFAULT();
void add_style_panel(lv_obj_t *obj);
void remove_style_panel(lv_obj_t *obj);

// Style: base
lv_style_t *get_style_base_MAIN_DEFAULT();
lv_style_t *get_style_base_MAIN_PRESSED();
void add_style_base(lv_obj_t *obj);
void remove_style_base(lv_obj_t *obj);

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/