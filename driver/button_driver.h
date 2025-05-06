#ifndef BUTTON_DRIVER_H
#define BUTTON_DRIVER_H

#include <stdint.h>
#include <avr/io.h>

typedef struct {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    volatile uint8_t *pin;
    uint8_t bit;
    uint8_t last_state;
    uint32_t last_debounce_time;
} Button;

Button button_create(uint8_t arduino_pin);
void button_init(Button *btn);
uint8_t button_read(Button *btn, uint32_t debounce_delay_ms);

#endif
