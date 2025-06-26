#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <avr/io.h>

#define RBUFSIZE 4

class RingBuffer
{
private:
    uint8_t buffer[RBUFSIZE];
    uint8_t bufstart, bufend;

public:
    RingBuffer();
    uint8_t available(void);
    bool put(uint8_t);
    bool get(uint8_t *);
};

#endif
