#include "myArduino.h"
#include <util/delay.h>

#define TX_PIN 3
#define BIT_DELAY 101.6

void Serial_Tx(uint8_t data)
{
    // 1. Start Bit: 0
    PORTD &= ~(1 << TX_PIN);     // LOW
    _delay_us(BIT_DELAY);

    // 2. 8비트 데이터 전송 (LSB부터)
    for (uint8_t i = 0; i < 8; i++) {
        if (data & (1 << i)) {
            PORTD |= (1 << TX_PIN);   // HIGH
        } else {
            PORTD &= ~(1 << TX_PIN);  // LOW
        }
        _delay_us(BIT_DELAY);
    }

    // 3. Stop Bit: 1
    PORTD |= (1 << TX_PIN);      // HIGH
    _delay_us(BIT_DELAY);
}

int main(void)
{
    uint8_t ch = 0x45 ;
    pinMode(3, OUTPUT);
    DDRD |= (1 << PD3);   //D3 핀을 출력으로 설정

    while(1){
        Serial_Tx(ch);
        _delay_ms(10);
    }
    return 0 ;
}