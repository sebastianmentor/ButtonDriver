#include <avr/io.h>
#include <util/delay.h>
#include "driver/button_driver.h"
#include "driver/millis.h"

int main(void) {
    DDRB |= (1 << DDB5);  // LED på pin 13 (PORTB5) 00000001 << 5 --> b00100000
    millis_init();

    Button btn = button_create(2); // Använd pin 2
    button_init(&btn);

    uint8_t last = 0;

    while (1) {
        uint8_t current = button_read(&btn, 50);

        if (current && !last) {
            PORTB ^= (1 << PORTB5);
        }

        last = current;
        _delay_ms(500);
        PORTB ^= (1 << PORTB5);
    }
}
