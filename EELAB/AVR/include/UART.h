#ifndef UART_H
#define UART_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>

void UART_init(unsigned int baud);
void UART_putchar(unsigned char data);
unsigned char UART_getchar(void);
void UART_getstring(unsigned char *ptr);
void UART_putstring(unsigned char *str);
unsigned char UART_getchar_with_echo(void);
uint8_t UART_Available();

#ifdef __cplusplus
}
#endif

#endif
