#include "RingBuffer.h"
#include "SoftwareSerial.h"

#define ENABLE_EXT0_INTERRUPT()     ( EIMSK |=  ( 1<< INT0 ) )
#define DISABLE_EXT0_INTERRUPT()    ( EIMSK &= ~( 1<< INT0 ) )
#define CLEAR_EXT0_INTERRUPT()      ( EIFR  |= (1<< INTF0) )

#define ONEHALFTIME   156
#define ONEBITTIME    104

#define SET_TX_PIN()    ( PORTD |= (1<< txPin) )
#define CLR_TX_PIN()    ( PORTD &= ~(1<< txPin) )

SoftwareSerial *SoftwareSerial::active_object = 0 ;

SoftwareSerial::SoftwareSerial(uint8_t rx, uint8_t tx) : rxPin(rx), txPin(tx){
    pinMode(rxPin, INPUT_PULLUP);
    pinMode(txPin, OUTPUT);
    digitalWrite(txPin, HIGH);
}

void SoftwareSerial::begin(uint16_t baud){
    cli();
    EICRA |=  (1 << ISC01);
    EIFR  |= (1 << INTF0);
    EIMSK |= (1 << INT0);
    sei();
    active_object = this;
}

void SoftwareSerial::putchar(char ch){
    if ( ch == '\r' )
        putchar('\n');
    DISABLE_EXT0_INTERRUPT();

    CLR_TX_PIN();
    _delay_us(ONEBITTIME);

    for (uint8_t i = 0; i < 8; i++) {
        if (ch & (1 << i))
            SET_TX_PIN();
        else
            CLR_TX_PIN();
        _delay_us(ONEBITTIME);
    }

    SET_TX_PIN();
    _delay_us(ONEBITTIME);

    CLEAR_EXT0_INTERRUPT();
    ENABLE_EXT0_INTERRUPT();
}

ISR(INT0_vect)
{
    uint8_t data = 0;

    DISABLE_EXT0_INTERRUPT();
    _delay_us(ONEHALFTIME);

    for (uint8_t i = 0; i < 8; i++) {
        data >>= 1;
        if (PIND & 1 << 2)
            data |= 0x80;
        _delay_us(ONEBITTIME);
    }

    if (SoftwareSerial::active_object){
        SoftwareSerial::active_object->ringBuffer.put(data);
    }

    CLEAR_EXT0_INTERRUPT();
    ENABLE_EXT0_INTERRUPT();
}
