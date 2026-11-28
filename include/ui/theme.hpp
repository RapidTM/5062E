#pragma once
#include "liblvgl/lvgl.h"

namespace ui::theme {

namespace color {
    constexpr uint32_t background = 0x141414;
    constexpr uint32_t text = 0xFFFFFF;
    constexpr uint32_t primary = 0xff0051;
    constexpr uint32_t success = 0x42D392;
    constexpr uint32_t error = 0xC43E3E;
    constexpr uint32_t neutral = 0x505966;
} // namespace color

void init();
    extern lv_style_t background;
    extern lv_style_t ribbon;
    extern lv_style_t button;
    extern lv_style_t button_pressed;
    extern lv_style_t button_success;
    extern lv_style_t button_error;
    extern lv_style_t button_neutral;
} // namespace ui::theme