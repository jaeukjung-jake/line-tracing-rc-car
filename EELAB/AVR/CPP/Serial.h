#ifndef SERIAL_H_
#define SERIAL_H_

#include <avr/io.h>
#include "RingBuffer.h"
#include <avr/interrupt.h>
#include <mystdio.h>
#include <stdarg.h>

#define BUFSIZE 64

class Serial
{
private:
    uint8_t PrintBuf[BUFSIZE];

public:
    RingBuffer ringBuffer; 

    virtual void begin(uint16_t baud);

    virtual void putchar(char c);

    char getchar(void);

    void putstring(const char *str);

    void getstring(char *buffer);

    void printf(const char *format, ...);

    uint8_t available(void);

    static Serial *active_object;
};

#endif // SERIAL_H_
