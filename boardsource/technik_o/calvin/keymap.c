/* Copyright 2020 Boardsource
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
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
    _EXTRA,
    _QWERTY,
    _GAMING,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_ortho_4x12(
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,       KC_B,   KC_J,              KC_L,       KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,       KC_G,   KC_M,              KC_N,       KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,       KC_V,   KC_K,              KC_H,       KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_ESC,  KC_PSCR, KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, LT(_EXTRA,KC_ENT), MO(_RAISE), KC_RALT, KC_RGUI, XXXXXXX, KC_RCTL
    ),

    [_LOWER] = LAYOUT_ortho_4x12(
        KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        KC_DEL,  _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
        _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, KC_LBRC, KC_RBRC, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_RAISE] = LAYOUT_ortho_4x12(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,   KC_9,     KC_0,    _______,
        KC_DEL,  _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL, KC_LBRC,  KC_RBRC, KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT_ortho_4x12(
        _______,     KC_F1,       KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______,     _______,     KC_INS,  KC_HOME, KC_PGUP, _______, _______, RGB_TOG, RGB_HUI, KC_F11,  KC_F12,  _______,
        _______,     _______,     KC_DEL,  KC_END,  KC_PGDN, _______, _______, RGB_MOD, RGB_M_R, RGB_M_P, RGB_VAI, _______,
        TG(_QWERTY), TG(_GAMING), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_EXTRA] = LAYOUT_ortho_4x12(
        _______, G(KC_Q), G(KC_W), G(KC_F), G(KC_P), G(KC_B),   _______, _______, _______, _______, _______, _______,
        _______, G(KC_A), G(KC_R), G(KC_S), G(KC_T), G(KC_G),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, A(KC_C), _______, _______,   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, G(KC_SPC), _______, _______, _______, _______, _______, _______
    ),

    [_QWERTY] = LAYOUT_ortho_4x12(
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_GAMING] = LAYOUT_ortho_4x12(
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, _______, _______, _______, _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, _______, _______, _______, _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, _______, _______, KC_UP,   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
