#ifndef SOFTWARESERIAL_H
#define SOFTWARESERIAL_H

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include "Serial.h"         // Serial 클래스를 상속받기 위해
#include <myArduino.h>      // pinMode, digitalWrite 사용용
#include <util/delay.h>     // _delay 함수 사용

// 부모 클래스(Serial)로부터 상속받고, 다른 기능을 수행하는 함수만 override 구현함
class SoftwareSerial : public Serial {
private:
    uint8_t rxPin, txPin;

public:
    // 생성자 : rxPin, txPin 핀번호 설정
    SoftwareSerial(uint8_t, uint8_t);

    // SW UART 초기화 : 핀 입출력 모드 설정 및 txPin HIGH 값 초기 출력
    void begin(uint16_t baud);

    // SW 단일 문자 송신 : 부모 클래스와 다르게 재현함수 사용 구현 (override)
    void putchar(char);

    // 생성된 인스턴스 주소를 저장할 공간으로 부모 클래스 주소와 다름에 유의
    static SoftwareSerial* active_object;
};

#endif // SOFTWARESERIAL_H
