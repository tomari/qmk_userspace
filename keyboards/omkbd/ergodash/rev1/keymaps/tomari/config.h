/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS
#define RGBLIGHT_SLEEP
#define RGBLIGHT_SPLIT
#define RGBLIGHT_LIMIT_VAL 96
#define RGBLIGHT_LAYERS
#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_LED_COUNT 26
#undef RGBLED_SPLIT
#define RGBLED_SPLIT { 13, 13 }
#undef RGBLIGHT_LED_MAP
#define RGBLIGHT_LED_MAP { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13 }

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define LAYER_STATE_8BIT
