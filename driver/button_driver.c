#include "button_driver.h"
#include "millis.h"

Button button_create(uint8_t arduino_pin) {
    Button btn = {0};

    if (arduino_pin <= 7) {
        // Digital 0–7 = Port D
        btn.ddr = &DDRD;
        btn.port = &PORTD;
        btn.pin = &PIND;
        btn.bit = arduino_pin;
    } else if (arduino_pin >= 8 && arduino_pin <= 13) {
        // Digital 8–13 = Port B
        btn.ddr = &DDRB;
        btn.port = &PORTB;
        btn.pin = &PINB;
        btn.bit = arduino_pin - 8;
    } else {
        // Ogiltig pin – gör ingenting
        btn.ddr = 0;
        btn.port = 0;
        btn.pin = 0;
        btn.bit = 0;
    }

    return btn;
}

void button_init(Button *btn) {
    if (btn->ddr && btn->port) {
        *(btn->ddr) &= ~(1 << btn->bit);     // ingång
        *(btn->port) |= (1 << btn->bit);     // pull-up
        btn->last_state = 0;
        btn->last_debounce_time = 0;
    }
}

uint8_t button_read(Button *btn, uint32_t debounce_delay_ms) {
    if (!(btn->pin)) return 0;

    uint8_t reading = !((*(btn->pin)) & (1 << btn->bit));
    uint32_t now = millis();

    if (reading != btn->last_state) {
        btn->last_debounce_time = now;
    }

    if ((now - btn->last_debounce_time) > debounce_delay_ms) {
        btn->last_state = reading;
        return reading;
    }

    return btn->last_state;
}
