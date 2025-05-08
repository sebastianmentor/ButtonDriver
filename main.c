#include <avr/io.h>
#include <util/delay.h>
#include "drive/blink.h"

int main(void) {
    int8_t PIN_NUMBER = 0;
    int8_t PORT;
    int8_t BIT;

    if (PIN_NUMBER == 0){
        DDRD |= (1 <<DDD0);
        PORT = PORTD;
        BIT = PD0;
    }
    else if (PIN_NUMBER == 1)
    {        
        DDRD |= (1 <<DDD1);
    }
    else if (PIN_NUMBER == 2)
    {        
        DDRD |= (1 <<DDD2);
    }
    else if (PIN_NUMBER == 3)
    {        
        DDRD |= (1 <<DDD3);
    }
    else if (PIN_NUMBER == 4)
    {        
        DDRD |= (1 <<DDD4);
    }
    else if (PIN_NUMBER == 5)
    {        
        DDRD |= (1 <<DDD5);
    }
    else if (PIN_NUMBER == 6)
    {        
        DDRD |= (1 <<DDD6);
    }
    else if (PIN_NUMBER == 7)
    {        
        DDRD |= (1 <<DDD7);
    }
    else if (PIN_NUMBER == 8)
    {        
        DDRB |= (1 <<DDB0);
    }
    else if (PIN_NUMBER == 9)
    {        
        DDRB |= (1 <<DDB1);
    }
    else if (PIN_NUMBER == 10)
    {        
        DDRB |= (1 <<DDB2);
    }
    else if (PIN_NUMBER == 11)
    {        
        DDRB |= (1 <<DDB3);
    }
    else if (PIN_NUMBER == 12)
    {        
        DDRB |= (1 <<DDB4);
    }
    else if (PIN_NUMBER == 13)
    {        
        DDRB |= (1 <<DDB5);
    }

    // blink_init(10, 20); // Pinne 10 ska bli aktiverad som output,
    // blink_start();
    while (1) {
        _delay_ms(100);
    }
}
