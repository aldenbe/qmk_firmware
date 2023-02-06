#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NUM 1
#define _SYMB 2
#define _NAV 3
#define _ADJUST 4
#define _LOWER 5

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_s;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_l;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_v;

// Tap dance enums
enum {
    T_QT,
    S_QT,
    L_QT,
    V_QT,
    SOME_OTHER_DANCE
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the t tap dance. Put it here so it can be used in any keymap
void t_finished(qk_tap_dance_state_t *state, void *user_data);
void t_reset(qk_tap_dance_state_t *state, void *user_data);

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUM,
  SYMB,
  NAV,
  ADJUST,
  LOWER,
  ALTAB
};

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NATB LT(_NAV, KC_TAB)
#define KC_NAMI LT(_NAV, KC_MINS)
#define KC_NUMI LT(_NUM, KC_MINS)
#define KC_SYGR LT(_SYMB, KC_ESC)  // instead of SYM_L
#define JA_WIN LGUI_T(KC_ESC)
#define JA_SWIN SWIN_T(KC_LGUI)
#define JA_SYM MO(_LOWER)
#define JA_CTLPU LCTL_T(KC_PGUP)
#define JA_ALEN LALT_T(KC_ENT)
#define JA_SBSPC LSFT_T(KC_BSPC)
#define JA_CDEL LCTL_T(KC_DEL)
#define JA_ALENT LALT(KC_ENT)
#define JA_SSHOT RSG(KC_S)
#define JA_WINX LGUI(KC_E)
#define JA_STAB LSFT_T(KC_TAB)
#define JA_NBSPC LT(_NAV, KC_BSPC)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

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
                      _______ ,_______ ,_______ ,                          KC_ENT  ,KC_SPC  , _______
  //                 └────────┴────────┴────────┘                         └────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
    KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                         KC_GRV  ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS,
  //────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
    KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,                         KC_PAST ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,
  //────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
    KC_F11  ,KC_F12  ,KC_LPRN ,KC_RPRN ,KC_TILD ,                         XXXXXXX ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,
  //────────┴────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┴────────┘
                       _______ ,_______ ,_______ ,                         KC_P0   ,  KC_P0 ,KC_PDOT
  //                 └────────┴────────┴────────┘                         └────────┴────────┴────────┘
  ),
  [_LOWER] = LAYOUT(
  //────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
    XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,XXXXXXX ,                         KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0,
  //────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
    KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,                         KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,XXXXXXX ,
  //────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
    XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                         XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //────────┴────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┴────────┘
                      KC_BTN1 , KC_BTN2 ,_______ ,                         _______ ,_______ ,_______
  //                 └────────┴────────┴────────┘                         └────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
    KC_F1   ,KC_BTN2 ,KC_BTN3 ,KC_BTN1 ,KC_F5   ,                          KC_ASDN ,KC_ASUP ,KC_ASRP ,KC_ASON ,KC_ASOFF,
  //────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
    KC_F6   ,KC_LALT ,KC_LCTL ,KC_LSFT ,KC_TAB  ,                          KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,XXXXXXX ,
  //────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
    KC_F11  ,KC_F12  ,ALTAB   ,JA_SSHOT,JA_WINX ,                          KC_HOME ,KC_END  ,KC_PGUP ,KC_PGDN ,XXXXXXX ,
  //────────┴────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┴────────┘
                       _______ ,_______ ,_______ ,                         JA_ALENT,ALTAB   , KC_LGUI
  //                 └────────┴────────┴────────┘                         └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
    XXXXXXX   ,RGB_M_P ,RGB_TOG ,RGB_MOD ,RGB_HUD ,                          RGB_SAI ,RGB_VAD ,RGB_VAI ,XXXXXXX ,XXXXXXX ,
  //────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
    XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
    XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //────────┴────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┴────────┘
                      XXXXXXX , KC_BSPC,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX
  //                 └────────┴────────┴────────┘                         └────────┴────────┴────────┘
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
    SEQ_ONE_KEY(KC_N) { // launch notepad
        // register_code(KC_LGUI);
        // unregister_code(KC_LGUI);
        SEND_STRING(SS_TAP(X_LGUI));
        SEND_STRING("notepad");
        SEND_STRING(SS_TAP(X_ENT));
    }
    SEQ_ONE_KEY(KC_P) { // launch paint brush
        // register_code(KC_LGUI);
        // unregister_code(KC_LGUI);
        SEND_STRING(SS_TAP(X_LGUI));
        SEND_STRING("paint");
        SEND_STRING(SS_TAP(X_ENT));
    }
    SEQ_ONE_KEY(KC_C) { // launch command prompt
        // register_code(KC_LGUI);
        // unregister_code(KC_LGUI);
        SEND_STRING(SS_TAP(X_LGUI));
        SEND_STRING("cmd");
        SEND_STRING(SS_TAP(X_ENT));
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

// bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
// #ifndef NO_AUTO_SHIFT_ALPHA
//         case KC_A: case KC_B: case KC_C: case KC_D: case KC_E: case KC_F: case KC_G: case KC_H: case KC_I:
//         case KC_J: case KC_K: case KC_L: case KC_M: case KC_N: case KC_O: case KC_P: case KC_Q: case KC_R:
//         case KC_U: case KC_W: case KC_X: case KC_Y: case KC_Z: // no S or T, define in Tap Dance
// #endif
// #ifndef NO_AUTO_SHIFT_NUMERIC
//         case KC_1 ... KC_0:
// #endif
// #ifndef NO_AUTO_SHIFT_SPECIAL
//         case KC_TAB:
//         case KC_MINUS ... KC_SLASH:
//         case KC_NONUS_BSLASH:
// #endif
//             return true;
//     }
//     return false;
// }



 /* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 't' tap dance.
static td_tap_t ttap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void register_shift_t (void) {
  register_code (KC_LSFT);
  register_code (KC_T);
}
void unregister_shift_t (void) {
  unregister_code (KC_LSFT);
  unregister_code (KC_T);
}

// Create an instance of 'td_tap_s' for the 's' tap dance.
static td_tap_s stap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void register_shift_s (void) {
  register_code (KC_LSFT);
  register_code (KC_S);
}
void unregister_shift_s (void) {
  unregister_code (KC_LSFT);
  unregister_code (KC_S);
}

// Create an instance of 'td_tap_l' for the 'l' tap dance.
static td_tap_l ltap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void register_shift_l (void) {
  register_code (KC_LSFT);
  register_code (KC_L);
}
void unregister_shift_l (void) {
  unregister_code (KC_LSFT);
  unregister_code (KC_L);
}

// Create an instance of 'td_tap_v' for the 'v' tap dance.
static td_tap_v vtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void register_shift_v (void) {
  register_code (KC_LSFT);
  register_code (KC_V);
}
void unregister_shift_v (void) {
  unregister_code (KC_LSFT);
  unregister_code (KC_V);
}

void t_finished(qk_tap_dance_state_t *state, void *user_data) {
    ttap_state.state = cur_dance(state);
    switch (ttap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_T); break;
        case TD_SINGLE_HOLD: register_shift_t(); break;
        case TD_DOUBLE_TAP: SEND_STRING("tt"); break;
        case TD_DOUBLE_HOLD: SEND_STRING("'t"); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_T);
        default:;
    }
}

void t_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ttap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_T); break;
        case TD_SINGLE_HOLD: unregister_shift_t(); break;
        //case TD_DOUBLE_TAP: unregister_code(KC_T); break;
        //case TD_DOUBLE_HOLD: unregister_shift_t();
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_T);
        default:;
    }
    ttap_state.state = TD_NONE;
}

void s_finished(qk_tap_dance_state_t *state, void *user_data) {
    stap_state.state = cur_dance(state);
    switch (stap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_S); break;
        case TD_SINGLE_HOLD: register_shift_s(); break;
        case TD_DOUBLE_TAP: SEND_STRING("ss"); break;
        case TD_DOUBLE_HOLD: SEND_STRING("'s"); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_S);
        default:;
    }
}

void s_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (stap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_S); break;
        case TD_SINGLE_HOLD: unregister_shift_s(); break;
        //case TD_DOUBLE_TAP: unregister_code(KC_T); break;
        //case TD_DOUBLE_HOLD: unregister_shift_t();
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_S);
        default:;
    }
    stap_state.state = TD_NONE;
}

void l_finished(qk_tap_dance_state_t *state, void *user_data) {
    ltap_state.state = cur_dance(state);
    switch (ltap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_L); break;
        case TD_SINGLE_HOLD: register_shift_l(); break;
        case TD_DOUBLE_TAP: SEND_STRING("ll"); break;
        case TD_DOUBLE_HOLD: SEND_STRING("'ll"); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_L);
        default:;
    }
}

void l_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ltap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_L); break;
        case TD_SINGLE_HOLD: unregister_shift_l(); break;
        //case TD_DOUBLE_TAP: unregister_code(KC_T); break;
        //case TD_DOUBLE_HOLD: unregister_shift_t();
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_L);
        default:;
    }
    ltap_state.state = TD_NONE;
}

void v_finished(qk_tap_dance_state_t *state, void *user_data) {
    vtap_state.state = cur_dance(state);
    switch (vtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_V); break;
        case TD_SINGLE_HOLD: register_shift_v(); break;
        case TD_DOUBLE_TAP: SEND_STRING("vv"); break;
        case TD_DOUBLE_HOLD: SEND_STRING("'ve"); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_V);
        default:;
    }
}

void v_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (vtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_V); break;
        case TD_SINGLE_HOLD: unregister_shift_v(); break;
        //case TD_DOUBLE_TAP: unregister_code(KC_T); break;
        //case TD_DOUBLE_HOLD: unregister_shift_t();
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_V);
        default:;
    }
    vtap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [T_QT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, t_finished, t_reset),
    [S_QT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, s_finished, s_reset),
    [L_QT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, l_finished, l_reset),
    [V_QT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, v_finished, v_reset),

};

// MACROS

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
