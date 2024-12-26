#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define LED_COUNT 10
const uint ledPins[LED_COUNT] = {16, 17, 18, 19, 20, 21, 22, 26, 27, 28};

const int dutys[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4095, 2047, 1023, 512, 256, 128, 64, 32, 16, 8,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

int delayTimes = 50;

void setup_pwm(uint pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM); // set pin to pwm function
    uint slice_num = pwm_gpio_to_slice_num(pin); // pwm slice
    pwm_set_wrap(slice_num, 4095); // set pwm wrap value (12-bit resolution)
    pwm_set_enabled(slice_num, true); // enable pwm slice
}

void set_pwm_duty(uint pin, uint16_t duty) {
    uint slice_num = pwm_gpio_to_slice_num(pin);
    uint channel = pwm_gpio_to_channel(pin);
    pwm_set_chan_level(slice_num, channel, duty);
}

int main() {
    // initialize the gpios and pwm for each led
    for (int i = 0; i < LED_COUNT; i++) {
        setup_pwm(ledPins[i]);
    }

    while (true) {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < LED_COUNT; j++) {
                int duty_index = i + j;
                if (duty_index < sizeof(dutys) / sizeof(dutys[0])) {
                    set_pwm_duty(ledPins[j], dutys[duty_index]);
                } else {
                    set_pwm_duty(ledPins[j], 0);
                }
            }
            sleep_ms(delayTimes);
        }

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < LED_COUNT; j++) {
                int duty_index = i + j;
                if (duty_index < sizeof(dutys) / sizeof(dutys[0])) {
                    set_pwm_duty(ledPins[LED_COUNT - j - 1], dutys[duty_index]);
                } else {
                    set_pwm_duty(ledPins[LED_COUNT - j - 1], 0);
                }
            }
            sleep_ms(delayTimes);
        }
    }

    return 0;
}
