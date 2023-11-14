# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

RGB_MATRIX_SUPPORTED = yes  # RGB matrix is supported and enabled by default
RGBLIGHT_SUPPORTED = no     # RGB underglow is supported, but not enabled by default

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
EXTRAKEY_ENABLE = yes

SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
MUSIC_ENABLE = no

SERIAL_DRIVER = vendor

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360 # Assembled version uses SPI.

