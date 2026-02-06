/* Copyright 2015-2021 Jack Humbert
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

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

enum layer_number { _QWERTY = 0, _LOWER, _RAISE, _ADJUST };

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define CTLLNG2 LCTL_T(KC_LNG2)
#define SFTSPC LSFT_T(KC_SPC)
#define RAILNG1 LT(_RAISE,KC_LNG1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
    [_QWERTY] = LAYOUT_planck_grid(
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS, KC_GRV,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    
      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC, KC_QUOT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, 
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_RBRC, KC_BSLS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, 
      LOWER,   KC_ESC,  KC_LGUI, KC_LALT, SFTSPC,  CTLLNG2, RAILNG1, KC_ENT,  KC_RSFT, KC_RCTL, KC_DEL,  KC_TAB
    ),
    [_LOWER] = LAYOUT_planck_grid(
      _______, KC_WBAK, KC_UP,   KC_WFWD, KC_PGUP, KC_MYCM, KC_MPLY, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST,
      _______, KC_LEFT, KC_DOWN, KC_RIGHT,KC_PGDN, KC_MPRV, KC_MNXT, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS,
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NUM,  _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS,
      _______, KC_LCTL, _______, _______, KC_SPC,  KC_BSPC, _______, KC_PENT, KC_KP_0, KC_PDOT, KC_RALT, KC_PSLS
    ),
    [_RAISE] = LAYOUT_planck_grid(
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    
      _______, _______, _______, KC_MINS, KC_EQL,  _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSLS,
      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, KC_LBRC, KC_RBRC, KC_MUTE,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_NO,   KC_VOLD, KC_VOLU, _______
    ),
    [_ADJUST] = LAYOUT_planck_grid(
      _______, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,
      KC_CAPS, BL_TOGG, BL_STEP, _______, _______, AG_NORM, AG_SWAP, KC_MINS, KC_EQL,  KC_PSCR, KC_SCRL, KC_PAUS,
      _______, _______, _______, _______, _______, _______, CK_TOGG, CK_UP,   CK_DOWN, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_INS,  _______, KC_END
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_detected_host_os_user(os_variant_t os) {
    if(os==OS_MACOS || os==OS_IOS){
        keymap_config.swap_lalt_lgui = keymap_config.swap_ralt_rgui = true;
    } else {
        keymap_config.swap_lalt_lgui = keymap_config.swap_ralt_rgui = false;
    }
    return true;
}
