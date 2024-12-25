#include <stdio.h>
#include "pico/stdlib.h"

#define PIN_LED    15
#define PIN_BUTTON 13

void toggle_led(bool *led_state) {
    *led_state = !*led_state;
    gpio_put(PIN_LED, *led_state);
}

int main() {
    stdio_init_all();

    gpio_init(PIN_LED);
    gpio_set_dir(PIN_LED, GPIO_OUT);

    gpio_init(PIN_BUTTON);
    gpio_set_dir(PIN_BUTTON, GPIO_IN);
    gpio_pull_up(PIN_BUTTON);

    bool led_state = false;

    while (true) {
        // check if the button is pressed
        if (gpio_get(PIN_BUTTON) == 0) {
            sleep_ms(20);  // debounce delay
            if (gpio_get(PIN_BUTTON) == 0) {  // verify the button is still pressed
                toggle_led(&led_state);

                while (gpio_get(PIN_BUTTON) == 0) {
                    sleep_ms(10);
                }
            }
        }

        // small delay for loop timing
        sleep_ms(10);
    }
}
