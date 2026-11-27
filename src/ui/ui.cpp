#include "ui.hpp"
#include "liblvgl/lvgl.h"
#include "liblvgl/misc/lv_area.h"
#include "main.h"
#include "theme.hpp"
#include "ui.hpp"

namespace ui {

  void ui() {

    
    theme::init();

    lv_obj_t *screen = lv_screen_active();
    lv_obj_add_style(screen, &theme::background, 0);

    lv_obj_t *tabview = lv_tabview_create(screen);
    lv_obj_set_size(tabview, LV_PCT(100), LV_PCT(100));

    lv_tabview_set_tab_bar_position(tabview, LV_DIR_TOP);
    lv_tabview_set_tab_bar_size(tabview, 40);

    lv_obj_add_style(tabview, &theme::background, 0);

    lv_obj_t *ribbon = lv_tabview_get_tab_bar(tabview);
    lv_obj_add_style(ribbon, &theme::ribbon, 0);

    lv_obj_t *auton = lv_tabview_add_tab(tabview, "Auton");
    lv_obj_t *diag = lv_tabview_add_tab(tabview, "Diagnostics");
    lv_obj_t *settings = lv_tabview_add_tab(tabview, "Settings");

    lv_obj_add_style(auton, &theme::background, 0);
    lv_obj_add_style(diag, &theme::background, 0);
    lv_obj_add_style(settings, &theme::background, 0);
  }
} // namespace ui