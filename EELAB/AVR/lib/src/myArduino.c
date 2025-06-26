// #include "myArduino.h"
// #include <stdint.h> 
// #include <stddef.h> 
// #include <avr/io.h>

// #define INPUT 0
// #define OUTPUT 1
// #define INPUT_PULLUP 2

// typedef struct _arduinopin { 
//     uint16_t DDRaddr ; 
//     uint16_t PORTaddr; 
//     uint16_t PINaddr ; 
//     uint8_t BITmask ;
// } ARDUINOPIN ;

#include <myArduino.h>
#include <avr/io.h>
#include <util/delay.h>



typedef struct _arduinopin {
    uint16_t DDRaddr ;
    uint16_t PORTaddr;
    uint16_t PINaddr ;
    uint8_t BITmask ;
} ARDUINOPIN ;

const ARDUINOPIN ArdPin[] ={
    { (uint16_t)&DDRD, (uint16_t)&PORTD, (uint16_t)&PIND, (1<<0)}, // Arduino Pin #0    
    { (uint16_t)&DDRD, (uint16_t)&PORTD, (uint16_t)&PIND, (1<<1)}, // Arduino Pin #1
    { (uint16_t)&DDRD, (uint16_t)&PORTD, (uint16_t)&PIND, (1<<2)}, // Arduino Pin #2
    { (uint16_t)&DDRD, (uint16_t)&PORTD, (uint16_t)&PIND, (1<<3)}, // Arduino Pin #3
    { (uint16_t)&DDRD, (uint16_t)&PORTD, (uint16_t)&PIND, (1<<4)}, // Arduino Pin #4
    { (uint16_t)&DDRD, (uint16_t)&PORTD, (uint16_t)&PIND, (1<<5)}, // Arduino Pin #5
    { (uint16_t)&DDRD, (uint16_t)&PORTD, (uint16_t)&PIND, (1<<6)}, // Arduino Pin #6
    { (uint16_t)&DDRD, (uint16_t)&PORTD, (uint16_t)&PIND, (1<<7)}, // Arduino Pin #7
    { (uint16_t)&DDRB, (uint16_t)&PORTB, (uint16_t)&PINB, (1<<0)}, // Arduino Pin #8
    { (uint16_t)&DDRB, (uint16_t)&PORTB, (uint16_t)&PINB, (1<<1)}, // Arduino Pin #9
    { (uint16_t)&DDRB, (uint16_t)&PORTB, (uint16_t)&PINB, (1<<2)}, // Arduino Pin #10
    { (uint16_t)&DDRB, (uint16_t)&PORTB, (uint16_t)&PINB, (1<<3)}, // Arduino Pin #11
    { (uint16_t)&DDRB, (uint16_t)&PORTB, (uint16_t)&PINB, (1<<4)}, // Arduino Pin #12
    { (uint16_t)&DDRB, (uint16_t)&PORTB, (uint16_t)&PINB, (1<<5)}, // Arduino Pin #13
    { (uint16_t)&DDRC, (uint16_t)&PORTC, (uint16_t)&PINC, (1<<0)}, // A0 = PC0 = Arduino Pin #14
    { (uint16_t)&DDRC, (uint16_t)&PORTC, (uint16_t)&PINC, (1<<1)}, // A1
    { (uint16_t)&DDRC, (uint16_t)&PORTC, (uint16_t)&PINC, (1<<2)}, // A2
    { (uint16_t)&DDRC, (uint16_t)&PORTC, (uint16_t)&PINC, (1<<3)}, // A3
    { (uint16_t)&DDRC, (uint16_t)&PORTC, (uint16_t)&PINC, (1<<4)}, // A4
    { (uint16_t)&DDRC, (uint16_t)&PORTC, (uint16_t)&PINC, (1<<5)}  // A5
};
void pinMode(uint8_t pin, uint8_t mode)
{
    uint8_t bitmask = ArdPin[pin].BITmask;
    volatile uint8_t *dreg = (uint8_t *)ArdPin[pin].DDRaddr ;
    volatile uint8_t *preg = (uint8_t *)ArdPin[pin].PORTaddr ;
    if ( mode == OUTPUT) 
        *dreg |= bitmask ;
    else{
        *dreg &= ~bitmask ;
        if(mode == INPUT_PULLUP)
            *preg |= bitmask ;
    }
}
void digitalWrite(uint8_t pin, uint8_t val)
{
    uint8_t bitmask = ArdPin[pin].BITmask;
    volatile uint8_t *out = (uint8_t *)ArdPin[pin].PORTaddr ;
    if (val == LOW) {
        *out &= ~bitmask;
    } else {
        *out |= bitmask;
    }
}
int digitalRead(uint8_t pin)
{
    uint8_t bitmask = ArdPin[pin].BITmask;
    volatile uint8_t *reg = (uint8_t *)ArdPin[pin].PINaddr ;
    if (*reg & bitmask) return HIGH ;
    return LOW;
}

void delay_ms(uint16_t ms) {
    while (ms) {
        _delay_ms(1);  // _delay_ms는 최대 약 262ms까지 정확
    }
}