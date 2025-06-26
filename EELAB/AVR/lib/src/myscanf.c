#include "mystdio.h"

#include "mylib.h"

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#include "UART.h"


//myscanf
void myscanf(const char *format, ...){
    va_list args;
    va_start(args, format);

    const char *ptr = format;
    int *int_ptr;
    char *char_ptr;
    char buffer[100];
    int buffer_index;
    char ch;

    while(*ptr){
        if (*ptr == '%'){
            ptr++;
            switch(*ptr){
                case 'd':{
                    int_ptr=va_arg(args,int*);
                    buffer_index=0;
                    ch=UART_getchar_with_echo();
                    while(ch==' ' ||ch=='\n') ch= UART_getchar_with_echo();

                    if(ch=='-'||ch=='+') {
                        buffer[buffer_index++]=ch;
                        ch=UART_getchar_with_echo();
                    }
                    while(ch>='0' && ch<='9' && buffer_index<99){
                        buffer[buffer_index++]=ch;
                        ch=UART_getchar_with_echo();
                    }
                    buffer[buffer_index]='\0';
                    *int_ptr=str2int(buffer);
                
                    break;
                }
                case 'c':{
                    char_ptr=va_arg(args,char*);
                    ch=UART_getchar_with_echo();
                    while(ch==' '||ch=='\n') ch=UART_getchar_with_echo();

                    *char_ptr=ch;
                    break;
                }
                case 's':{
                    char_ptr=va_arg(args,char*);
                    buffer_index=0;
                    ch=UART_getchar_with_echo();
                    while (ch==' '||ch=='\n') ch=UART_getchar_with_echo();

                    while(ch != ' ' && ch!='\n' && buffer_index<99){
                        char_ptr[buffer_index++]=ch;
                        ch=UART_getchar_with_echo();
                    }
                    char_ptr[buffer_index]='\0';
                    break;
                }
                default:
                    break;
            }
        }
        ptr++;
    }
    va_end(args);

}
