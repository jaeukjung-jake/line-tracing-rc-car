#include "mystdio.h"

#include "mylib.h"
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#include "UART.h"

// //myprintf 만들기
// int myvprintf(char *pbuf, const char *format, va_list ap)
// {
//     int format_len = strlen(format);
//     int i, pbuf_i = 0;
//     char temp[32];

//     for (i=0;i<format_len;i++){
//         if (format[i]=='%'){
//             i++;
//             switch(format[i]) {
//                 case 'd': {
//                     int val = va_arg(ap, int);
//                     I2A(val, temp,10);
//                     int j = 0;
//                     while(temp[j]!='\0'){
//                         pbuf[pbuf_i++]=temp[j++];
//                     }
//                     break;
//                 }
//                 case 'o': {
//                     int val = va_arg(ap, int);
//                     I2A(val, temp,8);
//                     int j = 0;
//                     while(temp[j]!='\0'){
//                         pbuf[pbuf_i++]=temp[j++];
//                     }
//                     break;
//                 }
//                 case 'b': {
//                     int val = va_arg(ap, int);
//                     I2A(val, temp,2);
//                     int j = 0;
//                     while(temp[j]!='\0'){
//                         pbuf[pbuf_i++]=temp[j++];
//                     }
//                     break;
//                 }
//                 case 'c':{
//                     char val = (char)va_arg(ap,int);
//                     pbuf[pbuf_i++]=val;
//                     break;
//                 }
//                 case 'x': {
//                     int val=va_arg(ap,int);
//                     I2A(val,temp,16);
//                     int j=0;
//                     while(temp[j]!='\0'){
//                         pbuf[pbuf_i++]=temp[j++];
//                     }
//                     break;
//                 }
//                 case 's':{
//                     char *val=va_arg(ap,char*);
//                     int j=0;
//                     while(val[j]!='\0'){
//                         pbuf[pbuf_i++]=val[j++];
//                     }
//                     break;
//                 }
//                 case 'p': {
//                     void *ptr = va_arg(ap, void*);
//                     uintptr_t addr = (uintptr_t)ptr;
//                     I2A(addr, temp, 16);  // 16진수로 변환
//                     int j = 0;
//                     while (temp[j] != '\0') {
//                         pbuf[pbuf_i++] = temp[j++];
//                     }
//                     break;
//                 }
                
//             }
//         }
//         else{   
//             pbuf[pbuf_i] = format[i];
//             pbuf_i++;
//         }
//     }
//     pbuf[pbuf_i]='\0';
//     return pbuf_i;
// }

//myprintf 만들기
int bprintf(char *pbuf, const char *format, va_list ap)
{
    int format_len = strlen(format);
    int i, pbuf_i = 0;
    char temp[32];

    for (i=0;i<format_len;i++){
        if (format[i]=='%'){
            i++;
            switch(format[i]) {
                case 'd': {
                    int val = va_arg(ap, int);
                    I2A(val, temp,10);
                    int j = 0;
                    while(temp[j]!='\0'){
                        pbuf[pbuf_i++]=temp[j++];
                    }
                    break;
                }
                case 'o': {
                    int val = va_arg(ap, int);
                    I2A(val, temp,8);
                    int j = 0;
                    while(temp[j]!='\0'){
                        pbuf[pbuf_i++]=temp[j++];
                    }
                    break;
                }
                case 'b': {
                    int val = va_arg(ap, int);
                    I2A(val, temp,2);
                    int j = 0;
                    while(temp[j]!='\0'){
                        pbuf[pbuf_i++]=temp[j++];
                    }
                    break;
                }
                case 'c':{
                    char val = (char)va_arg(ap,int);
                    pbuf[pbuf_i++]=val;
                    break;
                }
                case 'x': {
                    int val=va_arg(ap,int);
                    I2A(val,temp,16);
                    int j=0;
                    while(temp[j]!='\0'){
                        pbuf[pbuf_i++]=temp[j++];
                    }
                    break;
                }
                case 's':{
                    char *val=va_arg(ap,char*);
                    int j=0;
                    while(val[j]!='\0'){
                        pbuf[pbuf_i++]=val[j++];
                    }
                    break;
                }
                case 'p': {
                    void *ptr = va_arg(ap, void*);
                    uintptr_t addr = (uintptr_t)ptr;
                    I2A(addr, temp, 16);  // 16진수로 변환
                    int j = 0;
                    while (temp[j] != '\0') {
                        pbuf[pbuf_i++] = temp[j++];
                    }
                    break;
                }
                
            }
        }
        else{   
            pbuf[pbuf_i] = format[i];
            pbuf_i++;
        }
    }
    pbuf[pbuf_i]='\0';
    return pbuf_i;
}

//myprintf
int myprintf(const char *format, ...)
{
    char pbuf[256];
    int len;
    va_list ap;
    va_start(ap, format);

    len = bprintf(pbuf, format, ap);
    va_end(ap);
    
    UART_putstring(pbuf);
    return len;
}