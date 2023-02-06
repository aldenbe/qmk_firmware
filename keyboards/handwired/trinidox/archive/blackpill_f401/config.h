/* Copyright 2019
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

#include "config_common.h"

// #define PRODUCT Onekey Blackpill STM32F401

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 5

// wiring of each half
#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS { A6, A5, A4, A3, A2 }
// #define MATRIX_COL_PINS { B5, B4, E6, D7, C6 }
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS { B3, B4, B5, B6, B7 }



// #define MATRIX_COL_PINS { B0 }
// #define MATRIX_ROW_PINS { A7 }
// #define UNUSED_PINS

// #define BACKLIGHT_PIN         A0
// #define BACKLIGHT_PWM_DRIVER  PWMD5
// #define BACKLIGHT_PWM_CHANNEL 1

// #define RGB_DI_PIN A1

#define ADC_PIN A0
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
// #define PMW3360_CS_PIN B0
#define PMW3360_CPI 400

#define PMW3360_CS_PIN                       B0
#define PMW3360_SPI_MODE                     3

// /* spi config for eeprom and  pmw3360 sensor */
// #define SPI_DRIVER                           SPID1
// #define SPI_SCK_PIN                          A5
// #define SPI_SCK_PAL_MODE                     5
// #define SPI_MOSI_PIN                         A7
// #define SPI_MOSI_PAL_MODE                    5
// #define SPI_MISO_PIN                         A6
// #define SPI_MISO_PAL_MODE                    5
