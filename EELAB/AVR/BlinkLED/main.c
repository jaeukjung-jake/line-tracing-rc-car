#include <avr/io.h>
#include <util/delay.h>

int main() {
    DDRB = 0x20;  // PB5를 출력으로 설정

    while (1) {
        PORTB = 0x20;  // LED ON
        _delay_ms(500);
        PORTB = 0x00;  // LED OFF
        _delay_ms(500);
    }
}
