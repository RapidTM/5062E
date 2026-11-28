#include "ui/ui.hpp"
#include "ui/pid_ui.hpp"
#include "generated/ui.h"
#include "liblvgl/lvgl.h"
#include "liblvgl/misc/lv_area.h"
#include "lvgl_compat.h"
#include "main.h"
#include "ui/theme.hpp"

namespace ui {

static void tick(lv_timer_t *timer) { ui_tick(); }

void init() {
  ui_init();
  pid_ui::init();

  lv_timer_create(tick, 20, nullptr);
}
} // namespace ui