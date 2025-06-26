#include "mylib.h"

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <avr/io.h>


//문자열 길이 구하는 함수 
int my_strlen(const char *str) 
{
    int length = 0;
    while (str[length] != '\0') { 
        length++;
    }
    return length;
}

//문자열에서 문자 찾기
char *findchr(const char *str, char c) {
    while (*str) {
        if (*str == c) {
            return (char *)str; 
        }
        str++;
    }
    return NULL; 
}

//문자열 역정렬
void flipstr(char *str) {
    int len = my_strlen(str); 
    int i;
    for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

//문자열을 숫자로 변환
int str2int(const char *str) {
    int result = 0;
    int sign = 1; 

    if (*str == '-') {
        sign = -1;
        str++; 
    } else if (*str == '+') {
        str++; 
    }

    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0'); 
        str++;
    }

    return result * sign;
}

//숫자를 문자열로 변환
void int2str(int n, char *str) {
    int i = 0;
    int isNegative = 0;

    if (n == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    if (n < 0) {
        isNegative = 1;
        n = -n; 
    }

    while (n > 0) {
        str[i++] = (n % 10) + '0';
        n /= 10;
    }

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0'; 

    flipstr(str);
}

//다양한 진법으로 변환
void I2A(int n, char *str, int radix) {
    int i = 0, isNegative = 0;
    char digits[] = "0123456789ABCDEF"; 

    if (radix < 2 || radix > 16) {
        str[0] = '\0'; 
        return;
    }

    if (n < 0 && radix == 10) {
        isNegative = 1;
        n = -n;
    }

    if (n < 0 && (radix == 2 || radix == 8 || radix == 16)) {
        unsigned int un = (unsigned int)n; 

        do {
            str[i++] = digits[un % radix];
            un /= radix;
        } while (un > 0);
    } 
    else { 
        do {
            str[i++] = digits[n % radix];
            n /= radix;
        } while (n > 0);
    }

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';
    
    flipstr(str);
}

//isspace
int is_space(char ch)
{
    if (ch == ' ' || ch == '\t' || ch =='\n'){
        return 1;
    } else {
        return 0;
    }
}

//isdigit
int is_digit(char ch)
{
    char digits[] = "0123456789";
    if (findchr(digits, ch)){
        return 1;
    } else {
        return 0;
    }
}

//copystr
void copystr(const char *str1, char *str2)
{
    while(*str1 !='\0')
        *str2++ = *str1++;
    *str2='\0';
}

//치환하기
void insstr(const char *str1, char *str2, char *str3)
{
    while(*str1!='%')
        *str3++ = *str1++;
    str1++;
    while(*str2)
        *str3++ = *str2++;
    while(*str1)
        *str3++ = *str1++;
    *str3='\0';
}



