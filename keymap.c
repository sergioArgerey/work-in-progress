#include QMK_KEYBOARD_H

#include "../../../../quantum/keymap_extras/keymap_spanish.h"

/* STUPID JS code to split by ergodox rows. Call the format function with the unformatted array
sliceBy = groups => items => groups.reduce(({start, acc},size) => ({
    acc: (acc.push(items.slice(start,start+size)),acc ),
    start: start + size
}), {acc:[],start:0}).acc
findMaxLen = items => items.reduce((max,curr) => max < curr.length ? curr.length : max,0)
setLen = len => strings => strings.map(str => str.padEnd(len, " "));
const format = string => {
  const items = string.split(/,\s*(?![^()]*\))/)
  const group = sliceBy([7,7,6,7,5,2,1,3])
  const resize = setLen(findMaxLen(items));
  const joinstr = ',\n'
  const leftItems = group(items.slice(0,items.length/2))
  const rightItems = group(items.slice(items.length/2))
  const [left,right] = [leftItems.map(resize).join(joinstr),rightItems.map(resize).join(joinstr)]
  return `\n${left},\n\n${right}\n`
}
*/

// The layers that we are defining for this keyboards.
#define QWERTY 0
#define SYMBOL 1
#define CONTROL 2
#define IDEA 3
#define WORKMAN 4

// Tap Dance declarations
enum {
    TD_PARENTS,
    TD_BRACK,
    TD_CBRAC,
    TD_SLASHES,
    TD_EXCLM,

    TD_QUOTES,
    TD_AMP_DOL,    
    TD_EQUALS,
    TD_GT_LT,
    TD_PLUSES ,

    TD_AT_PER,
    TD_PIPE, 

    TD_HAS_PER,

    TD_AT_EXLM,
    TD_AT_QES,
};





/* CUSTOM SIMPLE KEYS ********************************************************************************/

// The most portable copy/paste keys (windows (mostly), linux, and some terminal emulators).








/* LAYOUTS ******************************************************************************************/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 1: Qwerty Layer
*
* ,---------------------------------------------------.           ,---------------------------------------------------.
* |         |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |         |
* |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+---------|
* |         |   "' |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   @? |         |
* |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+---------|
* |         |   Q  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   P  |         |
* |---------+------+------+------+------+------| Down |           |  Up  |------+------+------+------+------+---------|
* |         |   A  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,; |  .:  |   Ñ  |         |
* `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+---------'
*   | Ctrl  |   Z  |      |      |M Sym |                                       | Shift| M Con|      |  -_  |      |
*   `-----------------------------------'                                       `----------------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Home | End  |         |      | Esc  |
*                                 ,------|------|------|         |------+------+------.
*                                 | Space|  Tab |      |         | Pg↑  |      |Enter |
*                                 |      |      |------|         |------|Bspace|      |
*                                 |      |      |Delete|         | Pg↓  |      |      |
*                                 `--------------------'         `--------------------'
*/
[QWERTY] = LAYOUT_ergodox_pretty(
    /* left hand */
    KC_NO,        KC_1,           KC_2,         KC_3,     KC_4,     KC_5,    KC_NO,               KC_NO,    KC_6,   KC_7,    KC_8,     KC_9,       KC_0,              KC_NO,
  KC_NO,          TD(TD_QUOTES),  KC_W,         KC_E,     KC_R,     KC_T,    KC_NO,          TO(QWERTY),    KC_Y,   KC_U,    KC_I,     KC_O,       TD(TD_AT_QES),   KC_NO,
    KC_NO,        KC_Q,           KC_S,         KC_D,     KC_F,     KC_G,                                   KC_H,   KC_J,    KC_K,     KC_L,       KC_P,              KC_NO,
    A(KC_TAB),    KC_A,           KC_X,         KC_C,     KC_V,     KC_B,    KC_DOWN,             KC_UP,    KC_N,   KC_M,  KC_COMMA,   KC_DOT,     KC_SCLN,           TT(IDEA),
    CTL_T(KC_ESCAPE),     KC_Z,      KC_NO,    KC_NO,  MO(SYMBOL),                                                 KC_LSFT,  TT(CONTROL),  KC_NO,  CTL_T(ES_MINS),  KC_NO,
                                                                    KC_HOME, KC_END,                    KC_NO, KC_ESCAPE,
                                                                              KC_NO,                    KC_PGUP,
                                                        KC_SPACE, KC_TAB, KC_DELETE,                    KC_PGDOWN, KC_BSPACE, KC_ENTER),




/* Keymap 1: Symbol Layer
*
* ,---------------------------------------------------.           ,--------------------------------------------------.
* |     F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |           |      |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
* |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
* |         |      |      |  / \ |      |      |      |           |      |      |      |   |  |      |      |        |
* |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |         |      |  [ ] |  { } |  ( ) |      |------|           |------|  + * |  < > |  = ~ |  & $ |      |        | 
* |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |         |  ! ¡ |      |      |      |      |      |           |      |      |      |      |      | # %  |        |
* `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   |       |      |      |      |      |                                       |      |      |      |      |      |
*   `-----------------------------------'                                       `----------------------------------'
*                                        ,-------------.         ,-------------.
*                                        |      |      |         |      |      |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      |      |         |      |      |      |
*                                 |      |      |------|         |------|      |      |
*                                 |      |      |      |         |      |      |      |
*                                 `--------------------'         `--------------------'
*/

[SYMBOL] = LAYOUT_ergodox(
        /* Left hand */

        /*-----------------------------------------------------------------------------------------------------------------------------------------*/
        /**/           /**/                     /**/                  /**/                   /**/                 /**/            /**/           /**/
        /**/   KC_F1,  /**/        KC_F2,       /**/       KC_F3,     /**/   KC_F4,          /**/   KC_F5,        /**/    KC_F6,  /**/   KC_NO,  /**/
        /**/           /**/                     /**/                  /**/                   /**/                 /**/            /**/           /**/
        /*-----------------------------------------------------------------------------------------------------------------------------------------*/
        /**/           /**/                     /**/                  /**/                   /**/                 /**/            /**/           /**/
        /**/   KC_NO,  /**/        KC_NO,       /**/       KC_NO,     /**/  TD(TD_SLASHES),  /**/    KC_NO,       /**/    KC_NO,  /**/   KC_NO,  /**/
        /**/           /**/                     /**/                  /**/                   /**/                 /**/            /**/           /**/
        /*--------------------------------------------------------------------------------------------------------------------------*/           /**/
        /**/           /**/                     /**/                  /**/                   /**/                 /**/            /**/           /**/
        /**/   KC_NO,  /**/        KC_NO,       /**/   TD(TD_BRACK),  /**/   TD(TD_CBRAC),   /**/ TD(TD_PARENTS), /**/    KC_G,   /*===============*/
        /**/           /**/                     /**/                  /**/                   /**/                 /**/            /**/           /**/
        /*--------------------------------------------------------------------------------------------------------------------------*/           /**/
        /**/           /**/                     /**/                  /**/                   /**/                 /**/            /**/           /**/
        /**/   KC_NO,  /**/     TD(TD_EXCLM),   /**/      KC_NO,      /**/        KC_NO,     /**/      KC_NO,     /**/    KC_B,   /**/  KC_DOWN, /**/
        /**/           /**/                     /**/                  /**/                   /**/                 /**/            /**/           /**/
        /*-----------------------------------------------------------------------------------------------------------------------------------------*/
             /**/           /**/           /**/           /**/           /**/              /**/
             /**/   KC_NO,  /**/   KC_Z,   /**/   KC_NO,  /**/   KC_NO,  /**/ MO(SYMBOL),  /**/
             /**/           /**/           /**/           /**/           /**/              /**/
             /*==============================================================================*/
                                                                                                                        /*==============================*/
                                                                                                                        /**/           /**/           /**/
                                                                                                                        /**/ KC_HOME,  /**/  KC_END,  /**/
                                                                                                                        /**/           /**/           /**/
                                                                                                         /*=============================================*/
                                                                                                         /**/           /**/           /**/           /**/
                                                                                                         /**/           /**/           /**/   KC_NO,  /**/
                                                                                                         /**/           /**/           /**/           /**/
                                                                                                         /**/           /**/           /*===============*/
                                                                                                         /**/           /**/           /**/           /**/
                                                                                                         /**/ KC_SPACE, /**/  KC_TAB,  /**/ KC_DELETE,/**/
                                                                                                         /**/           /**/           /**/           /**/
                                                                                                         /*=============================================*/

        /* Right hand */

              /*-----------------------------------------------------------------------------------------------------------------------------------*/
              /**/           /**/                /**/                 /**/               /**/                /**/                 /**/           /**/
              /**/   KC_NO,  /**/   KC_F7,       /**/       KC_F8,    /**/   KC_F9,      /**/      KC_F10,   /**/     KC_F11,     /**/   KC_F12, /**/ 
              /**/           /**/                /**/                 /**/               /**/                /**/                 /**/           /**/
              /*-----------------------------------------------------------------------------------------------------------------------------------*/
              /**/           /**/                /**/                 /**/               /**/                /**/                 /**/           /**/
              /**/   KC_NO,  /**/     KC_NO,     /**/       KC_NO,    /**/  TD(TD_PIPE), /**/      KC_NO,    /**/     KC_NO,      /**/   KC_NO,  /**/
              /**/           /**/                /**/                 /**/               /**/                /**/                 /**/           /**/
              /**/           /*-------------------------------------------------------------------------------------------------------------------=*/
              /**/           /**/                /**/                 /**/               /**/                /**/                 /**/           /**/
              /*---------------*/ TD(TD_PLUSES), /**/   TD(TD_GT_LT), /**/ TD(TD_EQUALS),/**/ TD(TD_AMP_DOL),/**/   KC_SCLN,      /**/   KC_NO,  /**/
              /**/           /**/                /**/                 /**/               /**/                /**/                 /**/           /**/
              /**/           /*-------------------------------------------------------------------------------------------------------------------=*/
              /**/           /**/                /**/                 /**/               /**/                /**/                 /**/           /**/
              /**/   KC_UP,  /**/      KC_NO,    /**/      KC_NO,     /**/     KC_NO,    /**/     KC_NO,     /**/ TD(TD_HAS_PER), /**/   KC_NO,  /**/
              /**/           /**/                /**/                 /**/               /**/                /**/                 /**/           /**/
              /*-----------------------------------------------------------------------------------------------------------------------------------*/
                                                              /**/           /**/              /**/           /**/           /**/           /**/
                                                              /**/  KC_LSFT, /**/ TT(CONTROL), /**/  KC_LEFT, /**/  KC_DOWN, /**/ KC_RIGHT, /**/
                                                              /**/           /**/              /**/           /**/           /**/           /**/
                                                              /*==============================================================================*/
        /*===============================*/
        /**/           /**/            /**/
        /**/  KC_NO,   /**/ KC_ESCAPE, /**/
        /**/           /**/            /**/
        /*==============================================*/
        /**/           /**/            /**/           /**/
        /**/   KC_NO,  /**/            /**/           /**/
        /**/           /**/            /**/           /**/
        /*===============*/            /**/           /**/
        /**/           /**/            /**/           /**/
        /**/   KC_NO,  /**/ KC_BSPACE, /**/ KC_ENTER  /**/
        /**/           /**/            /**/           /**/
        /*==============================================*/
    ),




/* Keymap 2: Mouse control, browse  and media
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      | Mute |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |🠐 Arr| Ms UP |Arr →|brilup|      |           |      |VolUp | Prev |Wheel↑| Next |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|brildw|------|           |------|VolDn |MsLeft|Wheel↓|MsRigh|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,-------------.         ,-------------.
 *                                       |      |      |         |      |      |
 *                                ,------|------|------|         |------+------+------.
 *                                |      |      |      |         |      |      | Play |
 *                                | F5   |      |------|         |------|      |      |
 *                                |      |      |      |         |      |      |      |
 *                                `--------------------'         `--------------------'
 */
[CONTROL] = LAYOUT_ergodox_pretty(
  // left hand
  KC_NO,  KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO, KC_NO,   KC_NO,   KC_NO,         KC_MUTE, KC_NO, KC_NO,
  KC_NO,  KC_NO, KC_LEFT, KC_MS_U, KC_RGHT, KC_BRIU, KC_NO,         KC_NO, KC_VOLU, KC_MPRV, KC_MS_WH_UP,   KC_MNXT, KC_NO, TO(SYMBOL),
  KC_NO,  KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_BRID,                       KC_VOLD, KC_BTN1, KC_MS_WH_DOWN, KC_BTN2, KC_NO, TO(QWERTY),
  KC_NO,  KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_DOWN,       KC_UP, KC_NO,   KC_NO,   KC_NO,         KC_NO,   KC_NO, KC_NO,
  CTL_T(KC_ESCAPE),   KC_NO,    KC_NO,  KC_NO,    KC_NO,                          KC_LSFT, TO(QWERTY),   KC_NO,   KC_NO,   KC_NO,

                                           KC_NO, KC_NO,               KC_NO, KC_NO,
                                                  KC_NO,               KC_NO,
                                  KC_F5, KC_WBAK, KC_NO,               KC_NO, KC_NO, KC_MPLY
),




/* Keymap 3: IDEA/CLion layer
 *
 * Search everywhere: double shift
 * Smart code completion: ctrl + 
 *
 *
 *
 *
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,-------------.         ,-------------.
 *                                       |      |      |         |      |      |
 *                                ,------|------|------|         |------+------+------.
 *                                |      |      |      |         |      |      |      |
 *                                |      |      |------|         |------|      |      |
 *                                |      |      |      |         |      |      |      |
 *                                `--------------------'         `--------------------'
 */
[IDEA] = LAYOUT_ergodox_pretty(
    /* left hand */
    KC_NO,        KC_1,   KC_2,        KC_3,           KC_4,      KC_5,          KC_NO,                KC_NO,    KC_6,        KC_7,   KC_8,   KC_9,   KC_0,   KC_NO,
    KC_NO,        KC_NO,  C(S(KC_W)),  C(KC_W),        S(KC_F6),  C(S(KC_F12)),  KC_NO,                KC_NO,    KC_NO,       KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,        KC_NO,  KC_NO,       C(A(KC_SPACE)), KC_NO,     A(KC_INS),                                     KC_NO,   A(KC_ENTER),  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    TO(CONTROL),  KC_NO,  KC_NO,       KC_NO,          KC_NO,     KC_NO,         KC_DOWN,              KC_UP,    KC_NO,       KC_NO,  KC_NO,  KC_NO,  KC_NO,  TO(QWERTY),
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                                                                            TO(QWERTY),  KC_NO,  KC_NO,  KC_NO,  KC_NO,
                                                                   KC_HOME,  KC_END,                       KC_NO,  KC_ESCAPE,
                                                                             KC_NO,                       KC_PGUP,
                                                          KC_SPACE,  KC_TAB, KC_DELETE,                       KC_PGDOWN, KC_BSPACE,  KC_ENTER),



/* Keymap 3: Workman layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,-------------.         ,-------------.
 *                                       |      |      |         |      |      |
 *                                ,------|------|------|         |------+------+------.
 *                                |      |      |      |         |      |      |      |
 *                                |      |      |------|         |------|      |      |
 *                                |      |      |      |         |      |      |      |
 *                                `--------------------'         `--------------------'
 */
[WORKMAN] = LAYOUT_ergodox_pretty(
    /* left hand */
    KC_NO,  KC_1,     KC_2,     KC_3,       KC_4,     KC_5,     KC_NO,        KC_NO, KC_6,      KC_7,     KC_8,     KC_9,     KC_0,     KC_NO,
    KC_NO,  KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_NO,  KC_NO,                KC_NO, KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  TO(SYMBOL),
    KC_NO,  KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_NO,                           KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    TO(CONTROL),  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,  KC_DOWN,        KC_UP, KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                                                        TO(QWERTY),  KC_NO,  KC_NO,  KC_NO,  KC_NO,
                                                KC_HOME,  KC_END,               KC_NO,  KC_ESCAPE,
                                                          KC_DELETE,            KC_PGUP,
                                       KC_SPACE,  KC_TAB, KC_DLR,               KC_PGDOWN, KC_BSPACE,  KC_ENTER),

};










// The current set of active layers (as a bitmask).ff
// There is a global 'layer_state' variable but it is set after the call
// to layer_state_set_user().
static uint32_t current_layer_state = 0;
uint32_t layer_state_set_user(uint32_t state);


// Runs for each key down or up event.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  return true; // Let QMK send the enter press/release events
}



// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};




// LEDS ********************************************************************************************/


// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
};


// Value to use to switch LEDs on. The default value of 255 is far too bright.
static const uint8_t max_led_value = 20;

// Whether the given layer (one of the constant defined at the top) is active.
#define LAYER_ON(layer) (current_layer_state & (1<<layer))

void led_1_on(void) {
  ergodox_right_led_1_on();
  ergodox_right_led_1_set(max_led_value);
}

void led_2_on(void) {
  ergodox_right_led_2_on();
  ergodox_right_led_2_set(max_led_value);
}

void led_3_on(void) {
  ergodox_right_led_3_on();
  ergodox_right_led_3_set(max_led_value);
}

void led_1_off(void) {
  ergodox_right_led_1_off();
}

void led_2_off(void) {
  ergodox_right_led_2_off();
}

void led_3_off(void) {
  ergodox_right_led_3_off();
}

uint32_t layer_state_set_user(uint32_t state) {
  current_layer_state = state;

  if (LAYER_ON(SYMBOL)) {
    led_1_on();
  } else {
    led_1_off();
  }

  if (LAYER_ON(CONTROL)) {
    led_2_on();
  } else {
    led_2_off();
  }

  if (LAYER_ON(IDEA)) {
    led_3_on();
  } else {
    led_3_off();
  }

  return state;
};



/* TAP DANCE ACTIONS *******************************************************************************/

// The definition of the tap dance actions:
qk_tap_dance_action_t tap_dance_actions[] = {
  
  [TD_PARENTS]     =  ACTION_TAP_DANCE_DOUBLE(ES_LPRN, ES_RPRN),
  [TD_BRACK]       =  ACTION_TAP_DANCE_DOUBLE(ES_LBRC, ES_RBRC),
  [TD_CBRAC]       =  ACTION_TAP_DANCE_DOUBLE(ES_LCBR, ES_RCBR),
  [TD_EXCLM]       =  ACTION_TAP_DANCE_DOUBLE(ES_EXLM, ES_IEXL),
  [TD_SLASHES]     =  ACTION_TAP_DANCE_DOUBLE(ES_SLSH, ES_BSLS),

  [TD_QUOTES]      =  ACTION_TAP_DANCE_DOUBLE(ES_DQUO, ES_QUOT),
  [TD_AMP_DOL]     =  ACTION_TAP_DANCE_DOUBLE(ES_AMPR, ES_DLR),
  [TD_EQUALS]      =  ACTION_TAP_DANCE_DOUBLE(ES_EQL,  ES_DIAE),
  [TD_GT_LT]       =  ACTION_TAP_DANCE_DOUBLE(ES_LABK, ES_RABK),
  [TD_PLUSES]      =  ACTION_TAP_DANCE_DOUBLE(ES_PLUS, ES_ASTR),

  [TD_AT_PER]      =  ACTION_TAP_DANCE_DOUBLE(ES_AT,   ES_PERC),
  [TD_PIPE]        =  ACTION_TAP_DANCE_DOUBLE(ES_PIPE, KC_GRV),

  [TD_HAS_PER]     =  ACTION_TAP_DANCE_DOUBLE(ES_HASH, ES_PERC),

  [TD_AT_QES]      =  ACTION_TAP_DANCE_DOUBLE(ES_AT,   ES_QUES),
  [TD_AT_EXLM]     =  ACTION_TAP_DANCE_DOUBLE(ES_AT,   ES_EXLM),

};