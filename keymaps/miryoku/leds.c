
// const rgblight_segment_t PROGMEM layer0_colors[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 2, 85, 255, 75}
// );
// const rgblight_segment_t PROGMEM layer1_colors[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 2, 170, 255, 75}
// );
// const rgblight_segment_t PROGMEM layer2_colors[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 2, 55, 255, 75}
// );
// const rgblight_segment_t PROGMEM layer3_colors[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 2, 191, 255, 75}
// );
// const rgblight_segment_t PROGMEM layer4_colors[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 2, 30, 218, 75}
// );
// const rgblight_segment_t PROGMEM layer5_colors[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 2, 11, 176, 75}
// );
// const rgblight_segment_t PROGMEM layer6_colors[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 2, 106, 255, 75}
// );


/*Remember to also change the color in keyboard_post_init_kb in boston.c to make the startup color match the layer 0 color */
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_WHITE} 
                // {0, 2, 0,0, 75 }

);

const rgblight_segment_t PROGMEM layer_1[] = RGBLIGHT_LAYER_SEGMENTS(
            {0, 2, HSV_TEAL} 
            // {0, 2, 180, 87, 75 }
            

);

const rgblight_segment_t PROGMEM layer_2[] = RGBLIGHT_LAYER_SEGMENTS(
             {0, 2, HSV_YELLOW} /*Yellow*/
                        // {0, 2, 60, 87, 75 }

   
);

const rgblight_segment_t PROGMEM layer_3[] = RGBLIGHT_LAYER_SEGMENTS(
     {0, 2, HSV_MAGENTA} /*Yellow*/
                        // {0, 2, 300, 89, 75 }

);

const rgblight_segment_t PROGMEM layer_4[] = RGBLIGHT_LAYER_SEGMENTS(
            {0, 2, HSV_BLUE} /*Yellow*/
                        // {0, 2, 240, 77, 75 }


);

const rgblight_segment_t PROGMEM layer_5[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 2, HSV_GREEN} /*Yellow*/
                    // {0, 2, 120, 85, 75 }


);

const rgblight_segment_t PROGMEM layer_6[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 2, HSV_RED} /*Yellow*/
                    // {0, 2, 0, 84, 75 }

);

const rgblight_segment_t PROGMEM layer_7[] = RGBLIGHT_LAYER_SEGMENTS(
                {0, 2, HSV_WHITE} /*Yellow*/
                            // {0, 2,0,0, 75 }


);

const rgblight_segment_t PROGMEM layer_8[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_WHITE} /*Yellow*/
                // {0, 2, 0,0, 75 }

);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    capslock_layer,
    layer_1,
    layer_2,
    layer_3,
    layer_4,
    layer_5,
    layer_6,
    layer_7,
    layer_8
    // layer0_colors,
    // layer1_colors,
    // layer2_colors,
    // layer3_colors,
    // layer4_colors,
    // layer5_colors,
    // layer6_colors,
    // layer_7,
    // layer_8
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    // rgblight_set_layer_state(0, layer_state_cmp(state, 0));
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