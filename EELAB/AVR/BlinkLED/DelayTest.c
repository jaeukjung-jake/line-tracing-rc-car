#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000UL

int main(void)
{
    DDRC |= (1 << PC0);  // PORTC.0 출력 설정

    while (1) {
        PORTC ^= (1 << PC0);  // 토글
        _delay_ms(500);       // 0.5초마다 토글
    }
}
