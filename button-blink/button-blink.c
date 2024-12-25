#include <stdio.h>
#include "pico/stdlib.h"

#define PIN_LED    15
#define PIN_BUTTON 13

int main() {
    stdio_init_all();

    gpio_init(PIN_LED);
    gpio_set_dir(PIN_LED, GPIO_OUT);

    gpio_init(PIN_BUTTON);
    gpio_set_dir(PIN_BUTTON, GPIO_IN);
    gpio_pull_up(PIN_BUTTON);

    while (true) {
        // read the button state (low if pressed due to pull-up)
        bool button_state = gpio_get(PIN_BUTTON) == 0;

        // control the led based on the button state
        gpio_put(PIN_LED, button_state);

        // small delay to debounce the button
        sleep_ms(10);
    }
}
