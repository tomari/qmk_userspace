/* Copyright 2019 ENDO Katsuhiro <ka2hiro@kagizaraya.jp>
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

#include "board.h"

enum layer_number { _QWERTY = 0, _LOWER, _RAISE, _ADJUST };

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |ADJUST| Esc  | Alt  | GUI  |LOWER |Space |             | Space| RAISE| Left | Down |  Up  | Right|
   * `-----------------------------------------'             `-----------------------------------------'
   */
    [_QWERTY] = LAYOUT(
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_ESC,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,              KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
      LOWER,KC_LGUI,KC_F12,LALT_T(KC_LNG2),KC_LSFT,KC_SPC,            KC_ENT,  RAISE,RALT_T(KC_LNG1),KC_DEL,KC_EQL,KC_RCTL
    ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |   -  |   _  |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      | Home | End  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      | Next | Vol- | Vol+ | Play |
   * `-----------------------------------------'             `-----------------------------------------'
   */
    [_LOWER] = LAYOUT(
      _______, KC_WBAK, KC_UP,   KC_WFWD, KC_PGUP, KC_MYCM,           KC_MPLY, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST, _______,
      _______, KC_LEFT, KC_DOWN, KC_RIGHT,KC_PGDN, KC_MPRV,           KC_MNXT, KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS, _______,
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,             KC_NUM,  KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS, _______,
      _______, _______, _______, KC_LALT, _______, KC_BSPC,           KC_PENT, _______, KC_KP_0, KC_PDOT, KC_PSLS, _______
    ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |             |  F12 |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      | Next | Vol- | Vol+ | Play |
   * `-----------------------------------------'             `-----------------------------------------'
   */
    [_RAISE] = LAYOUT(
      KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
      _______, _______, _______, _______, KC_MINS, KC_EQL,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP, KC_BSLS,
      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,            _______, _______, KC_LBRC, KC_RBRC, KC_PGDN, KC_MUTE,
      _______, _______, _______, _______, _______, KC_BSPC,           _______, _______, KC_NO,   KC_VOLD, KC_VOLU, _______
    ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      | Reset|      |      |      |      |             |      |Qwerty|Colemk|Dvorak|      | Ins  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Caps |      |      |      |      | Mac  |             | Win  |  -   |   =  |Print |ScLock|Pause |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             | KANA |      | Home |PageDn|PageUp| End  |
   * `-----------------------------------------'             `-----------------------------------------'
   */
    [_ADJUST] = LAYOUT(
      _______, QK_BOOT, _______, _______, _______, _______,           _______, _______, _______, _______, _______, KC_INS,
      KC_CAPS, _______, _______, _______, _______, AG_NORM,           AG_SWAP, KC_MINS, KC_EQL,  KC_PSCR, KC_SCRL, KC_PAUS,
      _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,           _______, _______, KC_HOME, KC_INS,  _______, KC_END
    )
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool led_update_user(led_t led_state) {
    board_set_led_by_index(0, LED_YELLOW, led_state.caps_lock);
    board_set_led_by_index(1, LED_YELLOW, led_state.scroll_lock);

    return false;
}

bool process_detected_host_os_user(os_variant_t os) {
    if(os==OS_MACOS || os==OS_IOS){
        keymap_config.swap_lalt_lgui = keymap_config.swap_ralt_rgui = true;
    } else {
        keymap_config.swap_lalt_lgui = keymap_config.swap_ralt_rgui = false;
    }
    return true;
}
