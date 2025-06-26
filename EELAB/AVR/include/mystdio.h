#ifndef MYSTDIO_H
#define MYSTDIO_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stddef.h>
#include <stdarg.h>
#include <avr/io.h>


int bprintf(char *pbuf, const char *format, va_list ap);
int myprintf(const char *format, ...);

void myscanf(const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif
