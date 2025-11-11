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
    CHILD,
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
    LV_FN = MO(WIN_FN),
    LV_FN2 = LT(MAC_FN, KC_ESC),
    LV_ET1,
    LV_ET2,
    LV_ET3,
    LV_ET4,
    LV_ET5,
    LV_ET6,
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
        case LV_ET1:
            send_unicode_string("¯\\_(ツ)_/¯");
            return false;
        case LV_ET2:
            send_unicode_string("(-̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥᷄◞ω◟-̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥̥᷅ )");
            return false;
        case LV_ET3:
            send_unicode_string("٩(͡๏̯͡๏)۶");
            return false;
        case LV_ET4:
            send_unicode_string("\\(༎ຶ益༎ຶ)ᕗ");
            return false;
        case LV_ET5:
            send_unicode_string("¯\\_(◉‿◉)_/¯");
            return false;
        case LV_ET6:
            send_unicode_string("◕‿↼");
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
        _______,   _______, _______, _______, _______, _______, _______, _______, _______,  KC_PWR, _______, _______, _______, _______,           LV_ET6,
        _______,   KC_6,    KC_7,       KC_8,    KC_9,    KC_0, _______, _______, _______, LV_AWOP, LV_AWCL, _______,   LV_EQ, _______,           LV_ET1,
        _______,   KC_PGDN, KC_UP,   KC_PGUP, _______, _______, _______, _______, _______, _______, _______, _______, _______, LV_DDBS,           LV_ET2,
        _______,   KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,   KC_NO, _______,           LV_ET3,
        _______,     KC_NO, _______, _______, _______, _______, _______, _______, _______, _______,   LV_MD,  LV_DDS,          _______, _______,  LV_ET5,
        _______,   _______, _______,                    KC_ENT,                            _______, _______, _______,          _______, _______, _______),

    [WIN_FN] = LAYOUT_all(
        _______, KC_MYCM, KC_MAIL, KC_WSCH, KC_WHOM, KC_MSEL, _______, _______, _______, QK_BOOT,  KC_NUM,  UC_WIN, DF(CHILD), _______,            LV_ET1,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_P0, RGB_SPD,   RGB_SPI, _______,            MS_BTN1,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,  _______, KC_PSCR, _______,   _______, RGB_MOD,            MS_BTN2,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, _______, _______,     KC_NO, RGB_HUI,            MS_BTN4,
        _______,   KC_NO, _______, _______, KC_CALC, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_EJCT,            _______,  RGB_VAI,  MS_BTN5,
        _______, _______, _______,                   _______,                            KC_MENU, _______,  KC_APP,            RGB_SAD,  RGB_VAD, RGB_SAI),

    [CHILD] = LAYOUT_all( /* Lily */
        LV_FN2,     UC(0x00D0), UC(0x00D0), UC(0x2168), UC(0x058E), UC(0x30C4), LV_ET6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,   KC_EQL,   KC_DEL,           LV_ET1,
        LSFT(KC_1), KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,   KC_EQL,   KC_BSPC,          LV_ET2,
        LSFT(KC_2), LSFT(KC_Q), LSFT(KC_W), LSFT(KC_E), LSFT(KC_R),	LSFT(KC_T),	LSFT(KC_Y),	LSFT(KC_U),	LSFT(KC_I),	LSFT(KC_O),	LSFT(KC_P),	KC_LBRC,   KC_RBRC,  KC_BSLS,          LV_ET3,
        LSFT(KC_3), LSFT(KC_A), LSFT(KC_S), LSFT(KC_D), LSFT(KC_F),	LSFT(KC_G),	LSFT(KC_H),	LSFT(KC_J),	LSFT(KC_K),	LSFT(KC_L),	KC_SCLN,    KC_QUOT,   KC_NUHS,   KC_ENT,          LV_ET4,
        LSFT(KC_4), KC_NUBS,    LSFT(KC_Z), LSFT(KC_X), LSFT(KC_C),	LSFT(KC_V),	LSFT(KC_B),	LSFT(KC_N),	LSFT(KC_M),	KC_COMM,    KC_DOT,     KC_SLSH,              LV_ET5, KC_UP,   LV_ET5,
        LSFT(KC_5), LSFT(KC_6), LSFT(KC_7),                     LV_ET1,                                             LV_ET2,     LV_ET3,     LV_ET4,              KC_LEFT, KC_DOWN, KC_RGHT),

    [MAC_W] = LAYOUT_all( /* WASD/↑←↓→ */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_W,    _______,
        _______, _______, _______,                   _______,                            _______, MO(MAC_FN), _______,          KC_A,    KC_S,    KC_D),

    [MAC_FN] = LAYOUT_all( /* Lily FN */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,           DF(WIN_B),
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,          _______,  _______, _______,
        _______, _______, _______,                   _______,                            _______,  _______,  _______,          _______,  _______, _______)
};

// clang-format off
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [WIN_B] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [WIN_CAPS] = { ENCODER_CCW_CW(MS_WHLR, MS_WHLL) },
    [WIN_FN] = { ENCODER_CCW_CW(RGB_VAI, RGB_VAD) },
    [CHILD] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [MAC_W] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [MAC_FN] = { ENCODER_CCW_CW(RGB_VAI, RGB_VAD) }
};
#endif
