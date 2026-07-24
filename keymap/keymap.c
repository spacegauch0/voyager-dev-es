// SPDX-License-Identifier: GPL-2.0-or-later
// Voyager Dev-ES: a from-scratch English/Spanish + TypeScript layout for macOS.

#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,
    CODE,
    NAV,
    NUM,
    SPANISH,
};

enum custom_keycodes {
    TS_EQ3 = SAFE_RANGE,
    TS_NEQ3,
    TS_NULLISH,
    TS_OPTCHAIN,
    TS_SPREAD,
    TS_ARROW,
    TS_AND,
    TS_OR,
    TS_LTE,
    TS_GTE,
    TS_ADD_ASSIGN,
    TS_SUB_ASSIGN,
    ES_A_ACUTE,
    ES_E_ACUTE,
    ES_I_ACUTE,
    ES_O_ACUTE,
    ES_U_ACUTE,
    ES_N_TILDE,
    ES_U_DIAERESIS,
    ES_INV_QUESTION,
    ES_INV_EXCLAIM,
};

#define HM_E LCTL_T(KC_E)
#define HM_O LALT_T(KC_O)
#define HM_I LGUI_T(KC_I)
#define HM_S RGUI_T(KC_S)
#define HM_T RALT_T(KC_T)
#define HM_R RCTL_T(KC_R)

#define TH_NUM LT(NUM, KC_BSPC)
#define TH_NAV LT(NAV, KC_SPC)
#define TH_SFT RSFT_T(KC_TAB)
#define TH_CODE LT(CODE, KC_ENT)

#define MAC_UNDO LGUI(KC_Z)
#define MAC_CUT LGUI(KC_X)
#define MAC_COPY LGUI(KC_C)
#define MAC_PASTE LGUI(KC_V)
#define MAC_REDO LGUI(LSFT(KC_Z))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_voyager(
        CW_TOGG, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        KC_ESC,  KC_Q,    KC_J,    KC_Y,    KC_COMM, KC_DOT,                        KC_B,    KC_H,    KC_D,    KC_M,    KC_P,    KC_BSLS,
        OSL(SPANISH), KC_A, HM_E,  HM_O,    HM_I,    KC_U,                          KC_N,    HM_S,    HM_T,    HM_R,    KC_L,    KC_QUOT,
        OS_HYPR, KC_Z,    KC_X,    KC_C,    KC_G,    KC_MINS,                       KC_K,    KC_W,    KC_F,    KC_V,    KC_SLSH, KC_ENT,
                                                    TH_NUM, TH_NAV,         TH_SFT, TH_CODE
    ),

    [CODE] = LAYOUT_voyager(
        TS_EQ3,  TS_NEQ3, TS_NULLISH, TS_OPTCHAIN, TS_SPREAD, TS_ARROW,              TS_AND,  TS_OR,   TS_LTE,  TS_GTE,  TS_ADD_ASSIGN, TS_SUB_ASSIGN,
        KC_ESC,  KC_GRV,  KC_LT,      KC_GT,       KC_AT,     KC_HASH,               KC_AMPR, KC_PIPE, KC_QUES, KC_COLN, KC_SCLN,      KC_BSLS,
        KC_LBRC, KC_LCBR, KC_LPRN,    KC_RPRN,     KC_RCBR,   KC_RBRC,               TS_ARROW, KC_EQL, KC_PLUS, KC_MINS, KC_ASTR,      KC_SLSH,
        KC_UNDS, KC_DQUO, KC_QUOT,    KC_DLR,      KC_PERC,   KC_CIRC,               KC_EXLM, KC_TILD, KC_BSLS, KC_DOT,  KC_COMM,      KC_SCLN,
                                                    KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS
    ),

    [NAV] = LAYOUT_voyager(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       LGUI(KC_GRV), LGUI(KC_TAB), LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), LGUI(KC_W), LGUI(LSFT(KC_T)),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       LGUI(KC_UP),  LALT(KC_LEFT), KC_PGUP, KC_PGDN, LALT(KC_RGHT), LGUI(KC_DOWN),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       LGUI(KC_LEFT), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, LGUI(KC_RGHT),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       MAC_UNDO, MAC_CUT, MAC_COPY, MAC_PASTE, MAC_REDO, KC_DEL,
                                                    KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS
    ),

    [NUM] = LAYOUT_voyager(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TRNS, KC_DOT,  KC_COMM, KC_PLUS, KC_MINS, KC_EQL,                        KC_SLSH, KC_ASTR, KC_EQL,  KC_UNDS, KC_BSLS, KC_ENT,
                                                    KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS
    ),

    [SPANISH] = LAYOUT_voyager(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,
        ES_INV_EXCLAIM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ES_INV_QUESTION,
        KC_TRNS, ES_A_ACUTE, ES_E_ACUTE, ES_O_ACUTE, ES_I_ACUTE, ES_U_ACUTE,        ES_N_TILDE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        ES_INV_EXCLAIM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, ES_U_DIAERESIS, KC_TRNS, KC_TRNS, ES_INV_QUESTION, KC_TRNS,
                                                    KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS
    ),
};

// Explicit handedness makes Chordal Hold predictable. Thumb keys are exempt.
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_voyager(
    'L','L','L','L','L','L',  'R','R','R','R','R','R',
    'L','L','L','L','L','L',  'R','R','R','R','R','R',
    'L','L','L','L','L','L',  'R','R','R','R','R','R',
    'L','L','L','L','L','L',  'R','R','R','R','R','R',
                    '*','*',  '*','*'
);

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HM_E:
        case HM_O:
        case HM_I:
        case HM_S:
        case HM_T:
        case HM_R:
            return 225;
        case TH_NUM:
        case TH_NAV:
        case TH_SFT:
        case TH_CODE:
            return 205;
        default:
            return TAPPING_TERM;
    }
}

static void send_string_clean(const char *string) {
    const uint8_t mods = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();

    clear_mods();
    clear_oneshot_mods();
    send_keyboard_report();
    send_string(string);
    set_mods(mods);
    set_oneshot_mods(oneshot_mods);
    send_keyboard_report();
}

static void send_macos_dead_key(uint16_t dead_key, uint16_t letter) {
    const uint8_t mods = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();
    const bool uppercase = ((mods | oneshot_mods) & MOD_MASK_SHIFT) != 0;

    clear_mods();
    clear_oneshot_mods();
    send_keyboard_report();

    tap_code16(LALT(dead_key));
    if (uppercase) {
        tap_code16(LSFT(letter));
    } else {
        tap_code16(letter);
    }

    set_mods(mods);
    set_oneshot_mods(oneshot_mods);
    send_keyboard_report();
}

static void send_macos_symbol(uint16_t keycode) {
    const uint8_t mods = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();

    clear_mods();
    clear_oneshot_mods();
    send_keyboard_report();
    tap_code16(keycode);
    set_mods(mods);
    set_oneshot_mods(oneshot_mods);
    send_keyboard_report();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case TS_EQ3:        send_string_clean("==="); return false;
        case TS_NEQ3:       send_string_clean("!=="); return false;
        case TS_NULLISH:    send_string_clean("??");  return false;
        case TS_OPTCHAIN:   send_string_clean("?.");  return false;
        case TS_SPREAD:     send_string_clean("..."); return false;
        case TS_ARROW:      send_string_clean("=>");  return false;
        case TS_AND:        send_string_clean("&&");  return false;
        case TS_OR:         send_string_clean("||");  return false;
        case TS_LTE:        send_string_clean("<=");  return false;
        case TS_GTE:        send_string_clean(">=");  return false;
        case TS_ADD_ASSIGN: send_string_clean("+=");  return false;
        case TS_SUB_ASSIGN: send_string_clean("-=");  return false;

        // These use macOS ABC/US dead-key sequences. Hold the Shift thumb for uppercase.
        case ES_A_ACUTE:      send_macos_dead_key(KC_E, KC_A); return false;
        case ES_E_ACUTE:      send_macos_dead_key(KC_E, KC_E); return false;
        case ES_I_ACUTE:      send_macos_dead_key(KC_E, KC_I); return false;
        case ES_O_ACUTE:      send_macos_dead_key(KC_E, KC_O); return false;
        case ES_U_ACUTE:      send_macos_dead_key(KC_E, KC_U); return false;
        case ES_N_TILDE:      send_macos_dead_key(KC_N, KC_N); return false;
        case ES_U_DIAERESIS:  send_macos_dead_key(KC_U, KC_U); return false;
        case ES_INV_QUESTION: send_macos_symbol(LALT(LSFT(KC_SLSH))); return false;
        case ES_INV_EXCLAIM:  send_macos_symbol(LALT(KC_1)); return false;
    }

    return true;
}
