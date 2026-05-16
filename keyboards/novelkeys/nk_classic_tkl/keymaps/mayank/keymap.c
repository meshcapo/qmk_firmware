/* Copyright 2024 Yiancar-Designs
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

/* Mod-tap */
#define WINSPC  LGUI_T(KC_SPC)  // Win if held, space if tapped
#define ESCCTRL LCTL_T(KC_ESC)  // Ctrl if held, esc if tapped

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
#define MVESPC1 LSG(KC_1)       // Move window to workspace 1
#define MVESPC2 LSG(KC_2)       // Move window to workspace 2
#define MVESPC3 LSG(KC_3)       // Move window to workspace 3
#define MVESPC4 LSG(KC_4)       // Move window to workspace 4
#define MVESPC5 LSG(KC_5)       // Move window to workspace 5
#define MVESPC6 LSG(KC_6)       // Move window to workspace 6
#define MVESPC7 LSG(KC_7)       // Move window to workspace 7
#define MVESPC8 LSG(KC_8)       // Move window to workspace 8
#define MVESPC9 LSG(KC_9)       // Move window to workspace 9

/* Zen-browser commands */
#define ZENWSC1 LCA(KC_1)       // Move to Zen workspace 1
#define ZENWSC2 LCA(KC_2)       // Move to Zen workspace 2
#define ZENWSC3 LCA(KC_3)       // Move to Zen workspace 3
#define ZENWSC4 LCA(KC_4)       // Move to Zen workspace 4
#define ZENWSC5 LCA(KC_5)       // Move to Zen workspace 5
#define ZENWSC6 LCA(KC_6)       // Move to Zen workspace 6
#define ZENWSC7 LCA(KC_7)       // Move to Zen workspace 7
#define ZENWSC8 LCA(KC_8)       // Move to Zen workspace 8
#define ZENWSC9 LCA(KC_9)       // Move to Zen workspace 9
#define ZENPREV LCA(KC_LEFT)    // Move to previous Zen workspace
#define ZENNEXT LCA(KC_RGHT)    // Move to next Zen workspace
#define ZENSPTQ LCA(KC_U)       // Close split view
#define ZENSPTH LCA(KC_H)       // Horizontal split view
#define ZENSPTV LCA(KC_V)       // Vertical split view

enum my_keycodes {
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_tkl_ansi_tsangan( /* Base */
    KC_ESC,  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           BUILD,   LOCKSCR, UNLOCK,
    KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,
    KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  KC_END,  KC_PGDN,
    ESCCTRL, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,                   KC_UP,
    KC_LALT, MO(2),   KC_LGUI,                KC_SPC,                                            KC_RGUI, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

[1] = LAYOUT_tkl_ansi_tsangan( /* Windows/VS/Hyprland Layer */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, UNLCODE,
    _______, MVESPC1, MVESPC2, MVESPC3, MVESPC4, MVESPC5, MVESPC6, MVESPC7, MVESPC8, MVESPC9, _______, _______, _______, _______, _______, _______, _______,
    _______, KILLWIN, _______, _______, VSPYTHN, GTIMAIL, _______, UNCOMMT, _______, _______, PASSWD1, _______, _______, _______, TASKMGR, _______, _______,
    _______, PASSWD2, _______, DLTBRKS, _______, GMAIL1,  _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, COMMENT, _______, BLDONLY, NOBUILD, GMAIL2,  _______, _______, _______,          _______,                   _______,
    _______, _______, _______,                   _______,                                              _______, _______, _______, PRVSRCH, _______, NXTSRCH),

[2] = LAYOUT_tkl_ansi_tsangan( /* Zen browser + RGB Layer */
    _______, RM_TOGG, RM_NEXT, RM_HUED, RM_HUEU, RM_SATD, RM_SATD, RM_VALD, RM_VALU, RM_SPDD, RM_SPDU, _______, _______,          _______, _______, _______,
    _______, ZENWSC1, ZENWSC2, ZENWSC3, ZENWSC4, ZENWSC5, ZENWSC6, ZENWSC7, ZENWSC8, ZENWSC9, _______, _______, _______, _______, _______, _______, _______,
    _______, ZENSPTQ, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, ZENSPTH, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, ZENSPTV, _______, _______, _______, _______, _______, _______,          _______,                   _______,
    _______, _______, _______,                   _______,                                              _______, _______, _______, ZENPREV, _______, ZENNEXT),

};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = 50; i <= 55; i++) {
            rgb_matrix_set_color(i, 255, 86, 0);
        }
    } else if ((rgb_matrix_get_mode() == RGB_MATRIX_TYPING_HEATMAP) || (rgb_matrix_get_mode() == RGB_MATRIX_DIGITAL_RAIN)) {
        for (uint8_t i = 50; i <= 55; i++) {
            rgb_matrix_set_color(i, 0, 0, 0);
        }
    }
    return false;
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
