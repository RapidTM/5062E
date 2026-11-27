#include "theme.hpp"

namespace ui::theme {

// Style definitions
lv_style_t background;
lv_style_t ribbon;
lv_style_t button;
lv_style_t button_pressed;
lv_style_t button_success;
lv_style_t button_error;
lv_style_t button_neutral;

void init() {

  // Global LVGL theme
  lv_display_t *display = lv_display_get_default();

  lv_theme_t *theme = lv_theme_default_init(
      display,
      lv_color_hex(color::primary),
      lv_color_hex(color::success),
      true,
      LV_FONT_DEFAULT);

  lv_display_set_theme(display, theme);

  // Background
  lv_style_init(&background);
  lv_style_set_bg_color(&background, lv_color_hex(color::background));
  lv_style_set_bg_opa(&background, LV_OPA_COVER);
  lv_style_set_text_color(&background, lv_color_hex(color::text));
  lv_style_set_border_width(&background, 0);
  lv_style_set_radius(&background, 0);

  // Navigation ribbon
  lv_style_init(&ribbon);
  lv_style_set_bg_color(&ribbon, lv_color_hex(color::background));
  lv_style_set_bg_opa(&ribbon, LV_OPA_COVER);
  lv_style_set_text_color(&ribbon, lv_color_hex(color::text));
  lv_style_set_radius(&ribbon, 0);
  lv_style_set_pad_all(&ribbon, 4);
  lv_style_set_pad_column(&ribbon, 4);
  lv_style_set_border_width(&ribbon, 0);

  // Standard button
  lv_style_init(&button);
  lv_style_set_bg_color(&button, lv_color_hex(color::primary));
  lv_style_set_bg_opa(&button, LV_OPA_COVER);
  lv_style_set_text_color(&button, lv_color_hex(color::text));
  lv_style_set_radius(&button, 6);
  lv_style_set_border_width(&button, 0);
  lv_style_set_shadow_width(&button, 0);
  lv_style_set_pad_all(&button, 8);

  // Pressed button
  lv_style_init(&button_pressed);
  lv_style_set_opa(&button_pressed, LV_OPA_70);

  // Button color variants
  lv_style_init(&button_success);
  lv_style_set_bg_color(&button_success, lv_color_hex(color::success));
  lv_style_set_text_color(&button_success, lv_color_hex(color::background));

  lv_style_init(&button_error);
  lv_style_set_bg_color(&button_error, lv_color_hex(color::error));

  lv_style_init(&button_neutral);
  lv_style_set_bg_color(&button_neutral, lv_color_hex(color::neutral));
}
} // namespace ui::theme
