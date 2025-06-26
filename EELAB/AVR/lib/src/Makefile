# 라이브러리 이름 및 타겟 보드 설정
LIBNAME = mystdio
BOARD = atmega328p

# 컴파일러 및 도구 설정
CC = avr-gcc
AR = avr-ar
RM = rm -f
CP = cp

# Mac 경로 설정 (슬래시 사용)
INCDIR = /Users/JAYDEN/Documents/EELAB/AVR/include

# 컴파일 플래그 설정
CFLAGS = -g -Os -mmcu=$(BOARD) -I$(INCDIR)

# 소스 파일 및 오브젝트 파일 목록
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# 기본 타겟: 라이브러리 생성
all: lib$(LIBNAME).a

# 라이브러리 생성 규칙
lib$(LIBNAME).a: $(OBJS)
	$(AR) rcs $@ $^
	$(CP) $@ ..

# 오브젝트 파일 생성 규칙
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# 정리(clean) 규칙
clean:
	$(RM) $(OBJS) lib$(LIBNAME).a