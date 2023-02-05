#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NUM 1
#define _NAV 2
// #define _ADJUST 3

// typedef enum {
//     TD_NONE,
//     TD_UNKNOWN,
//     TD_SINGLE_TAP,
//     TD_SINGLE_HOLD,
//     TD_DOUBLE_TAP,
//     TD_DOUBLE_HOLD,
//     TD_DOUBLE_SINGLE_TAP, // Send two single taps
//     TD_TRIPLE_TAP,
//     TD_TRIPLE_HOLD
// } td_state_t;

// typedef struct {
//     bool is_press_action;
//     td_state_t state;
// } td_tap_t;

// typedef struct {
//     bool is_press_action;
//     td_state_t state;
// } td_tap_s;

// typedef struct {
//     bool is_press_action;
//     td_state_t state;
// } td_tap_l;

// typedef struct {
//     bool is_press_action;
//     td_state_t state;
// } td_tap_v;

// // Tap dance enums
// enum {
//     T_QT,
//     S_QT,
//     L_QT,
//     V_QT,
//     SOME_OTHER_DANCE
// };

// td_state_t cur_dance(qk_tap_dance_state_t *state);

// // For the t tap dance. Put it here so it can be used in any keymap
// void t_finished(qk_tap_dance_state_t *state, void *user_data);
// void t_reset(qk_tap_dance_state_t *state, void *user_data);

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUM,
  SYMB,
  NAV,
  ADJUST,
  LOWER,
  ALTAB,
  CARET,
  SLOW
};

// Shortcut to make keymap more readable
// #define SYM_L   MO(_SYMB)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NATB LT(_NAV, KC_TAB)
#define KC_NAMI LT(_NAV, KC_MINS)
#define KC_NUMI LT(_NUM, KC_MINS)
// #define KC_SYGR LT(_SYMB, KC_ESC)  // instead of SYM_L
#define JA_WIN LGUI_T(KC_ESC)
#define JA_SWIN SWIN_T(KC_LGUI)
// #define JA_SYM MO(_LOWER)
#define JA_CTLPU LCTL_T(KC_PGUP)
#define JA_ALEN LALT_T(KC_ENT)
#define JA_SBSPC LSFT_T(KC_BSPC)
#define JA_CDEL LCTL_T(KC_DEL)
#define JA_ALENT LALT(KC_ENT)
#define JA_SSHOT RSG(KC_S)
#define JA_WINX LGUI(KC_E)
#define JA_STAB LSFT_T(KC_TAB)
#define JA_NBSPC LT(_NAV, KC_BSPC)
#define JA_MIDMB LT(0, KC_NO)


// #define KC_ADEN LT(_ADJUST, KC_END)
// #define KC_ADPU LT(_ADJUST, KC_PGUP)

// mods from https://precondition.github.io/home-row-mods
// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

#include "g/keymap_combo.h"
#include "pointing.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
    KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,                          KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P ,
  //────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
    KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                          KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_QUOT ,
  //────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
    KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                          KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,
  //────────┴────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┴────────┘
                      JA_STAB ,JA_NBSPC,JA_CDEL ,                          JA_ALEN ,KC_SPC  ,KC_NUMI
  //                 └────────┴────────┴────────┘                         └────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT(
  //────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
    KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                          KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,
  //────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
    KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                          KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,
  //────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
    KC_SLSH ,KC_PAST ,KC_MINS ,KC_PPLS ,KC_EQL  ,                          KC_F11  ,KC_F12  ,KC_COMM ,KC_DOT  ,KC_NUBS ,
  //────────┴────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┴────────┘
                      _______ ,_______ ,KC_DEL  ,                          KC_ENT  ,KC_SPC  , _______
  //                 └────────┴────────┴────────┘                         └────────┴────────┴────────┘
  ),
   [_NAV] = LAYOUT(
  //────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
    CARET   ,KC_BTN2 ,JA_MIDMB,KC_BTN1 , SLOW   ,                          KC_WBAK, KC_BTN1,JA_MIDMB, KC_BTN2, KC_WFWD,
  //────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
    _______ ,KC_LALT ,KC_LCTL ,KC_LSFT ,KC_TAB  ,                          KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT, KC_GRV ,
  //────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
    _______ ,_______ ,ALTAB   ,JA_SSHOT,JA_WINX ,                          KC_HOME ,KC_END  ,KC_PGUP ,KC_PGDN ,KC_SCLN ,
  //────────┴────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┴────────┘
                       _______ ,_______ ,_______ ,                         JA_ALENT,ALTAB   , KC_LGUI
  //                 └────────┴────────┴────────┘                         └────────┴────────┴────────┘
  ),
};


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


// MACROS

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

