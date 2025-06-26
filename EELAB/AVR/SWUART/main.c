#include <mystdio.h>
#include <myArduino.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <UART.h>
#include <avr/io.h>
#include "SWserial.h"


#define INT0_PIN 2

// ISR(INT0_vect)
// {
//     cli();
//     myprintf("Here is Interrupt Service routine\n");
//     digitalWrite(13, (digitalRead(13)==HIGH ? LOW :HIGH));
//     _delay_ms(100);
//     //EIFR |= (1 << INTF0);
//     sei();
// } //사전 실습

int main(void)
{
    init_ArdPin(); //main함수에서 함수 호출해야함
    // cli();
    // UART_init(9600);
    // pinMode(INT0_PIN, INPUT_PULLUP);
    // pinMode(13,OUTPUT);

    // EICRA = (1 << ISC01);   
    // EIMSK = (1 << INT0);
    // EIFR |= (1 << INTF0);
    // sei();

    // digitalWrite(13, LOW);
    // myprintf("Now we are waiting INT0 \n");
    // while(1){

    // }   //사전실습 과제 (스위치 인터럽트)




    // cli();
    // SWU_init();
    // UART_init(9600);
    // sei();

    // myprintf("Now waiting for External Interrupt from PIN2 \n");

    // while(1){
    //     ;
    // }

    // return 0; 
    //P3



    // char ch;
    // cli();
    // SWU_init();
    // UART_init(9600);
    // sei();

    // myprintf("Now waiting for External Interrupt from PIN2 \n");

    // while(1){
    //     if(SWU_available()!=0){
    //         ch = SWU_getchar();
    //         myprintf("SWU: Received Data is %c\n", ch);
    //     }
    // }
    // return 0;  
    //P4


    // char ch;
    // cli();
    // SWU_init();
    // UART_init(9600);
    // sei();

    // myprintf("Now waiting for External Interrupt from PIN2 \n");

    // while(1){
    //     if(SWU_available()){
    //         ch=SWU_getchar();
    //         //myprintf("SWU: Received Data is %c \n",ch);            
    //         SWU_putchar(ch);
    //     }
    // }
    // return 0;  
    //P5





    // char ch;
    // unsigned char cmd[20];
    // cli();
    // SWU_init();
    // UART_init(9600);
    // sei();
    // pinMode(13, OUTPUT);
    // digitalWrite(13, LOW);
    // myprintf("Software Serial Test \n");

    // while(1){
    //     if (SWU_available()){
    //         ch = SWU_getchar();
    //         PORTB ^= (1 << 5);
    //         SWU_putchar(ch);
    //         myprintf("Received data is %c\n", ch);
    //     }
    //     if (UART_Available()){
    //         UART_getstring(cmd);
    //         SWU_putstring(cmd);
    //         const unsigned char newline[] = "\r\n";
    //         SWU_putstring(newline);
    //     }
    // }
    // return 0;
    //P6

    // uint8_t age = 28;
    // uint8_t blood = 'B';
    // char name[]="JUNG JAE UK";
    // UART_init(9600);
    // myprintf("My name is %s, Age is %d. Blood is %c\n", name, age, blood);
    // while(1); //myprintf test p1


}   