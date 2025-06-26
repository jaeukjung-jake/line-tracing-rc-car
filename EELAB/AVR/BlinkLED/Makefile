MCU = atmega328p
F_CPU = 16000000UL
BAUD = 115200
PORT = /dev/tty.usbmodem1101

CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

CFLAGS = -std=c11 -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU)
TARGET = 8bitdata
SRC = $(TARGET).c myArduino.c   # 소스 파일 목록

all: $(TARGET).hex

$(TARGET).elf: $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC)

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

flash: $(TARGET).hex
	$(AVRDUDE) -v -p $(MCU) -c arduino -P $(PORT) -b $(BAUD) -D -U flash:w:$(TARGET).hex:i

clean:
	rm -f *.elf *.hex
