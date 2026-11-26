
#include "liblvgl/lvgl.h"
#include "main.h"


static int count = 0;

static lv_obj_t *count_label;
static lv_obj_t *slider_label;
static lv_obj_t *timer_label;

// Update counter display
static void update_count() {
  lv_label_set_text_fmt(count_label, "Count: %d", count);
}

// Button event callbacks
static void increment_cb(lv_event_t *e) {
  count++;
  update_count();
}

static void decrement_cb(lv_event_t *e) {
  count--;
  update_count();
}

static void reset_cb(lv_event_t *e) {
  count = 0;
  update_count();
}

// Slider event callback
static void slider_cb(lv_event_t *e) {
  lv_obj_t *slider = lv_event_get_target_obj(e);

  lv_label_set_text_fmt(slider_label, "Slider: %d%%",
                        (int)lv_slider_get_value(slider));
}

// Timer callback
static void timer_cb(lv_timer_t *timer) {
  lv_label_set_text_fmt(timer_label, "Uptime: %lu s",
                        (unsigned long)(pros::millis() / 1000));
}

// Helper function for creating buttons
static void create_button(lv_obj_t *parent, const char *text, uint32_t color,
                          int x, int y, lv_event_cb_t callback) {
  lv_obj_t *btn = lv_button_create(parent);

  lv_obj_set_size(btn, 120, 44);
  lv_obj_set_pos(btn, x, y);

  lv_obj_set_style_bg_color(btn, lv_color_hex(color), 0);

  lv_obj_t *label = lv_label_create(btn);
  lv_label_set_text(label, text);
  lv_obj_center(label);

  lv_obj_add_event_cb(btn, callback, LV_EVENT_CLICKED, nullptr);
}

// Main UI initialization
void init_test_ui() {
  lv_obj_t *screen = lv_screen_active();

  lv_obj_clean(screen);
  lv_obj_remove_flag(screen, LV_OBJ_FLAG_SCROLLABLE);

  lv_obj_set_style_bg_color(screen, lv_color_hex(0x101820), 0);

  lv_obj_set_style_text_color(screen, lv_color_hex(0xFFFFFF), 0);

  // Title
  lv_obj_t *title = lv_label_create(screen);
  lv_label_set_text(title, "5062E | LVGL TEST");
  lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 8);

  // Status
  lv_obj_t *status = lv_label_create(screen);
  lv_label_set_text(status, "LVGL 9.2.0 Running");
  lv_obj_set_style_text_color(status, lv_color_hex(0x42D392), 0);
  lv_obj_align(status, LV_ALIGN_TOP_MID, 0, 30);

  // Counter
  count_label = lv_label_create(screen);
  update_count();
  lv_obj_align(count_label, LV_ALIGN_TOP_MID, 0, 62);

  // Buttons
  create_button(screen, "-1", 0xC43E3E, 30, 90, decrement_cb);
  create_button(screen, "Reset", 0x505966, 180, 90, reset_cb);
  create_button(screen, "+1", 0x2176CF, 330, 90, increment_cb);

  // Slider label
  slider_label = lv_label_create(screen);
  lv_label_set_text(slider_label, "Slider: 50%");
  lv_obj_align(slider_label, LV_ALIGN_TOP_MID, 0, 150);

  // Slider
  lv_obj_t *slider = lv_slider_create(screen);
  lv_obj_set_size(slider, 380, 12);
  lv_obj_align(slider, LV_ALIGN_TOP_MID, 0, 180);

  lv_slider_set_range(slider, 0, 100);
  lv_slider_set_value(slider, 50, LV_ANIM_OFF);

  lv_obj_add_event_cb(slider, slider_cb, LV_EVENT_VALUE_CHANGED, nullptr);

  // Uptime display
  timer_label = lv_label_create(screen);
  lv_label_set_text(timer_label, "Uptime: 0 s");
  lv_obj_align(timer_label, LV_ALIGN_BOTTOM_MID, 0, -8);

  // Update uptime every 250 ms
  lv_timer_create(timer_cb, 250, nullptr);
}
