#include <avr/io.h>
#include <util/delay.h>

int main(void){
    DDRB |= (1 <<DDB3);
    DDRB &= ~(1 << DDB4);
    PORTB |= (1 << PB4);

    while (1) {
        //핀12번의 입력 값 읽기
        if (bit_is_clear(PINB, PB4)) {
        // 스위치가 눌린 경우 (LOW), LED 켜기 (HIGH)
                    PORTB |= (1 << PB3);
                } else {
        // 스위치가 눌리지 않은 경우 (HIGH), LED 끄기 (LOW)
                    PORTB &= ~(1 << PB3);
                }
                _delay_ms(100);
            }
        return 0; 
}