/* Copyright 2020 Nick Brassel (tzarc)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include_next "mcuconf.h"

#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 TRUE

#undef STM32_PWM_USE_TIM5
#define STM32_PWM_USE_TIM5 TRUE

// /*
//  * SPI driver system settings.
//  */
#undef STM32_SPI_USE_SPI1
#define STM32_SPI_USE_SPI1                  TRUE
// #define STM32_SPI_USE_SPI2                  FALSE
// #define STM32_SPI_USE_SPI3                  FALSE
#define STM32_SPI_SPI1_RX_DMA_STREAM        STM32_DMA_STREAM_ID(2, 0)
#define STM32_SPI_SPI1_TX_DMA_STREAM        STM32_DMA_STREAM_ID(2, 3)
// #define STM32_SPI_SPI2_RX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 3)
// #define STM32_SPI_SPI2_TX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 4)
// #define STM32_SPI_SPI3_RX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 0)
// #define STM32_SPI_SPI3_TX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 7)
#define STM32_SPI_SPI1_DMA_PRIORITY         1
// #define STM32_SPI_SPI2_DMA_PRIORITY         1
// #define STM32_SPI_SPI3_DMA_PRIORITY         1
#define STM32_SPI_SPI1_IRQ_PRIORITY         10
// #define STM32_SPI_SPI2_IRQ_PRIORITY         10
// #define STM32_SPI_SPI3_IRQ_PRIORITY         10
#define STM32_SPI_DMA_ERROR_HOOK(spip)      osalSysHalt("DMA failure")

// /* spi config for eeprom and  pmw3360 sensor */
// #define SPI_DRIVER                           SPID1
// #define SPI_SCK_PIN                          A5
// #define SPI_SCK_PAL_MODE                     5
// #define SPI_MOSI_PIN                         A7
// #define SPI_MOSI_PAL_MODE                    5
// #define SPI_MISO_PIN                         A6
// #define SPI_MISO_PAL_MODE                    5
