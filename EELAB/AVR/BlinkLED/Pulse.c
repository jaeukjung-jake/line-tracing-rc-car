#define F_CPU 16000000UL
#define BAUDRATE 9600
#define BIT_DELAY F_CPU/BAUDRATE/16

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRC |= (1<<0);
    PORTC |= 0x01 ;

    while (1)
    {
        PORTC ^= 0x01;
        _delay_us(BIT_DELAY);
    }
}