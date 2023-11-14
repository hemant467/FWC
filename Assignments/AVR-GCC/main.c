#include <avr/io.h>

int main(void) {
    DDRB = 0b11110001;

    while (1) {
        uint8_t r17, r18, r19;

        r17 = PINB;
        r18 = PINB;
        r19 = PINB;

        r17 <<= 3;
        r17 |= r17;
        r17 = ~r17;

        r18 <<= 2;
        r17 ^= r18;
        r17 = ~r17;

        PORTB = r17;
    }

    return 0;
}
