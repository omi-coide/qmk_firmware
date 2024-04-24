#include QMK_KEYBOARD_H
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NAV,
  ADJUST,
};

// Shortcut to make keymap more readable
#define SYM_L   TT(_SYMB)
#define NAV_L   TT(_NAV)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

#define KC_NDPU LT(_NAV, KC_PGUP)
#define KC_NDPD LT(_NAV, KC_PGDN)

//#define KC_ADEN LT(_ADJUST, KC_END)
//#define KC_ADPU LT(_ADJUST, KC_PGUP)
#define KC_SYMLP LT(_SYMB,KC_COMM)
#define KC_NAVRP LT(_NAV ,KC_DOT)
enum combos {
  KL_QUOT,
  JK_SLSH,
  OP_BSLS,
  IO_PLUS
};

const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM io_combo [] = {KC_I, KC_O, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [KL_QUOT] = COMBO(kl_combo, KC_QUOT),
  [JK_SLSH] = COMBO(jk_combo, KC_SLSH),
  [OP_BSLS] = COMBO(op_combo, KC_BSLS),
  [IO_PLUS] = COMBO(io_combo, KC_EQL)
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,   NAV_L,                          SYM_L   ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
LCTL_T(KC_ESC),KC_A   ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_NDPU ,KC_HOME,         KC_END,  KC_NDPD ,KC_B    ,KC_N    ,KC_M    ,KC_P    ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     MO(_NAV),KC_MINS  ,KC_EQL ,KC_LALT ,     KC_SYMLP    ,KC_SPC  ,KC_ENT  ,        KC_LGUI ,KC_BSPC ,    KC_NAVRP     ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6                                               ,KC_PSLS ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS ,_______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,_______ ,                          _______ ,KC_PAST ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,_______ ,                          _______ ,KC_BSLS ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PDOT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_TILD ,KC_GRV  ,KC_LBRC ,KC_RBRC ,KC_EQL  ,_______ ,_______ ,        _______ ,_______ ,KC_SLSH ,KC_P0   ,KC_QUOT ,KC_DOT  ,KC_PENT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    KC_DEL ,      KC_NUM  ,KC_CAPS ,KC_PENT ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,                                            KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,XXXXXXX ,_______ ,                          _______ ,KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,_______ ,                          _______ ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,CM_TOGG ,NK_TOGG ,XXXXXXX ,_______ ,_______ ,        _______ ,XXXXXXX ,XXXXXXX ,KC_PSCR ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,     KC_BTN1 ,    KC_BTN2 ,KC_BTN3 ,        _______ ,_______ ,    XXXXXXX ,     KC_VOLU ,KC_VOLD ,KC_BRIU ,KC_BRID
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )//,

  //[_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  // XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // XXXXXXX ,RESET   ,RGB_M_P ,RGB_TOG ,RGB_MOD ,RGB_HUD ,RGB_HUI ,                          RGB_SAD ,RGB_SAI ,RGB_VAD ,RGB_VAI ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_ASRP ,KC_ASDN ,KC_ASUP ,KC_ASTG ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
  // XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  //)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _QWERTY:
            set_led_off;
            break;
        case _SYMB:
            set_led_green;
            break;
        case _NAV:
            set_led_blue;
            break;
        case _ADJUST:
            set_led_red;
            break;
        default:
            break;
    }
  return state;
}


