#ifndef SWSERIAL_H_
#define SWSERIAL_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define DISABLE_EXT0_INTERRUPT()   (EIMSK &= ~(1 << INT0))
#define CLEAR_EXT0_INTERRUPT()     (EIFR |= (1 << INTF0))
#define ENABLE_EXT0_INTERRUPT()    (EIMSK |= (1 << INT0)) 


void SWU_init( void );
void SWU_putchar( const unsigned char c);
unsigned char SWU_getchar(void);
unsigned char SWU_available(void);

void SWU_putstring( const unsigned char *data);


#endif
