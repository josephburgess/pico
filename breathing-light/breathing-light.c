#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PIN_LED 15

void set_pwm_duty_cycle(uint slice_num, uint channel, uint16_t duty) {
    pwm_set_gpio_level(PIN_LED, duty); // set the duty cycle (0-65535)
}

int main() {
    // initialize the selected pin for pwm
    gpio_set_function(PIN_LED, GPIO_FUNC_PWM);

    // find the pwm slice for the specified gpio
    uint slice_num = pwm_gpio_to_slice_num(PIN_LED);

    // get the pwm channel for the gpio
    uint channel = pwm_gpio_to_channel(PIN_LED);

    pwm_set_wrap(slice_num, 255);  // set the period to 256 (0-255 for an 8-bit resolution)
    pwm_set_chan_level(slice_num, channel, 0); // set initial duty cycle to 0

    pwm_set_enabled(slice_num, true);

    while (true) {
        // breahte in
        for (uint16_t i = 0; i <= 255; i++) {
            set_pwm_duty_cycle(slice_num, channel, i);
            sleep_ms(5); // delay to make the fading visible
        }

        // breathe out
        for (uint16_t i = 255; i > 0; i--) {
            set_pwm_duty_cycle(slice_num, channel, i);
            sleep_ms(5);
        }
    }

    return 0;
}
