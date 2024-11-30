#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif
#include "leds.c"
#include "keymap_russian.h"

enum custom_keycodes {
    LANG_ENG = SAFE_RANGE, // Ensure these don't conflict with existing keycodes
    LANG_RUS,
    LT_SYM_ENT,
    LT_NUM_BSPC,
};

typedef struct {
    bool     is_active;
    bool     command_sent;
    uint16_t timer;
} layer_tap_t;

layer_tap_t my_lt = {false, false, 0};

bool need_to_restore_layer = false;

enum LAYERS {
    _BASE,
    _NAV,
    _MOUSE,
    _MEDIA,
    _NUM,
    _SYM,
    _FUN,
    //_RULEMAK,
    _GAME,
    _QWERTY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // base layer - colemak-dh
    [_BASE] = LAYOUT(
        KC_Q, KC_W, KC_F, KC_P, KC_B,                                   /* || */ KC_J, KC_L, KC_U, KC_Y, KC_QUOT, 
        LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,   /* || */ KC_M, LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), 
        KC_Z, ALGR_T(KC_X), KC_C, KC_D, KC_V,                           /* || */ KC_K, KC_H, KC_COMM, ALGR_T(KC_DOT), KC_SLSH, 
        XXXXXXX, XXXXXXX, LT(3, KC_ESC), LT(1, KC_SPC), LT(2, KC_TAB),  /* || */ LT(5, KC_ENT), LT(4, KC_BSPC), LT(6, KC_DEL), XXXXXXX, XXXXXXX
    ),

    // navigation layer
    [_NAV] = LAYOUT(
        RESET, KC_NO, KC_NO, KC_NO, KC_NO,              KC_AGIN, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, 
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,      KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,  
        KC_NO, KC_RALT, KC_NO, KC_NO, KC_NO,            KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, 
        XXXXXXX, XXXXXXX, KC_NO, KC_NO, KC_NO,          KC_ENT, KC_BSPC, KC_DEL, XXXXXXX, XXXXXXX
    ),

    // mouse layer
    [_MOUSE] = LAYOUT(
        RESET, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,      KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, 
        KC_NO, KC_RALT, KC_NO, KC_NO, KC_NO,            KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, 
        XXXXXXX, XXXXXXX, KC_NO, KC_NO, KC_NO,          KC_BTN2, KC_BTN1, KC_BTN3, XXXXXXX, XXXXXXX
    ),

    // media layer
    [_MEDIA] = LAYOUT(
        RESET, KC_NO, KC_NO, KC_NO, KC_NO,              RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,      KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, 
        KC_NO, KC_RALT, KC_NO, KC_NO, KC_NO,            LANG_RUS, LANG_ENG, KC_NO, KC_NO, DF(_GAME), 
        XXXXXXX, XXXXXXX, KC_NO, KC_NO, KC_NO,          KC_MSTP, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX
    ),

    // numpad layer
    [_NUM] = LAYOUT(
        KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,             KC_NO, KC_NO, KC_NO, KC_NO, RESET, 
        KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,              KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, 
        KC_GRV, KC_1, KC_2, KC_3, KC_BSLS,              KC_NO, KC_NO, KC_NO, KC_RALT, KC_NO, 
        XXXXXXX, XXXXXXX, KC_DOT, KC_0, KC_MINS,        KC_NO, KC_NO, KC_NO, XXXXXXX, XXXXXXX
    ),

    // symbols layer (num + shift)
    [_SYM] = LAYOUT(
        KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,    KC_NO, KC_NO, KC_NO, KC_NO, RESET,
        KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,     KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE,      KC_NO, KC_NO, KC_NO, KC_RALT, KC_NO, 
        XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_UNDS,    KC_NO, KC_NO, KC_NO, XXXXXXX, XXXXXXX
    ),

    // functional keys layer
    [_FUN] = LAYOUT(
        KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,           KC_NO, KC_NO, KC_NO, KC_NO, RESET, 
        KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,           KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, 
        KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,           KC_NO, KC_NO, KC_NO, KC_RALT, KC_NO, 
        XXXXXXX, XXXXXXX, KC_APP, KC_SPC, KC_TAB,       KC_NO, KC_NO, KC_NO, XXXXXXX, XXXXXXX
    ),

    // // phonetic Russian layer
    // [_RULEMAK] = LAYOUT(
    //     RU_YU, RU_SHA, RU_EF, RU_PE, RU_BE,                                         /* || */ RU_YA, RU_EL, RU_U, RU_SHTI, RU_SOFT, 
    //     LGUI_T(RU_A), LALT_T(RU_ER), LCTL_T(RU_ES), LSFT_T(RU_TE), RU_GHE,          /* || */ RU_EM, LSFT_T(RU_EN), LCTL_T(RU_IE), LALT_T(RU_I), LGUI_T(RU_O), 
    //     RU_ZE, ALGR_T(RU_SHCH), RU_TSE, RU_DE, RU_VE,                               /* || */ RU_KA, RU_HA, RU_CHE, ALGR_T(RU_ZHE), RU_HARD, 
    //     XXXXXXX, XXXXXXX, LT(_MEDIA, KC_ESC), LT(1, KC_SPC), LT(_MOUSE, KC_TAB),    /* || */ LT_SYM_ENT, LT(4, KC_BSPC), LT(6, KC_DEL), XXXXXXX, XXXXXXX
    // ),

    [_QWERTY] = LAYOUT(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,          /*||*/  KC_Y,         KC_U,          KC_I,         KC_O,           KC_P,
        LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,          /*||*/  KC_H,         LSFT_T(KC_J),  LCTL_T(KC_K), LALT_T(KC_L),   LGUI_T(KC_SCLN),
        KC_Z,         RALT_T(KC_X), KC_C,         KC_V,         KC_B,          /*||*/  KC_N,         KC_M,          KC_COMM,      RALT_T(KC_DOT), KC_SLSH,
        XXXXXXX,XXXXXXX,  KC_ESC, KC_SPC, KC_TAB,  /*||*/  LT_SYM_ENT, LT_NUM_BSPC, KC_DEL, XXXXXXX, XXXXXXX
    ),

    // gaming layer
    [_GAME] = LAYOUT(
        KC_1, KC_Q, KC_W, KC_E, KC_R,                   /* || */ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_BASE), 
        KC_2, KC_A, KC_S, KC_D, KC_F,                   /* || */ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        KC_3, KC_Z, KC_X, KC_C, KC_V,                   /* || */ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, XXXXXXX, KC_LCTL, KC_LSFT, KC_SPC,     /* || */ KC_TAB, KC_LALT, KC_ESC, XXXXXXX, XXXXXXX
    ),
};

void switch_to_english(void) {
    uint8_t mod_state = get_mods();
    clear_mods();
    SEND_STRING(SS_LGUI(" "));
    layer_move(_BASE);
    set_mods(mod_state);
};

#define RUS_LAYER_TIMEOUT 5000 // timeout in milliseconds

void switch_to_russian(void) {
    if (_QWERTY == get_highest_layer(layer_state)) {
        switch_to_english();
    } else {
        uint8_t mod_state = get_mods();
        clear_mods();
        SEND_STRING(SS_LGUI(" "));
        layer_move(_QWERTY);
        set_mods(mod_state);
    };
};

void matrix_scan_user(void) {
    // this resets current language to English after <timeout> if Russian was active
    if (_QWERTY == get_highest_layer(layer_state)) {
        if (RUS_LAYER_TIMEOUT < last_input_activity_elapsed()) {
            switch_to_english();
        }
    }
}

////////////////////////////////////////////////////////////////////
// This switches to English but only when LT-key is pressed and another key it tapped.
//
// Function to handle layer-tap logic
void process_layer_tap(uint16_t keycode, uint16_t layer, keyrecord_t *record) {
    if (record->event.pressed) {
        // Key was pressed - start timer.
        my_lt.timer     = timer_read();
        my_lt.is_active = true;
        layer_on(layer);
    } else { // Key was released
             // Was it a tap?
        if (my_lt.is_active && (TAPPING_TERM > timer_elapsed(my_lt.timer))) {
            tap_code(keycode);
        }
        layer_off(layer);

        if (my_lt.command_sent) {
            SEND_STRING(SS_LGUI(" "));
            my_lt.command_sent = false;
        }
        my_lt.is_active = false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mod_state = get_mods();

    // Check if the current layer is _QWERTY
    // and key is pressed
    // and HRMs are active
    if (layer_state_cmp(layer_state, _QWERTY) && record->event.pressed && (mod_state & (MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI)))) {
        {
            layer_move(_BASE);
            need_to_restore_layer = true;
            return true; // Continue normal tab processing
        }
    }

    if (!record->event.pressed && need_to_restore_layer) {
        layer_move(_QWERTY);
        need_to_restore_layer = false;
        return true; // Continue normal tab processing
    }

    // check for specific keycodes
    switch (keycode) {
            // user keys first
        case LANG_ENG:
            if (record->event.pressed) switch_to_english();
            return false; // Skip further processing

        case LANG_RUS:
            if (record->event.pressed) switch_to_russian();
            return false; // Skip further processing
        case LT_SYM_ENT:
            process_layer_tap(KC_ENT, _SYM, record);
            return false; // Skip all further processing of this key
        case LT_NUM_BSPC:
            process_layer_tap(KC_BSPC, _NUM, record);
            return false; // Skip all further processing of this key
                          // special consideration for TAB & ESCAPE & digits
        case LT(_MOUSE, KC_TAB):
        case LT(_MEDIA, KC_ESC):
            // only operate if pressed
            if (record->event.pressed &&
                // Ignore if held
                record->tap.count &&
                // Check if the current layer is _QWERTY
                layer_state_cmp(layer_state, _QWERTY) &&
                // And any of the modifiers are active
                (mod_state & (MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI)))) {
                switch_to_english();
            };
            return true; // Continue normal tab processing
        default:
            if (my_lt.is_active && record->event.pressed) {
                if (!my_lt.command_sent) {
                    my_lt.command_sent = true;
                    SEND_STRING(SS_LGUI(" "));
                }
                return true; // Allow the key press to be handled normally by QMK
            }
            break;
    } // done with specific keys
   
   
    return true;
}