#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define RED_PIN 13
#define GREEN_PIN 12
#define BLUE_PIN 11
#define LED_DELAY_MS 200

void set_color(uint8_t r, uint8_t g, uint8_t b) {
    pwm_set_gpio_level(RED_PIN, 255 - r);
    pwm_set_gpio_level(GREEN_PIN, 255 - g);
    pwm_set_gpio_level(BLUE_PIN, 255 - b);
}

void init_pwm(uint pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_set_wrap(slice_num, 255);
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(pin), 0);
    pwm_set_enabled(slice_num, true);
}

int main() {
    stdio_init_all();
    srand(time(NULL));

    init_pwm(RED_PIN);
    init_pwm(GREEN_PIN);
    init_pwm(BLUE_PIN);

    while (true) {
        uint8_t red = rand() % 256;
        uint8_t green = rand() % 256;
        uint8_t blue = rand() % 256;

        set_color(red, green, blue);
        sleep_ms(LED_DELAY_MS);
    }
}
