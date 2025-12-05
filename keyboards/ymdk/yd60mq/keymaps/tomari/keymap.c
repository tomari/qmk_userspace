/* Copyright 2020 rbange https://github.com/rbange
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "os_detection.h"

#define _______ KC_TRNS

enum layer_names {
    _QWERTY,
    _LOW,
    _NUM,
    _ADJ,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   MO(_ADJ),
LT(_NUM,KC_LNG2),KC_LGUI, KC_LALT,                 KC_SPC,  KC_SPC,  KC_SPC,         MT(MOD_RALT,KC_LNG1), MO(_LOW),KC_LEFT, KC_DOWN, KC_RGHT
    ),

	[_LOW] = LAYOUT_all(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLEP,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_INS,
        KC_RCTL, _______, KC_SCRL, KC_PAUS, _______, _______, _______, _______, KC_F16,  KC_F17,  KC_F18,  KC_F19,  _______, _______,
        _______, _______, KC_STOP, _______, _______, _______, TG(_NUM),_______, _______, KC_WBAK, KC_WFWD, KC_MCTL, _______, KC_PGUP, _______,
        KC_CAPS, _______, _______,                   _______, _______, _______,                   KC_RALT, _______, KC_HOME, KC_PGDN, KC_END
    ),

    [_NUM] = LAYOUT_all(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST, _______, KC_PEQL, KC_EJCT, KC_PWR,
        _______, MS_BTN4, MS_UP,   MS_BTN5, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS, MS_BTN2, MS_BTN3, _______,
        _______, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS, MS_BTN1, _______, KC_PENT,
        _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, KC_NUM,  KC_KP_0, _______, KC_PDOT, KC_PSLS, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,                   _______, _______, _______, _______, _______
    ),

    [_ADJ] = LAYOUT_all(
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_TOG, _______, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_UP,   _______, KC_DEL,
        _______, _______, _______, _______, _______, EE_CLR,  _______, _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______, _______,
        _______, _______, NK_TOGG, _______, BL_DOWN, BL_TOGG, BL_UP,   AG_NORM, AG_SWAP, KC_END,  KC_PGDN, KC_DOWN, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,                   _______, _______, _______, _______, _______
    ),

};

enum led_layer_name {
  _ll_caps,
  _ll_scrl,
  _ll_numlayer,
  _ll_numlock,
  _ll_adj,
};
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED},       // Light 1 LED, starting with LED 0
    {15, 1, HSV_RED}       // Light 1 LED, starting with LED 15
);

const rgblight_segment_t PROGMEM my_scrollock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 2, HSV_BLUE}       // Light 2 LEDs, starting with LED 7
);

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 1, HSV_YELLOW}       // Light 1 LED, starting with LED 9
);

const rgblight_segment_t PROGMEM my_numlayer_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 3, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {14, 1, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    [_ll_caps] = my_capslock_layer,
    [_ll_scrl] = my_scrollock_layer,
    [_ll_numlayer] = my_numlayer_layer,
    [_ll_numlock] = my_numlock_layer,
    [_ll_adj] = my_layer1_layer
);

bool process_detected_host_os_user(os_variant_t os) {
    if(os==OS_MACOS || os==OS_IOS){
        keymap_config.swap_lalt_lgui = keymap_config.swap_ralt_rgui = true;
    }
    return true;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(_ll_caps, led_state.caps_lock);
    rgblight_set_layer_state(_ll_scrl, led_state.scroll_lock);
    rgblight_set_layer_state(_ll_numlock, led_state.num_lock && layer_state_is(_NUM));
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_ll_numlayer, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(_ll_numlock, host_keyboard_led_state().num_lock && layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(_ll_adj, layer_state_cmp(state, _ADJ));
    return state;
}
