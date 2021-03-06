/*
    dz60 - splitspace
    by FlyingBBQ
*/
#include "dz60.h"

// Renaming keys
#define  ______   KC_TRNS
#define  CTL_BSP  CTL_T(KC_BSPC)
#define  CTL_ESC  CTL_T(KC_ESC)
#define  WIN_L    LCTL(LGUI(KC_LEFT))
#define  WIN_R    LCTL(LGUI(KC_RGHT))

// layers
enum layers {
    _DF,
    _L1,
    _L2,
    _FN,
    _MC,
};

// Macro names
enum custom_keycodes {
    MURL_1 = SAFE_RANGE,
    MURL_2,
    MTXT_1,
    MCLR_1,
    MCLR_2,
    MCLR_3,
    MCLR_4
};

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Default Left Space to backspace, CTRL when held
    [_DF] = LAYOUT(
            KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5   , KC_6    , KC_7    , KC_8  , KC_9    , KC_0     , KC_MINS , KC_EQL  , KC_NO   , KC_BSPC ,
            KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T   , KC_Y    , KC_U    , KC_I  , KC_O    , KC_P     , KC_LBRC , KC_RBRC , KC_BSLS ,
            KC_ESC  , KC_A    , KC_S    , KC_D    , KC_F    , KC_G   , KC_H    , KC_J    , KC_K  , KC_L    , KC_SCLN  , KC_QUOT , KC_ENT  ,
            KC_LSFT , KC_NO   , KC_Z    , KC_X    , KC_C    , KC_V   , KC_B    , KC_N    , KC_M  , KC_COMM , KC_DOT   , KC_SLSH , KC_RSFT , KC_DEL  ,
            KC_LCTL , KC_LGUI , KC_LALT , CTL_BSP , MO(_FN) , KC_SPC , KC_RALT , KC_RGUI , KC_NO , OSL(_MC), KC_RCTL) ,

    // Left and Right Space
    [_L1] = LAYOUT(
            ______  , ______ , ______ , ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ , ______ , ______ ,
            ______  , ______ , ______ , ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ , ______ ,
            ______  , ______ , ______ , ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ ,
            ______  , ______ , ______ , ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ , ______ ,
            ______  , ______ , ______ , KC_SPC  , ______ , ______ , ______ , ______ , ______ , ______ , ______) ,

    // Control-escape
    [_L2] = LAYOUT(
            ______  , ______  , ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ , ______ , ______ ,
            ______  , ______  , ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ , ______ ,
            CTL_ESC , ______  , ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ ,
            ______  , ______  , ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ , ______ ,
            ______  , ______  , ______  , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______) ,

    // Function layer via mid-space modifier key
    [_FN] = LAYOUT(
            ______  , KC_F1   , KC_F2   , KC_F3   , KC_F4  , KC_F5  , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10   , KC_F11  , KC_F12  , ______  , ______ ,
            ______  , ______  , KC_PGUP , ______  , ______ , ______ , ______  , ______  , ______  , ______  , ______   , ______  , ______  , RESET   ,
            KC_CAPS , KC_HOME , KC_PGDN , KC_END  , ______ , ______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , ______   , ______  , ______  ,
            ______  , ______  , WIN_L   , WIN_R   , ______ , ______ , KC_MPLY , KC_VOLD , KC_VOLU , KC_MPRV , KC_MNXT  , KC_MUTE , RGB_TOG , KC_PSCR ,
            ______  , ______  , ______  , TG(_L1) , ______ , TG(_L2), RGB_VAD , RGB_VAI , ______  , RGB_M_P , RGB_M_B) ,

    // Macro layer
    [_MC] = LAYOUT(
            ______ , MURL_1 , MURL_2 , MTXT_1 , ______ , MCLR_1 , MCLR_2 , MCLR_3 , MCLR_4 , ______ , ______ , ______  , ______ , ______ , ______ ,
            ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ , ______ ,
            ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ ,
            ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______  , ______ , ______ , ______ ,
            ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______ , ______) ,
};

// Macro function
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case MURL_1:
                SEND_STRING("https://www.github.com/flyingbbq");
                return false;
            case MURL_2:
                SEND_STRING("https://www.reddit.com/r/MechanicalKeyboards/");
                return false;
            case MTXT_1:
                SEND_STRING("snap"SS_TAP(X_HOME)"oh, "SS_TAP(X_END)"!");
                return false;
            case MCLR_1:
                rgblight_show_solid_color(69, 133, 136);
                return false;
            case MCLR_2:
                rgblight_sethsv(183, 49, 52);
                return false;
            case MCLR_3:
                rgblight_show_solid_color(255, 255, 255);
                return false;
            case MCLR_4:
                rgblight_sethsv(0, 0, 100);
                return false;
        }
    }
    return true;
};
