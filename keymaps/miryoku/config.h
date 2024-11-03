/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0x10, 0x0C, 0x2F, 0xF2, 0xD9, 0xD2, 0xEE, 0xEC}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

// Set the mouse settings to a comfortable speed/accuracy trade-off,
// assuming a screen refresh rate of 60 Htz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
#define MOUSEKEY_INTERVAL 16
// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#define MOUSEKEY_TIME_TO_MAX 40
// The default is 100
#define MOUSEKEY_WHEEL_INTERVAL 50
// The default is 40
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100


// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64


// Pick good defaults for enabling homerow modifiers
#undef TAPPING_TERM
#define TAPPING_TERM 250

// Prevent normal rollover on alphas from accidentally triggering mods.
// this is default cfg
// #define IGNORE_MOD_TAP_INTERRUPT

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
// #define AUTO_SHIFT_NO_SETUP

// Disable rapid switch from tap to hold, enables double tap hold auto-repeat.
#undef QUICK_TAP_TERM
#define QUICK_TAP_TERM 120

// #define DEBOUNCE 10  // Increase to reduce noise from the switches

// This line ensures that the tapping toggle feature is disabled across the board, so none of the modifier keys will stick after tapping them multiple times.
#define TAPPING_TOGGLE 0

// Turning this on helps ensure that if you're still holding a tap-hold key and press another key, it will treat the original tap-hold key as a hold. This is a good default for modifier keys (like ALT, GUI, or CTRL).
#define HOLD_ON_OTHER_KEY_PRESS

#define PERMISSIVE_HOLD
// #undef HOLD_ON_OTHER_KEY_PRESS

#define NO_ACTION_ONESHOT
#define ONESHOT_TAP_TOGGLE 0

/*Combos*/
// #ifdef COMBO_ENABLE
// #    define COMBO_TERM 25
// #endif
