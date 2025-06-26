// #include <mystdio.h>     // myprintf 함수 사용
// #include <UART.h>        // UART_init() 함수 사용
// #include "RingBuffer.h"

// int main(void) {
//     char cmd[10];
//     uint8_t num;
//     RingBuffer rbuf;

//     UART_init(9600);

//     while(1) {
//         myprintf("put/get data: ");
//         myscanf("%s %d", cmd, &num);

//         if (strcmp("put", cmd) == 0) {
//             if (rbuf.put(num) == true)
//                 myprintf("Success: put data is %d, datasize is %d\n", num, rbuf.available());
//             else
//                 myprintf("Fail: Buffer is full !!, datasize is %d\n", rbuf.available());
//         }

//         else if (strcmp("get", cmd) == 0) {
//             if (rbuf.get(&num) == true)
//                 myprintf("Success: got data is %d, datasize is %d\n", num, rbuf.available());
//             else
//                 myprintf("Fail: Buffer is empty !!, datasize is %d\n", rbuf.available());
//         }
//     }

//     return 0;
// }  //////////////////////////////////////////////////////////////////////////////P1


// #include "Serial.h"

// Serial serial;

// void setup() {
//     // UART 초기화 및 Baud Rate 설정
//     serial.begin(9600);
//     serial.printf("Serial Class Test Program \r");
// }

// int main(void) {
//     char buffer[50];
//     setup();

//     while (1) {
//         // 문자열 송신
//         serial.putstring("Send a message: ");

//         // 문자열 수신
//         serial.getstring(buffer);

//         // 수신된 메시지 송신
//         serial.putstring("\rYou sent: ");
//         serial.putstring(buffer);
//         serial.putchar('\r');
//     }

//     return 0;
// } ///////////////////////////////////////////////////////////////////////P4

// #include "Serial.h"
// #include "SoftwareSerial.h"

// Serial serial;
// SoftwareSerial swserial(2, 3);
// void setup(){
//     // UART 초기화 및 Baud Rate 설정
//     serial.begin(9600);
//     swserial.begin(9600);
//     serial.printf("This terminal is connected to UART \r");
//     swserial.printf("This terminal is connected to SWUART");
// }

// void loop(void){
//     if (serial.available() > 0){
//         swserial.putchar(serial.getchar());
//     }

//     if (swserial.available() > 0){
//         serial.putchar(swserial.getchar());
//     }
// }

// int main(void){
//     setup();

//     while(1)
//         loop();

//     return 0;
// } /////////////////////////////////////////////////////////////////P5

////////////////////////////////////////////////////////////////////////////9주차

// #include "Serial.h"
// #include "SoftwareSerial.h"

// Serial serial;
// SoftwareSerial swserial(2,3);

// int main(void){
//     char cmd[10];

//     serial.begin(9600);
//     swserial.begin(9600);
//     serial.printf("Bluetooth Module Test using Software Serial Port \r");

//     while(1){
//         if(serial.available()>0){
//             serial.getstring(cmd);
//             swserial.putstring(cmd);
//         }
//         if(swserial.available()>0){
//             serial.putchar(swserial.getchar());
//         }
//     }
//     return 0;
// }///////////////////////////////////////////////////////////////////블루투스 연경 확인


// #include "Serial.h"
// #include "SoftwareSerial.h"
// #include <mylib.h>

// Serial serial;
// SoftwareSerial swserial(2,3);

// #include <string.h>  // strcmp 사용

// void decode(char *cmd){
//     // 1단계: 받은 명령 출력
//     serial.printf("CMD: %s\r", cmd);
    

//     // 2단계: 명령어 해석 및 설명 출력
//     if (strcmp(cmd, "FL") == 0) {
//         serial.printf("RCCAR: Turn Front Left.\r");
//     }
//     else if (strcmp(cmd, "FF") == 0) {
//         serial.printf("RCCAR: Go Front Forward.\r");
//     }
//     else if (strcmp(cmd, "FR") == 0) {
//         serial.printf("RCCAR: Turn Front Right.\r");
//     }
//     else if (strcmp(cmd, "LL") == 0) {
//         serial.printf("RCCAR: Turn Left.\r");
//     }
//     else if (strcmp(cmd, "ST") == 0) {
//         serial.printf("RCCAR: STOP.\r");
//     }
//     else if (strcmp(cmd, "RR") == 0) {
//         serial.printf("RCCAR: Turn Right.\r");
//     }
//     else if (strcmp(cmd, "BL") == 0) {
//         serial.printf("RCCAR: Turn Backward Left.\r");
//     }
//     else if (strcmp(cmd, "BB") == 0) {
//         serial.printf("RCCAR: Move Backward.\r");
//     }
//     else if (strcmp(cmd, "BR") == 0) {
//         serial.printf("RCCAR: Turn Backward Right.\r");
//     }
//     else if (is_digit(cmd[0])) {
//         int speed = str2int(cmd);
//         serial.printf("Change Speed to: %d\r", speed);
//     }
//     else {
//         serial.printf("RCCAR: Unknown Command.\r");
//     }
// }


// int main(void){
//     char cmd[10];

//     serial.begin(9600);
//     swserial.begin(9600);
//     serial.printf("RC CAR Module Test using Software Serial Port \r");

//     while(1){
//         if (serial.available() >0){
//             serial.getstring(cmd);
//             swserial.putstring(cmd);
//         }

//         if (swserial.available() > 0){
//             swserial.getstring(cmd);
//             decode(cmd);
//         }
//     }
//     return 0;
// }///////////////////////////////////////////////////////////////////////////////////P1

// #include "Serial.h"
// #include "SoftwareSerial.h"
// #include <mylib.h>
// #include "string.h"

// Serial serial;
// SoftwareSerial swserial(2,3);

// void initPWM() {
//     // D6 (OC0A), D5 (OC0B)를 출력으로 설정
//     DDRD |= (1 << DDD6) | (1 << DDD5);

//     TCCR0A |= (1 << COM0A1) | (0 << COM0A0);
//     TCCR0A |= (1 << COM0B1) | (0 << COM0B0);

//     TCCR0A |= (1 << WGM00) | (1 << WGM01);
//     TCCR0B &= ~(1 << WGM02); 

//     TCCR0B |= (1 << CS01) | (1 << CS00);
//     TCCR0B &= ~(1 << CS02);

//     // 초기 속도값 설정
//     OCR0A = 0;
//     OCR0B = 0;
// }


// void decode(char *cmd){
//     serial.printf("CMD: %s\r", cmd);

//     if (strcmp(cmd, "FL") == 0) {
//         serial.printf("RCCAR: Turn Front Left.\r");
//     }
//     else if (strcmp(cmd, "FF") == 0) {
//         serial.printf("RCCAR: Go Front Forward.\r");
//     }
//     else if (strcmp(cmd, "FR") == 0) {
//         serial.printf("RCCAR: Turn Front Right.\r");
//     }
//     else if (strcmp(cmd, "LL") == 0) {
//         serial.printf("RCCAR: Turn Left.\r");
//     }
//     else if (strcmp(cmd, "ST") == 0) {
//         serial.printf("RCCAR: STOP.\r");
//         OCR0A = 0;
//         OCR0B = 0;
//     }
//     else if (strcmp(cmd, "RR") == 0) {
//         serial.printf("RCCAR: Turn Right.\r");
//     }
//     else if (strcmp(cmd, "BL") == 0) {
//         serial.printf("RCCAR: Turn Backward Left.\r");
//     }
//     else if (strcmp(cmd, "BB") == 0) {
//         serial.printf("RCCAR: Move Backward.\r");
//     }
//     else if (strcmp(cmd, "BR") == 0) {
//         serial.printf("RCCAR: Turn Backward Right.\r");
//     }
//     else if (is_digit(cmd[0])) {
//         int speed = str2int(cmd);
//         serial.printf("Change Speed to: %d\r", speed);
//         OCR0A = speed;
//         OCR0B = speed;
//     }
//     else {
//         serial.printf("RCCAR: Unknown Command.\r");
//     }
// }

// int main(void){
//     char cmd[10];
//     serial.begin(9600);
//     swserial.begin(9600);
//     serial.printf("RC CAR Module Test using Software Serial Port \r");
//     initPWM();

//     while(1){
//         // AT 명령어를 터미널로부터 입력받아 HC-06에 명령어 전송
//         if (serial.available() > 0){
//             serial.getstring(cmd);
//             swserial.putstring(cmd);
//         }
//         // HC-06으로부터 명령을 받아 해석하고 실행
//         if (swserial.available() > 0){
//             swserial.getstring(cmd);
//             decode(cmd);
//         }
//     }
//     return 0;
// }///////////////////////////////////////////////////////////////////////////////////P2

// 핀 설정

// #include "Serial.h"
// #include "SoftwareSerial.h"
// #include <mylib.h>
// #include <myArduino.h>
// #include "string.h"

// #define ENA 5   //왼쪽
// #define ENB 6   //오른쪽

// #define IN1 9
// #define IN2 10
// #define IN3 11
// #define IN4 12

// #define SPEED 200

// void initPWM() {
//     pinMode(ENA, OUTPUT);
//     pinMode(ENB, OUTPUT);

//     TCCR0A |= (1 << WGM00) | (1 << WGM01);
//     TCCR0B &= ~(1 << WGM02);

//     TCCR0A |= (1 << COM0B1);  
//     TCCR0A |= (1 << COM0A1);  

//     TCCR0B |= (1 << CS01) | (1 << CS00);
//     TCCR0B &= ~(1 << CS02);

//     OCR0A = 0;
//     OCR0B = 0;
// }

// void setSpeed(uint8_t left, uint8_t right) {
//     OCR0B = left;  
//     OCR0A = right; 
// }


// void stopMotors() {
//     digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
//     digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
//     setSpeed(0, 0);
// }
// void forward() {
//     digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
//     digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
//     setSpeed(SPEED, SPEED);
// }
// void backward() {
//     digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
//     digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
//     setSpeed(SPEED, SPEED);
// }
// void turnRight() {
//     // 왼쪽 바퀴 전진
//     digitalWrite(IN1, HIGH);
//     digitalWrite(IN2, LOW);

//     // 오른쪽 바퀴 후진
//     digitalWrite(IN3, LOW);
//     digitalWrite(IN4, HIGH);

//     setSpeed(SPEED, SPEED); 
// }
// void turnLeft() {
//     // 왼쪽 바퀴 후진
//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, HIGH);

//     // 오른쪽 바퀴 전진
//     digitalWrite(IN3, HIGH);
//     digitalWrite(IN4, LOW);

//     setSpeed(SPEED, SPEED); 
// }

// int main(void) {
//     initPWM();

//     pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
//     pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);

//     while (1) {
//         forward();
//         _delay_ms(3000);
//         stopMotors();
//         _delay_ms(1000);

//         backward();
//         _delay_ms(3000);
//         stopMotors();
//         _delay_ms(1000);

//         turnLeft();
//         _delay_ms(500);
//         stopMotors();
//         _delay_ms(1000);

//         turnRight();
//         _delay_ms(500);
//         stopMotors();
//         _delay_ms(1000);
//     }
// }
/////////////////////////////////////////////// 11주차 사전실습 과제

// #include <mylib.h>
// #include "Serial.h"
// #include "SoftwareSerial.h"
// #include <string.h>

// #define LWHEELA 9
// #define LWHEELB 10
// #define RWHEELA 11
// #define RWHEELB 12

// #define LPWM 5
// #define RPWM 6


// Serial serial;
// SoftwareSerial swserial(2, 3);

// void initPWM() {
//     DDRD |= (1 << DDD6) | (1 << DDD5);

//     TCCR0A |= (1 << COM0A1);
//     TCCR0A |= (1 << COM0B1);

//     TCCR0A |= (1 << WGM00) | (1 << WGM01);
//     TCCR0B &= ~(1 << WGM02);

//     TCCR0B |= (1 << CS01) | (1 << CS00);
//     TCCR0B &= ~(1 << CS02);

//     OCR0A = 0;
//     OCR0B = 0;
// }

// int currentSpeed = 255;

// void decode(char *cmd) {
//     int speed = str2int(cmd);

//     if (strcmp(cmd, "FL") == 0) {
//         digitalWrite(LWHEELA, LOW);
//         digitalWrite(LWHEELB, LOW);
//         digitalWrite(RWHEELA, HIGH);
//         digitalWrite(RWHEELB, LOW);
//         OCR0A = currentSpeed;
//         OCR0B = currentSpeed;
//     }
//     else if (strcmp(cmd, "FF") == 0) {
//         digitalWrite(LWHEELA, HIGH);
//         digitalWrite(LWHEELB, LOW);
//         digitalWrite(RWHEELA, HIGH);
//         digitalWrite(RWHEELB, LOW);
//         OCR0A = currentSpeed;
//         OCR0B = currentSpeed;
//     }
//     else if (strcmp(cmd, "FR") == 0) {
//         digitalWrite(LWHEELA, HIGH);
//         digitalWrite(LWHEELB, LOW);
//         digitalWrite(RWHEELA, LOW);
//         digitalWrite(RWHEELB, LOW);
//         OCR0A = currentSpeed;
//         OCR0B = currentSpeed;
//     }
//     else if (strcmp(cmd, "LL") == 0) {
//         digitalWrite(LWHEELA, LOW);
//         digitalWrite(LWHEELB, HIGH);
//         digitalWrite(RWHEELA, HIGH);
//         digitalWrite(RWHEELB, LOW);
//         OCR0A = currentSpeed;
//         OCR0B = currentSpeed;
//     }
//     else if (strcmp(cmd, "ST") == 0) {
//         OCR0A = 0;
//         OCR0B = 0;
//         digitalWrite(LWHEELA, HIGH);
//         digitalWrite(LWHEELB, HIGH);
//         digitalWrite(RWHEELA, LOW);
//         digitalWrite(RWHEELB, LOW);
//     }
//     else if (strcmp(cmd, "RR") == 0) {
//         digitalWrite(LWHEELA, HIGH);
//         digitalWrite(LWHEELB, LOW);
//         digitalWrite(RWHEELA, LOW);
//         digitalWrite(RWHEELB, HIGH);
//         OCR0A = currentSpeed;
//         OCR0B = currentSpeed;
//     }
//     else if (strcmp(cmd, "BL") == 0) {
//         digitalWrite(LWHEELA, HIGH);
//         digitalWrite(LWHEELB, HIGH);
//         digitalWrite(RWHEELA, LOW);
//         digitalWrite(RWHEELB, HIGH);
//         OCR0A = currentSpeed;
//         OCR0B = currentSpeed;
//     }
//     else if (strcmp(cmd, "BB") == 0) {
//         digitalWrite(LWHEELA, LOW);
//         digitalWrite(LWHEELB, HIGH);
//         digitalWrite(RWHEELA, LOW);
//         digitalWrite(RWHEELB, HIGH);
//         OCR0A = currentSpeed;
//         OCR0B = currentSpeed;
//     }
//     else if (strcmp(cmd, "BR") == 0) {
//         digitalWrite(LWHEELA, LOW);
//         digitalWrite(LWHEELB, HIGH);
//         digitalWrite(RWHEELA, LOW);
//         digitalWrite(RWHEELB, LOW);
//         OCR0A = currentSpeed;
//         OCR0B = currentSpeed;
//     }
//     else if (speed >= 0 && speed <= 255) {
//         currentSpeed = speed;
//     }
//     else {
//         serial.printf("RCCAR: Unknown Command.\r\n");
//     }
// }

// void setup(){
//     serial.begin(9600);
//     swserial.begin(9600);    
//     initPWM();

//     pinMode(LWHEELA, OUTPUT);
//     pinMode(LWHEELB, OUTPUT);
//     pinMode(RWHEELA, OUTPUT);
//     pinMode(RWHEELB, OUTPUT);
// }

// int main(void) {
//     char cmd[10];

//     setup();

//     while (1) {
//         if (serial.available() > 0) {
//             serial.getstring(cmd);
//             swserial.putstring(cmd);
//         }

//         if (swserial.available() > 0) {
//             swserial.getstring(cmd);
//             decode(cmd);
//         }
//     }
//     return 0;
// }////////////////////////////////////////////////11주차 실습 과제

// #include <mylib.h>
// #include "Serial.h"
// #include "SoftwareSerial.h"

// #define IRSENSOR 14

// Serial serial;

// int main(void) {
//     serial.begin(9600);
//     serial.printf("Infrared Sensor Module Test\r");

//     pinMode(IRSENSOR, INPUT); 

//     while (1) {
//         int value = digitalRead(IRSENSOR);

//         serial.printf("Received Data is %d\r", value);

//         _delay_ms(1000);
//     }

//     return 0;
//}////////////////////////////////////12주차 예비 과제


// #include <mylib.h>
// #include "Serial.h"
// #include "SoftwareSerial.h"
// #include <avr/io.h>
// #include <util/delay.h>
// #include <stdbool.h>


// #define LWHEELA 9
// #define LWHEELB 10
// #define RWHEELA 11
// #define RWHEELB 12
// #define LPWM 5     
// #define RPWM 6  
// #define IRSENSOR 14 

// #define SPEED 200

// Serial serial;
// bool movingForward = true;
// bool ignoreSensor = false;

// void initPWM() {
//     DDRD |= (1 << DDD6) | (1 << DDD5);  

//     TCCR0A |= (1 << COM0A1) | (1 << COM0B1);
//     TCCR0A |= (1 << WGM00) | (1 << WGM01);   
//     TCCR0B &= ~(1 << WGM02);
//     TCCR0B |= (1 << CS01) | (1 << CS00);     

//     OCR0A = 0;
//     OCR0B = 0;
// }

// void setup() {
//     serial.begin(9600);
//     serial.printf("Sensor Module Test\r");

//     pinMode(LWHEELA, OUTPUT);
//     pinMode(LWHEELB, OUTPUT);
//     pinMode(RWHEELA, OUTPUT);
//     pinMode(RWHEELB, OUTPUT);
//     pinMode(IRSENSOR, INPUT);

//     initPWM();
// }

// void stopCar() {
//     digitalWrite(LWHEELA, LOW);
//     digitalWrite(LWHEELB, LOW);
//     digitalWrite(RWHEELA, LOW);
//     digitalWrite(RWHEELB, LOW);
//     OCR0A = 0;
//     OCR0B = 0;
// }

// void forward() {
//     digitalWrite(LWHEELA, HIGH);
//     digitalWrite(LWHEELB, LOW);
//     digitalWrite(RWHEELA, HIGH);
//     digitalWrite(RWHEELB, LOW);
//     OCR0A = SPEED;
//     OCR0B = SPEED;
// }

// void backward() {
//     digitalWrite(LWHEELA, LOW);
//     digitalWrite(LWHEELB, HIGH);
//     digitalWrite(RWHEELA, LOW);
//     digitalWrite(RWHEELB, HIGH);
//     OCR0A = SPEED;
//     OCR0B = SPEED;
// }

// bool readIRSensor() {
//     return digitalRead(IRSENSOR); 
// }

// int main(void) {
//     setup();
//     while (1) {
//         int sensorValue = readIRSensor(); 

//         serial.printf("Received Data is %d\r", sensorValue);

//         if (sensorValue == 1 && !ignoreSensor) {
//             stopCar();
//             _delay_ms(300);            
//             movingForward = !movingForward;

//             if (movingForward)
//                 forward();
//             else
//                 backward();
//             _delay_ms(300);  

//             ignoreSensor = true;
//             _delay_ms(500);
//             ignoreSensor = false;
//         }

//         if (movingForward)
//             forward();
//         else
//             backward();

//         _delay_ms(50);
//     }

//     return 0;
// } ////////////////////////////////12주차 사전실습 P2

#include <mylib.h>
#include <Serial.h>
#include <SoftwareSerial.h>
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#define LWHEELA 10
#define LWHEELB 9
#define RWHEELA 8
#define RWHEELB 7
#define LPWM 6
#define RPWM 11

Serial serial;

// === 방향 기억용 열거형 ===
enum Direction
{
    FORWARD_DIR,
    LEFT_DIR,
    RIGHT_DIR
};
Direction lastDirection = FORWARD_DIR;
Direction lastlast = FORWARD_DIR;
int speed = 220;
void initPWM()
{
    DDRD |= (1 << PD6);
    TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);
    TCCR0B |= (1 << CS01) | (1 << CS00);
    OCR0A = 0;

    DDRB |= (1 << PB3);
    TCCR2A |= (1 << COM2A1) | (1 << WGM21) | (1 << WGM20);
    TCCR2B |= (1 << CS22);
    OCR2A = 0;
}
void initPins()
{
    DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2);
    DDRD |= (1 << PD7);
}

void setup()
{
    serial.begin(9600);
    serial.printf("Line Tracer Start\r");

    pinMode(LWHEELA, OUTPUT);
    pinMode(LWHEELB, OUTPUT);
    pinMode(RWHEELA, OUTPUT);
    pinMode(RWHEELB, OUTPUT);

    DDRC &= ~((1 << PC0) | (1 << PC1) | (1 << PC2)); // IR sensors input

    initPWM();
}

void stopCar()
{
    digitalWrite(LWHEELA, LOW);
    digitalWrite(LWHEELB, LOW);
    digitalWrite(RWHEELA, LOW);
    digitalWrite(RWHEELB, LOW);
    OCR0A = 0;
    OCR0B = 0;
}

void forward()
{
    PORTB &= ~(1 << PB2);
    PORTB |= (1 << PB1);
    PORTB |= (1 << PB0);
    PORTD &= ~(1 << PD7);
    OCR0A = speed;
    OCR2A = speed;
    lastDirection = FORWARD_DIR;
}

void forward1()
{
    PORTB &= ~(1 << PB2);
    PORTB |= (1 << PB1);
    PORTB |= (1 << PB0);
    PORTD &= ~(1 << PD7);
    OCR0A = 250;
    OCR2A = 250;
    lastDirection = FORWARD_DIR;
}

void turnLeft()
{
    PORTB &= ~(1 << PB2);
    PORTB |= (1 << PB1);
    PORTB &= ~(1 << PB0);
    PORTD &= ~(1 << PD7);
    OCR0A = 130;
    OCR2A = 250;
    lastDirection = LEFT_DIR;
}

void turnRight()
{
    PORTB &= ~(1 << PB2);
    PORTB &= ~(1 << PB1);
    PORTB |= (1 << PB0);
    PORTD &= ~(1 << PD7);
    OCR0A = 250;
    OCR2A = 130;
    lastDirection = RIGHT_DIR;
}

void hardLeft()
{
    PORTB &= ~(1 << PB2);
    PORTB |= (1 << PB1);
    PORTB &= ~(1 << PB0);
    PORTD |= (1 << PD7);
    OCR0A = 200;
    OCR2A = 200;
}

void hardRight()
{
    PORTB |= (1 << PB2);
    PORTB &= ~(1 << PB1);
    PORTB |= (1 << PB0);
    PORTD &= ~(1 << PD7);
    OCR0A = 200;
    OCR2A = 200;
}

void hardLeft1()
{
    PORTB &= ~(1 << PB2);
    PORTB |= (1 << PB1);
    PORTB &= ~(1 << PB0);
    PORTD |= (1 << PD7);
    OCR0A = 130;
    OCR2A = 130;
}

void hardRight1()
{
    PORTB |= (1 << PB2);
    PORTB &= ~(1 << PB1);
    PORTB |= (1 << PB0);
    PORTD &= ~(1 << PD7);
    OCR0A = 130;
    OCR2A = 130;
}

uint8_t readIRSensors()
{
    return PINC & 0x07; // PC2(Left), PC1(Center), PC0(Right)
}

int main(void)
{
    setup();
    int time = 0;
    while (1)
    {
        uint8_t sensors = readIRSensors();
        bool left = (sensors & 0x04) >> 2;
        bool center = (sensors & 0x02) >> 1;
        bool right = (sensors & 0x01);

        serial.printf("L:%d C:%d R:%d\r", left, center, right);

        if (left == 0 && center == 1 && right == 0)
        {
            forward();
        }
        else if (left == 0 && right == 1)
        {   
            //stopCar();
            turnLeft();
        }
        else if (right == 0 && left == 1)
        {
            //stopCar();
            turnRight();
        }
        else if (left == 1 && center == 1 && right == 1)
        {
            forward1(); // 정지선
            time += 100;
            if (time >= 300)
            {
                stopCar();
            }
        }
        else if (left == 0 && center == 0 && right == 0)
        {
            // 선을 잃었을 때
            stopCar();
            if (lastDirection == LEFT_DIR)
            {
                while(1){
                    hardLeft();
                    uint8_t sensors = readIRSensors();
                    bool left = (sensors & 0x04) >> 2;
                    bool center = (sensors & 0x02) >> 1;
                    bool right = (sensors & 0x01);
                    if (left == 0 && center == 1 && right == 0){
                        forward();
                        break;
                    }
                }
            }
            else if (lastDirection == RIGHT_DIR)
            {
                 while(1){
                    hardRight();
                    uint8_t sensors = readIRSensors();
                    bool left = (sensors & 0x04) >> 2;
                    bool center = (sensors & 0x02) >> 1;
                    bool right = (sensors & 0x01);
                    if (left == 0 && center == 1 && right == 0){
                        forward();
                        break;
                    }
                }
            }
            else if (lastDirection == FORWARD_DIR)
            {   
                stopCar();
                hardRight1();
                
                uint8_t sensors = readIRSensors();
                bool left = (sensors & 0x04) >> 2;
                bool center = (sensors & 0x02) >> 1;
                bool right = (sensors & 0x01);
                if (center == 1){
                    forward();
                    continue;
                }
                
                hardLeft1();
            }
        }
         _delay_ms(10);
    }
}
//////////////////////////////////////13주차 실습