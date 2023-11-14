#include <avr/io.h>
#include <util/delay.h>

//Declaring all variables as integers
int  D1, D2, CLK;
int Q1 = 0, Q2 = 0;

//Creating a function
void ref( int D1, int D2, int CLK) {
    if (D1)
        PORTD |= (1 << PD2);
    else
        PORTD &= ~(1 << PD2);
    
    if (D2)
        PORTD |= (1 << PD3);
    else
        PORTD &= ~(1 << PD3);
    
    if (CLK)
        PORTB |= (1 << PB3);
    else
        PORTB &= ~(1 << PB3);
}

int main(void) {
    //Setting DDR registers for required pins
    DDRD |= (1 << PD2) | (1 << PD3);
    DDRB |= (1 << PB3);
    
    //Setting input pins
    DDRD &= ~((1 << PD6) | (1 << PD7));
    
    //the loop function runs over and over again
    while (1) {
        PORTB |= (1 << PB3);
        _delay_ms(1000);
        
        Q1 = (PIND >> PD6) & 0x01;
        Q2 = (PIND >> PD7) & 0x01;
        
        D2 = Q1; //D2=Q1
        D1 = Q2 || Q1; //D1=Q2+Q1
        
        PORTB &= ~(1 << PB3);
        ref(D1, D2, CLK);
    }
}
