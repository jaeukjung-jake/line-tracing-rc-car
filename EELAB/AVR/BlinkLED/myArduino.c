#include "myArduino.h"
#include <stdint.h> 
#include <stddef.h> 
#include <avr/io.h>


typedef struct _arduinopin { 
    uint16_t DDRaddr ; 
    uint16_t PORTaddr; 
    uint16_t PINaddr ; 
    uint8_t BITmask ;
} ARDUINOPIN ;

ARDUINOPIN ArdPin[14];  // const 제거! 초기화는 나중에

void init_ArdPin() {
    ArdPin[0]  = (ARDUINOPIN){ (uint16_t)&DDRD, (uint16_t)&PORTD, (uint16_t)&PIND,  (1<<0) }; // Arduino Pin 0
    ArdPin[1]  = (ARDUINOPIN){ (uint16_t)&DDRD, (uint16_t)&PORTD, (uint16_t)&PIND,  (1<<1) }; // Arduino Pin 1
    ArdPin[2]  = (ARDUINOPIN){ (uint16_t)&DDRD, (uint16_t)&PORTD, (uint16_t)&PIND,  (1<<2) }; // Arduino Pin 2
    ArdPin[3]  = (ARDUINOPIN){ (uint16_t)&DDRD, (uint16_t)&PORTD, (uint16_t)&PIND,  (1<<3) }; // Arduino Pin 3
    ArdPin[4]  = (ARDUINOPIN){ (uint16_t)&DDRD, (uint16_t)&PORTD, (uint16_t)&PIND,  (1<<4) }; // Arduino Pin 4
    ArdPin[5]  = (ARDUINOPIN){ (uint16_t)&DDRD, (uint16_t)&PORTD, (uint16_t)&PIND,  (1<<5) }; // Arduino Pin 5
    ArdPin[6]  = (ARDUINOPIN){ (uint16_t)&DDRD, (uint16_t)&PORTD, (uint16_t)&PIND,  (1<<6) }; // Arduino Pin 6
    ArdPin[7]  = (ARDUINOPIN){ (uint16_t)&DDRD, (uint16_t)&PORTD, (uint16_t)&PIND,  (1<<7) }; // Arduino Pin 7
    ArdPin[8]  = (ARDUINOPIN){ (uint16_t)&DDRB, (uint16_t)&PORTB, (uint16_t)&PINB,  (1<<0) }; // Arduino Pin 8
    ArdPin[9]  = (ARDUINOPIN){ (uint16_t)&DDRB, (uint16_t)&PORTB, (uint16_t)&PINB,  (1<<1) }; // Arduino Pin 9
    ArdPin[10] = (ARDUINOPIN){ (uint16_t)&DDRB, (uint16_t)&PORTB, (uint16_t)&PINB,  (1<<2) }; // Arduino Pin 10
    ArdPin[11] = (ARDUINOPIN){ (uint16_t)&DDRB, (uint16_t)&PORTB, (uint16_t)&PINB,  (1<<3) }; // Arduino Pin 11
    ArdPin[12] = (ARDUINOPIN){ (uint16_t)&DDRB, (uint16_t)&PORTB, (uint16_t)&PINB,  (1<<4) }; // Arduino Pin 12
    ArdPin[13] = (ARDUINOPIN){ (uint16_t)&DDRB, (uint16_t)&PORTB, (uint16_t)&PINB,  (1<<5) }; // Arduino Pin 13
}


void pinMode(uint8_t pin, uint8_t mode)
{
    uint8_t bitmask = ArdPin[pin].BITmask;
    volatile uint8_t *reg = (uint8_t *)ArdPin[pin].DDRaddr ;
    if ( mode == INPUT) *reg &= ~bitmask ;
    else *reg |= bitmask ; 
}
    
void digitalWrite(uint8_t pin, uint8_t val)
{
    uint8_t bitmask = ArdPin[pin].BITmask;
    volatile uint8_t *out = (uint8_t *)ArdPin[pin].PORTaddr ;
    if (val == LOW) { *out &= ~bitmask;
    } else {
        *out |= bitmask; }
}

int digitalRead(uint8_t pin)
{
    uint8_t bitmask = ArdPin[pin].BITmask;
    volatile uint8_t *reg = (uint8_t *)ArdPin[pin].PINaddr ;
    if (*reg & bitmask) return HIGH ;
    return LOW; 
}