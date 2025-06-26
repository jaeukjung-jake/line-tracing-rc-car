#include "UART.h"
#include <stdint.h>
#include <avr/io.h>
#include <stdio.h>

void UART_init(unsigned int baud)
{
    unsigned int ubrr = (16000000/baud/16)-1;

    UBRR0H = (uint8_t)(ubrr >>8);
    UBRR0L = (uint8_t)(ubrr & 0xFF);

    //송수신 기능 설정
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);

    //비동기, 패리티 없음, 8bit data, 1bit stop bit
    UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);

}

//UART를 통해 1 바이트 데이터 전송 함수 
void UART_putchar(unsigned char data){
    //송신 버퍼가 비어있을 때까지 대기
    while(!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
    //출력 데이터가 개행문자이면 \r 추가하여 보냄
    if (data == '\n')
        UART_putchar('\r');
}

//UART를 통해 1 바이트 데이터 수신 함수
unsigned char UART_getchar(void){
    //수신 버퍼에 데이터가 다 찰때까지 대기
    while(!(UCSR0A & (1 << RXC0)));

    return(UDR0);
}


//echo확인하기 위해 만든 추가 함수 
unsigned char UART_getchar_with_echo(void) {
    unsigned char ch = UART_getchar();
    UART_putchar(ch);    // Echo 출력
    return ch;
}

void UART_getstring(unsigned char *ptr)
{
    char ch;
    while((ch = UART_getchar())!='\r' && (ch != '\n')){
        *ptr++=ch;

        UART_putchar(ch); //Echo the received char to PC monitor
    }
    *ptr = '\0';

    UART_putchar('\n'); //After getting all string, send a new line to PC
}

void UART_putstring(unsigned char *str)
{
    while(*str)
        UART_putchar(*str++);
}

uint8_t UART_Available(){
    return (UCSR0A & (1<<RXC0)) ? 1 : 0;
}