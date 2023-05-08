# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
RGB_MATRIX_SUPPORTED = yes  # RGB matrix is supported and enabled by default
RGBLIGHT_SUPPORTED = no     # RGB underglow is supported, but not enabled by default
RGB_MATRIX_ENABLE = yes     # Enable keyboard RGB matrix functionality
RGB_MATRIX_DRIVER = WS2812

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

AUTO_SHIFT_ENABLE = yes
VPATH  +=  keyboards/gboards/
COMBO_ENABLE=yes
LEADER_ENABLE = yes
TAP_DANCE_ENABLE = yes

LTO_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = no

SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
MUSIC_ENABLE = no

SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_spi # Assembled version uses SPI.

