/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

/* Layers */
#define LAYER2  LT(2, KC_ENT)   // Activate layer 2 if held, enter if tapped
#define LAYER3  LT(3, KC_SPC)   // Activate layer 3 if held, space if tapped
#define LAYER4  LT(4, KC_LEFT)  // Activate layer 4 if held, left arrow if tapped
#define CTRLTAB LCTL_T(KC_TAB)  // Control if held, tab if tapped
#define GUIQUOT LGUI_T(KC_QUOT) // Win if held, quotation if tapped

/* Windows commands */
#define BLDONLY RCS(KC_B)       // Ctrl + Shift + B (start building in Visual Studio)
#define NOBUILD LCTL(KC_PAUS)   // Ctrl + Pause/Break (stop build in Visual Studio)
#define RUNONLY LCTL(KC_F5)     // Ctrl + F5 (run without debugging in Visual Studio)
#define NODEBUG LSFT(KC_F5)     // Shift + F5 (stop debugging in Visual Studio)
#define DLTBRKS RCS(KC_F9)      // Ctrl + Shift + F9 (delete all brakpoints in Visual Studio)
#define PRVSRCH RCS(KC_F3)      // Ctrl + Shift + F3 (go to previous match in Visual Studio)
#define NXTSRCH LCTL(KC_F3)     // Ctrl + F3 (go to next match in Visual Studio)
#define TASKMGR LCA(KC_DEL)     // Ctrl + Alt + Delete
#define GT_ISE  MEH(KC_I)       // Ctrl + Shift + Alt + I
#define LOCKSCR LGUI(KC_L)      // Win + L (lock screen)
#define KILLWIN LALT(KC_F4)     // Alt + F4 (close window)

/* Hyprland commands */
#define WSPACE1 LGUI(KC_1)      // Move to workspace 1
#define WSPACE2 LGUI(KC_2)      // Move to workspace 2
#define WSPACE3 LGUI(KC_3)      // Move to workspace 3
#define WSPACE4 LGUI(KC_4)      // Move to workspace 4
#define WSPACE5 LGUI(KC_5)      // Move to workspace 5
#define WSPACE6 LGUI(KC_6)      // Move to workspace 6
#define WSPACE7 LGUI(KC_7)      // Move to workspace 7
#define WSPACE8 LGUI(KC_8)      // Move to workspace 8
#define WSPACE9 LGUI(KC_9)      // Move to workspace 9
#define WSPACE0 LGUI(KC_0)      // Move to workspace 10
#define MVESPC1 LSG(KC_1)       // Move window to workspace 1
#define MVESPC2 LSG(KC_2)       // Move window to workspace 2
#define MVESPC3 LSG(KC_3)       // Move window to workspace 3
#define MVESPC4 LSG(KC_4)       // Move window to workspace 4
#define MVESPC5 LSG(KC_5)       // Move window to workspace 5
#define MVESPC6 LSG(KC_6)       // Move window to workspace 6
#define MVESPC7 LSG(KC_7)       // Move window to workspace 7
#define MVESPC8 LSG(KC_8)       // Move window to workspace 8
#define MVESPC9 LSG(KC_9)       // Move window to workspace 9
#define MVESPC0 LSG(KC_0)       // Move window to workspace 10

/* Zen-browser commands */
#define ZENPREV LCA(KC_LEFT)    // Move to previous Zen workspace
#define ZENNEXT LCA(KC_RGHT)    // Move to next Zen workspace
#define ZENSPTQ LCA(KC_U)       // Close split view
#define ZENSPTH LCA(KC_H)       // Horizontal split view
#define ZENSPTV LCA(KC_V)       // Vertical split view

/* Macros */
enum custom_keycodes {
    UCMAIL  = SAFE_RANGE,
    GMAIL1,
    GMAIL2,
    GTIMAIL,
    PASSWD1,
    PASSWD2,
    NUMBER,
    BUILD,
    COMMENT,
    UNCOMMT,
    VSPYTHN,
    UNLCODE,
    UNLOCK
};

enum {
    TDWSPC1,
    TDWSPC2,
    TDWSPC3,
    TDWSPC4,
    TDWSPC5,
    TDWSPC6,
    TDWSPC7,
    TDWSPC8,
    TDWSPC9,
    TDWSPC0
};

tap_dance_action_t tap_dance_actions[] = {
    [TDWSPC1] = ACTION_TAP_DANCE_DOUBLE(WSPACE1, MVESPC1),
    [TDWSPC2] = ACTION_TAP_DANCE_DOUBLE(WSPACE2, MVESPC2),
    [TDWSPC3] = ACTION_TAP_DANCE_DOUBLE(WSPACE3, MVESPC3),
    [TDWSPC4] = ACTION_TAP_DANCE_DOUBLE(WSPACE4, MVESPC4),
    [TDWSPC5] = ACTION_TAP_DANCE_DOUBLE(WSPACE5, MVESPC5),
    [TDWSPC6] = ACTION_TAP_DANCE_DOUBLE(WSPACE6, MVESPC6),
    [TDWSPC7] = ACTION_TAP_DANCE_DOUBLE(WSPACE7, MVESPC7),
    [TDWSPC8] = ACTION_TAP_DANCE_DOUBLE(WSPACE8, MVESPC8),
    [TDWSPC9] = ACTION_TAP_DANCE_DOUBLE(WSPACE9, MVESPC9),
    [TDWSPC0] = ACTION_TAP_DANCE_DOUBLE(WSPACE0, MVESPC0),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_4x12(
            KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
            CTRLTAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, GUIQUOT,
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,
            KC_LGUI, KC_DEL,  KC_LALT, MO(1),   LAYER2,  LAYER2,  LAYER3,  LAYER3,  LAYER4,  KC_DOWN, KC_UP,   KC_RGHT
    ),

    [1] = LAYOUT_ortho_4x12(
            _______, _______, _______, _______, _______, _______, _______, ZENSPTQ, WSPACE9, WSPACE0, _______, _______,
            _______, _______, _______, _______, _______, _______, ZENSPTH, _______, WSPACE5, WSPACE6, WSPACE7, WSPACE8,
            _______, _______, _______, _______, _______, _______, _______, _______, WSPACE1, WSPACE2, WSPACE3, WSPACE4,
            _______, _______, _______, _______, _______, _______, _______, _______, ZENPREV, _______, _______, ZENNEXT
    ),

    [2] = LAYOUT_ortho_4x12(
            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS,
            UNLOCK,  _______, _______, DLTBRKS, _______, _______, _______, _______, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,
            _______, _______, _______, _______, _______, BLDONLY, NOBUILD, _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,
            _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_PGUP, KC_PGDN, KC_RBRC
    ),

    [3] = LAYOUT_ortho_4x12(
            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, UNCOMMT, KC_9,    KC_0,    KC_MINS, KC_EQL,
            _______, _______, _______, _______, _______, _______, _______, _______, KC_5,    KC_6,    KC_7,    KC_8,
            _______, _______, _______, COMMENT, _______, BUILD,   _______, _______, KC_1,    KC_2,    KC_3,    KC_4,
            _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, _______, _______, KC_RCBR
    ),

    [4] = LAYOUT_ortho_4x12(
            _______, KILLWIN, _______, _______, VSPYTHN, _______, _______, _______, _______, GMAIL2,  PASSWD1, KC_DEL,
            _______, PASSWD2, _______, _______, _______, GTIMAIL, _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______, NUMBER,  GMAIL1,  _______, _______, KC_BSLS, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, PRVSRCH, KC_HOME, KC_END,  NXTSRCH
    ),

    [5] = LAYOUT_ortho_4x12(
            _______, _______, _______, _______, _______, _______, _______, _______, MVESPC9, MVESPC0, _______, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, MVESPC5, MVESPC6, MVESPC7, MVESPC8,
            _______, _______, _______, _______, _______, _______, _______, _______, MVESPC1, MVESPC2, MVESPC3, MVESPC4,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, 1, 4, 5);
}

bool process_record_user (uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case UCMAIL:
      if (record->event.pressed) {
        // when UCMAIL is pressed
        SEND_STRING ("sharmamm@mail.uc.edu");
      } else {
        //when UCMAIL is released
      }
      break;
    case GMAIL1:
      if (record->event.pressed) {
        // when GMAIL1 is pressed
        SEND_STRING ("mayanksharma1806@gmail.com");
      } else {
        //when GMAIL1 is released
      }
      break;
    case GMAIL2:
      if (record->event.pressed) {
        // when GMAIL2 is pressed
        SEND_STRING ("onlyforotherapps2016@gmail.com");
      } else {
        //when GMAIL2 is released
      }
      break;
    case GTIMAIL:
      if (record->event.pressed) {
        // when GTIMAIL is pressed
        SEND_STRING ("m.sharma@gtisoft.com");
      } else {
        //when GTIMAIL is released
      }
      break;
    case PASSWD1:
      if (record->event.pressed) {
        // when PASSWD1 is pressed
        SEND_STRING ("win@Spring2026");
      } else {
        //when PASSWD1 is released
      }
      break;
    case PASSWD2:
      if (record->event.pressed) {
        // when PASSWD2 is pressed
        SEND_STRING ("aeem15@UC");
      } else {
        //when PASSWD2 is released
      }
      break;
    case NUMBER:
      if (record->event.pressed) {
        // when NUMBER is pressed
        SEND_STRING ("4088399849");
      } else {
        //when NUMBER is released
      }
      break;
    case BUILD:
      if (record->event.pressed) {
        // when BUILD is pressed
        // save and then build in Visual Studio
        // Ctrl + S followed by Ctrl + Shift + B
        SEND_STRING(SS_LCTL(SS_TAP(X_S) SS_LSFT(SS_TAP(X_B))));
      } else {
        //when BUILD is released
      }
      break;
    case COMMENT:
      if (record->event.pressed) {
        // when COMMENT is pressed
        // comment a block of lines in Visual Studio
        // Ctrl + K, Ctrl + S
        SEND_STRING(SS_LCTL(SS_TAP(X_K) SS_TAP(X_C)));
      } else {
        //when COMMENT is released
      }
      break;
    case UNCOMMT:
      if (record->event.pressed) {
        // when UNCOMMT is pressed
        // comment a block of lines in Visual Studio
        // Ctrl + K, Ctrl + U
        SEND_STRING(SS_LCTL(SS_TAP(X_K) SS_TAP(X_U)));
      } else {
        //when UNCOMMT is released
      }
      break;
    case VSPYTHN:
      if (record->event.pressed) {
        // when VSPYTHN is pressed
        // comment a block of lines in Visual Studio
        // Ctrl + K, Ctrl + U
        SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_TAP(X_W) SS_TAP(X_ENT) SS_LCTL(SS_TAP(X_F5)));
      } else {
        //when VSPYTHN is released
      }
      break;
    case UNLCODE:
      if (record->event.pressed) {
        // when UNLCODE is pressed
        SEND_STRING ("180691");
      } else {
        //when UNLCODE is released
      }
      break;
    case UNLOCK:
      if (record->event.pressed) {
        // when UNLOCK is pressed
        SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_DEL))) SS_DELAY(1000) "180691");
      } else {
        //when UNLOCK is released
      }
      break;
  }
  return true;
}
