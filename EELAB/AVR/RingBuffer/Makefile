# 타겟 설정
TARGET = main
BOARD = atmega328p
PORT = /dev/cu.usbmodem1101  # 실제 연결된 포트로 변경
# 컴파일러 및 플래그 설정
CC = avr-gcc
CFLAGS = -Os -mmcu=$(BOARD) -DF_CPU=16000000UL -Wall -I/Users/JAYDEN/Documents/EELAB/AVR/include # 경고도 표시되도록 -Wall 추가
LDFLAGS = -mmcu=$(BOARD) -L/Users/JAYDEN/Documents/EELAB/AVR/lib -lmystdio
# 소스 코드 파일 및 오브젝트 파일 목록
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# .hex 파일 생성 규칙
$(TARGET).hex: $(TARGET)
	avr-objcopy -O ihex -R .eeprom $< $@

# 오브젝트 파일 생성 규칙
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# 메인 타겟 빌드 규칙
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ -lmystdio

# 클린업 규칙
clean:
	rm -f *.o $(TARGET) $(TARGET).elf $(TARGET).hex

# 플래시 규칙 (avrdude를 사용하여 프로그램 업로드)
flash: $(TARGET).hex
	avrdude -V -c arduino -p $(BOARD) -P $(PORT) -D -U flash:w:$<
