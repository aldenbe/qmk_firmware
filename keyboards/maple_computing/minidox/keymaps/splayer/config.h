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

// #ifndef CONFIG_USER_H
// #define CONFIG_USER_H

// #include "../../config.h"

#define USE_SERIAL

#define MASTER_LEFT
// #define EE_HANDS

/* ws2812 RGB LED */
// #define RGB_DI_PIN D7

// #define RGBLED_NUM 8   // Number of LEDs
// #define RGBLIGHT_ANIMATIONS
// #define RGBLIGHT_HUE_STEP 10
// #define RGBLIGHT_SAT_STEP 17
// #define RGBLIGHT_VAL_STEP 17

// #define IGNORE_MOD_TAP_INTERRUPT
// #undef PERMISSIVE_HOLD

// #endif
#define COMBO_VARIABLE_LEN
#define COMBO_TERM 50
#define COMBO_MUST_HOLD_MODS
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 300
#define LEADER_NO_TIMEOUT
// #define TAPPING_TERM 200


#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE
#define LAYER_STATE_8BIT

#ifdef MATRIX_ROW_PINS
#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS { F6, B6, B4, B5 }
#endif

#ifdef DIODE_DIRECTION
#undef DIODE_DIRECTION
#define DIODE_DIRECTION ROW2COL
#endif

#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define PMW3360_CS_PIN F7
#define PMW3360_CPI 600
#define POINTING_DEVICE_INVERT_X
