// Copyright 2024 Andrew Kannan
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum {
    TD_NUM_CALC
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_NUM_CALC] = ACTION_TAP_DANCE_DOUBLE(KC_NUM, KC_CALC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_ansi_6u_split_bs_numplus( /* Base */
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,   KC_DEL,  KC_PSLS, KC_PAST,  TD(TD_NUM_CALC),
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,           KC_P7,   KC_P8,   KC_P9,    KC_PMNS,
        CW_TOGG, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,                     KC_P4,   KC_P5,   KC_P6,    KC_PPLS,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,           KC_UP,            KC_P1,   KC_P2,   KC_P3,    KC_PENT,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,           KC_RALT, MO(1),  KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT,          KC_P0,   KC_PDOT
    ),

    [1] = LAYOUT_ansi_6u_split_bs_numplus( /* Function Layer 1 */
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PAUS, KC_PSCR,  _______, S(KC_9), S(KC_0), KC_CALC,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,            KC_F7,   KC_F8,   KC_F9,   S(KC_6),
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, G(KC_L), _______, _______, _______,                    KC_F4,   KC_F5,   KC_F6,   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,          KC_F1,   KC_F2,   KC_F3,   _______,
        _______, _______, _______,                            _______,          MO(2),   _______, _______,           _______, _______, _______,          KC_F10,  KC_F11
    ),

    [2] = LAYOUT_ansi_6u_split_bs_numplus( /* Function Layer 2 */
        QK_BOOT, DB_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_RBT,   _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______,
        _______, UG_TOGG, UG_HUEU, UG_SATU, UG_VALU, _______, _______, _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______,
        _______, UG_NEXT, UG_HUED, UG_SATD, UG_VALD, _______, _______, _______, _______, _______, _______, _______,           _______,          _______, _______, _______, _______,
        _______, _______, _______,                            _______,          _______, _______, _______,           _______, _______, _______,          _______,  _______
    ),

};
