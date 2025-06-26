#ifndef MYLIB_H
#define MYLIB_H

#ifdef __cplusplus
extern "C"{
#endif


#include <stddef.h>
#include <stdarg.h>

// P1
int my_strlen(const char *str);

//P2
char *findchr(const char *str, char c);

//P3
void flipstr(char *str);

// P4
int str2int(const char *str);

// P5
void int2str(int n, char *str);

//I2A
void I2A(int n, char *str, int radix);

//is_space
int is_space(char ch);

//is_digit
int is_digit(char ch);

//copystr
void copystr(const char *str1, char *str2);

//치환하기
void insstr(const char *str1, char *str2, char *str3);

//myprintf 만들기
int myvprintf(char *pbuf, const char *format, va_list ap);

//myprintf
int myprintf(const char *format, ...);

//myscanf
void myscanf(const char *format, ...);

//myscanf2
void myscanf2(const char *format, ...);


#ifdef __cplusplus
}
#endif

#endif