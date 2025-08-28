/* Copyright (C) 2023 jonylee@hfd
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

enum layers {
    WIN_B,
    WIN_CAPS,
    WIN_FN,
    MAC_B,
    MAC_W,
    MAC_FN
};

enum custom_keycodes {
    LV_AWOP = SAFE_RANGE,
    LV_AWCL,
    LV_CAPS = LT(WIN_CAPS, KC_ESC),
    LV_EQ,
    LV_DDBS,
    LV_DDS,
    LV_MD = UC(0x00B7),
    LV_FN = MO(WIN_FN)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case LV_EQ:
            SEND_STRING("===");
            return false;
        case LV_DDBS:
            SEND_STRING("..\\");
            return false;
        case LV_DDS:
            SEND_STRING("../");
            return false;
        case LV_AWOP:
            SEND_STRING("() => " SS_LCTL(SS_TAP(X_LEFT)) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
            return false;
        case LV_AWCL:
            SEND_STRING("() => ");
            return false;
        }
    }
    return true;
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [WIN_B] = LAYOUT_all(
        KC_ESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12, KC_DEL,           KC_MPLY,
        KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL, KC_BSPC,          KC_HOME,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_END,
        LV_CAPS,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,   KC_NO, KC_ENT,           KC_PGUP,
        KC_LSFT,   KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL,   KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, LV_FN,   KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_CAPS] = LAYOUT_all(
        _______,   _______, _______, _______, _______, _______, _______, _______, _______,  KC_PWR, _______, _______, _______, _______,          KC_MUTE,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, LV_AWOP, LV_AWCL, _______,   LV_EQ, _______,          MS_BTN1,
        _______,   _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LV_DDBS,          MS_BTN2,
        _______,   KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,   KC_NO, _______,          MS_BTN4,
        _______,     KC_NO, _______, _______, _______, _______, _______, _______, _______, _______,   LV_MD,  LV_DDS,          _______, KC_W,    MS_BTN5,
        _______,   _______, _______,                    KC_ENT,                            _______, _______, _______,          KC_A,    KC_S,       KC_D),

    [WIN_FN] = LAYOUT_all(
        _______, KC_MYCM, KC_MAIL, KC_WSCH, KC_WHOM, KC_MSEL, _______, _______, _______, QK_BOOT,  KC_NUM, _______, _______, _______,           KC_MUTE,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_P0, RGB_SPD, RGB_SPI, _______,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,  _______, KC_PSCR, _______, _______, RGB_MOD,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, _______, _______,   KC_NO, RGB_HUI,           _______,
        _______,   KC_NO, _______, _______, KC_CALC, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_EJCT,          _______,  RGB_VAI, _______,
        _______, GU_TOGG, _______,                   _______,                            KC_MENU, _______,  KC_APP,          RGB_SAD,  RGB_VAD, RGB_SAI),

    [MAC_B] = LAYOUT_all( /* Base */
        KC_ESC,  KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, KC_F5,   KC_F6,   KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,KC_VOLU,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,KC_EQL,   KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,KC_RBRC,  KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,KC_NUHS,  KC_ENT,           KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                             KC_RGUI, MO(MAC_FN),KC_RCTL,        KC_LEFT, KC_DOWN, KC_RGHT),

    [MAC_W] = LAYOUT_all( /* WASD/↑←↓→ */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_W,    _______,
        _______, _______, _______,                   _______,                            _______, MO(MAC_FN), _______,          KC_A,    KC_S,    KC_D),

    [MAC_FN] = LAYOUT_all( /* FN */
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,  KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL,            RGB_MOD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SPD, RGB_SPI, _______,           _______,
        _______, _______,TG(MAC_W),_______, _______, _______, _______, _______, KC_INS,  DF(WIN_B),KC_PSCR,_______, _______, RGB_MOD,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, _______, _______, RGB_MOD, RGB_HUI,           _______,
        _______, _______, _______, _______, KC_CALC, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,          _______,  RGB_VAI, _______,
        _______, _______, _______,                   _______,                            _______, _______, _______,          RGB_SAD,  RGB_VAD, RGB_SAI)
};

// clang-format off
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [WIN_B] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [WIN_CAPS] = { ENCODER_CCW_CW(MS_WHLR, MS_WHLL) },
    [WIN_FN] = { ENCODER_CCW_CW(RGB_VAI, RGB_VAD) },
    [MAC_B] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [MAC_W] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [MAC_FN] = { ENCODER_CCW_CW(RGB_VAI, RGB_VAD) }
};
#endif
