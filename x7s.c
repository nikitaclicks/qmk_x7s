// Copyright 2024 zvecr <git@zvecr.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

void keyboard_pre_init_kb(void) {
    // Workaround for reversible pcb/mcu
    // gpio_set_pin_output_open_drain(C13);
    // gpio_set_pin_output_open_drain(B9);
    // gpio_set_pin_output_open_drain(B8);

//   rgblight_enable_noeeprom(); 
    // rgblight_sethsv_noeeprom(0, 0, 128); 

    // keyboard_post_init_user();
    keyboard_pre_init_user();
}

bool led_update_kb(led_t led_state) {
    if (!led_update_user(led_state)) { return false; }
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

void board_init(void) {
    // AFIO->MAPR |= AFIO_MAPR_USART1_REMAP | AFIO_MAPR_TIM3_REMAP_PARTIALREMAP;
     AFIO->MAPR |= AFIO_MAPR_USART1_REMAP;
}
