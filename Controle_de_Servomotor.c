#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include <stdio.h>

#define SERVO_PIN 22
#define PWM_FREQUENCY 50  // 50Hz (Período de 20ms)
#define CLOCK_DIVIDER 100  // Ajuste do divisor de clock
#define PWM_WRAP_VALUE 24999  // Para um período de 20ms

#define LED_RED 13
#define LED_GREEN 11
#define LED_BLUE 12

// Converte o tempo de pulso (em µs) para nível PWM
uint32_t calcular_pwm_duty(uint32_t microssegundos) {
    return (uint32_t)(microssegundos * 1.25f); // 1µs ≈ 1.25 unidades
}

// Inicializa o PWM no pino do servo
void configurar_pwm_servo() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(SERVO_PIN);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, CLOCK_DIVIDER);
    pwm_config_set_wrap(&config, PWM_WRAP_VALUE);
    pwm_init(slice, &config, true);
}

// Inicializa os LEDs RGB
void configurar_leds() {
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
}

// Alterna cores do LED RGB
void alternar_cor_led(int estado) {
    gpio_put(LED_RED, estado == 0);
    gpio_put(LED_GREEN, estado == 1);
    gpio_put(LED_BLUE, estado == 2);
}

int main() {
    stdio_init_all();
    configurar_pwm_servo();
    configurar_leds();
    uint slice = pwm_gpio_to_slice_num(SERVO_PIN);
    int estado_led = 0;

    // Ajusta servo para 180 graus (2400µs)
    pwm_set_gpio_level(SERVO_PIN, calcular_pwm_duty(2400));
    alternar_cor_led(estado_led++ % 3);
    sleep_ms(5000);

    // Ajusta servo para 90 graus (1470µs)
    pwm_set_gpio_level(SERVO_PIN, calcular_pwm_duty(1470));
    alternar_cor_led(estado_led++ % 3);
    sleep_ms(5000);

    // Ajusta servo para 0 graus (500µs)
    pwm_set_gpio_level(SERVO_PIN, calcular_pwm_duty(500));
    alternar_cor_led(estado_led++ % 3);
    sleep_ms(5000);

    // Movimento suave entre 0° e 180°
    while (1) {
        for (uint32_t pos = 500; pos <= 2400; pos += 5) {
            pwm_set_gpio_level(SERVO_PIN, calcular_pwm_duty(pos));
            sleep_ms(10);
        }
        alternar_cor_led(estado_led++ % 3);
        sleep_ms(100);

        for (uint32_t pos = 2400; pos >= 500; pos -= 5) {
            pwm_set_gpio_level(SERVO_PIN, calcular_pwm_duty(pos));
            sleep_ms(10);
        }
        alternar_cor_led(estado_led++ % 3);
        sleep_ms(100);
    }
}