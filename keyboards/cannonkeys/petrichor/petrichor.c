// Copyright 2023 Andrew Kannan
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

enum {
    RGB_LAYER_CAPSWORD,
    RGB_LAYER_CAPSLOCK,
    RGB_LAYER_NUMLOCK,
    RGB_LAYER_LAYER1,
    RGB_LAYER_LAYER2
};

const rgblight_segment_t PROGMEM my_capsword_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 1, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_ORANGE}
);

const rgblight_segment_t* const PROGMEM enabled_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capsword_layer,
    my_capslock_layer,
    my_numlock_layer,
    my_layer1_layer,
    my_layer2_layer
);

void keyboard_post_init_kb(void) {
    keyboard_post_init_user();

    rgblight_layers = enabled_rgb_layers;
}

void caps_word_set_user(bool active) {
    rgblight_set_layer_state(RGB_LAYER_CAPSWORD, active);
}

bool led_update_kb(led_t led_state) {
    if(!led_update_user(led_state)){
        return false;
    }

    rgblight_set_layer_state(RGB_LAYER_CAPSLOCK, led_state.caps_lock);
    rgblight_set_layer_state(RGB_LAYER_NUMLOCK, led_state.num_lock);

    return true;
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    state = layer_state_set_user(state);

    rgblight_set_layer_state(RGB_LAYER_LAYER1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(RGB_LAYER_LAYER2, layer_state_cmp(state, 2));

    return state;
}
