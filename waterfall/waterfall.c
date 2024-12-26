#include "pico/stdlib.h"

#define LED_COUNT 10 // Define the number of LEDs
const uint ledPins[LED_COUNT] = {16, 17, 18, 19, 20, 21, 22, 26, 27, 28};

int main() {
    for (int i = 0; i < LED_COUNT; i++) {
        gpio_init(ledPins[i]); // init gpio
        gpio_set_dir(ledPins[i], GPIO_OUT); // set gpio as output
    }

    while (true) {
        // bottom to top
        for (int i = 0; i < LED_COUNT; i++) {
            gpio_put(ledPins[i], 1); // turn on the led
            sleep_ms(100);          // delay 100ms
            gpio_put(ledPins[i], 0); // turn off
        }

        // top to bottom
        for (int i = LED_COUNT - 1; i >= 0; i--) {
            gpio_put(ledPins[i], 1);
            sleep_ms(100);
            gpio_put(ledPins[i], 0);
        }
    }

    return 0; // (shouldnt reach this)
}
