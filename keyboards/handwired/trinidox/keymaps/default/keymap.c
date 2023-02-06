#include QMK_KEYBOARD_H

enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
    ALTAB,
    CARET,
    SLOW,
};

// #include "g/keymap_combo.h"
// #include "pointing.h"

// from /users/drashna/pointing/pointing.c
// static uint16_t mouse_timer           = 0;
// static uint16_t mouse_debounce_timer  = 0;
// static uint8_t  mouse_keycode_tracker = 0;
// bool            tap_toggling = false, enable_acceleration = false;

// enum userspace_custom_keycodes {
//     KC_ACCEL
// };

// #ifdef TAPPING_TERM_PER_KEY
// #    define TAP_CHECK get_tapping_term(KC_BTN1, NULL)
// #else
// #    ifndef TAPPING_TERM
// #        define TAPPING_TERM 200
// #    endif
// #    define TAP_CHECK TAPPING_TERM
// #endif

#define _BASE 0
#define _RAISE 1
#define _LOWER 2

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)


#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2

#define JA_NATB LT(_RAISE, KC_TAB)
#define JA_NDEL LT(_RAISE, KC_DEL)
#define JA_NBSPC LT(_RAISE, KC_BSPC)
#define JA_SBSPC LSFT_T(KC_BSPC)
#define JA_CDEL LCTL_T(KC_DEL)
#define JA_CTAB LCTL_T(KC_TAB)
#define JA_STAB LSFT_T(KC_TAB)
#define JA_NTAB LCTL(KC_PGUP)
#define JA_PTAB LCTL(KC_PGDN)
#define JA_ALEN LALT_T(KC_ENT)
#define JA_ALMIN LALT_T(KC_MINS)
#define JA_NUMI LT(_LOWER, KC_MINS)
#define JA_NENT LT(_LOWER, KC_ENT)
// #define JA_MIDMB MT(DRAG_SCROLL, KC_BTN3)
#define JA_MIDMB LT(0, KC_NO)
#define JA_SSHOT RSG(KC_S)
#define JA_WINX LGUI(KC_E)
#define JA_ALENT LALT(KC_ENT)

#include "g/keymap_combo.h"
#include "pointing.h"

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * ,----------------------------------,                             ,----------------------------------,
     * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   '  |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |  [   |   ]  |                                                         |   -  |   =  |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      | ESC  |  BS  |                             | SPACE|ENTER |
     *                      |  +   |   +  |                             |  +   |  +   |
     *                      | SHIFT| CTRL |                             | ALT  |SHIFT |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    | TAB  | HOME | | END  | DEL  |
     *                                    '------+------' '------+------'
     *                                    | Raise|  ~   | | GUI  | Lower|
     *                                    '------+------' '------+------'
     */
    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                          KC_LBRC, KC_RBRC,                                                        KC_LGUI, KC_SCLN,
                                                     _______,  _______, _______,  _______,
                                                     JA_CDEL, JA_NBSPC,  KC_SPC,  JA_ALEN,
                                                     JA_STAB, _______,  _______,  JA_NUMI
    ),

    /* Raise
     * ,----------------------------------,                             ,----------------------------------,
     * |      |      |  mup |      |      |                             | VOL+ |      |  up  |      | PgUp |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |      | mleft| mdown|mright|      |                             | MUTE | left | down |right | PgDn |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |      |      |      |      |      |                             | VOL- |  /   |  \   |  ?   |  |   |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |      |      |                                                         | mbtn |mbtn2 |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     */
    [_RAISE] = LAYOUT(
          CARET,KC_BTN2 ,JA_MIDMB,KC_BTN1 , SLOW   ,                                      KC_WBAK, KC_BTN1,JA_MIDMB, KC_BTN2, KC_WFWD,
        _______,KC_LALT ,KC_LCTL ,KC_LSFT ,KC_TAB  ,                                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
        _______,_______ ,ALTAB   ,JA_SSHOT,JA_WINX ,                                      KC_HOME, KC_END , KC_PGUP, KC_PGDN, _______,
                 _______, _______,                                                                          JA_NTAB, JA_PTAB,
                                   _______, _______,                                      _______, _______,
                                                     _______, _______,  _______, JA_ALENT,
                                                     _______, _______,  _______, KC_LGUI
    ),

    /* Lower
     * ,----------------------------------,                             ,----------------------------------,
     * | F1   | F2   | F3   | F4   | F5   |                             |  F6  | F7   |  F8  |  F9  |  F10 |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  0   |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   |  (   |  )   |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        | F11  | F12  |                                                         |  -   |  =   |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     */
    [_LOWER] = LAYOUT(
        KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                     KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,
        KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                     KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,
        KC_SLSH ,KC_PAST ,KC_MINS ,KC_PPLS ,KC_EQL  ,                                     _______ ,_______ ,KC_COMM ,KC_DOT  ,KC_NUBS ,
                   KC_GRV, KC_BSLS,                                                                           _______, _______,
                                   _______, _______,                                      _______, _______,
                                                     JA_CDEL, JA_SBSPC, _______, _______,
                                                     _______, _______,  _______, _______
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

// from https://docs.qmk.fm/#/feature_pointing_device?id=drag-scroll-or-mouse-scroll
bool set_scrolling = false;
bool set_caret = false;
bool set_slow = false;
int scroll_scaling = 10;
int scroll_scale = 10;
int caret_scale_horiz = 15;
int caret_scale_vert = 50;
int slow_scale = 5;
int scroll_rollover_x = 0;
int scroll_rollover_y = 0;
int horiz = 0;
int vert = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {

    //scale = set_scrolling * scroll_scale + set_caret * caret_scale + set_slow * slow_scale;

    if (set_scrolling) {
        mouse_report.h = (mouse_report.x + scroll_rollover_x) / scroll_scale;
        mouse_report.v = -(mouse_report.y + scroll_rollover_y) / scroll_scale;
        scroll_rollover_x = (mouse_report.x + scroll_rollover_x) % scroll_scale;
        scroll_rollover_y = (mouse_report.y + scroll_rollover_y) % scroll_scale;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    if (set_caret) {
        horiz = (mouse_report.x + scroll_rollover_x) / caret_scale_horiz;
        vert = -(mouse_report.y + scroll_rollover_y) / caret_scale_vert;
        scroll_rollover_x = (mouse_report.x + scroll_rollover_x) % caret_scale_horiz;
        scroll_rollover_y = (mouse_report.y + scroll_rollover_y) % caret_scale_vert;
        int i;
        // horizontal movement
        for(i = 0; i < abs(horiz); i = i + 1){
            if (horiz > 0){
                tap_code16(KC_RIGHT);
            } else {
                tap_code16(KC_LEFT);
            }
        }
        // vertical movement
        for(i = 0; i < abs(vert); i = i + 1){
            if (vert > 0){
                tap_code16(KC_UP);
            } else {
                tap_code16(KC_DOWN);
            }
        }
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    if (set_slow){
        scroll_rollover_x = (mouse_report.x + scroll_rollover_x) % slow_scale;
        scroll_rollover_y = (mouse_report.y + scroll_rollover_y) % slow_scale;
        mouse_report.x = (mouse_report.x + scroll_rollover_x) / slow_scale;
        mouse_report.y = (mouse_report.y + scroll_rollover_y) / slow_scale;
    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // if (keycode == DRAG_SCROLL && record->event.pressed) {
    //     set_scrolling = !set_scrolling;
    //     if (set_scrolling) {
    //         pointing_device_set_cpi(100);
    //     }
    //     else {
    //         pointing_device_set_cpi(PMW3360_CPI);
    //     }
    // }

    switch (keycode) {
    case ALTAB:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            register_code(KC_LALT);
            register_code(KC_TAB);
            unregister_code(KC_TAB);
        } else {
            // when keycode ALTAB is released
            unregister_code(KC_LALT);
        }
        break;

    case CARET:
        if (record->event.pressed) {
            set_caret = true;
        } else {
            set_caret = false;
        }
        break;
    case SLOW:
        if (record->event.pressed) {
            set_slow = true;
        } else {
            set_slow = false;
        }
        break;
    // case DRAG_SCROLL:
    //     if (record->event.pressed) {
    //         set_scrolling = true;
    //     } else {
    //         set_scrolling = false;
    //     }
    //     break;
    case LT(0, KC_NO):
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_BTN3); // Intercept tap function to send Ctrl-C
        } else if (record->event.pressed) {
            set_scrolling = true;
        } else {
            set_scrolling = false;
        }
        return false;
    }

    return true;
}

// __attribute__((weak)) report_mouse_t pointing_device_task_keymap(report_mouse_t mouse_report) {
//     return mouse_report;
// }

// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//     int8_t x = mouse_report.x, y = mouse_report.y;
//     mouse_report.x = 0;
//     mouse_report.y = 0;

//     if (x != 0 && y != 0) {
//         mouse_timer = timer_read();
// #ifdef OLED_ENABLE
//         oled_timer = timer_read32();
// #endif
//         if (timer_elapsed(mouse_debounce_timer) > TAP_CHECK) {
//             // if (enable_acceleration) {
//             //     x = (x > 0 ? x * x / 16 + x : -x * x / 16 + x);
//             //     y = (y > 0 ? y * y / 16 + y : -y * y / 16 + y);
//             // }
//             mouse_report.x = x;
//             mouse_report.y = y;
//             if (!layer_state_is(_RAISE)) {
//                 layer_on(_RAISE);
//             }
//         }
//     } else if (timer_elapsed(mouse_timer) > 650 && layer_state_is(_RAISE) && !mouse_keycode_tracker && !tap_toggling) {
//         layer_off(_RAISE);
//     } else if (tap_toggling) {
//         if (!layer_state_is(_RAISE)) {
//             layer_on(_RAISE);
//         }
//     }

//     return pointing_device_task_keymap(mouse_report);
// }


// bool process_record_pointing(uint16_t keycode, keyrecord_t* record) {
//     switch (keycode) {
//         case TT(_RAISE):
//             if (record->event.pressed) {
//                 mouse_keycode_tracker++;
//             } else {
// #if TAPPING_TOGGLE != 0
//                 if (record->tap.count == TAPPING_TOGGLE) {
//                     tap_toggling ^= 1;
// #    if TAPPING_TOGGLE == 1
//                     if (!tap_toggling) mouse_keycode_tracker -= record->tap.count + 1;
// #    else
//                     if (!tap_toggling) mouse_keycode_tracker -= record->tap.count;
// #    endif
//                 } else {
//                     mouse_keycode_tracker--;
//                 }
// #endif
//             }
//             mouse_timer = timer_read();
//             break;
//         case TG(_RAISE):
//             if (record->event.pressed) {
//                 tap_toggling ^= 1;
//             }
//             break;
//         case MO(_RAISE):
// #if defined(KEYBOARD_ploopy)
//         case DPI_CONFIG:
// #elif (defined(KEYBOARD_bastardkb_charybdis) || defined(KEYBOARD_handwired_tractyl_manuform)) && !defined(NO_CHARYBDIS_KEYCODES)
//         case SAFE_RANGE ... (CHARYBDIS_SAFE_RANGE-1):
// #endif
//         case KC_MS_UP ... KC_MS_WH_RIGHT:
//             record->event.pressed ? mouse_keycode_tracker++ : mouse_keycode_tracker--;
//             mouse_timer = timer_read();
//             break;
//         case KC_ACCEL:
//             enable_acceleration = record->event.pressed;
//             record->event.pressed ? mouse_keycode_tracker++ : mouse_keycode_tracker--;
//             mouse_timer = timer_read();
//             break;
//         case QK_ONE_SHOT_MOD ... QK_ONE_SHOT_MOD_MAX:
//             break;
//         case QK_MOD_TAP ... QK_MOD_TAP_MAX:
//             if (record->event.pressed || !record->tap.count) {
//                 break;
//             }
//         default:
//             if (IS_NOEVENT(record->event)) break;
//             if ((keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) && (((keycode >> 0x8) & 0xF) == _RAISE)) {
//                 record->event.pressed ? mouse_keycode_tracker++ : mouse_keycode_tracker--;
//                 mouse_timer = timer_read();
//                 break;
//             }
//             if (layer_state_is(_RAISE) && !mouse_keycode_tracker && !tap_toggling) {
//                 layer_off(_RAISE);
//             }
//             mouse_keycode_tracker = 0;
//             mouse_debounce_timer  = timer_read();
//             break;
//     }
//     return true;
// }

// // layer_state_t layer_state_set_pointing(layer_state_t state) {
// //     if (layer_state_cmp(state, _GAMEPAD) || layer_state_cmp(state, _DIABLO) || layer_state_cmp(state, _DIABLOII)) {
// //         state |= ((layer_state_t)1 << _RAISE);
// //     }
// //     return state;
// // }

LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    SEQ_ONE_KEY(KC_F) { // ()
      SEND_STRING("()" SS_TAP(X_LEFT));
    }
    SEQ_ONE_KEY(KC_D) { // []
      SEND_STRING("[]" SS_TAP(X_LEFT));
    }
    SEQ_ONE_KEY(KC_S) { // {}
      SEND_STRING("{}" SS_TAP(X_LEFT));
    }
    SEQ_ONE_KEY(KC_A) { // <>
      SEND_STRING("<>" SS_TAP(X_LEFT));
    }
    SEQ_ONE_KEY(KC_L) { // logout of windows
      SEND_STRING(SS_LGUI("l"));
    }
    SEQ_ONE_KEY(KC_E) { // windows file explorer
      SEND_STRING(SS_LGUI("e"));
    }
    SEQ_ONE_KEY(KC_R) { // windows run
      SEND_STRING(SS_LGUI("r"));
    }

    // SEQ_ONE_KEY(KC_N) { // launch notepad
    //     // register_code(KC_LGUI);
    //     // unregister_code(KC_LGUI);
    //     SEND_STRING(SS_TAP(X_LGUI));
    //     SEND_STRING("notepad");
    //     SEND_STRING(SS_TAP(X_ENT));
    // }
    // SEQ_ONE_KEY(KC_P) { // launch paint brush
    //     // register_code(KC_LGUI);
    //     // unregister_code(KC_LGUI);
    //     SEND_STRING(SS_TAP(X_LGUI));
    //     SEND_STRING("paint");
    //     SEND_STRING(SS_TAP(X_ENT));
    // }
    // SEQ_ONE_KEY(KC_C) { // launch command prompt
    //     // register_code(KC_LGUI);
    //     // unregister_code(KC_LGUI);
    //     SEND_STRING(SS_TAP(X_LGUI));
    //     SEND_STRING("cmd");
    //     SEND_STRING(SS_TAP(X_ENT));
    // }
    SEQ_TWO_KEYS(KC_D, KC_D) { // select line
      SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
    }
    SEQ_TWO_KEYS(KC_C, KC_A) { // copy all
      SEND_STRING(SS_LCTL("a") SS_LCTL("c") SS_LCTL(SS_TAP(X_END)));
    }
    // SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
    //   SEND_STRING("https://start.duckduckgo.com\n");
    // }
    SEQ_THREE_KEYS(KC_C, KC_I, KC_W) { // c-i-w change inside word
      SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)) SS_LSFT(SS_LCTL(SS_TAP(X_RIGHT))));
    }
    // SEQ_TWO_KEYS(KC_A, KC_S) {
    //   register_code(KC_LGUI);
    //   register_code(KC_S);
    //   unregister_code(KC_S);
    //   unregister_code(KC_LGUI);
    // }
  }
}
