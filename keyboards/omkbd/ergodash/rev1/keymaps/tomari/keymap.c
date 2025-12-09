#include QMK_KEYBOARD_H
#include "os_detection.h"

enum layer_names {
    _QWERTY,
    _LOWER,
    _UPPER,
    _NUM,
    _ADJUST,
};

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   [  |                    |   ]  |   6  |   7  |   8  |   9  |   0  |  `   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Caps |   A  |   S  |   D  |   F  |   G  | Space|                    | Enter|   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Lower|   Z  |   X  |   C  |   V  |   B  | GUI  |                    | Ctrl |   N  |   M  |   ,  |   .  |   /  | Up   |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Back |  Fwd |  Del | EISU |||||||| Ctrl | Alt  | Shift|||||||| Shift| Alt  |  BS  |||||||| KANA | Left | Right| Down |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT(
           KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_F4,                           KC_F3,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
           KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_F1,                           KC_F2,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
           KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MINS,                        KC_EQL,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
           KC_ESC,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,                         KC_F5,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,
        TT(_UPPER), KC_F12,  KC_DEL,  KC_LALT, KC_LNG2, KC_LSFT, KC_SPC,                        KC_ENT,MO(_LOWER), KC_LNG1, TT(_NUM),KC_LEFT, KC_RGHT, KC_DOWN
  ),
  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Boot |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |                    | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |Eject |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |RGBTOG|RGBMOD| Hue- | Hue+ |      |                    |      | Sat- | Sat+ | Br-  | Br+  |PrtSc | Vol+ |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Stop |      |ScrLoc|Pause |      |EeClr |      |                    |      | Left | Down | Up   | Right| Mute | Vol- |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      | PC   | Mac  |      |      |      | PgUp |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |Home  |End   | PgDn |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_MYCM,                        KC_MPLY, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MPRV,                        KC_MNXT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PGUP,
    _______,  _______, KC_SCRL, KC_PAUS, KC_MINS, KC_EQL,  _______,                        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_PGDN,
 MO(_ADJUST), KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  _______,                        _______, KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_NO,   KC_NO,
    _______,  KC_APP,  KC_INS, _______,          _______,  _______, KC_BSPC,      _______, _______, _______,         TG(_NUM), KC_HOME, KC_END,  MO(_UPPER)
  ),

  [_UPPER] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______,
    _______, KC_WBAK, KC_UP,   KC_WFWD, KC_PGUP, _______, _______,                        _______, _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS,
    _______, KC_LEFT, KC_DOWN, KC_RIGHT,KC_PGDN, _______, _______,                        _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                        KC_APP,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,          KC_LALT, _______, KC_BSPC,      _______, _______, KC_RALT,          _______, _______, _______, _______
  ),

  [_NUM] = LAYOUT(
    _______, KC_STOP, KC_AGIN, KC_MENU, KC_UNDO, KC_SLCT, KC_HELP,                        _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST, KC_MUTE,
    _______, _______, MS_BTN4, MS_UP,   MS_BTN5, MS_WHLU, _______,                        KC_PEQL, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS, KC_VOLU,
    _______, _______, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD, _______,                        _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS, KC_VOLD,
 MO(_ADJUST),KC_COPY, KC_EXEC,KC_PASTE, KC_FIND, KC_CUT,  MS_BTN3,                        _______, KC_NUM,  KC_KP_0, _______, KC_PDOT, KC_PSLS, KC_WSTP,
    _______, _______, KC_INS,  _______,          KC_RCTL, MS_BTN2, MS_BTN1,       KC_PENT,_______, _______,          _______, KC_WBAK, KC_WFWD, KC_WREF
  ),

  [_ADJUST] = LAYOUT(
    QK_BOOT, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______,
    _______, _______, UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, _______,                        _______, UG_SATU, UG_SATD, UG_VALU, UG_VALD, _______, _______,
    KC_CAPS, _______, UG_SPDU, UG_SPDD, _______, EE_CLR,  _______,                        _______, _______, _______, _______, _______, _______, _______,
    _______, NK_TOGG, _______, _______, _______, _______, _______,                        _______, AG_NORM, AG_SWAP, _______, _______, _______, _______,
    _______, _______, _______, _______,          _______, _______, _______,       _______,_______, _______,          _______, _______, _______, _______
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

bool process_detected_host_os_user(os_variant_t os) {
    if(os==OS_MACOS || os==OS_IOS){
        keymap_config.swap_lalt_lgui = keymap_config.swap_ralt_rgui = true;
    } else {
        keymap_config.swap_lalt_lgui = keymap_config.swap_ralt_rgui = false;
    }
    return true;
}

enum ledlayer_names {
    _LEDLAYER_CAPSLOCK,
    _LEDLAYER_SCROLLLOCK,
    _LEDLAYER_NUMLOCK,
    _LEDLAYER_NUMLAYER,
    _LEDLAYER_OFF,
};

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 4, HSV_RED}       // Light 4 LEDs, starting with LED 2
);

const rgblight_segment_t PROGMEM my_scrollock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {18, 4, HSV_BLUE}       // Light 4 LEDs, starting with LED 18
);

const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {13, 1, HSV_GREEN}       // Light 1 LED, starting with LED 13
);

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 2, HSV_OFF}       // turn off
);

const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {16, 3, HSV_GREEN}       // Light 3 LEDs, starting with LED 16
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    [_LEDLAYER_CAPSLOCK] = my_capslock_layer,
    [_LEDLAYER_SCROLLLOCK] = my_scrollock_layer,
    [_LEDLAYER_NUMLOCK] = my_numlock_layer,
    [_LEDLAYER_NUMLAYER] = my_layer3_layer,
    [_LEDLAYER_OFF] = my_layer1_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(_LEDLAYER_CAPSLOCK, led_state.caps_lock);
    rgblight_set_layer_state(_LEDLAYER_SCROLLLOCK, led_state.scroll_lock);
    rgblight_set_layer_state(_LEDLAYER_NUMLOCK, led_state.num_lock && layer_state_is(_NUM));
    rgblight_set_layer_state(_LEDLAYER_OFF, 1);

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_LEDLAYER_NUMLAYER, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(_LEDLAYER_NUMLOCK, host_keyboard_led_state().num_lock && layer_state_cmp(state, _NUM));
    return state;
}
