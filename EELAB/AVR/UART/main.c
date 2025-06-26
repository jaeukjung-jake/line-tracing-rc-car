// #include <avr/io.h>
// #include <UART.h>

// #define BAUDRATE 9600

// int main(void){
//     unsigned char rxdata, buffer[20];
//     UART_init(BAUDRATE);

//     while(1){
//         UART_getstring(buffer);
//         UART_putstring(buffer);
//         UART_putchar('\n');
//     }
//     return 0;
// }

//7주차 P3
#include <mystdio.h>
#include <UART.h>
#include <avr/interrupt.h>
#define BAUDRATE 9600

#define ENABLE_UART0_INTERRUPT() (UCSR0B |= (1 << RXCIE0))
#define DISABLE_UART0_INTERRUPT() (UCSR0B &= ~(1 << RXCIE0))

ISR(USART_RX_vect)
{
    DISABLE_UART0_INTERRUPT();
    uint8_t data=UDR0;
    myprintf("Interrupt: Received Data is %c\n",data);
    ENABLE_UART0_INTERRUPT();
}

int main(void)
{
    UART_init(9600);
    ENABLE_UART0_INTERRUPT();
    sei();

    while(1){

    }
    return 0;
}