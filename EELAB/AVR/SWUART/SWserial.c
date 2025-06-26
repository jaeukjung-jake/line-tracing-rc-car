#include "SWserial.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <mystdio.h>
#include <myArduino.h>

#define F_CPU 16000000UL
#define BAUD_RATE 9600
#define BIT_TIME_US (1000000 / BAUD_RATE)
#define ONEHALFTIME 156
#define ONEBITTIME 104
#define BUFSIZE 128
#define RX_Pin 2
#define TX_pin 3
#define TX_PORT PORTD       // 포트 D
#define TX_DDR DDRD         // 포트 방향 레지스터



static char SWU_buffer[BUFSIZE];
static char *bufstart, *bufend;


// Circular buffer initialization
void InitBuffer(void) {
    bufstart = bufend = SWU_buffer;
}


// External Interrupt Service Routine
ISR(INT0_vect)
{
    uint8_t data = 0;
    DISABLE_EXT0_INTERRUPT();
    _delay_us(ONEHALFTIME);

    for (uint8_t i = 0; i < 8; i++) {
        PORTD ^= (1<<4);
        if (PIND & (1<<RX_Pin))
            data |= (1 << i);
        _delay_us(ONEBITTIME);
    }

    *bufend++ = data; 

    if (bufend == SWU_buffer + BUFSIZE)
        bufend = SWU_buffer;
    // myprintf("Received Data is %c \n", data);
    CLEAR_EXT0_INTERRUPT();
    ENABLE_EXT0_INTERRUPT();
}

// Function to initialize the software UART.
void SWU_init(void)
{
    // RX (PD2) 입력 + 풀업
    DDRD &= ~(1 << RX_Pin);
    PORTD |= (1 << RX_Pin);

    // TX (PD3) 출력
    DDRD |= (1 << TX_pin);
    PORTD |= (1 << TX_pin);

    // PD4 디버깅용 출력    
    DDRD |= (1 << 4);
    PORTD |= (1 << 4);

    // INT0: falling edge
    EICRA |= (1 << ISC01);
    EICRA &= ~(1 << ISC00);

    CLEAR_EXT0_INTERRUPT();       // 플래그 초기화
    ENABLE_EXT0_INTERRUPT();      // 인터럽트 허용

    InitBuffer();                 // 버퍼 초기화
}

// Check the received buffer and return unread data size
unsigned char SWU_available(void) {
    return ((BUFSIZE + bufend - bufstart) % BUFSIZE);
}

// Only read when data in buffer is available
unsigned char SWU_getchar(void) {
    unsigned char rxd = *bufstart++;  
    if (bufstart == SWU_buffer + BUFSIZE)
        bufstart = SWU_buffer;

    return rxd;
}

void SWU_putchar(const unsigned char data){
    PORTD &= ~(1 << TX_pin);
    _delay_us(ONEBITTIME);

    // 8 data bits
    for (uint8_t i = 0; i < 8; i++) {
        if (data & (1 << i))
            PORTD |= (1 << TX_pin);
        else
            PORTD &= ~(1 << TX_pin);
        _delay_us(ONEBITTIME);
    }

    // Stop bit
    PORTD |= (1 << TX_pin);
    _delay_us(ONEBITTIME);
}

void SWU_putstring(const unsigned char *data) {
    while (*data) {
        SWU_putchar(*data++);
    }
}

