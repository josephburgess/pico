#include <stdio.h>
#include "pico/stdlib.h"

#define LED_PIN 15
#define LED_DELAY_MS 1000

int main()
{
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        gpio_put(LED_PIN, true);
        sleep_ms(LED_DELAY_MS);
        gpio_put(LED_PIN, false);
        sleep_ms(LED_DELAY_MS);
    }
}
