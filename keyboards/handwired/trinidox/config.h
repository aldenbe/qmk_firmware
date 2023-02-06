/*
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

#include "config_common.h"

// #define VENDOR_ID    0x444D
// #define MANUFACTURER tshort
// #define PRODUCT_ID  0x3636
// #define DEVICE_VER  0x0001
// #define PRODUCT     "Dactyl-Manuform (6x6)"

/* USB Device descriptor parameter */

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 5

// #define SPLIT_POINTING_ENABLE
// #define POINTING_DEVICE_RIGHT
// #define PMW3360_CS_PIN A4
// #define PMW3360_CPI 600
// #define POINTING_DEVICE_INVERT_X
// #define ROTATIONAL_TRANSFORM_ANGLE  20
