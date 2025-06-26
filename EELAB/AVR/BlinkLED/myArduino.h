#ifndef myArduino_H_
#define myArduino_H_
#include <stddef.h> // uint8_t 타입이 정의

// Arduino Related Function Libraries
#ifndef F_CPU
#define F_CPU 16000000L 
#endif

#include <avr/io.h> 
#define HIGH 0x1
#define LOW  0x0
#define INPUT 0x0 
#define OUTPUT 0x1 
#define INPUT_PULLUP 0x2

void init_ArdPin(void);

void pinMode(uint8_t pin, uint8_t mode); 
void digitalWrite(uint8_t pin, uint8_t val);
#endif /* myArduino_H_ */