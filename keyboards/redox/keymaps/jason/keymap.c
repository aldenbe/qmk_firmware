#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _LOWER 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NAV,
  LOWER,
  ALTAB
};

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)
#define KC_SYGR LT(_SYMB, KC_ESC)  // instead of SYM_L
#define JA_WIN LGUI_T(KC_ESC)
#define JA_SWIN SWIN_T(KC_LGUI)
#define JA_SYM MO(_LOWER)
#define JA_CTLPU LCTL_T(KC_PGUP)
#define JA_ALTPD LALT_T(KC_PGDN)
#define JA_SBSPC LSFT_T(KC_BSPC)

//#define KC_ADEN LT(_ADJUST, KC_END)
//#define KC_ADPU LT(_ADJUST, KC_PGUP)

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

// ported from minidox
#define JA_STAB LSFT_T(KC_TAB)
#define JA_NBSPC LT(_NAV, KC_BSPC)
#define JA_CDEL LCTL_T(KC_DEL)
#define JA_ALEN LALT_T(KC_ENT)




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_NAMI ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_SYGR   ,                          SYM_L   ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_A    ,KC_S    ,KC_D    ,  KC_F  ,KC_G    ,JA_WIN ,                           JA_SWIN ,    KC_H,  KC_J  ,KC_K  ,    KC_L  ,KC_QUOT ,KC_SCLN ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSLS ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,JA_CTLPU,JA_ALTPD,        KC_HOME ,KC_END  ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_BSLS ,KC_PPLS ,KC_PMNS ,KC_ALAS ,     JA_STAB ,    JA_NBSPC,JA_CDEL  ,       JA_ALEN ,KC_SPC  ,    KC_MINS ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_PIPE ,_______ ,                          _______ ,KC_PSLS ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_HASH ,KC_DLR  ,KC_LBRC ,KC_RBRC ,KC_GRV  ,_______ ,                          _______ ,KC_PAST ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_PERC ,KC_CIRC ,KC_LPRN ,KC_RPRN ,KC_TILD ,_______ ,_______ ,        _______ ,_______ ,XXXXXXX ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    KC_P0   ,     KC_P0   ,KC_PDOT ,KC_PENT ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,XXXXXXX ,_______ ,                          _______ ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0     ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,_______ ,                          _______ ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,        _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_BTN1 ,    KC_BTN2 ,_______ ,        _______ ,_______ ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,XXXXXXX ,_______ ,                          _______ ,KC_ASDN, KC_ASUP, KC_ASRP, KC_ASON, KC_ASOFF, KC_ASTG,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MS_L ,KC_LALT ,KC_LCTL ,KC_LSFT ,KC_TAB ,_______ ,                          _______ ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,ALTAB   ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,        _______ ,XXXXXXX ,KC_HOME ,KC_END  ,KC_PGUP ,KC_PGDN ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_BTN1 ,    KC_BTN2 ,_______ ,        _______ ,_______ ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
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
    SEQ_TWO_KEYS(KC_D, KC_D) { // select line
      SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
    }
    SEQ_TWO_KEYS(KC_C, KC_A) { // copy all
      SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      SEND_STRING("https://start.duckduckgo.com\n");
    }
    SEQ_THREE_KEYS(KC_C, KC_I, KC_W) { // c-i-w change inside word
      SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)) SS_LSFT(SS_LCTL(SS_TAP(X_RIGHT)) SS_TAP(X_LEFT)));
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
    }
    return true;
};
