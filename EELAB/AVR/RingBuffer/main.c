#include <mystdio.h>
#include <avr/io.h>
#include <UART.h>
#include <mylib.h>

#define BUFSIZE 4
uint8_t RingBuffer[BUFSIZE];
uint8_t *bufstart, *bufend;

void InitBuffer()
{
    bufstart=bufend=RingBuffer;
}

unsigned char BufAvailable()
{
    return ((bufend+BUFSIZE -bufstart)%BUFSIZE);
}

uint8_t putBuffer(uint8_t data){
    if(BufAvailable() == (BUFSIZE-1)){
        myprintf("Err : Buffer is Full. Can't push data %d !!!\n", data);
        return -1;
    }
    else{
        *bufend++ = data;
        if( bufend == RingBuffer+BUFSIZE) 
            bufend = RingBuffer;
        return 0;
    }
}

uint8_t getBuffer(){
    if(!BufAvailable()){
        myprintf("Err: Buffer is empty. !!!\n");
        return -1;
    }
    else{
        uint8_t rxd = *bufstart++;
        if(bufstart == RingBuffer + BUFSIZE)
            bufstart = RingBuffer;
        return rxd;
    }
}

void PrintBuf(){
    uint8_t *ptr = bufstart;
    uint8_t i, len = BufAvailable();

    myprintf("Buf Contents (%d): ", len);
    for (i=0; i<len; i++){
        myprintf("%x", *ptr++);
        if(ptr==RingBuffer+BUFSIZE) ptr = RingBuffer;
    }
    myprintf("\n");
}

int main(void){
    //char ch;
    char cmd[10];
    uint8_t num;
    UART_init(9600);
    InitBuffer();

    while(1){
        myprintf("put/get data: ");
        myscanf("%s %d", cmd, &num);
        if(strcmp("put",cmd)==0){
            if(putBuffer(num)!=-1)
                myprintf("put data is %d, bufstart: %p, bufend: %p\n", num, bufstart, bufend);
        }
        else if (strcmp("get",cmd)==0){
            num=getBuffer();
            myprintf("got data is %d, bufstart: %p, bufend: %p\n", num, bufstart, bufend);
        }
        PrintBuf();
    }
    return 0;
}