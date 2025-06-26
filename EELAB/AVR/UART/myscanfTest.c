// #include <UART.h>
// #include <mystdio.h>
// #define BAUDRATE 9600

// int main(){
//     int num;    
//     char ch;
//     char str[100];

//     UART_init(BAUDRATE);

//     myprintf("정수 문자 문자열을 입력하세요 (공백으로 구분): ");
//     myscanf("%d %c %s", &num, &ch, str);

//     myprintf("입력한 정수: %d\n", num);
//     myprintf("입력한 문자: %c\n", ch);
//     myprintf("입력한 문자열: %s\n", str);

//     return 0;
// }