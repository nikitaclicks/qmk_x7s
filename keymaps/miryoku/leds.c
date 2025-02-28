
/*Remember to also change the color in keyboard_post_init_kb in boston.c to make the startup color match the layer 0 color */
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_WHITE} 
                // {0, 2, 0,0, 75 }

);

const rgblight_segment_t PROGMEM layer_nav[] = RGBLIGHT_LAYER_SEGMENTS(
            {0, 2, HSV_TEAL} 
            // {0, 2, 180, 87, 75 }
            

);

const rgblight_segment_t PROGMEM layer_mouse[] = RGBLIGHT_LAYER_SEGMENTS(
             {0, 2, HSV_YELLOW} /*Yellow*/
                        // {0, 2, 60, 87, 75 }

   
);

const rgblight_segment_t PROGMEM layer_media[] = RGBLIGHT_LAYER_SEGMENTS(
     {0, 2, HSV_MAGENTA} /*Yellow*/
                        // {0, 2, 300, 89, 75 }

);

const rgblight_segment_t PROGMEM layer_num[] = RGBLIGHT_LAYER_SEGMENTS(
            {0, 2, HSV_BLUE} /*Yellow*/
                        // {0, 2, 240, 77, 75 }


);

const rgblight_segment_t PROGMEM layer_sym[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 2, HSV_GREEN} /*Yellow*/
                    // {0, 2, 120, 85, 75 }


);

const rgblight_segment_t PROGMEM layer_fun[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 2, HSV_RED} /*Yellow*/
                    // {0, 2, 0, 84, 75 }

);

const rgblight_segment_t PROGMEM layer_white[] = RGBLIGHT_LAYER_SEGMENTS(
                {0, 2, HSV_WHITE} /*Yellow*/
                            // {0, 2,0,0, 75 }


);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    capslock_layer,
    layer_white,
    layer_white,
    layer_nav,
    layer_mouse,
    layer_media,
    layer_num,
    layer_sym,
    layer_fun
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    rgblight_set_layer_state(5, layer_state_cmp(state, 5));
    rgblight_set_layer_state(6, layer_state_cmp(state, 6));
    rgblight_set_layer_state(7, layer_state_cmp(state, 7));
    rgblight_set_layer_state(8, layer_state_cmp(state, 8));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    return state;
}