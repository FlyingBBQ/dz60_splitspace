// 
// dz60 - splitspace
// by FlyingBBQ
//
#include "dz60.h"

// Layers
#define _DF 0
#define _L1 1
#define _L2 2
#define _L3 3
#define _FN 8
#define _MC 9

// keys
#define  ______   KC_TRNS
#define  CTL_SPC  CTL_T(KC_SPC)
#define  CTL_BSP  CTL_T(KC_BSPC)
#define  FN_DEL   LT(_FN, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Default with Left and Right Space
    [_DF] = KEYMAP(
            KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5   , KC_6    , KC_7    , KC_8  , KC_9    , KC_0     , KC_MINS , KC_EQL  , KC_NO   , KC_BSPC ,
            KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T   , KC_Y    , KC_U    , KC_I  , KC_O    , KC_P     , KC_LBRC , KC_RBRC , KC_BSLS ,
            KC_ESC  , KC_A    , KC_S    , KC_D    , KC_F    , KC_G   , KC_H    , KC_J    , KC_K  , KC_L    , KC_SCLN  , KC_QUOT , KC_ENT  ,
            KC_LSFT , KC_NO   , KC_Z    , KC_X    , KC_C    , KC_V   , KC_B    , KC_N    , KC_M  , KC_COMM , KC_DOT   , KC_SLSH , KC_RSFT , KC_DEL  ,
            KC_LCTL , KC_LGUI , KC_LALT , KC_SPC  , MO(_FN) , KC_SPC , KC_RALT , KC_RGUI , KC_NO , OSL(_MC), KC_RCTL) ,

    // Left Space to backspace
    [_L1] = KEYMAP(
            ______  , ______ , ______ , ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ , ______ , ______ ,
            ______  , ______ , ______ , ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ , ______ ,
            ______  , ______ , ______ , ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ ,
            ______  , ______ , ______ , ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ , ______ ,
            ______  , ______ , ______ , CTL_BSP , ______ , ______ , ______ , ______ , ______ , ______ , ______) ,

    // Modifier to delete when tapped
    [_L2] = KEYMAP(
            ______ , ______  , ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ , ______ , ______ ,
            ______ , ______  , ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ , ______ ,
            ______ , ______  , ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ ,
            ______ , ______  , ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ , ______ ,
            ______ , ______  , ______  , ______ , FN_DEL , ______ , ______ , ______ , ______ , ______ , ______) ,

    // When tapping shift write ( or )
    [_L3] = KEYMAP(
            ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______  , ______ , ______ ,
            ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______  , ______ ,
            ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______  ,
            KC_LSPO , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , KC_RSPC , ______ ,
            ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______) ,


    // Function layer via mid-space modifier key
    [_FN] = KEYMAP(
            ______  , KC_F1   , KC_F2   , KC_F3   , KC_F4  , KC_F5  , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10   , KC_F11  , KC_F12  , ______  , ______ ,
            ______  , ______  , KC_PGUP , ______  , ______ , ______ , ______  , ______  , ______  , ______  , ______   , ______  , ______  , RESET   ,
            ______  , KC_HOME , KC_PGDN , KC_END  , ______ , ______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , ______   , ______  , ______  ,
            TG(_L3) , ______  , ______  , ______  , ______ , ______ , KC_MPLY , KC_VOLD , KC_VOLU , KC_MPRV , KC_MNXT  , KC_MUTE , RGB_TOG , KC_PSCR ,
            ______  , ______  , ______  , TG(_L1) , ______ , TG(_L2), RGB_VAD , RGB_VAI , ______  , RGB_M_P , RGB_M_B) ,

    // Macro layer
    [_MC] = KEYMAP(
            ______ , M(1)   , M(2)   , M(3)   , M(4)   , M(5)   , M(6)   , M(7)   , M(8)   , M(9)   , M(10)   , M(11)  , M(12)  , ______ , ______ ,
            ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ , ______ ,
            ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ ,
            ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ , ______ ,
            ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______) ,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch(id) {
            case 1:
                SEND_STRING("https://www.reddit.com/r/MechanicalKeyboards/");
                break;
            case 2:
                rgblight_show_solid_color(69, 133, 136);
                break;
            case 3:
                rgblight_show_solid_color(254, 128, 25);
                break;
            case 5:
                //cyan
                rgblight_sethsv(183, 49, 52);
                break;
            case 6:
                //orange
                rgblight_sethsv(27, 90, 100);
                break;
        }
    }
    return MACRO_NONE;
}

