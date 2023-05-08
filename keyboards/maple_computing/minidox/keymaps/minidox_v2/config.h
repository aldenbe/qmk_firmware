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
#define COMBO_TERM 25
#define COMBO_MUST_HOLD_MODS
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 300
#define LEADER_NO_TIMEOUT
// #define TAPPING_TERM 200


////////////////////////////////////

/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#pragma once


/* Key matrix configuration. */
#ifdef MATRIX_ROW_PINS
#    undef MATRIX_ROW_PINS
#endif
#define MATRIX_ROW_PINS \
{ GP2, GP3, GP4, GP5 }

#ifdef MATRIX_COL_PINS
#    undef MATRIX_COL_PINS
#endif
#define MATRIX_COL_PINS \
    { GP6, GP7, GP8, GP9, GP10 }

#ifdef DIODE_DIRECTION
#undef DIODE_DIRECTION
#endif
#define DIODE_DIRECTION ROW2COL

/* Handedness. */
#ifdef SPLIT_HAND_PIN
#    undef SPLIT_HAND_PIN
#endif
#define SPLIT_HAND_PIN GP12

#ifdef SPLIT_HAND_PIN_LOW_IS_LEFT
#    undef SPLIT_HAND_PIN_LOW_IS_LEFT
#endif
#define SPLIT_HAND_PIN_LOW_IS_LEFT // High -> right, Low -> left.


/* serial.c configuration (for split keyboard). */
#ifdef SOFT_SERIAL_PIN
#    undef SOFT_SERIAL_PIN
#endif
#define SOFT_SERIAL_PIN GP15

/* VBUS detection. */
#define USB_VBUS_PIN GP21

/* CRC. */
#define CRC8_USE_TABLE
#define CRC8_OPTIMIZE_SPEED

/* Cirque trackpad over SPI. */
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN GP19
#define SPI_MISO_PIN GP16
#define POINTING_DEVICE_CS_PIN GP17
#undef CIRQUE_PINNACLE_DIAMETER_MM
#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define CIRQUE_PINNACLE_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE

/* OLED over i2c. */
#define I2C1_CLOCK_SPEED 400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_16_9
#define OLED_DISPLAY_HEIGHT 128

/* Reset. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17

/* RGB settings. */
// #define RGBLED_NUM 36
// #define RGBLED_SPLIT
//     { 18, 18 }

/* RGB matrix support. */
#ifdef RGB_MATRIX_ENABLE
#    define RGB_DI_PIN GP11 // Underglow.
#    define RGB_MATRIX_LED_COUNT 36
#    define RGB_MATRIX_SPLIT { 18, 18 }
#    define RGB_MATRIX_CENTER { 133, 54 }

#    define SPLIT_TRANSPORT_MIRROR
//#    define RGB_MATRIX_LED_COUNT RGBLED_NUM
// #    define RGB_MATRIX_SPLIT RGBLED_SPLIT
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_KEYPRESSES

// Startup values.
#    define RGB_MATRIX_DEFAULT_HUE 0
#    define RGB_MATRIX_DEFAULT_SAT 255
#    define RGB_MATRIX_DEFAULT_VAL 64
#    define RGB_MATRIX_DEFAULT_HSV RGB_MATRIX_DEFAULT_HUE, RGB_MATRIX_DEFAULT_SAT, RGB_MATRIX_DEFAULT_VAL

// Rainbow swirl as startup mode.
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT

// Slow swirl at startup.
#    define RGB_MATRIX_DEFAULT_SPD 32

// Enable all animations on ARM boards since they have plenty of memory
// available for it.
#    define ENABLE_RGB_MATRIX_ALPHAS_MODS
#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_BAND_SAT
#    define ENABLE_RGB_MATRIX_BAND_VAL
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#    define ENABLE_RGB_MATRIX_DUAL_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define ENABLE_RGB_MATRIX_RAINDROPS
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define ENABLE_RGB_MATRIX_HUE_BREATHING
#    define ENABLE_RGB_MATRIX_HUE_PENDULUM
#    define ENABLE_RGB_MATRIX_HUE_WAVE
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define ENABLE_RGB_MATRIX_SPLASH
#    define ENABLE_RGB_MATRIX_MULTISPLASH
#    define ENABLE_RGB_MATRIX_SOLID_SPLASH
#    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif
