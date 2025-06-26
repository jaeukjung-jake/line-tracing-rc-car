#include "Serial.h"

Serial *Serial::active_object=0;

void Serial::begin(uint16_t baud)
{
    cli();

    unsigned int ubrr = (16000000/baud/16)-1;

    UBRR0H = (uint8_t)(ubrr >>8);
    UBRR0L = (uint8_t)(ubrr & 0xFF);

    UCSR0B = _BV(RXEN0) | _BV(TXEN0);

    UCSR0B |= _BV(RXCIE0);

    UCSR0C = (1<<UCSZ01)| (1<<UCSZ00);
    active_object= this;
    sei();
}

void Serial::putchar(char c)
{
    if (c=='\r')
        Serial::putchar('\n');
    while (!(UCSR0A&(1<<UDRE0)));

    UDR0 = c;
}

char Serial::getchar(void)
{
    uint8_t ch;
    ringBuffer.get(&ch);
    return ch;
}

uint8_t Serial::available(void)
{
    return ringBuffer.available();
}

void Serial::putstring(const char*str)
{
    while (*str)
    {
        putchar(*str);
        str++;
    }
}

void Serial::getstring(char*buffer)
{
    uint8_t index =0;
    char c;
    while((c=getchar())!='\r'&&c!='\n'){
        buffer[index++]=c;
        while(!ringBuffer.available());
    }
    buffer[index]='\0';
}

void Serial::printf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    bprintf((char*)PrintBuf, format, ap);
    va_end(ap);
    putstring((char*)PrintBuf);
}

#define ENABLE_UART0_INTERRUPT() (UCSR0B |= (1<<RXCIE0))
#define DISABLE_UART0_INTERRUPT() (UCSR0B &= ~(1<<RXCIE0))

ISR(USART_RX_vect)
{
    DISABLE_UART0_INTERRUPT();
    uint8_t data = UDR0;
    ENABLE_UART0_INTERRUPT();

    if(Serial::active_object)
        Serial::active_object->ringBuffer.put(data);
}
