#include "RingBuffer.h"

// 클래스 생성자
RingBuffer::RingBuffer()
{
    bufstart = 0;
    bufend = 0;
}

uint8_t RingBuffer::available(void)
{
    return ((bufend + RBUFSIZE - bufstart) % RBUFSIZE);
}

bool RingBuffer::put(uint8_t data)
{
    // Buffer is full !!!
    if (available() == (RBUFSIZE - 1))
        return false;
    else
    {
        buffer[bufend] = data;
        bufend = (bufend + 1) % RBUFSIZE;
        return true;
    }
}

bool RingBuffer::get(uint8_t *rxd)
{
    // Buffer is empty !!!
    if (!available())
        return false;
    else
    {
        *rxd = buffer[bufstart];
        bufstart = (bufstart + 1) % RBUFSIZE;
        return true;
    }
}
